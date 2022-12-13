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
#include <regex>
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
void printv(ll v[], ll n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const int N = 2e5+10;

// int n, k, l, p, q, m, d, x, y;
// string s, b;
// vector<pll>v;
// ll a[N][N];
int a[N], degree[N];

void solve() {
    ll n, x;
    cin >> n >> x;
    // ll a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    ll sum = 0, ans = 0, day = 0;
    sort(a, a+n);
    // for(int i = n-1; i>=0; i--) {
    for(int i=0; i<n; i++) {
        sum += a[i];

        if(sum <= x) {
            ans += ((x - sum) / (i+1) ) + 1;
        }

        // if(sum > x) {
        //     sum -= (a[i] + ans);
        //     continue;
        // }
        
    }
    cout << ans; line;
}

/*
STILL DOUBTFUL
Observation:
When our sum will exceed from x, we will remove the max number out of them
Remopving the max element means, waha tak ki arr ka sum - the last element

Kitne din tak mai i sugar shops se sugar le skti hu, ye find krna hai
Har din 1 increase ho rha hai, sum ke respect me sum is inc by n every other day
Sum is forming an AP -> ((x-sum)/no of days till now) + 1;
*/


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