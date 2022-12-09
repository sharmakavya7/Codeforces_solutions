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
string a, b;
// vector<pll>v;
// int a[N], b[N], M[N];

void solve() {
    ll n;
    cin >> n >> a >> b;
    int same = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == b[i]) {
            same++;
        }
    }
    if(same != 0 && same != n) {
        cout << "NO"; line;
        return;
    }
    vector<pii>ind;
    int steps = 0;
    // now convert all the continuous segments of 1s to 0s in string a
    for(int i=0; i<n; ) {
        if(a[i] == '1') {
            steps++;
            int j = i;  // starting point
            while(a[i] == a[j] && i < n) {
                i++;
                // steps++;
                
            }
            ind.push_back({j+1, i});
        } else {
            i++;
        }
    }
    if(same == n && steps % 2 != 0) {
        steps += 3;
        ind.push_back({1, n});
        ind.push_back({1, 1});
        ind.push_back({2, n});
    }
    // string a ke saare char ko jab humne 0 kara to b ke sab 1 ho gye honge 
    else if(same == 0 && steps % 2 == 0) {
        steps += 3;
        ind.push_back({1, n});
        ind.push_back({1, 1});
        ind.push_back({2, n});
    }
    cout<<"YES"; line;
    cout<<steps; line;

    for(int i=0; i<steps; i++) {
        cout<<ind[i].first<<" "<<ind[i].second; line;
    }
}

/*
2 cases :
 same == n || same == 0 && steps%2 ==0 {
    3 steps hai, put them in vector, see below
 }
 example:
 0000000
 1111111
 by obv:
 sare char ko ulta krdo l = 1, r = n
 1111111
 1111111
 now, l = 1, r = 1;
 0111111
 1000000
 now, l = 2, r = n;
 0000000
 0000000
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
