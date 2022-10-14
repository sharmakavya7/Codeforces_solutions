#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);

const int N = 1e5 + 5;
vector<int> freq(N), seq(N);
ll dp[N];
int n;

void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        // seq.push_back(t);
        freq[t]++;
    }
}

void solve() {
    // for(int i=0; i<n; i++) {
    //     cout << freq[i]<<" ";
    // }
    dp[1] = freq[1];
    // cout << dp[1]<<" ";
    dp[0] = freq[0];
    for(int i=2; i<100001; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + (1ll*i*freq[i]));
	}
    cout << dp[100000] << endl;
}

int main() {
    input();
    solve();
    return 0;
}
