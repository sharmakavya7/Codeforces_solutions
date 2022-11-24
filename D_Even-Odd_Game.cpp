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

ll n, k, l, p, q, m, d, x, r;
string s, t;
vector<ll>v, v1, v2;
// ll v[N], v1[N], v2[N], a[N], b[N];

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int o;
        cin >> o;
        v.push_back(o);
    }
    ll cntA = 0, cntB = 0;
    sort(all(v), greater<int>());

    for(ll i=0; i<n; i++) {
        if(i % 2 == 0) {
            if(v[i] % 2 == 0) {
                cntA += v[i];
            }
        } else {
            if(v[i] % 2 != 0) {
                cntB += v[i];
            }
        }
    }
    if(cntA > cntB) {
        cout << "Alice"; line;
    } else if(cntA < cntB) {
        cout << "Bob"; line;
    } else {
        cout << "Tie"; line;
    }
}

void clear_global() {
    v.clear();
    v1.clear();
    v2.clear();
    // cnt = -1;
    // mp.clear();
    // fill_n(v, n, 0);
    // fill_n(v1, n, 0);
    // fill_n(v2, n, 0);
}

int main() {
    fast;
    ll t;
    cin >> t;
    while(t--) {
        solve();
        clear_global();
    }
    // solve();
    return 0;
}

/* SOME ERROR
for(int i=0; i<n; i++) {
        if(v[i] % 2 != 0) {
            v1.push_back(v[i]);
        } else {
            v2.push_back(v[i]);
        }
    }
for(auto i : v1) {
       cout << i << " ";
    } line;
    for(auto i : v2) {
       cout << i << " ";
    } line;
    int cntA = 0, cntB = 0;
    int i = 0, j = 0;
    bool flag = 0;
    while(i < n && j < n) {
        // alice
        if(flag == 0) {
            if(v2[i] > v1[j]) {
                cntA += v2[i];
                i++;
            } else {
                j++;
            }
            // cout <<"cntA:"<< cntA <<" ";
            flag = 1;
        }
        // bob
        if(flag == 1) {
            if(v2[i] < v1[j]) {
                cntB += v1[j];
                j++;
            } else {
                i++;
            }
            // cout <<"cntB:" << cntB <<" ";
            flag = 0;
        }
    }
    // cout<<i<<" ";
    while(i < v2.size()) {
        cntA += v2[i];
        i++;
    }
    while(j < v1.size()) {
        cntB += v1[j];
        j++;
    }
    // line;
    if(cntA > cntB) {
        cout << "Alice"; line;
    } else if(cntA < cntB) {
        cout << "Bob"; line;
    } else {
        cout << "Tie"; line;
    }
*/