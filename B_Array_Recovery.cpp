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
const int N = 2e5 + 2 ; 
vector<int>adj[N];
int vis[N] = {0};
int n, m;

void solve() {
    
    int n;
    cin>>n;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) {
        cin>>vec[i];
    }
    //cout<<vec[0]<<" ";
    int a[n];
    a[0] = vec[0];
    int flag = 0;
    for (int i = 1; i < n; i++) {
        a[i] = a[i-1] + vec[i];  
        if(a[i-1] >= vec[i] && vec[i] != 0) {
            flag=1;
            break;
        }
    }
    if(flag) {
        cout<<-1; line
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << a[i] <<" ";
        }
        line;
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
