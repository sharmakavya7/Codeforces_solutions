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
#define maxh priority_queue<ll>
#define minh priority_queue<ll,vector<ll>,greater<ll>>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], ll n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}
bool isprime(int n){for(int i=2;i*i<=n;i++){if(n%i==0)return 0;}return 1;}

const int mod = (int)1e9+7;
// const ll N = 2e5 + 5 ;  

// ll a[N], b[N], pref[N];

void solve() {
    ll n;
    cin >> n;

    vector<int>v1(n), v2(n);

    for(int i=0; i<n; i++) {
        cin >> v1[i];
    }
    for(int i=0; i<n; i++) {
        cin >> v2[i];
    }

    // int maxi1 = *max_element(all(v1));
    // int maxi2 = *max_element(all(v2));

    // if(maxi1 == v1[n-1] && maxi2 == v2[n-1]) {
    //     cout << "YES"; line;
    //     return;
    // }
    for(int i=0; i<n; i++) {
        if(v1[i] <= v2[i]) {
            swap(v1[i], v2[i]);
        }
    }
    // print(v1);
    // print(v2);
    int maxi1 = *max_element(all(v1));
    int maxi2 = *max_element(all(v2));

    if(maxi1 == v1[n-1] && maxi2 == v2[n-1]) {
        cout << "YES"; line;
        return;
    }
    else {
        cout <<"NO"; line
    }
    
}
/*
1 2 3 
2 4 2

1 4 3
2 2 2
*/

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