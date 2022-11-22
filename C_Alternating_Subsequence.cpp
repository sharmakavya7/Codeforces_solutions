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
ll v[N], v1[N], v2[N];
 
void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    ll i=0, sum = 0;
    while(i < n) {
        ll maxi = v[i];
        i++;
        // same signs multiplication > 0 => same window => save window max
        while(i < n && v[i]*v[i-1] > 0) {
            maxi = max(v[i++], maxi);
        }
        // add window max
        sum += maxi;
    }
    
    cout << sum; line;
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

/*
find max in every window
window : positves ki window and negatives ki window
*/

/*
thoda kam sense => bad code
while(i < n && j < n) {
        if(v[i] < 0) {
            int max_neg = v[i];
            while(v[j] < 0) {
                if(max_neg < v[j]) {
                    max_neg = v[j];
                }
                j++;
            }
            i = j;
            sum += max_neg;
        } else if(v[i] > 0) {
            int max_pos = v[i];
            while(v[i] > 0) {
                if(max_pos < v[i]) {
                    max_pos = v[i];
                }
                i++;
            }
            j = i;
            sum += max_pos;
        }
    }
*/