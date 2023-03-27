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
const ll N = 2e5 + 2 ;  

void solve() {
    int n;
    cin >> n;
    int v[n];
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    int mini = *min_element(v, v+n);
    int maxi = *max_element(v, v+n);

    int minIdx = -1, maxIdx = -1;
    for(int i=0; i<n; i++) {
        if(v[i] == mini) {
            minIdx = i;
        }
    }
    for(int i=n-1; i>=0; i--) {
        if(v[i] == maxi) {
            maxIdx = i;
        }
    }
    if(minIdx - maxIdx < 0) {
        cout << (n-minIdx) + (maxIdx-1) - 1;
    }
    else {
        cout << (n-minIdx) + maxIdx - 1;
    }
    // cout << (n-minIdx) <<" "<<maxIdx<<" ";
    
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
