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
# define mp make_pair
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}

const int N = 2e5+10;

ll n, k, l, p, q, m, d, a, b;
string s, t;
// vector<int>v, v1, v2;
int v[1004], v1[10000], v2[10000];
int cnt = 0, sum = 0, res = 1, ans = 0;
long long dp[N];


void solve() {
    cin >> s;
    for(int i=0; i<50; i++) {
        t += "Yes";
    }
    int j = 0;
    int p = s.size();
    for(int i=0; i<p; i++) {
        if(s[i] == 'Y' || s[i] == 'e' || s[i] == 's') {
            continue;
        } else {
            cout <<"NO"; line;
            return;
        }
    }
    for(int i=0; i<t.size(); i++) {
        if(s[j] != t[i]) {
            continue;
        } else {
            while(p--) {
                if(s[j] == t[i]) {
                    j++;
                    i++;
                } else {
                    cout << "NO"; line;
                    return;
                }
            }
        }
    }
    cout << "YES"; line;
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
