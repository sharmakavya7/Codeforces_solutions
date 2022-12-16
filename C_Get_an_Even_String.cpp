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
#include <regex>
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

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], ll n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const int N = 2e5+10;


void solve() {
    // string s;
    // cin >> s;
    // memo
    // vector<ll>dp(s.size()+1, -1);
    // cout << calc(s, 0, dp) << endl;

    // Greedy way ezz pzzz
    string a;
	cin >> a;
    set<char> st;
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        if(st.find(a[i]) != st.end()) {
            // cout << st.size() <<" ";
            ans += st.size()-1;
            st.clear();
            continue;
        }
        st.insert(a[i]);
    }
    ans += st.size();
    cout << ans << endl;
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


// DP Solution

// ll calc(string &s,ll ind,vector<ll> &dp){
//     if(ind>=s.size()){
//         return 0;
//     }
//     if(ind == s.size()-1){
//         return 1;
//     }
//     if(dp[ind]!=-1){
//         return dp[ind];
//     }

//     if(ind < s.size()-1 && s[ind] == s[ind+1]){
//         return dp[ind] = calc(s, ind+2, dp);
//     }
//     else{
//         ll temp;
//         for(temp = ind+1; temp<s.size(); ){
//             if(s[ind] == s[temp]){
//                 break;
//             }
//             temp++;
//         }
//         if(temp == s.size()) {
//             return dp[ind] = 1+calc(s, ind+1, dp);
//         }
//         else {
//             ll v1 = temp - ind - 1 + calc(s, temp+1, dp);
//             ll v2 = 1 + calc(s, ind+1, dp);
//             return dp[ind] = min(v1,v2);
//         }
//     }
// }

