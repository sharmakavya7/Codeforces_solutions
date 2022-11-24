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

int n, k, l, p, q, m, d, x;
string s, t;
// vector<ll>v, v1, v2;
int v[N], v1[N], v2[N], a[N], b[N];

bool isSorted(int a[], int n) {
    
    if (n == 0 || n == 1)
        return true;
 
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
 
    return true;
}

void solve() {
    cin >> n >> x;
    ll idx = -1, idx2 = 0, sum = 0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int ans = -1;
    if(sum % x) {
        cout << n; line;
    } else {
        int ans = -1;
        for(int i=0; i<n; i++) {
            if(v[i] % x) {
                ans = max(ans, max(i, n - i - 1));   // imp
            }
        }
        cout << ans; line;
    }
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
