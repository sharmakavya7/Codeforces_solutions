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
    vector<pll>a, ans;
    for(int i=1; i<=n; i++) {   
        // cin >> a[i];
        int j;
        cin >> j;
        a.push_back({j, i});
    }
    sort(a.begin(), a.end());
    int x = 0;
    for(int i=1; i<n; i++) {
        if(a[i].first % a[i-1].first != 0) {
            x = (a[i].first / a[i-1].first + 1)*a[i-1].first - a[i].first; // *****
            ans.push_back({a[i].second, x});
            a[i].first += x;
        }
    }
    cout << ans.size(); line;
    for(auto i : ans) {
        cout << i.first <<" "<<i.second; line;
    }
}
/*
*****
lets say we have 5, 13
[(13/5) + 1 ] * 5  = 15
15 - 13 = 2 -> x
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

/*

for(int i=0; i<n; i++) {
        if(a[i] == mini) {
            continue;
        }
        // int rem = a[i] % mini;
        // int divhoga = a[i] - rem;
        // int num = divhoga + mini;
        // alag.push_back(num);
        int k = a[i] / mini;   // 57
        k *= mini;             // 342
        k += mini - a[i];      // 343 - 342 = 1
        
        ans.push_back({i+1, k});
    }
    // for(auto [i,j] : ans) {
    cout << ans.size(); line;
    for(auto i : ans) {
        cout << i.first <<" "<< i.second; line;
    }
    // line;
*/