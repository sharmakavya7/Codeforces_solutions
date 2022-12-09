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

/// hardddd

void solve() {
    int n, m, z, y;
    cin >> n >> m;
    //int tot = 0;
    for(int i=0; i<m; i++){
        cin >> a[i];
    }
    vector<int> v;
    sort(a, a + m);
    for(int i=0; i<m; i++) {
        if(i < m-1)
            z = abs(a[i+1] - a[i]);
        else {
            z = n - a[m-1] + a[0];
        }
        v.push_back(z-1);
    }
    sort(v.begin(), v.end(), greater<int>());
    int cnt = 0, i=1, j=0;
    for( ; i<=2*m && j<=m; i++) {
        if(v[j] <= 2*i-2) {
            break;
        }
        if(i % 2) {
            cnt++; 
        } else {
            //cout<<" v[j]: "<<v[j]<<"  ";
            cnt += v[j] - 2*i+2;
            j++;
        }
    }

    cout<< n - cnt ; line;
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

