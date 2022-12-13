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
    ll n;
    string s;
    cin >> n >> s;
    // r -> remaining
    ll r = 0, c = 0;

    for(int i=0; i<n; ) {
        if(s[i] == '(') {
            // agr ye last char hua to bach jaega and hum kuch nhi kr paenge
            if(i == n-1) {
                i++, r++;
            } else {
                // why i+=2? ( iska next agr ) hua to ye regular me cnt hoga else palindrome me, ez
                c++, i+=2;
            }
        } else {
            // if it a )
            // 2 cases: find ki next closing kab aara hai, agr nhi aaya to sab remaining me add honge
            int flag = 0;
            for(int j=i+1; j<n; j++) {
                if(s[j] == ')') {
                    c++, flag++, i = j+1;
                    break;
                }
            }
            if(flag == 0) {
                // pura traverse kia but closing bracket nhi mila mtlb
                // jitne bhi the uske aagr, sabhi remaining count me add ho jaenge
                r = n-i;
                break;
            }
        }
    } 
    cout << c <<" "<<r; line;
}

/*
2 cases:
either the string will start from '('  this or ')' this
Iske aage ka khud socho ki konse case me palindrome ban rha etc etc
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