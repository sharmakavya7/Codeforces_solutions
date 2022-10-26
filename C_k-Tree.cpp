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
const int mod= (int)1e9+7;
# define fast ios_base::sync_with_stdio(false); cin.tie(0);
ll __gcd(ll a,ll b) {
	if(a!=0)return __gcd(b%a,a);
	return b;
}

const int N = 200 + 5;
ll n, k, d, max_wt = 0, ways = 0;
ll dp[N][N];

void input() {
    cin >> n >> k >> d;
}

int solve(int n, int max_wt) {
    // base case
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        if(max_wt >= d) {
            // cout <<"d: "<<d << " max_wt: " << max_wt<<" ";
            return 1;
        }
        return 0;
    }
    if(dp[n][max_wt] != -1) {
        return dp[n][max_wt];
    }

    int ways = 0;
    // cout << ways<<" ";
    for(int i=1; i<=k; i++) {
        // cout << "i: " << i <<" n: "<<n<< " ways: " << ways <<" "; line;
        ways += solve(n - i, max(max_wt, i));
        ways %= mod;
    }
    ways %= mod;
    return dp[n][max_wt] = ways;
}

void global() {
    // fill_n(dp, n, 0);
    max_wt = 0, ways = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dp[i][j] = -1;
        }
    }
}

int main() {
    input();
    memset(dp, -1, sizeof(dp));
    cout << solve(n, 0);
    global();
    return 0;
}



// dp[total weight required][max weight so far] 
//        |
// n is total wt we want and remaining wt after considering the curr edge would be => n - i
// n - i in the next call will be n, and when this d will become 0, we'll enter in base case
// in base case we need to check if the max wt so far is greater than or equal to d