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
#define maxh priority_queue<ll>
#define minh priority_queue<ll,vector<ll>,greater<ll>>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], ll n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}
bool isprime(int n){for(int i=2;i*i<=n;i++){if(n%i==0)return 0;}return 1;}

const int mod = (int)1e9+7;
// const ll N = 2e5 + 5 ;  

// ll a[N], b[N], pref[N];

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
      cout << 0 ; line
    }
    else {
        ll  ans = sqrt(n);
        ans -= 1;
        while (ans * ans < n) {
            ans += 1;
        }
        cout << ans - 1 ; line
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