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

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const int N = 2e5+10;

// int n, k, l, p, q, m, d, x, y;
// string s, b;
// vector<pll>v;
ll a[N], b[N];

void solve() {
    ll n, i = 0, j = 0;
    cin >> n;
    ll d_max[n];
    for(i=0; i<n; i++) {
        cin >> a[i];
    }

    for(i=0; i<n; i++) {
        cin >> b[i];
    }

    for(i=0; i<n; i++){
        while(b[j] < a[i]) {
            j++;
        }
        cout << b[j] - a[i] << " ";
    }
    line;

    d_max[n-1] = b[n-1] - a[n-1];

    for(i = n-2, j = n-1; i>=0; i--) {
        if(a[i+1] <= b[i]){
            d_max[i] = b[j] - a[i];
        } else{
            j = i;
            d_max[i] = b[i]  - a[i];
        }
    }

    for(i=0; i<n; i++){
        cout << d_max[i] << " ";
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

