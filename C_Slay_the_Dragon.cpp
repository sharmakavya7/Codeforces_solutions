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
const int N = 3e5+10;

// ll n, k, l, p, q, m, d, x, y;
// string s, t;
// vector<pll>v;
ll a[N], X[N], Y[N];

void solve() {
    ll n;
    cin >> n;
    ll sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    ll q;
    cin >> q;
    while(q--) {
        int X, Y;
        cin >> X >> Y;
        ll k = upper_bound(a, a+n, X) - a;
        ll mini = LLONG_MAX;
        if(k != n) {
            ll temp = sum - a[k];
            mini = min(mini, max(0LL, Y - temp));
        } 
        if(k != 0) {
            k--;
            ll temp = sum - a[k];
            mini = min(mini, (X-a[k]) + max(0LL, Y - temp));
        }
        cout << mini ; line;
    }
    
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
