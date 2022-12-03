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
// string s, t;
// vector<pll>v;
// ll a[N], b[N];

void solve() {
    cin >> n;
    ll sum = 0;
    vector<ll>a(n);
    for(int i=0; i<n; i++) {
        ll t;
        cin >> t;
        a.push_back(t);
        sum += t;
    }
    // ll sum = accumulate(all(a), 0);
    sort(allrev(a));
    
    // cout << sum <<" ";
    priority_queue<ll>pq;
    pq.push(sum);
    string ans = "YES";
    ll i = 0;
    // while(!a.empty()) {
    while(pq.size() && i < n) {

        auto topi = pq.top();
        pq.pop();
        // cout << topi <<" ";
        if(topi < a[i]) {
            ans = "NO"; 
            break;
        }
        if(topi == a[i]) {
            // a.pop_back();
            i++;
            continue;
        }
        
        ll f = topi / 2, s = topi - f;
        pq.push(f);
        pq.push(s);
    }
    cout << ans; line
    // return;
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