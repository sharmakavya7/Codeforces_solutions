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
    ll n;
    cin >> n;
    vector<ll> v(n+1);
    vector<ll>pref(n+1, 0);
    // pref[0] = v[0];
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }

    // pref[n] = 0
    if(pref[n] != 0) {
        cout <<"No"; line;
        return;
    }

    // all pref[i] >= 0

    // for(int i=0; i<n; i++) {
    //     if(pref[i] < 0) {
    //         cout <<"No"; line;
    //         return;
    //     }
    // }

    // if some pref[i] == 0, then all the following will be zerooo
    // for(int i=0; i<n; i++) {
    //     if(pref[i] == 0) {
    //         for(int j=i; j<n; j++) {
    //             if(pref[j] != 0) {
    //                 cout << "No"; line;
    //                 return;
    //             }
    //         }
    //     }
    // }

    bool check = false, tf = true;

    for(int i=1; i<=n; i++) {
        if(pref[i]==0) {
            check=true;
            continue;
        }

        if(check || pref[i] < 0) {
            tf = false;
            break;
        }
    }

    if(tf)
        cout<<"Yes"; 
    else
        cout<<"No"; line;
}

/*
first ele agr negative hai then ALWAYS NO
- if first ele is zero then all the ele must be zero
a1   a2   a3   a4

0   -a1   0    0
    a2-(-a1)        // opearions needed
=> a1 + a2 >= 0 for the ans to be possible
- if here only a1+a2 = 0 then all the further elements will be zero

a1   a2   a3   a4

-    -  a1+a2+a3   // operations
=> a1 + a2 + a3 >= 0 for the ans to be possible
- if here only a1+a2 = 0 then all the further elements will be zero

Apply the same logic to all the remaining elements

- This implies all the prefix of ai, should be >= 0; pref[i] >= 0
- If some pref[i] = 0, then all pref[i+1]----n should be 0
- pref[n] = 0;
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