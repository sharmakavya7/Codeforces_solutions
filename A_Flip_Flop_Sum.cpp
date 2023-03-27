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
    int n;
    cin >> n;
    int a[n];
    int flag = 0, p = 0;
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
        if(a[i] == -1) {
            p = 1;
        }
    }
    for(int i=1; i<n; i++) {
        if(a[i-1] == -1 && a[i] == -1) {
            flag = 1;
            i+=2;
            break;
        }
    }
    if(p == 0) {
        sum -= 4;
    }
    // cout << sum <<" ";
    if(flag == 1) {
        sum += 4;
    }
    cout << sum ; line;
    // for(int i=0; i<n; i++) {
    //     if(a[i] == -1 && flag == 0) {
    //         a[i] = 1;
    //         cout << i <<" " << a[i] <<" ";
    //         sum += a[i];
    //         flag = 1;
    //         continue;
    //     }
    //     sum += a[i];
    // }
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
