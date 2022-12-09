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

void solve() {
    ll n, c, q;
    cin >> n >> c >> q;
    cin >> s;
    vector<pair<ll,ll>> ans(c);
    vector<ll>log = {n};
    for(int i=0; i<c; i++) {
        cin >> ans[i].first >> ans[i].second;
        ans[i].first--;
        log.push_back(log.back() + ans[i].second - ans[i].first);
    }
    while(q--) {
        ll k;
        cin >> k;
        k--;
        for(int i = (int)ans.size()-1; i>=0; i--) {
            if(k >= log[i]) {
                k = ans[i].first + k - log[i];
            }
        }
        cout << s[k] ; line;
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

/*
kth char ka index uske pehle wali substr tak kya hai, and uske pehle se pehle wali mekya hai etcetc
to hume kya find krna hai? 
i+1th and (i-1)th string me kya reln bnta hai
                    n'            n'+r-l+1
---------|------|----||------|----|
         l      k    r/l     k    r
         
jo dist k ki l se hai, in the first part, wahi same dist k ki hogi from l in the sec part
to agr hume l to k dist pta chal gyi then l + this_dist - 1
eg if -  -  -  -  -  -  -  
      10 11 12 13 14 15 16
      n' l         k     r
    10 se k konsa char hai? 4th, l se start krke konsi position pe k aata hai
    14 - 10 = 4
  => k - n' = new k
  iske peeche wali string me k kya hoga?
  k = l + k - 1; (vid me dekh lo itna type krne ka mann ni hai)
*/