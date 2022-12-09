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
int a[N], b[N], Y[N];

void solve() {
    cin >> n;
    ll sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        // sum += a[i];
    }
    cout<<n-1<<endl;
    sum += a[0] + a[n-1];
    // if(sum == even) then all the elements could be either odd or even
    // so now we just have to place the last number to the forst position so that
    // aaage chalke we convert all the elements accordingly
    // odd example: (same goes for even)
    // 5 7 3 9 11 1
    //          1 1
    //       1  1 1
    //     1 1  1 1  and so on
    // odd + even elements example: if(sum == odd)
    // 7 2 3 4 9 1 11 6 8 
    // odd + even = odd => right wale chnge honge
    // 7 7
    // 7 7   7        7 7
    // odd + odd => even => left wale change honge but usme problem hai cz arr is not sorted we'll face issues
    // so deal with all the odd numbers pehle se hi
    // 7  2 3  4  9  1  11 6 8 
    // 11   11   11  11 11
    // now, odd + even = odd
    // sabko 11 bana do, simpleeeeeee
    if(n == 1) {
        return;
    }
    cout << 1 <<" "<<n; line;
    if( sum % 2 == 0 ) {
        a[0] = a[n-1];

    } 
    else if(sum % 2 != 0) {

        a[n-1] = a[0];
        // cout << 1 << " " << n; line;
    }
    for(int i=1; i<n-1; i++) {
        // even
        if(a[0] + a[i] % 2 == 0) {
            cout << i+1 << " " << n; line;
        } else {   // odd
            cout << 1 <<" "<< i+1; line;
        }
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

