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
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 101; 
// int a[N][N];

void solve () {
    int n, m, d;
    cin >> n >> m >> d;
    ll p[n],a[m];
    for(int i=0; i<n; i++) {
        cin >> p[i];
    }
    for(int i=0; i<m; i++) {
        cin >> a[i];
    }
    map<ll,ll>mp;
    for(int i=0; i<n; i++){
        mp[p[i]]=i;
    }
    ll cnt=0;
    for(int i=0 ; i <m-1; i++){
        // all three relations if koi bhi ye inequalities fulfil nhi kia then ans = 0
        if(mp[a[i+1]] > mp[a[i]] && mp[a[i+1]] <= mp[a[i]] + d) {
            cnt++;
        }
    }
    if(cnt >= m-1){
        ll ans = INT_MAX;
        for(int i=0 ; i<m-1; i++){
            ll a1 = mp[a[i+1]] - mp[a[i]];
            if(d+1 > n-1) {
                ans = min(ans,a1);
            } else {
                ll a2 = (d+1) - a1;
                ans = min(ans,min(a1,a2));
            }
        }
        cout<<ans; line
    }
    else {
        cout<<0; line
    }

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
