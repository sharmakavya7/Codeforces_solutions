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
#include <regex>
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

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], ll n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const int N = 2e5 + 2 ; 
vector<int> adj[N] , node;
int vis[N] = {0};
int n, m;

void dfs(int s , int p ) {
    if(p != -1)
	    node.push_back(adj[s].size() - 1);
    else 
        node.push_back(adj[s].size());

	if(node.back() == 0){
		node.pop_back();
	}
    for(auto u : adj[s]) {
        if(u == p) continue;
        dfs(u,s);
    }
}


void solve() {
    // input
    cin >> n;
	int u;
	node.clear();
	for(int i = 0; i <= n; i++){
		adj[i].clear();
	}
	for(int i = 1; i < n; i++){
		cin >> u;
		adj[u].push_back(i+1);
		adj[i+1].push_back(u);
	}
    // solve
    dfs(1, -1);
	node.push_back(1);
	sort(all(node));
	reverse(all(node));
	int ans = 0;
	n = node.size();
	for(int i = 0; i < n; i++){
		ans++;
		node[i] = node[i] - (n-i);
	}
	sort(all(node));
	reverse(all(node));
	while((!node.empty()) && node.back() <= 0){
		node.pop_back();
	}
	n = node.size();
	while(n){
        int last = 0;
        for(int i = 0; i < n; i++){
            if(node[0] == node[i]){
                last = i;
            } else break;
        }
        node[last]--;
        for(int i = 0; i < n; i++){
            node[i]--;
        }
        ans++;
        while((!node.empty()) && node.back() <= 0){
            node.pop_back();
            n--;
        }
	}
	cout << ans ; line
}

int main() {
    fast;
    ll t;
    cin >> t;
    while(t--) {
        solve();
        // clear_global();
    }
    // solve();
    return 0;
}
