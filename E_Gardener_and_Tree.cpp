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
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 400000 + 5; 
int deg[N], rnk[N], n, k;
vector<int>G[N];

void toposort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) {
            q.push(i);
            rnk[i] = 1;
        }
    }
    while(!q.empty()) {
        int u = q.front(); 
        q.pop();
 
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            deg[v]--;
            if(deg[v] == 1) {
                rnk[v] = rnk[u] + 1;
                q.push(v);
                // deg[v]--;
            }
        }
    }
}

void solve () {
    memset(deg, 0, sizeof(deg));
    memset(rnk, 0, sizeof(rnk));

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        G[i].clear();
    }
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++; 
        deg[v]++;
    }
    toposort();
    int ans = n;
    for(int i = 1; i <= n; i++) {
        if(rnk[i] <= k) {
            ans--;
        }
    }
    cout << ans << endl;
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
