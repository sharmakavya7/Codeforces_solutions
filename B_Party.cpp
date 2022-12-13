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
const int N = 2e5+10;

// int n, k, l, p, q, m, d, x, y;
// string s, b;
// vector<pll>v;
// ll a[N][N];
int a[N], degree[N];

void solve() {
    // GRAPH SOLN (same hi hai bas degrees ke respect me visualize it)
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> v;

    for(int i=1; i<=n; i++) {
        cin >> a[i];
        // p += a[i];
        degree[i] = 0;
    }
    for(int i=1; i<=m; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
        degree[x]++;
        degree[y]++;
    }
    int ans = INT_MAX;
    if(m % 2 == 0) {
        cout << "0"; line;
        return;
    } 
    // printv(degree, n);
    for(int i=1; i<=n; i++) {
        if(degree[i] % 2 != 0) {
            ans = min(ans, a[i]);
        }
    }
    for(int i=0; i<m; i++) {
        ll x = v[i].first;
        ll y = v[i].second;

        if(degree[x] % 2 == 0 && degree[y] % 2 != 0) {
            ans = min(a[x] + a[y], ans);
        }
    }
    cout << ans; line;

}

/*
MAP SOLUTION:
IF m IS ODD:
way1: Iterate over odd positions and if freq of x = odd, then ans = min(ans, ax)
way2: Choose a pair, where both  and y are occuring even times and remove both of them, meaning;
Iterate over all pairs, (x,y), If frw of x is even and freq of y = even then ans = min(ans, ax+ay)
int n, m;
    cin >> n >> m;
    map<int, int>mp, frq;
    vector<pair<int, int>>vp;
    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x;
        mp[i] = x;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vp.push_back({ x,y });
        frq[x]++;
        frq[y]++;
    }
    if (m % 2 != 0) {
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (frq[i] % 2 != 0) {
                ans = min(ans, mp[i]);
            }
        }
        for (int i = 0; i < m; i++) {
            if (frq[vp[i].first] % 2 == 0 && frq[vp[i].second] % 2 == 0) {
                ans = min(ans, mp[vp[i].first] + mp[vp[i].second]);
            }
        }
        cout << ans << "\n";
    }
    else { 
        cout << 0 << "\n"; 
    }
*/


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