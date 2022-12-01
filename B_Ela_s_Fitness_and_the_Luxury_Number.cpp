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
void print(vector<ll> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 3e5+10;

ll n, k, l, p, q, m, d, x, y;
// string s, t;
// vector<pll>v;
ll a[N];


ll mySqrt(ll x) {
    ll res = 0;
    for (int i = 0; i <= 2; i++) {
        ll low = 0;
        ll high = (ll)2e9;
        // double epsilon = 0.000001;
        ll ans = 0;
        while(low <= high) {                    //trim it trim it trim it 
            ll mid = (low + high + 1)/2;        //shrink them till the diff becomes close to 1e^-6
            if((mid*(mid+i)) <= x ) {           // 1e^-6 = 10^-6
                ans = mid;
                low = mid + 1;
            }
            else{                               //sqrt find krna h, so we have found the sq of mid
                high = mid - 1;                 //if power was different, see below
            }
        }
        res += ans;
    }
    return res;
}

void solve() {
    ll l, r ;
    cin >> l >> r;
    ll cntl = mySqrt(l-1), cntr = mySqrt(r);
    cout <<cntr - cntl; line;
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

// IMPORTANT:
// for powers greater than 2, say for power n:
// we have to change line 10 and 13 to multiple(mid,n)
// this multiple fuunction will return:
// double multiply(int x, int n) {
//     double ans=1.0;
//     for(int i=1; i<=n; i++) {
//         ans *= x;
//     }
//     return ans;
// }