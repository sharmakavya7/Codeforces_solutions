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

const int N = 55 ; 
// pii b[N];
// vector<ll> a[N];
// ll vis[N];

int mat[N][N] = {0};

void rev(int i,  int n) {
    int p = 0, q = n-1;

    while(p < q) {
        int temp = mat[i][p];
        mat[i][p] = mat[i][q];
        mat[i][q] = temp;
        p++, q--;
    }
}

void solve () {
    ll n;
    cin >> n;
    ll a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int low = 0;
    int high = 1e9;

    for(int i=0; i<n-1; i++) {
        if(a[i] == a[i+1]) {
            continue;
        }
        else if(a[i] < a[i+1]) {
            int x = (a[i] + a[i+1])/2;
            high = min(high, x);
            // cout << high <<" x:" << x <<" ";
        } else {
            int x = (a[i] + a[i+1] + 1) / 2;
            low = max(low, x);
        }
    }
    if(high >= low) {
        cout << high; line
    } else {
        cout << -1; line;
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
