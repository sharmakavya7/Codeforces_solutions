#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstring>
#include <cstdlib> 
#include <ctime>
#include <sstream>
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <utility>
#include <deque>
#include <queue>
#include <stack>

#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)    for(int i = 0; i < a; i++)

using namespace std;
 
# define D double
# define I insert
# define ll long long
# define ld long double

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) (v).begin() , (v).end() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >

# define F first
# define S second
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = (int)1e9+7;
// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

// MY CODE
struct Node {
	string v;
	vector<Node*>links;
	Node* parent;
	int anc_locked, dec_locked, uid;
	bool isLocked;

	Node(string x, Node* p) {
		v = x;
		parent = p;
		anc_locked = 0;
		dec_locked = 0;
		uid = 0;
		isLocked = false;
	}

	void addLinks(vector<string>l, Node* p) {
		for(auto &i : l) {
			links.push_back(new Node(i, p));
		}
	}
};

void printTree(Node* r) {
	cout << "Parent: " << r->v << endl;
	cout << "Child: "<< endl;
	for(auto k : r->links) {
		cout << k->v << " anc_locked: " << k->anc_locked << " dec_locked:"
		<< k->dec_locked << " isLocked:" << k->isLocked <<" uid:" << k->uid << endl;
	}
	cout << endl;
	for(auto k : r->links) {
		printTree(k);
	}
}

struct Node* buildTree(Node* root, int &m, vector<string>& s) {
	queue<Node*>q;
	q.push(root);

	int st = 1;
	while(!q.empty()) {
		Node* r = q.front();
		q.pop();

		if(st >= s.size()) {
			continue;
		}

		vector<string>temp;
		for(int i=st; i<st+m; i++) {
			temp.push_back(s[i]);
		}
		r->addLinks(temp, r);
		st+=m;

		for(auto k : r->links) {
			q.push(k);
		}
	}
	return root;
}

class Tree {
	private:
		Node* root;
		unordered_map<string, Node*>vton;
	public:

		Tree(Node* r) {
			root = r;
		}
		Node* getRoot() {
			return root;
		}
		void fillVtoN(Node* r) {
			if(!r) {
				return;
			}
			vton[r->v] = r;
			for(auto k : r->links) {
				fillVtoN(k);
			}
		}

		void inforDecendants(Node *r, int val) {
			for(auto k : r->links) {
				k -> anc_locked += val;
				inforDecendants(k, val);
			}
		}

		bool verifyDecendants(Node* r, int &id, vector<Node*> &v) {
			if(r->isLocked) {
				if(r->uid != id) {
					return false;
				}
				v.push_back(r);
			}
			if(r->dec_locked == 0) {
				return true;
			}

			bool ans = true;
			for(auto k : r->links) {
				ans &= verifyDecendants(k, id, v);
				if(ans == false) {
					return false;
				}
			}
			return ans;
		}

		bool lock(string v, int id) {
			Node *t = vton[v];
			if(t->isLocked) return false;

			// if(t->anc_locked != 0) return false;
      
      // traversing through parent if they are locked or not
      Node* cur = t->parent;
      while(cur) {
      	if(cur -> isLocked) {
        	return false;
        }
      }

			if(t->dec_locked != 0) return false;

			Node* cur = t->parent;
			while(cur) {
				cur -> dec_locked++;
				cur = cur->parent;
			}
			// inforDecendants(t, 1);
			t->isLocked = true;
			t -> uid = id;
			return true;
		}

		bool unlock(string v, int id) {
			Node* t = vton[v];
			if(!t->isLocked) return false;
			if(t->isLocked && t->uid != id) {
				return false;
			}

			Node* cur = t->parent;
			while(cur) {
				cur -> dec_locked--;
				cur = cur -> parent;
			}
			inforDecendants(t, -1);
			t->isLocked = false;
			return true;
		}

		bool upgrade (string v, int id) {
			Node* t = vton[v];
			if(t->isLocked) return false;

			if(t->anc_locked != 0) return false;
			if(t->dec_locked == 0) return false;

			vector<Node*>vec;
			if(verifyDecendants(t, id, vec)) {
				for(auto k : vec) {
					unlock(k->v, id);
				}
			} else return false;
			lock(v, id);
			return true;
		}
};

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<string>s(n);
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}
	Node* r = new Node(s[0], NULL);
	r = buildTree(r, m, s);

	Tree t(r);
	t.fillVtoN(t.getRoot());

	int op, uid;
	string sq;

	for(int i=0; i<q; i++) {
		cin >>  op >> sq >> uid;
		switch(op) {
			case 1: if(t.lock(sq, uid)) {
					cout << "true"<< endl;
				} else {
					cout << "false" <<endl;
				}
				break;
			case 2: if(t.unlock(sq, uid)) {
					cout << "true" << endl;
				} else {
					cout << "false"<<endl;
				}
				break;
			case 3: if(t.upgrade(sq, uid)) {
					cout <<"true"<<endl;
				} else {
					cout << "false" << endl;
				}
				break;
		}
	}
	return 0;
}


