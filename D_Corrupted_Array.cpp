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
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5+10;

ll n, k, l, p, q, m, d, x, y, r;
string s, t;
// vector<pll>v;
ll a[N];

void solve() {
    cin >> n;
    ll sum = 0;
    vector<int> b(n + 2);
    for(int i=0; i<n+2; i++) {
        cin>>b[i];
        sum += b[i];
    }
    // sort(b.begin(), b.end(), greater<ll>());
    sort(b.rbegin(), b.rend());
    // simple
    if(b[1] == sum - b[0] - b[1]) {
        for(int i=2; i<b.size(); i++) {
            cout << b[i] <<" ";
        }
        line;
    }
    else {
        // find that number by linearly iterating
        for(int i=1; i<b.size(); i++) {
            if(b[0] == sum - b[i] - b[0]) {
                for(int j = 1; j < i; j++) {
                    cout << b[j] <<" ";
                }
                for(int j=i+1; j<b.size(); j++) {
                    cout << b[j]<<" ";
                }
                line;
                return;
            }
        }
        cout << "-1"; line;
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