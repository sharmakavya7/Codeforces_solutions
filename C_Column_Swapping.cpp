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

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const int N = 2e5+10;

// int n, k, l, p, q, m, d, x, y;
// string s, b;
// vector<pll>v;
// ll a[N][N];


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>>a(n, vector<ll>(m));
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
;        }
    }
    // check all rows x = 0 to n
    int x = 0; 
    while(x<n && is_sorted(a[x].begin(), a[x].end())) {
        x++;
    }
    if(x == n) {
        cout <<"1 1"; line;
        return;
    }

    // 1st unsorted row
    auto b = a[x];

    sort(b.begin(), b.end());

    // now save all those indexes which were not in their correct places
    vector<int>p;
    for(int i=0; i<m; i++) {
        if(a[x][i] != b[i]) {
            p.push_back(i);
        }
    }
    
    if(p.size() > 2) {
        cout <<"-1"; line;
        return;
    }

    // now check if those i, j values, which have saved in our vector, holds true for every other
    // following rows or not

    for(int i = 0; i<n; i++) {
        swap(a[i][p[0]], a[i][p[1]]);
        if(!is_sorted(a[i].begin(), a[i].end())) {
            cout << "-1"; line;
            return;
        }
    }
    cout << p[0]+1 <<" "<< p[1]+1; line;
}

/*
2 cases:
- either -1 : if at any row, we find index > 2 which are not in their correct position after
sorting, then we'll return -1
- or any index:
    again 2 cases:
    - store both index that needs to be changed to get the array sorted, do this for every row and
    last me compare if all the values of i and j are same
    - if they are different, then return -1
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