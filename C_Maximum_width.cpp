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
void print(vector<int> vec){ for (int i{};i<vec.size();i++) cout<<vec[i]<<" "; cout<<endl;}

const int N = 2e5 + 2;
string s, t;
int pref[N], suf[N];
int n, m, maxWidth = 0;;

void input() {
    cin >> n >> m >> s >> t;
}

void solve() {
    input();
    for(int i=0, j=0; i<n, j<m; i++) {
        if(s[i] == t[j]) {
            pref[j] = i;
            j++;
        }
    }
    for(int i = n-1, j = m-1; i>=0, j>=0; i--) {
        if(s[i] == t[j]) {
            suf[j] = i;
            j--;
        }
    }
    for(int i=0; i<m-1; i++) {
        maxWidth = max(maxWidth, suf[i+1] - pref[i]);
    }
    cout << maxWidth; line;
}

int main() {
    fast;
    // int t;
    // cin >> t;
    // while(t--) {
    solve();
    // }
    return 0;
}

/*
1st approach: prefix & sufix array
Greedy. Find the p with the number as large as possible and p′ with number as small as possible.
The p match from right to left, so that can make pi largest. Similarly, p′
match from left to right, so that can make p′i smallest. Then the maximum width is:  
  max  (pi+1 - p'i)
1<=i<m
*/
