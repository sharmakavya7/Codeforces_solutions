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
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";}}
void printv(ll v[], ll n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const int N = 2e5+10;

// int n, k, l, p, q, m, d, x, y;
// string s, b;
// vector<pll>v;
// ll a[N][N];
// int a[N], degree[N];

void solve() {
    ll n, k;
    cin >> n>> k;
    vector<pair<ll,ll>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first;
    }
    ll mini = INT_MAX;
    for(int i=0; i<n; i++){
        cin >> v[i].second;
        mini = min(mini,v[i].second);
    }
 
    sort(all(v));
 
    vector<ll> h(n),p(n);
    for(int i=0; i<n; i++){
        h[i] = v[i].first;
        p[i] = v[i].second;
    }
    // for(auto i : v) {
    //     cout << i[0] <<" "<< i[1] <<" ";
    // } line
    ll suffix[n]={0};
    suffix[n-1]=p[n-1];
    for(int i=n-2; i>=0; i--){
        suffix[i] = min(suffix[i+1],p[i]);
    }
    // printv(suffix, n);
    // cout<<endl;
    // cout<<mini;
    bool flag = 0;
    int check = 0;
    int i=0;
    while(i<n) {
        check += k;
        int ct;
        // cout<<check<<"c ";
        if(check < h[i]){
            ct = i;
        }
        else{
            check -= k;
            i++;
            continue;
        }

        mini = suffix[ct];
        k -= mini;
        // cout<<ct<<"t ";
 
        if(check<=0){
            flag=0;
            break;
        }
    }
 
    if(i==n || check>0) flag=1;
 
    if(flag) cout << "YES";
    else cout << "NO"; line;
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

