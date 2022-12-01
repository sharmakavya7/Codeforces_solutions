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
// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], int n) { for(int i=1; i<=n; i++) { cout << v[i] <<" "; } line;}

const int N = 3e5+10;

// ll n, k, l, p, q, m, d, x, y;
// string s, t;
// vector<pll>v;
// ll a[N], b[N];

void solve() {
    // int a, s;
    string s, t, ans;
    cin >> s >> t;
    // s is thenumber, t is the sum
    reverse(t.begin(), t.end());
    reverse(s.begin(), s.end());
    int i = 0, j = 0;
    // for(int i=0; i<s.size(); i++) {
        while(i < s.size() && j < t.size()) {

        if(s[i] > t[j]) {
            
            ans += (char)(10 + t[j] - s[i] + '0');
            if (t[j+1]!='1') {
                cout <<"-1"; 
                return;
            }
            j += 2;
        } else {
            // ans += (t[j]-'0' - s[i] - '0');
            ans += (char)(t[j] - s[i] + '0');
            j++;
        }
        i++;
    }
    // cout << ans <<" ";
    // important
    if(i < s.size()) {
        cout << -1; line;
        return;
    } while(j < t.size()) {
        ans += t[j++];
        // j++;
    }
    /// nice thing to notice
    while(ans.back() == '0' && ans.size() > 1) {   // #gadha_panti
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    cout << ans; line;
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
// int temp = ((s[i-1] - '0')*10) + s[i] - '0';  // gadhi
            // int temp = 10 + s[i] - '0';
            // int diff = temp - a[j] + '0';
            // ans += diff;
            // cout << temp <<" "<<diff<<" ";
*/