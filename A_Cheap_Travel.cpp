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
void printv(ll v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5+10;

ll n, k, l, p, q, m, d, x, y, r;
string s, t;
// vector<pll>v;
ll a[N], b[N];
pll v[N];

void solve() {
    cin >> n >> m >> x >> y;
    ll ans = INT_MAX;
    for(int i=0; i<=n; i++) {
        int enhh = (n -i + m -1) / m;
        int abhi = x * i + enhh * y;
        if(abhi < ans) {
            ans = abhi;
        }
    }
    cout << ans; line;
}

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     // clear_global();
    // }
    solve();
    return 0;
}

/*
BRUTE
for(int i = 0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            if(i * m + j >= n) {
                ans = min(ans, y*i + x*j);
            }
        }
    }
*/