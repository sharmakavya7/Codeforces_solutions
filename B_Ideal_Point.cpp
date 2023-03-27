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
const ll N = 2e5 + 2 ;  

bool check(string a, string b ) {
        int n = a.size();
        for(int i=0; i<n; i++){
            if(a[i] <= b[i]) 
                continue;
            else 
                return false;
        }
        return true;
    }
int minDeletionSize(vector<string>& s) {
    vector<string> v;
    int n = s.size();
    int m = s[0].size();
    for(int i=0; i<m; i++){
        string str;
        for(int j=0; j<n; j++) {
            str += s[j][i];
        }
        v.push_back(str);
    }
    vector<int> dp(m+1, 1);
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<i;j++){
            if(check(v[j], v[i]) && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
    }
    return m-(*max_element(dp.begin(), dp.end()));
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int ops = minDeletionSize(A);
    cout << ops << endl;
    return 0;
}


// int main() {
//     fast;
//     // ll t;
//     // cin >> t;
//     // while(t--) {
//     //     solve();
//     //     // clear_global();
//     // }
//     solve();
//     return 0;
// }