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

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}


void solve() {
    int N;
    cin >> N;

    vector<int> A(N + 1), B(N + 1), pref(N + 2, 0), suf(N + 2, 0);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++)
        cin >> B[i];

    for (int i = 1, j = N; i <= N; i++, j--) {
        pref[i] = pref[i - 1] + A[i] * B[i];
        suf[j] = suf[j + 1] + A[j] * B[j];
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        dp[i][i] = A[i] * B[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (i == j) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + A[i] * B[j] + A[j] * B[i]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            ans = max(ans, dp[i][j] + pref[j - 1] + suf[i + 1]);

    cout << ans;
}

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     // clear_global();
    // }
    solve();
    return 0;
}

/*
sum[i][j] stores the new sum on reversing the subarray [j,i]
sum[i][j]=sum[i−1][j+1]+A[i]∗B[j]+A[j]∗B[i] 

We calculate the sum of elements we get on reversing every subarray [j,i].

To account for the rest of the array, loop over all subarrays and use prefix sums 
to add the remaining part. Take the best value over all subarrays.

Time complexity: O(N2)
*/