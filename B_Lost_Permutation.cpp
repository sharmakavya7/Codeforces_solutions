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
vector<int> v1, v2;
int v[1004]; // v1[1000], v2[10000];
int cnt = 0, sum = 0, res = 1, ans = 0;
long long dp[N];


void solve() {
    cin >> m >> k;
    for(int i = 0; i < m ; i++) {
        cin >> v[i];
    }
    unordered_map<int, int> mp;
    for(int i=0; i<m; i++) {
        mp[v[i]]++;
    }
    for(int i=1; i<=1000; i++) {
        if(k <= 0) {
            break;
        }
        if(mp.find(i) == mp.end() && k-i >= 0) {
            mp[i]++;
            k -= i;
        }
    }
    // for(auto i=mp.begin(); i!=mp.end(); i++) {
    //     cout << i->first<<" ";
    // }
    for(auto i=mp.begin(); i!=mp.end(); i++) {
        v1.push_back(i->first);
    }
    int l = v1.size();
    sort(v1.begin(), v1.end());
    // cout <<"mpsize:"<< mp.size()<<" " << v1[l-1]<<" ";
    if(v1.back() == mp.size() && k == 0) {
        cout <<"YES"; line;
    } else {
        cout <<"NO"; line;
    }
}

void clear_global() {
    v1.clear();
    // mp.clear();
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
