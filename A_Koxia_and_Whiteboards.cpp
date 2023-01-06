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

// ll n, k, l, p, q, m, d, x, y;
// string s, t;
// vector<pll>v;
ll a[N], b[N];

void solve() {
    ll n, m;
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll> > minh;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        minh.push(a[i]);
    }
    for(int i=0; i<m; i++) {
        cin >> b[i];
        minh.pop();
        minh.push(b[i]);
    }
    // printv(a,n); 
    // printv(b,m);
    // sort(a, a+n, greater<int>());
    // sort(b, b+m, greater<ll>());

    ll sum = 0;
    while(!minh.empty()) {
        sum += minh.top();
        minh.pop();
    }
    cout << sum ; line;
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
ll sum = 0;
    if(n > m) {
        // ll sum = 0;
        for(int i=0; i<m; i++) {
            sum += b[i];
            // cout <<"b[i] " << b[i] <<" sum:"<<sum <<" ";
        }
        for(int i=0; i<n-m; i++) {
            // cout <<"a[i] " << a[i] <<" ";
            sum += a[i];
        }
        
    } else {
        // ll sum = 0;
        for(int i=0; i<n; i++) {
            // cout << "b[i] " << b[i] <<" ";
            sum += b[i];
        }
    }
    cout << sum ; line;
*/