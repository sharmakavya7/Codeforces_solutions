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
    int n;
    cin >> n;
    vector<int>a, b(n);
    map<int, int>mp;
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
    for(int i=0; i<n; i++) {
        mp[b[i]]++;
    }
    for(auto i=0; i<n; i++) {
        if(mp[b[i]] % b[i] != 0) {
            cout <<"-1"; line;
            return;
        }
    }
    map<int,int>mp2, mp3;
    // line se numbers
    int j = 1;
    a.push_back(j);
    mp2[b[0]] = j++;
    mp3[b[0]]++;

    for(int i=1; i<n; i++) {
        if(mp2.find(b[i]) == mp2.end()) {
            a.push_back(j);
            mp2[b[i]] = j++;
            mp3[b[i]]++;
        } 
        else if( mp3[b[i]] % b[i] != 0) {
            a.push_back(mp2[b[i]]);
            mp3[b[i]]++;
            // a.push_back(mp3[b[i]]);
        }
        // case: 2 occurs 4 times or 2 occurs 6 times
        else {
            mp2[b[i]] = j;
            a.push_back(j++);
            mp3[b[i]]++;
        } 
    }
    print(a);
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
/*
if(count(mp2.begin(), mp2.end(), b[i]) == 0) {
            a.push_back(j);
            mp2[b[i]] = j++;
            mp3[b[i]]++;
        } 
for(auto i : mp) {
        if(i.first == i.second) {
            // mp2[i.first] = j++;
            a.push_back(j++);
        } else {
            if(i.second % i.first != 0) {
                int tim = i.second / i.first;
            }
            
        }
    } 
*/
