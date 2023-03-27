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
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 101; 
// int a[N][N];

void solve () {
    ll n;
    cin >> n;
    ll a[n];
    ll neg = 0;
    ll prevsum =0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i] < 0) {
            neg++;
        }
    }
    ll plusmesabsechhota = 1e9;
    for(int i=0; i<n; i++) {

        if(plusmesabsechhota > abs(a[i])) {
            plusmesabsechhota = abs(a[i]);
        }
    }
    for(int i=0; i<n; i++) {
        prevsum += abs(a[i]);
    }
    if(neg == 0) {
        cout << prevsum; line
        return;
    }
    // cout << plusmesabsechhota <<" ";
    if(neg % 2 != 0) {
        prevsum -= (2*plusmesabsechhota);
    }
    // cout << prevsum <<" " ;
    cout <<  prevsum; line;
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
