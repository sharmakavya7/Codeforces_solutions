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
void printv(ll v[], int n) { for(int i=1; i<=n; i++) { cout << v[i] <<" "; } line;}

using namespace std;

const int N = 2e5 + 2 ; 
vector<int>adj[N];
int vis[N] = {0};
ll n, m;

void input() {
    // int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
}

bool dfs(int node, int parent) {
    vis[node] = 1;

    for(auto i:adj[node]) {  
        if(!vis[i]) {
            if(dfs(i, node)) {
                return true;
            }
        }
        else if(i != parent ) {
            return true;
        }
    }
    return false;
}

int main() {
    input();
    ll cnt = 0;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(dfs(i, -1) == false) {
                cnt++;
            }
        }
    }
    cout << cnt; line;
    return 0;
}

