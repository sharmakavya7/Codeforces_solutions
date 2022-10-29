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
void print(vector<int> vec){ for (int i{};i<vec.size();i++) cout<<vec[i]<<" "; cout<<endl;}

const int N = 1e5 + 2;
// int pref[N], suf[N];
int n;;
vector <ll> a(N),b(N);

void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
}

void solve() {
    input();
    vector<ll> dp(2);
    for(int i = 0 ; i < n; i++){
		ll x, y ;
        // row 0
		x = max(dp[0], dp[1] + a[i]);
		// row 1
        y = max(dp[1], dp[0] + b[i]);
		dp[0] = x;
		dp[1] = y;
	}
    // cout <<"ihudsf";
    cout << max(dp[0],dp[1]); line;
}

int main() {
    fast;
    // int t;
    // cin >> t;
    // while(t--) {
        solve();
    // }
    return 0;
}

// dp[1] = total max height till current index choosing from 1st row
// dp[0] = total max height till current index choosing from 0th row