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

# define ll long long
priority_queue<vector<int>>pq;

void helper(int idx, int k, int t, vector<ll>&nums, vector<int>&subs, ll query) {
    if((k==0 || idx==nums.size()) && subs.size()==t) {
        pq.push(subs);
        while(pq.size() > query) {
            pq.pop();
        }
        // ans.push_back(subs);
        return;
    }
    for(int i=0; i<nums.size(); i++) {
        subs.push_back(nums[i]);
        k--;
        helper(i+1, k, t, nums, subs, query);
        k++;
        subs.pop_back();
    }
}



int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     // clear_global();
    // }
    // solve();

    int n = 3;

    vector<ll>arr = {3, 1, 2};
    ll k = 7;
    vector<int>subs;
    helper(0, 2, 2, arr, subs, k);
    cout << pq.top()[0] <<" "<< pq.top()[1];
    return 0;
}