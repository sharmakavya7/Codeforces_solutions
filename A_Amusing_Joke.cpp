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

const int N = 1e5 + 2;

ll n, l, p, q, m, d;
string s, t;
vector<int>v1, v2;
// int v1[31], v2[31];
int cnt = 0, sum = 0;
int matrix[5][5];

void solve() {
    unordered_map<char, int>mp;
    cin >>s;
    // for(auto i:s) {
    //     mp[i]++;
    // }
    cin >> t;
    // for(auto i:t) {
    //     mp[i]++;
    // }
    string k;
    cin >> k;
    // for(auto i:k) {
    //     mp[i]++;
    // }
    
    // for(int i=0; i<s.size(); i++) {
    //     if(mp.find(s[i])!=mp.end()) {
    //         mp.erase(s[i]);
    //         continue;
    //     }
    //     else {
    //         cout<<"NO";
    //         return;
    //     }
    // }
    // for(int i=0; i<t.size(); i++) {
    //     if(mp.find(t[i])!=mp.end()) {
    //         mp.erase(t[i]);
    //         continue;
    //     }
    //     else {
    //         cout<<"NO";
    //         return;
    //     }
    // }
    
    // cout <<"YES"; line;
    s += t;
    sort(s.begin(), s.end());
    // sort(t.begin(), t.end());
    sort(k.begin(), k.end());
    // for(int i=0; i<n; i++) {
    //     if(s[i] != k[i]) {
    //         cout<<"NO";
    //     }
    // }
    if(s == k)
    cout <<"YES"; 
    else cout <<"NO"; line;
}

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    // }
    solve();
    return 0;
}