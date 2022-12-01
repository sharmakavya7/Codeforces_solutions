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

const int mod = (int)1e9+7;
// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<ll> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 3e5+10;

ll n, k, l, p, q, m, d, x, y;
// string s, t;
// vector<pll>v;
ll a[N];

void solve() {
    cin >> n >> k;
    // vector<int> a(k);
    for(int i=0; i<k; i++) {
        cin >> a[i];
    }
    if(k == 1) {
        cout <<"Yes"; line;
        return;
    }
    ll b[k-1];
    // vector<ll>b(k-1);
    for(int i=0; i<k-1; i++) {
        b[i] = a[i+1] - a[i];
    }
    // print(b);
    // if(!is_sorted(b.begin(), b.end())) {
    if(!is_sorted(b, b+k-1)) {
        cout << "No"; line;
        return;
    }
    /// tutorial me given hai
    if((ll)(n - k + 1)*b[0] >= a[0]) {
        cout <<"Yes"; line;
    } else {
        cout <<"No"; line;
    }
    // line;
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