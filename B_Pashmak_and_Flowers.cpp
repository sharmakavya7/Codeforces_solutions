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

const int N = 2e5+10;

ll n, k, l, p, q, m, d, a, b;
string s, t;
// vector<int> v1, v2;
int v[N], v1[N], v2[N];
 
void solve() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    ll mini = *min_element(v, v+n);
    ll maxi = *max_element(v, v+n);

    cout << maxi - mini << " ";

    ll max_cnt = 0, min_cnt = 0;
    for(int i=0; i<n; i++) {
        if(v[i] == mini) {
            min_cnt++;
        }
        else if(v[i] == maxi) {
            max_cnt++;
        }
    }
    if(maxi - mini == 0) {
        cout << (n * (n-1)) / 2; line;
    } else {
        cout << max_cnt*min_cnt; line;
    }
}

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     clear_global();
    // }
    solve();
    return 0;
}

/*
If all numbers are equal then answer will be n * (n - 1) / 2,
otherwise the answer will be cnt1 * cnt2, 
where cnt1 is the number of our maximum elements and 
cnt2 is the number of our minimum elements.
*/