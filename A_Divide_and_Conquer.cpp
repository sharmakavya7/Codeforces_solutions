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
int a[N], degree[N];

void solve() {
    ll n;
    cin >> n;
    // vector<ll>a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    // number of odds and evens
    // if odd no of odds then smallest no ko /2 karo aur sum even bnao
    // else 0
    int odds = 0, evens= 0;

    for(int i=0; i<n; i++) {
        if(a[i] % 2 == 0) {
            evens++;
        }  else{
            odds++;
        }
    }
    int cnt = INT_MAX, cnteve = INT_MAX, cntodd = INT_MAX;
    int sum = accumulate(a, a+n, 0);
    if(sum % 2 == 0) {
        cout << "0"; line;
        return;
    }
    if(odds % 2 != 0) {
        // cout << a[0] <<" ";
        for(int i=0; i<n; i++) {
            int rem = a[i] % 2, ginbc = 0;
            // cout << "a[i]%2:" << a[i]%2 <<" rem:"<<rem <<" ";
            while(a[i] % 2 == rem) {
                cout <<"a[i]:"<<a[i] << " a[i]%2:" << a[i]%2 <<" rem:"<<rem <<" ";
                ginbc++;
                a[i] /= 2;
            }
            line;
            cnt = min(cnt, ginbc);
        }
    } else {
        cout <<"0"; line;
        return;
    }
    // cout << min(cnteve, cntodd) ; line;
    cout << cnt; line;
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
while(sum % 2 != 0) {
            a[0] /= 2;
            sum -= a[0];
            cnt++;
        }

for(int i=0; i<n; i++) {
            int rem = a[i]%2, ctr = 0;
            while(a[i]%2 == rem) {
                // cout << a[0]<<" "<< floor(a[0]/2);
                // a[0] = floor(a[0]/2);
                a[0] /= 2;
                // sum -= a[0];
                ctr++;
            }
            cnt = min(cnt, ctr);
        }
*/