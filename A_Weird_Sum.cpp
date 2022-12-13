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
// ll a[N][N];

ll f (map<ll, vector<ll>>& mp) {
    ll ans1 = 0;
    for (auto x : mp)
    {
        ll temp = 0;
        vector<ll> v = x.second;
        sort(all(v));
        for (int i=1; i<v.size(); ++i) 
        {
            temp = temp + i * abs(v[i]-v[i-1]);
            ans1 += temp;
        }
    }
    return ans1;
}

void solve() {
    ll n,m;
    cin >> n >> m;
    map<ll, vector<ll>> mx, my;

    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            int k;
            cin >> k;
            mx[k].push_back(i);
            my[k].push_back(j);
        }
    }
    // int ans1 = f(mx);
    
    // int ans2= f(my);

    cout << f(mx) + f(my); line;
}

/*

*/


int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     // clear_global();
    // }
    solve();
    return 0;
}