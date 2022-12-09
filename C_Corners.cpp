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
string a[N];

void solve() {
    cin >> n >> m;
    int ones = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        ones += count(all(a[i]), '1');
    }

    if(ones == m*n) {
        cout << ones - 2; line;
        return;
    }
    bool flag = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j] == '0' && i + 1 < n && a[i + 1][j] == '0') {
                flag = 1;
            } 
            if(a[i][j] == '0' && j + 1 < m && a[i][j + 1] == '0') {
                flag = 1;
            } 
            if(a[i][j] == '0' && i + 1 < n && j + 1 < m && a[i+1][j+1] == '0') {
                flag = 1;
            } 
            if(a[i][j] == '0' && i - 1 >= 0 && j + 1 < m && a[i-1][j+1] == '0') {
                flag = 1;
            } 
        }
    }
    if(flag == true) {
        cout << ones; line;
    } else {
        cout << ones - 1; line;
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

/*
Simplest logic everrrr (tutorial)
Note that if there is a connected area of zeros in the table of size at least 2, 
then we can add one 0 to this area by replacing only one 1 in the table. 
That means that if we have such area we can fill the table with zeros in cnt1 operations 
(we can't make more opertions because we need to replace at least one 1 by operation).


Simple language:
But if you don't have two 0s aligned (horizontally, vertically or diagonally) 
at first, then you have to place the first piece in an area with two 1s (if a 0 exists), 
or in an area with three 1s (if there is no 0 at all initially). After that, however, 
the remaining 1s can be covered one at a time.

Basically: if there exists two 0s aligned horizontally/vertically/diagonally, 
then the answer is the number of 1s initially. Otherwise, if there exists 
at least one 0, then the answer is (number of 1s) minus 1. Otherwise, 
if there is no 0, then the answer is (number of 1s) minus 2.
*/