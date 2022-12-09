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
int a[N], b[N], M[N];
vector<pair<int,int>> ans;

void bubbleSort(int a[], int b[], int n) {
    int i, j;
    for (i = 0; i < n ; i++) {
        for (j = 0; j < n ; j++) {
            if (a[j] > a[j + 1] || b[j] > b[j + 1]) {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                ans.push_back(make_pair(j, j+1));
                // cout << j << " " << j + 1; line;
            }
        }
    }
}

void solve() {
    cin >> n;
    ans.clear();
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> b[i];
    }
    bubbleSort(a, b, n);
    bool flag = 0;
    for(int i=1; i<n; i++) {
        if(b[i] > b[i+1] || a[i] > a[i+1]) {
            // cout <<"-1"; line;
            flag = 1;
        }
    }
    if(flag == 1) {
        cout << "-1"; line;
        // return;
    } else {
        cout << ans.size(); line;
        for(auto i : ans) {
            cout << i.first <<" "<<i.second; line;
        }
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




