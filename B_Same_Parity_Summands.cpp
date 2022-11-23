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

ll n, k, l, p, q, m, d, a, b, x;
string s, t;
unordered_map<int,int>mp;
// vector<int> v1, v2;
int v[N], v1[N], v2[N];
 
void solve() {
    cin >> n >> k;
    // odd
    if(n >= k && (n-k+1) % 2 == 1) {
        cout << "YES"; line;
        for(int i=1; i<k; i++) {
            // cout << i << " ";
            cout <<"1 ";
            // sum -= i;
        }
        cout << n - k + 1; line;
    } else if(n >= 2*k && n%2 == 0) {
        cout << "YES"; line;
        for(int i=1; i<k; i++) {
            // cout << i << " ";
            cout <<"2 ";
            // sum -= i;
        }
        cout << n-2*(k-1); line;  // KYA HAGA HAI BHAIIIIII 
    } else {
        cout << "NO"; line;
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
