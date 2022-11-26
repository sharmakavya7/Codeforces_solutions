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
void printv(ll v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5+10;

ll n, k, l, p, q, m, d, x, y, r;
string s, t;
// vector<pll>v;
// ll a[N], b[N];

void solve() {
    cin >> s;
    int n = s.size();
    char even = s[n-1] - '0';
    int idx = -1;
    for(int i=0; i<n; i++) {
        if((s[i] -'0') % 2 == 0 ) {
            idx = i;
            if( even > (s[i]-'0') ) {
                swap(s[n-1], s[i]);
                cout << s;
                return;
            }
        }
    }
    if(idx != -1) {
        swap(s[idx], s[n-1]);
        cout <<s; line;
        return;
    }
    if(idx == -1) {
        cout << -1;
        return;
    }
}


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


/*
if(i > idx) {
            // cout << s[i] <<" ";
                even = s[i] - '0';
                idx = i;
            }
            flag = 1;

                // cout << even ; line;
    // if(flag == 1) {
    //     s[idx] = s[n-1]; 
    //     s[n-1] = even + '0';
    //     cout << s; line;
    // }
*/