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

const int N = 1e5 + 2;
// string s, t;
// int pref[N], suf[N];
ll n, m;
// vector<pii>a;


bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

void solve() {
    cin >> n;
    ll fsum = 0;
    vector<ll>a(n), b(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] > b[i]) {
            swap(b[i], a[i]);
        }
        // cout << sma <<" ";
        fsum += a[i];
    }
    fsum += *max_element(b.begin(), b.end());
    fsum*=2;
    cout << fsum; line;
}


int main() {
    fast;
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/*
ll dif = abs(a[i]-prev);
        cout <<"a[i]:" <<a[i]<< " dif:"<<dif<<" ";
        sum += dif;
        cout <<"sum:" << sum <<" ";
        prev = a[i];
    }
    ll res = sum + b_ka_twice;
    cout << res; line;
*/