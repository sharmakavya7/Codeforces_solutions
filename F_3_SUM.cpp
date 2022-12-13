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
    ll n; cin >> n;
    vector<ll>v(n);
    for(int i=0; i<n ;i++) {
        cin >> v[i];
    }
    unordered_map<ll, ll>mp;
    for(int i=0; i<n; i++) {
        mp[v[i] % 10]++;
    }
    // Reduced array
    vector<ll>v1;
    for(int i=0; i<10; i++) {
        for(int j=0; j<min(3LL, mp[i]); j++) {
            v1.push_back(i);
        }
    }
    bool flag = 0;
    for(int i=0; i<v1.size(); i++) {
        for(int j=i+1; j<v1.size(); j++) {
            for(int k=j+1; k<v1.size(); k++) {
                if( (v1[i] + v1[j] + v1[k]) % 10 == 3) {
                    // cout <<"YES"; line;
                    flag = true;
                    break;
                    // return;
                }
            }
            if(flag == true) {
                break;
            }
        }
        if(flag == true) {
            break;
        }
    }
    if(flag == true) {
        cout << "YES"; 
    }
    else cout << "NO"; line;
}

/*
Ezzz pzzzz

    ( a + b + c ) % 10 = 3
=> ( (a % 10) + (b % 10) + (c % 10) ) % 10 = 3

- puri array ka % 10 kr ke save krlo (all eel will be between 0 to 9)
- now we just have to find those 3 numbers jinka sum krke %10 karo to 3 de, Find combinations;
Possibilities:
    ai  aj  ak
    1   1   1
    1   1   2
    1   1   3 
    1   1   4
    1   1   5

    => max 1s required for sum to be divisible by 3 = 3
    => kisi bhi no ki requirement 3 times hi hogi
    => useless numbers ko hata do to reduce the complexity

example:
   1 1 1 1 1 1 7 9 3 4
=> 1 1 1 7 9 3 4
Aise krke when we will reduce its complexity na, to len bhi decrease hoga arr ka
=> complexity: 0 to 9 numbers at max 3 baar occ ho skte hai => n = 3 * 10 => n <= 30
Ab we can apply n^3 approach (30*30*30) => loop laga do bas

*/


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