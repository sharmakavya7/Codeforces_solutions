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

const int N = 1e5 + 5;
ll n, arr[N], ans, maxDif=0;

void solve() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    ll k = arr[0];
    for(ll i=1; i<n; i++) {
        ans = 0;
        if(arr[i] > k) {
            k = arr[i];
        }
        if(arr[i] < k) {
            maxDif = max(maxDif, k - arr[i]);
        }
    }
    while(maxDif > 0) {
        ans++;
        maxDif /= 2;
    }
    cout << ans; line
}

void clear_global() {
    fill_n(arr, n, 0);
    ans = 0;
    // x = 0;
    maxDif = 0;
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--) {
        solve();
        clear_global();
    }
    return 0;
}

/*
if(arr[i-1] > arr[i]) {
            // cout <<"k: "<<k <<" ";
            while(arr[i-1] > k) {
                // cout << "sum: "<<k+pow(2, x)<<" ";
                // cout << "a[i]:" << arr[i]<<" ";
                if(arr[i-1] <= k+pow(2, x)) {
                    k = k+pow(2, x);
                }
                // cout <<"postk: " << k <<" ";
                x++;
            }
            // cout << "x: "<<x<<" ";
            // ans += x;
            arr[i] = k;
        }
*/