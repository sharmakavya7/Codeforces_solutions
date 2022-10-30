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
const int mod= (int)1e9+7;
ll __gcd(ll a,ll b) {
	if(a!=0)return __gcd(b%a,a);
	return b;
}
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}

const int N = 202;
int a[N], dp[N][3], n;


void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
        dp[i][2] = INT_MAX;
    }
}

void solve() {
    input();
    // we can always rest at day 0
    dp[0][0] = 1;

    // initially if a[i] = 1 or 3, we can have no rest
    if(a[0] == 1 || a[0] == 3) 
        dp[0][1] = 0;

    // initially if a[i] = 2 or 3, we can have no rest
    if(a[0] == 2 || a[0] == 3)
        dp[0][2] = 0;

    // now on from day 1 
    for(int i=1; i<n; i++) {
        // 0 pe to we can always rest, so fill that block 1 + prev min
        dp[i][0] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));

        if(a[i] == 1 || a[i] == 3) {
            // while choosing 1, we cant't choose 1 again right, we can only take our ans from 0/2
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }
        if(a[i] == 2 || a[i] == 3) {
            // while choosing 1, we cant't choose 1 again right, we can only take our ans from 0/2
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])); line;
}



int main() {
    fast;

    solve();

    return 0;
}

