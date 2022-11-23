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
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2 ) {
        int d = abs(y1-y2);
        cout << x1+d << " " << y1 << " " << x2+d <<" "<< y2;
        // return; 
    }
    else if(y1 == y2 ) {
        int d = abs(x1-x2);
        cout << x1 << " " << y1+d << " "<< x2 << " "<< y2+d;
        // return;
    }
    else {
        int d1 = abs(x1-x2), d2 = abs(y1-y2);
        if(d1 != d2) {
            cout << "-1";
            
        } else {
           cout << x1 <<" " << y2 <<" " << x2 <<" " << y1;
        }
    }
    line;
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
