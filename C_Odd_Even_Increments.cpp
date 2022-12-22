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
    int n;
    cin >> n;
    int a[n], b[n];
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    bool flag1 = 0;

    for(int i=2;i<n;i++){
        if(a[i]%2 != a[i-2]%2){
            flag1 = 1;
        }
    }
    if(flag1) {
        cout << "NO" ; line;
    } else {
        cout <<"YES"; line;
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

/*
bool fl1=0, fl2 = 0;
    int a1 = a[0], a2 = a[1];
    if(a1 % 2 == 0) {
        fl1 = 1;
    }
    if(a2 % 2 == 0) {
        fl2 = 1;
    }
    for(int i=0; i<n; i ++) {
        if(i % 2 == 0) {
            
        } else if(i % 2 != 0) {

        }
    }

    for(int i=0; i<n; i++) {
        if(i%2 == 0) {
            cin >> a[i];
        }
        else {
            cin >> b[i];
        }
    }
    if(a[0] % 2 == 0 || b[0] % 2 == 0) {
        for(int i=0; i<n/2; i++) {
            if(a[i] % 2 != 0 || b[i] % 2 != 0) {
                cout << "NO"; line;
                return;
            }
        }
    }
    if(a[0] % 2 != 0 || b[0] % 2 != 0) {
        for(int i=0; i<n/2; i++) {
            if(a[i] % 2 == 0 || b[i] == 0) {
                cout << "NO"; line;
                return;
            }
        }
    }
    cout <<"YES"; line;
*/
