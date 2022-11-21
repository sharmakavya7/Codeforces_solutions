#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstring>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
# define mp make_pair
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}

const int N = 2e5+10;

ll n, k, l, p, q, m, d, a, b;
string s, t;
// vector<int> v1, v2;
int v[N], v1[N], v2[N];

// ll calc(int cnt, int ans, int arr[]) {
//     for(int i=0; i<n; i++) {
//         if(arr[i] == 1) {
//             cnt++;
//         } else {
//             ans += cnt;
//         }
//     }
//     return ans;
// }

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        v1[i] = v[i];
        v2[i] = v[i];
    }

    ll cnt1 = 0, ans = 0;

    for(int i=0; i<n; i++) {
        if(v[i] == 0) {
            v2[i] = 1;
            break;
        }
    }
    
    for(int i=n-1; i>=0; i--) {
        if(v[i] == 1) {
            v1[i] = 0;
            break;
        }
    }
    for(int i=0; i<n; i++) {
        if(v1[i] == 1) {
            cnt1++;
        } else {
            ans += cnt1;
        }
    }
    ll maxi = ans;
    ans = 0;
    cnt1 = 0;
    for(int i=0; i<n; i++) {
        if(v2[i] == 1) {
            cnt1++;
        } else {
            ans += cnt1;
        }
    }
    maxi = max(maxi, ans);
    ans = 0;
    cnt1 = 0;
    for(int i=0; i<n; i++) {
        if(v[i] == 1) {
            cnt1++;
        } else {
            ans += cnt1;
        }
    }
    maxi = max(maxi, ans);

    cout << maxi; line;
}

void clear_global() {
    // v2.clear();
    // cnt = -1;
    // mp.clear();
    fill_n(v, n, 0);
    fill_n(v1, n, 0);
    fill_n(v2, n, 0);
}

int main() {
    fast;
    ll t;
    cin >> t;
    while(t--) {
        solve();
        clear_global();
    }
    // solve();
    return 0;
}
