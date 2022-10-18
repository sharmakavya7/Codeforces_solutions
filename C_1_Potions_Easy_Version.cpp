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
 
# define C continue;
# define R return
 
# define D double
# define I insert
# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define pb push_back
# define pf push_front
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvs vector < vs >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >
 
# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair
# define line cout<<"\n";
#define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int N = 2000 + 2;
ll n, a[N], dp[N][N] = {INT_MIN},t[N], maxi=0;
// dp -> [index, no_of_potions_frank]

void input() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        t[i] = INT_MIN;
    }
}

void solve() {
    for(ll i=1; i<=n; i++) {
        for(ll j=i; j>=1; j--) {
            if(t[j-1]+a[i] >= 0) {
                t[j] = max(t[j-1] + a[i], t[j]);
                maxi = max(maxi, j);
            } 
        }
    }
    cout << maxi; line
}

void clear_global() {
    maxi = INT_MIN;
    fill_n(t, n, INT_MIN);
}

int main() {
    fast;
    input();
    solve();
    clear_global();
    // cout << ans << endl;
    return 0;
}

/*
samjh nhi aaya bhai
void solve() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << "sum:"<<dp[i-1][j-1] + a[i]<<" ";
            if(dp[i-1][j-1] + a[i] >= 0) {
                cout << "a[i]:"<<a[i]<<" ";
                dp[i][j] = max(dp[i-1][j-1] + a[i], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n-1][n-1]; line
}
*/

// 1 D DP solution
/*
// fucking knapsack 2.0
void solve() {
    for(ll i=1; i<=n; i++) {
        for(ll j=i; j>=1; j--) {
            if(t[j-1]+a[i] >= 0) {
                t[j] = max(t[j-1] + a[i], t[j]);
                maxi = max(maxi, j);
            } 
        }
    }
    cout << maxi; line
}
*/

/*
for(int j=1; j<n+1; j++) {
            if(dp[i-1][j] + a[i] > 0) {
                cout << "a[i]:" << a[i] <<" ";
                ans++;
                dp[i][j] = dp[i-1][j] + a[i];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }

        if(a[i-1] > 0) {
            // cout << "a[i]:"<<a[i-1] <<" dp[i]:"<<dp[i-1] <<" ";
            ans++;
            dp[i] = dp[i-1] + a[i-1];
        } else {
            dp[i] = dp[i-1];
        }


        // new
        dp[0][0] = 0;
    int ans = 0;
    int sum = 0;
    int j = 0;
    for(int i=1; i<n; i++) {
        // for(int j=1; j<n+1; j++) {
            if(sum + a[i-1] > 0) {
                // cout << "a[i]: "<<a[i-1]<<" ";
                sum += a[i-1];
                // cout << "sum: "<<sum<<" ";
                dp[i][j] = 1 + max(dp[i-1][j], dp[i][j-1]);
                ans++;
            } else {
                dp[i][j] = dp[i][j-1]; 
            }
            // line
            j++;
        // }
    }
    // cout << dp[n-1][n-1] << endl;
    cout << ans ; line
*/

/*
for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(dp[i-1][j-1] + a[i] >= 0) {
                dp[i][j] = max(dp[i-1][j-1] + a[i], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n-1][n-1]; line
*/