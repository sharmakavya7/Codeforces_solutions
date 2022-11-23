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

ll n, k, l, p, q, m, d, a, b, x;
string s, t;
unordered_map<int,int>mp;
// vector<int> v1, v2;
int v[N], v1[N], v2[N];
 
void solve() {
    cin >> s;
    int n = s.size();
    int i=0, j=0;
    int mini =  INT_MAX;
    while(j < n && i < n) {
        mp[s[j]]++;
        // cout << "s[j]:"<< s[j] <<" mp:"<<mp[s[j]]<<" "<<" size:" << mp.size() << " ";
        while(i<n && mp[s[i]] > 1) {
            mp[s[i]]--;
            if(mp[s[i]]==0) {
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size() == 3) {
            mini = min(j-i+1, mini);
            // cout <<"mini:" << mini<<" ";
        }
        j++;
    }
    if(mini >= INT_MAX) {
        cout <<"0"; 
    }
    else cout << mini; line;
}

void clear_global() {
    // v2.clear();
    // cnt = -1;
    mp.clear();
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
