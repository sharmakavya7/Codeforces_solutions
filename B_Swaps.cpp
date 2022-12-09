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

ll n, k, l, p, q, m, d, x, y;
string s, t;
// vector<pll>v;
ll a[N], b[N], Y[N];

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    ll maxi = 0;
    for(int i=0; i<n; i++) {
        cin >> b[i];
        maxi = max(maxi, b[i]);
        if(b[i] < maxi) {
            b[i] = maxi;
        } 
    }
    int moves = 0;
    // if(b[0] > a[0]) {
    //     cout <<"0"; line;
    //     return;
    // }
    // int dhundo = b[0];
    // auto lb = lower_bound(a, a+n, dhundo) - a;
    // cout << lb <<" b[0]:" <<dhundo <<" ";
    // cout << lb; line;
    ll mini = INT_MAX;
    for(ll i = 0; i < n; i++) {
        ll lb = lower_bound(b, b + n, a[i]) - b;
        mini = min(mini, lb + i);
    }
    cout << mini; line;
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
