

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
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5 + 10; 
// int a[N][N];

void solve () {
    int w, d, h, a, b , f, g;
    cin >> w >> d >> h >> a >> b>> f >> g;
    int total = 0;
    int distfromy = f + a;
    int distfromx = g + b;

    // if(distfromx > distfromy) {
        // total += f + a;
        int mini = 1e9;
        mini = min(mini, (abs(b - g) + f + a));
        mini = min(mini, (abs(b - g) + abs(w-f) + abs(w-a)));
        // total += mini;
        // total += h;
    // }
    // else {
        // total += g + b;
        // int mini = 1e9;
        mini = min(mini, (abs(a - f) + b + g));
        mini = min(mini, (abs(a - f) + abs(d-b) + abs(d-g)));
        // total += abs(a - f);
        total += h;
        total += mini;
    // }
    cout << total; line
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
int total = 0;

    total += (g + b);

    total += abs(a - f);

    total += h;

    cout << total; line;
*/
