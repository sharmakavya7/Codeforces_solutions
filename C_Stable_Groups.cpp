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

void solve() {
    cin >> n >> k >> x;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ll cnt = 0;   // groups without merging
    for(int i=2; i<=n; i++) {
        if(a[i] - a[i-1] > x) {
            cnt++;
            b[cnt] = a[i] - a[i-1];
        }
    }
    sort(b+1, b+cnt+1);
    ll ans = cnt + 1;
    for(int i=1; i<=cnt; i++) {
        ll target;
        if(b[i] % x == 0) {
            target = b[i]/x;
        } else {
            target = b[i]/x + 1;  // upper limit lena hai
        }
        target--;
        // cout << target<<" ";
        if(k >= target) {
            k -= target; ans--;
            // cout << ans <<" " << k <<" ";
        } else {
            // khtm k
            break;
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