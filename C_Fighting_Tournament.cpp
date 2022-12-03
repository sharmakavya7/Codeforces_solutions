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
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)

const int mod = (int)1e9+7;
// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<ll> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 3e5+10;

ll n, k, l, p, q, m, d, x, y;
// string s, t;
// vector<ll>v;
int v[N], b[N];

// pyaarraaaaaa sawal
// OBV: ek aadmi tab tak jeetega jab tsk usse koi bada aadmi nhi aa jata uske samne
// i.e. next greater (stack)

int f(vector<vector<int>> &v, int i, int x) {
    return lower_bound(all(v[i]), x) - v[i].begin();
}


void solve() {
    cin >> n >> q;
    deque<int>d;
    // vector<int>v(n);
    // for(int &i : v) {
    //     cin >> i;
 
    //     d.push_back(i);
    // }
    for(int i=0; i<n; i++) {
        cin >> v[i] ;
    }
    for(int i=0; i<n; i++) {
        d.push_back(v[i]);
    }
    vector<vector<int>>wins(n+1);
    // till how many operations the max number comes at first 
    int rounds = 0;

    while(d.front() != n) {
        int top1 =  d.front();
        d.pop_front();
        int top2 = d.front();
        d.pop_front();

        rounds++;
        // cout << rounds <<" ";
        if(top1 > top2) {
            wins[top1].push_back(rounds);
            d.push_front(top1);
            d.push_back(top2);
            // cout <<"top:"<< top1 <<" rounds:" << rounds << " ";
        } else {
            wins[top2].push_back(rounds);
            d.push_front(top2);
            d.push_back(top1);
        }
    }
    while(q--) {
        int i, k;
        cin >> i >> k;
 
        --i;
 
        int lo = 0, hi = wins[v[i]].size() - 1, w = 0;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
 
            if(wins[v[i]][mid] <= k) {
                w = mid + 1; 
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }

        // int w = lower_bound(wins[i].begin(), wins[i].end(), i) - wins[i].begin();
 
        if(k <= rounds)
            cout << w << '\n';
        else {
            int ex = k - rounds;
            cout << w + (v[i] == n ? ex : 0) << '\n';
        }
    }
    // while(q--) {
    //     int x, k;
    //     cin >> x >> k;
    //     x--;
    //     if (v[x] != n) {
    //     cout << f(wins, x, k) << endl;
    //     } else {
    //     int ret = f(wins, x, k);
    //     if (k >= rounds)
    //         ret += k - rounds;
    //     cout << ret << endl;
    //     }
    // }
    // while(q--) {
    //     int i, t;
    //     cin >> i >> k;
    //     i--;
    //     // max element ke liye (cz its a permutation seq) 
    //     if(v[i] != n) {
    //         // cout << f(wins, i, k); line;
    //         cout << lower_bound(wins[i].begin(), wins[i].end(), i) - wins[i].begin();
    //         return;
    //     } else {
    //         int idx = lower_bound(wins[i].begin(), wins[i].end(), i) - wins[i].begin();
    //         if(k >= rounds)
    //             idx += k - rounds;
    //         cout << idx; line;
    //     }
    // }
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
while(q--) {
        int i, k;
        cin >> i >> k;
 
        --i;
 
        int lo = 0, hi = wins[v[i]].size() - 1, w = 0;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
 
            if(wins[v[i]][mid] <= k)
                w = mid + 1, lo = mid + 1;
            else
                hi = mid - 1;
        }
 
        if(k <= rounds)
            cout << w << '\n';
        else {
            int ex = k - rounds;
            cout << w + (v[i] == n ? ex : 0) << '\n';
        }
    }
*/