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
// int pref[N], suf[N];
// int n, m, maxWidth = 0;;

void input() {
    cin >> s >> t;
}

void solve() {
    input();
    if(s.size() < t.size()) {
        cout <<"NO"; line;
        return;
    }
    bool flag = 0;
    int cnt = 0;
    int i = s.size()-1, j=t.size()-1;
    
    for(;i>=0 && j>=0;) {
        if(s[i] == t[j]) {
            i--;j--;
        }
        else {
            i-=2;
        }
    }

    if(j >= 0) {
        // cout << "left: " << s.size() - i << " ";
        cout <<"NO"; line;
    }
    else {
        cout << "YES"; line;
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

/*
ULTA KRNA THA!!
for(i=0, j=0; i<=s.size(), j<t.size(); i++) {
        // cout << "s:"<<s[i]<<" t:"<<t[j]<<" ";
        if(s[i] == t[j]) {
            if(flag == 0) {
                if(s[i] != s[i+1]) {
                    j++;
                    flag = 1;
                    continue;
                }
            }
            else {
                // cout<<"cnt:"<<cnt<<" ";
                if(cnt%2 == 0) {
                    // cout << "s:"<<s[i]<<" t:"<<t[j]<<" ";
                    cnt = 0;
                    j++;
                }
                else {
                    // cout << "s:"<<s[i]<<" t:"<<t[j]<<" ";
                    cout << "NO"; line;
                    return;
                }
            }
        } else if(flag!=0 && s[i] != t[j]){
            cnt++;
        }
    }
*/
