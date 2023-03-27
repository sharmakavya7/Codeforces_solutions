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
const ll N = 2e5 + 5;
vector<int> adj[N];
vector<int> vis(N), sz(N), enter(N), ind(N);
vector<pair<int,int>> ans(N);
int n, m;

void dfs(int node) {
 
    vis[node]=1;
    sz[node]=1;
 
    enter.push_back(node);
    for(auto i:adj[node]) {
        if(!vis[i]){
            dfs(i);
            sz[node]+=sz[i];
        }
    }
}



int main() {
    fast;
    int n,q;
    int u,v;
    cin >> n >> q ;
 
    for(int i=2; i<=n; i++) {
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    dfs(1);
    for(int i=0; i<enter.size(); i++){
        ind[enter[i]] = i;
    }

    int k;
    while(q--) {
        cin >> u >> k;
        if(k > sz[u]) {
            cout << "-1"; line
        }
        else {
            cout << enter[ind[u]+k-1]; line
        }
    }
    return 0;
}
