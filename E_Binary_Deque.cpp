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

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const int N = 2e5+10;

// int n, k, l, p, q, m, d, x, y;
// string s, b;
// vector<pll>v;

// Make all elements of an Array equal by adding and subtracting 1 in single operation
void solve() {
    int n, s;
    cin >> n >> s;
    int a[n], sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int j = 0, ans = INT_MIN;

    if(sum < s) {
        cout << "-1"; line;
        return;
    } else if( sum == s) {
        cout <<"0"; line;
        return;
    } 
    vector<int>pref(n+1);

    for(int i=1; i<=n; i++) {
        pref[i] = pref[i-1] + a[i-1];
    }
    // print(pref);

    for(int i=1; i<=n; i++) {
        while(pref[i] - pref[j] > s) {
            j++;
        }
        ans = max(ans, (i - j));
    }
    // cout << n<<" "<<ans ; line;
    cout << (n-ans); line;    
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