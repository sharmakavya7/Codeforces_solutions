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
// int a[N], degree[N];

void solve() {
    ll n;
    cin >> n;
    ll a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    if (a[0] == a[n-1]) {
        cout << 1ll * n * (n - 1); line
        return;
    }
    int diff = a[n-1] - a[0];

    int i = 0, j = n-1;
    int cntl = 0, cntr = 0;
    // while(a[0] == a[i] && i < n) {
    for(int i=0; i<n; i++) {
        if(a[0] == a[i])
            cntl++;
    }
    // while(a[n-1] == a[j] && j >= 0) {
    for(int j=n-1; j>=0; j--) {
        if(a[n-1] == a[j])
            cntr++;
    }
    // jitne bhi same no honge, unke pair ka cnt return krna hai basically
    // 1 1 1 1 2 2 2, total pairs: no of 1s * no of 2s * 2 krdo cz if 1,2 cnsider kra hai then 2,1 
    // int cntStart = i;
    // int cntEnd = n - j - 1;

    cout << 1LL * cntl * cntr * 2; line;
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
