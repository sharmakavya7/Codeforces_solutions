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
int v1[N], v2[N];
ll cnt = 0, sum = 0, res = 1, ans = 0;

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> v1[i];
        v2[i] = v1[i];
    }
    sort(v2, v2+n);
    ll maxi = v2[n-1];
    ll secMax = v2[n-2];

    for(int i=0; i<n; i++) {
        if(v1[i] == maxi) {
            cout << v1[i] - secMax << " ";
        } else {
            cout << v1[i] - maxi << " ";
        }
    }
    line;
}

void clear_global() {
    // v1.clear();
    // cnt = -1;
    // mp.clear();
    fill_n(v1, n, 0);
}

int main() {
    fast;
    ll t;
    cin >> t;
    while(t--) {
        solve();
        clear_global();
    }
    // solve();
    return 0;
}

// mid/n means these many numbers are divisible by n**
// upto mid numbers... so subtract it.**