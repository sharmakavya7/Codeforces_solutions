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
    cin >> s;
    int n = s.size();
    int freq[10] = {};
    int mini = s[n-1];
    for(int i = n - 1; i >= 0; i--) {
        int num = s[i] - '0';

        if(num <= mini) {
            // mini store krre basically
            mini = num;
            freq[num]++;
        } else {
            // num + 1 ki frq ++;
            freq[min(num + 1, 9)]++;
        }
    }
    for(int i=0; i<=9; i++) {
        while(freq[i]--) {
            cout << i;
        }
    }
    line;
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

