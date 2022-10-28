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

// const int N = 1e5 + 2;
string s;
int dp[26][26];

void input() {
    cin>>s;
}

void solve() {
    input();

}

int main() {
    // int t;
    // cin >> t;
    // while(t--) {
    solve();
    // }
    return 0;
}


/*
Doubt in code (pta nhi kyai likha hai editorial me)
(only for easy to understand) dp[x][y] => this means, how many strings forms of length 2 
when combining characters "xy" by only using that much part => [0.....i].
Ex: aabbaabccbb, suppose I'm at index(i)= 7, so I can use only [0...7], dp['a']['b'] => 8,
so there will be 8-string of "ab" in [0...7] section.
So, we have to represent the characters in terms of integers. that's why we have done => str[i]-'a'.
*/