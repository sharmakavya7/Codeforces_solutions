#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
# define ll long long
# define pii pair<int,int>
# define pip pair<int, pii>

int n;
const int N = 1e5+2;
int a[N], b[N], c[N];
// int sum = 0, ans = 0;

void input() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> c[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> b[i];
    }
}

void solve() {
    int sum = 0, ans = 0;
    for(int i=2; i<=n; i++) {
        int x = a[i];
        int y = b[i];
        int diff = abs(x-y);
        if(x == y || i==2) {
            sum = c[i] + diff + 1;
        }
        else {
            sum = max( sum - diff + 1 + c[i], diff + 1 + c[i]);
        }
        ans = max( ans, sum);
    }
    cout << ans <<endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        input();
        solve();
        // clear_global_variables();
    }
    return 0;
}