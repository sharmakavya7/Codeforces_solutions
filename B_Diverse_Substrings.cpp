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

// int n, k, l, p, q, m, d, x, y;
string s, b;
// vector<pll>v;
// int a[N], b[N], M[N];

void solve() {
    int n;
    cin >> n >> s;
    // no of dis char & max freq & ans
    int ans = 0, maxfreq = 0, dis = 0;
    // freq array
    int c[10];
    // i -> starting point of substr
    for(int i=0; i<n; i++) {
        
        dis = 0, maxfreq=0;
        for(int k=0; k<=9; k++) {
            c[k] = 0;
        }
        // ending point of substr
        for(int j=i; j <= i+99 && j < n; j++) {
            c[s[j]-'0']++;
            maxfreq = max(maxfreq, c[s[j]-'0']);
            // first occ of this char, i.e. dis char
            if(c[s[j]-'0'] == 1) {
                dis++;
            }
            if(maxfreq <= dis) {
                ans++;
            }
        }
    }
    cout << ans; line;
}

/*
0 - 9 digits in string s
Loophole: 0 is 10 times, 1 is 10 times, 2 is 10 times ------- 9 is 10 times
=> 100 digits and high occ freq = 10 nad no of dis char = 10
=> conditons (till here hols true): 10 <= 10
But but, when we include an 11th character, this condn will become false as we dont have digits>=9
Steps: 
1. Check all the substr whose len <= 100, TC: n(100)
2. 
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
