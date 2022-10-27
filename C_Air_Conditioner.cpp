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
const int mod= (int)1e9+7;
ll __gcd(ll a,ll b) {
	if(a!=0)return __gcd(b%a,a);
	return b;
}
void printvec(vector<int> vec){ for (int i{};i<vec.size();i++) cout<<vec[i]<<" "; cout<<endl;}

ll n, m, t, l, h;

void input() {
    cin >> n >> m;
}

void solve() {
    input();
    ll prev_time = 0, mini_temp = m, maxi_temp = m, flag = 1;;
    // ll time_dif = m; int temp_dif = m;
    for(int i=0; i<n; i++) {
        cin >> t >> l >> h;
        // time_dif = t - prev_time;
        // temp_dif = abs(m - l);
        // if(time_dif < temp_dif) {
        //     cout <<"NO"; line;
        //     return;
        // }
        mini_temp -= (t - prev_time);
        maxi_temp += (t - prev_time);
        prev_time = t;

        maxi_temp = min(h, maxi_temp);
        mini_temp = max(l, mini_temp);

        if(maxi_temp < mini_temp) {
            flag = 0;
        }
    }
    if(flag) {
        cout<<"YES"; line;
    }
    else {
        cout << "NO"; line;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

// Common sense