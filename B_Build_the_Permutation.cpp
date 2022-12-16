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
int a[N], degree[N];

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if(a+b+2>n || abs(a-b) > 1){
        cout<< "-1" <<endl;
        return;
    }
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        v[i] = i;
    }
    for(int i = n-a-b; i<n; i+=2){
        swap(v[i], v[i+1]);
    }
    if(b > a){
        for(int i=1;i<=n;i++){
            v[i] = n - v[i] + 1;
        }
    }
    // print(v);
    for(auto i=1; i<=n; i++) {
        cout << v[i] <<" ";
    }

    // for(int i=n-1; i>=0; ) {
    //     for(int k=0; k<=i; k++) {
    //         int p = k+i;
    //         int q = sqrt(p);
    //         if(q * q == p) {
    //             // ye wo range hai jisme apan reverse krne hai
    //             int k1 = k, i1 = i;
    //             while(k1 <= i1) {
    //                 // swap(a[k1], a[i1]);
    //                 a[k1] = i1;
    //                 a[i1] = k1;
    //                 k1++, i1--;
    //             }
    //             i = k -1;
    //             break;
    //         }
    //     }
    // }
    // printv(a, n);
    line;
}

/*
n = 9
    0 1 2 3 4 5 6 7 8 
=>    8 7 6 5 4 3 2 1   permut seq

Search for pairs such that where i + n-1 is a perfect sq, then
0  -------- i --------n-2 n-1
          n-1 n-2 --- i+1  i 
Aise krke rearrange kr do, and for the index 0 to i, again, iterate and find where 
new i + n-1 (jo pehle i likha hua tha, since 1 se lekr n-1 ka find kr liya, to ab 0 to i-1 tak ka find krna)

example:
n = 6
0 1 2 3 4 5
0 3 2 1 5 4  <- permut seq
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