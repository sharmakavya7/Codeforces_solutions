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
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}

const int N = 2e5 + 2;
// string s, t;
// int pref[N], suf[N];
ll n, m;
vector<ll>a;
// priority_queue<int>pq1, pq2, pq3;


void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        // cin >> a[i];
        int p;
        cin >> p;
        a.push_back(p);
    }
}

// WRONG

void solve() {
    input();
    sort(a.begin(), a.end());

    int l = a[0];
    int m = a[1];
    int k = a[n-1];
    int ans = abs(l - m) + abs(l - k);
    cout << ans; line;
}


void global() {
    a.clear();
}

int main() {
    fast;
    ll t;
    cin >> t;
    while(t--) {
        solve();
        global();
    }
    return 0;
}


// it is a greedy approach, so think wisely
// i mean you've thoought of a soln that would work for some cases
// think of a TC that would break our logic, ex: 1, 2, 3, 9, 10 (ans: 14, but mine WA: 10)
// what to do?
// We can find a the partitions that could give me greater value, i.e. we could check for 
// all the ways in which i can get max value, i.e. kon kaha se pick krne me zyda value de rha,
// vo search karo
// mathematically, (a1-a2) + (a2-a3) > 