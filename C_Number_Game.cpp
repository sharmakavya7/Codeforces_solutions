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
const int N = 2e5+10;

// int n, k, l, p, q, m, d, x, y;
// string s, b;
// vector<pll>v;


void solve() {
    int n, i, j, k, ans, f, high, low;;
    cin>>n;
        
    ll a[n], c[n+1];

    for(i=0; i<=n; i++){
        c[i]=0;
    }

    for(i=0; i<n; i++){
        cin>>a[i];
        c[a[i]]++;
    }

    sort(a, a+n);
    ans=0;

    for(k=1; 2*k-2<n; k++) {
    //cout<<k; line
        for(i=2*k-2, j=k; i>=k-1; i--, j--)  {
            //cout<<a[i]<<" "<<j; line
            if(a[i] > j){
                break;
            }
        }

        if(j == 0) {
            ans = k;
        } else {
            break;
        }

    }

    cout<<ans; line
}

/*
// Make all elements of an Array equal by adding and subtracting 1 in single operation
    ll n, a[N];
    cin >> n;
    if(n == 1) {
        cout << "Yes"; line;
        return;
    }
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    ll sum = accumulate(a, a+n, 0LL);
    if(sum % n == 0) {
        cout <<"Yes"; line;
    } else {
        cout <<"No"; line;
    }
    // cout << sum; line;
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


