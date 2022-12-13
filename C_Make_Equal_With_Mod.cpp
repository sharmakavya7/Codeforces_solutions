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
    ll n;
    cin >> n;
    int a[N];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    bool flag = false, flag1 = false;
    for(int i=0; i<n; i++) {
        if(a[i] == 1) {
            flag = true;
            break;
        }
    }
    if(flag == false) {
        cout <<"YES"; line;
        return;
    }
    else {
        sort(a, a+n);
        // cherck consecutive
        for(int i=0; i<n-1; i++) {
            if(a[i + 1] - a[i] == 1) {
                flag1 = true;
                break;
            }
        }
        if(flag1) {
            cout << "NO"; line;
        } else {
            cout <<"YES"; line;
        }
    }
}

/*
Observation:
If there is atleast one 1 in the arr, we can't make all the elements same, why?
example:
0 2 5 6 7 9
0 2 5 6 7 0  // divide by 9 and replace it by % 9, do this for every element
0 2 5 6 0 0
0 2 5 0 0 0  -----> 0 0 0 0 0 0

example 2:
1 2 3 4
1 2 3 0
1 2 0 0
1 0 0 0 

1 cant be converted to 0, enhh bechara
But but, in this case, we can convert all the numbers to 1 na (is case me bhi not always thou)
Lets see:
1 3 5 7 10
1 3 5 7 1   // divide all by 9, then with 6 thne with 4, then with 2
1 1 1 1 1 

One more case in which this also fails:
WHEN WE HAVE 2 CONSECUTIVE ELEMENTS

1 3 4 5 7 10
1 3 4 5 7 1
1 3 4 5 1 1
1 1 0 1 1 1    // now divide it with 4
ab ye 0 bann gya to we cant convert 0 to 1 neither can we convert first wala 1 to 0

Final Conclusions:
1. if 1 is not present, then always YES;
2. if (1), then there should be nop consecutive elements, else, Never
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