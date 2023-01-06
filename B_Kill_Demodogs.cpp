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
void printv(ll v[], int n) { for(int i=1; i<=n; i++) { cout << v[i] <<" "; } line;}

const int N = 3e5+10;

// ll n, k, l, p, q, m, d, x, y;
// string s, t;
// vector<pll>v;
// ll a[N], b[N];

void solve() {
    ll n, ans=0;
    cin >> n;
	ans = n;
	ans *= n + 1;
	ans %= mod;
	ans *= 4 * n - 1;
	ans %= mod;
	ans *= 337;
	ans %= mod;
	cout << ans ; line;
    // ll idx = 1;
    // for(int i=1; i<=n; i++) {
    //     idx = 2 * (i % mod) % mod;
    // }
    // // cout << n <<" " << idx-2 <<" ";
    // ll ans = 1;
    // if(n == 2) {
    //     cout << "14154"; line;
    //     return;
    // }
    // if(n >= 3) {
    //     ans = 2;
    // }
    // vector<ll>v;
    // ll c = 2, ss = 0;
    // for(int i=2; i<=(idx-2)/2 + 1; i++) {
    //     for(int j=0; j<2; j++) {
    //         ans += c;
    //         // v.push_back(ans);
    //         cout << "ans:" <<ans << " ";
    //         ss += ans;
    //         // cout << ss <<" ";
    //     }
    //     // cout << c <<" "<< ans <<" ";
    //     c++;
    // }
    // cout << ss * 2022 ; line;
    // print(v);
    // cout << ans; line; line
    // ll sum = 0;
    // for(int i=0; i<v.size(); i++) {
        // sum += v[i];
    // }
    // sum += 3;
    // cout << sum % mod * 2022; line;
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
/*
ll n;
    cin >> n;
    ll idx = 1;
    for(int i=1; i<=n; i++) {
        idx = 2 * (i % mod) % mod;
    }
    // cout << n <<" " << idx-2 <<" ";
    ll ans = 1;
    if(n == 2) {
        cout << "14154"; line;
        return;
    }
    if(n >= 3) {
        ans = 2;
    }
    vector<ll>v;
    ll c = 2, ss = 0;
    for(int i=2; i<=idx-2; i++) {
        for(int j=0; j<2 && v.size()+2 <= idx-2; j++) {
            ans += c;
            // v.push_back(ans);
            // cout << "ans:" <<ans << " ";
            ss += ans;
            cout << ss <<" ";
        }
        // cout << c <<" "<< ans <<" ";
        c++;
    }
    cout << ss * 2022 ; line;
    // print(v);
    // cout << ans; line; line
    // ll sum = 0;
    // for(int i=0; i<v.size(); i++) {
        // sum += v[i];
    // }
    // sum += 3;
    // cout << sum % mod * 2022; line;
*/