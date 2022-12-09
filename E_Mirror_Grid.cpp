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

int n, k, l, p, q, m, d, x, y;
string s, t;
// vector<pll>v;
// int a[N], b[N], Y[N];

void solve() {
    cin >> n;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            char c;
            cin >> c;
            // v[i].push_back(c - '0');
            v[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i=0; i<n;i++) {
        for(int j =0; j<n; j++) {
            ll sum = v[i][j] + v[j][n-1-i] + v[n-1-i][n-1-j] + v[n-1-j][i];
            // cout<<sum<<" ";
            ans += min(sum, 4 - sum);
        }
    }
    cout << ans/4; line;
}

// https://youtu.be/76jBjNdfpUM

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

