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
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5+10;

ll n, k, l, p, q, m, d, x, r;
string s, t;
// vector<ll>v, v1, v2;
ll v[N], v1[N], v2[N], a[N], b[N];

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<int>ans;
    sort(v, v+n);
    int mini = INT_MAX;
    int d1 = -1, d2 = -1;
    for(int i=0; i+1<n; i++) {
        if(mini > (v[i+1] - v[i])) {
            mini = v[i+1] - v[i];
            d1 = i;
            d2 = i+1;
        }
    }
    for(int i=d2; i<n; i++) {
        ans.push_back(v[i]);
    }
    for(int i=0; i<=d1; i++) {
        ans.push_back(v[i]);
    }
    swap(ans[0], ans[n-1]);
    for(auto i : ans) {
        cout << i << " ";
    }
    line;
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
