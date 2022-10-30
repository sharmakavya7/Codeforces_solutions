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

const int N = 1e5 + 2;
// string s, t;
// int pref[N], suf[N];
int n, m;
vector<int>v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool isnotPrime(int k) {
    if (k <= 1)
        return true;
 
    // Check from 2 to n-1
    for (int i = 2; i < k; i++)
        if (k % i == 0)
            return true;
 
    return false;
}
void solve() {
    cin >> n;
    // int i = 0;
    // for(i=0; i<v.size(); i++) {
    //     // cout << "n:"<<n <<" v:"<< v[i]<<" ";
        
    //     if(isnotPrime(n + v[i])) {
    //         cout << v[i]; line;
    //         break;
    //     }
    // }
    cout << n; line;
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


// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97