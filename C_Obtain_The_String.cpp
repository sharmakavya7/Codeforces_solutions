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

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}

const int N = 2e5 + 2;

ll n, k, l, p, q, m, d;
string s, t, z = "";
// vector<int>v, v1, v2;
int v[N], v1[10000], v2[10000];
ll cnt = 0, sum = 0, res = 1;
int matrix[5][5];
vector<int>ans;

void input() {
    cin >> s >> t;
}

void solve() {
    int pos = -1;
    cnt = 0;
    for(int i=0; i<s.size(); i++) {
        
    }
}

vector<int> removeDups(vector<int> arr, int n)
{
    unordered_map<int, bool> mp;
    // vector<int>ans;
 
    for (int i = 0; i < n; ++i) {
 
        // Print the element if it is not
        // there in the hash map
        if (mp.find(arr[i]) == mp.end()) {
            ans.push_back(arr[i]);
        }
 
        // Insert the element in the hash map
        mp[arr[i]] = true;
    }
    return ans;
}

void clear_global() {
    sum = 0;
}

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     clear_global();
    // }
    // solve();
    vector<int>v = {1,1,3,2,1,4,5,4};
    removeDups(v, 8);
    for(int i:ans) {
        cout << i <<" ";
    }
    return 0;
}

/* GREEDY way:
    - replacing subarray of odd lengths wont benefit the max sum
    - try reversing the even len subarrays
    - store the initial sum in a variable sum
    - then one by one try reversing the subarrays and store the max sum in maxi
    - hume max milega kab? jab odd positions wale elements ka sum bada ho jaega even walo se
    - isliye apan reverse kr rhe hai in the first place
    - maxi me ky aaega? For eg. 7 8 4 5 7 6 8 9 7 3
    - when we reverse [7, 8], it basically means that we are removing 7 from our existing sum and 
    - adding 8 in it, and if comes greater than maxi, then update maxi with it
*/