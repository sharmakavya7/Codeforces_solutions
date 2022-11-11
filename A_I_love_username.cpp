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
# define mp make_pair
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}

const int N = 1e5 + 2;

ll n, k, l, p, q, m, d;
string s, t;
// vector<int>v1, v2;
int v1[10000], v2[10000];
int cnt = 0, sum = 0;
int matrix[5][5];

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> v1[i];
    }
    int maxi = INT_MIN, mini = INT_MAX;
    for(int i=0; i<n; i++) {
        if(maxi < v1[i]) {
            cnt++;
            maxi = v1[i];
        }
        if(mini > v1[i]) {
            cnt++;
            mini = v1[i];
        }
    }
    cout << cnt - 2; line;
}

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    // }
    solve();
    return 0;
}