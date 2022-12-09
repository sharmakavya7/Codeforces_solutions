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

// int n, k, l, p, q, m, d, x, y;
string s, t;
// vector<pll>v;
// int a[N], b[N], M[N];
// vector<pair<int,int>> ans;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    string s, t;
    cin >> s >> t;
    ll corr = 0;
    vector<ll>temp;
    for(int i=0; i<n; i++) {
        if(s[i] != t[i]) {
            corr++;
            temp.push_back(i);
        }
    }
    if(corr % 2 != 0) {
        cout << "-1"; line;
        return;
    }
    // x wale
    ll ans1 = 0;
    for(int i=0; i<s.size()-1; i++) {
        if(s[i] != t[i]) {
            ans1 += x;
            // cout <<"ans1:"<<ans1<<" ";
            s[i] = 1-s[i];
            s[i+1] = 1-s[i+1];
        }
    }
    ll ans2 = 0;
    if(corr != 2) {
        ans2 = y*(corr/2);
    } else {
        // tricky
        if(temp[1] - temp[0] == 1) {
            if(n>2) 
                x = min(x,2*y);
            ans2 =x;
        }
        else
            ans2 = y;
    }
    // cout <<"ans2:"<<ans2<<" ";
    cout << min(ans1, ans2); line;
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

/*
Odd corrections: -1
Rest: 2 pointer types, keep on adding x in ans1 and change adj digits by 1-a[i], 1-b[i]
At the end, find the ans of y too, ans2 = y*number_of_corrections/2
Return min (ans1, ans2)
*/