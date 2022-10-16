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
#define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int N = 1e5 + 5;
ll n, q, arr[N], sum = 0, even = 0, odd = 0;

bool isOdd(int i) {
    if (i % 2 != 0)
        return true;
    else
        return false;
}

bool isEven(int i) {
    if (i % 2 == 0)
        return true;
    else
        return false;
}

void solve() {
    cin >> n >> q;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if(arr[i] % 2 == 0) {
            even++;
        }
        if(arr[i] % 2 != 0) {
            odd++;
        }
    }
    for(int i=0; i<q; i++) {
        int type, x;
        cin >> type >> x;
        if(type == 0) {
            sum += x*even;
            if(x % 2 != 0) {
                odd += even;
                even = 0;
            }
            // sum += x*even;
        }
        if(type == 1) {
            sum += x*odd;
            if(x % 2 != 0) {
                even += odd;
                odd = 0;
            }
            // sum += x*odd;
        }
        cout << sum << endl;
    }
    // cout << sum << endl;
}

void clear_global() {
    fill_n(arr, n, 0);
    even = 0;
    odd = 0;
    sum = 0;
    q = 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        clear_global();
    }
    return 0;
}

/*
if(type == 0) {
            for(int i=0; i<n; i++) {
                if(arr[i] % 2 == 0) {
                    arr[i] += x;
                }
            }
            cout << accumulate(arr, arr+n, 0) << endl;
        }
        if(type == 1) {
            for(int i=0; i<n; i++) {
                if(arr[i] % 2 != 0) {
                    arr[i] += x;
                }
            }
            cout << accumulate(arr, arr+n, 0) << endl;
        }
*/