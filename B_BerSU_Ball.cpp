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

const int N = 2e5+10;

ll n, k, l, p, q, m, d, a, b;
string s, t;
// vector<int> v1, v2;
int v1[1000], v2[1000];
int cnt = 0, sum = 0, res = 1, ans = 0;
long long dp[N];

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> v1[i];
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> v2[i];
    }
    sort(v1, v1+n);
    sort(v2, v2+m);
    ll j = 0, i = 0;
    while(i < n && j < m) {
        // int dif = abs(v1[i]-v2[j]);
        if(abs(v1[i]-v2[j]) <= 1) {
            cnt++;
            j++;
            i++;
        } else if(v1[i] > v2[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << cnt; line;
}

void clear_global() {
    // v1.clear();
    // cnt = -1;
    // mp.clear();
    // fill_n(dp, N, INT_MIN);
}

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     clear_global();
    // }
    solve();
    return 0;
}

