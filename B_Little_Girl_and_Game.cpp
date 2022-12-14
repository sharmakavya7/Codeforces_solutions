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
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5+10;

int n, k, l, p, q, m, d, x;
string s, t;
// vector<ll>v, v1, v2;
int v[N], v1[N], v2[N], a[N], b[N];

bool isSorted(int a[], int n) {
    
    if (n == 0 || n == 1)
        return true;
 
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
 
    return true;
}

void solve() {
    cin >> s;
    unordered_map<char, int>mp;
    for(int i=0; i<s.size(); i++) {
        mp[s[i]]++;
    }

    // 2 cases: all char freq = even, all char freq odd,
    // odd freq wala sirf 1 hona chaaiye, even freq can be inf
    int cnt = 0;
    for(auto i:mp) {
        if(i.second % 2 != 0) {
            cnt++;
        }
    }
    if(cnt == 0) {
        cout <<"First";
        return;
    }
    if(cnt % 2 != 0) {
        cout << "First"; 
        return;
    } else {
        cout << "Second";
        return;
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
    solve();
    return 0;
}
