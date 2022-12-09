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
const int N = 3e5+10;

int n, k, l, p, q, m, d, x, y;
string s, t;
// vector<pll>v;
int a[N], b[N], Y[N];

void solve() {
    cin >> n >> k;
    map<int,int> mp;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> v1,v2;
    for(auto it:mp) {
        v1.push_back(it.first);
        v2.push_back(it.second);
    }
    int m = v1.size();
    int l = 0, r = 0, len = 0;
    for(int i = 0, j = 0; i<m && j<m; i++) {
        if(v2[i] < k) {
            continue;
        }
        j = i+1;
        // wimdow
        while(j < m && v1[j] - v1[j-1] == 1 && v2[j] >= k) {
            j++;
        }
        if(j-i > len) {
            len = j-i;
            l = v1[i];
            r = v1[j-1];
        }
        i = j-1;
    }
    if(len == 0) {
        cout<<-1; line;
    } else {
        cout << l << " " << r; line;
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

