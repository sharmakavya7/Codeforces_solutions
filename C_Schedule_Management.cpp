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

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const int N = 2e5+10;

// int n, k, l, p, q, m, d, x, y;
// string s, b;
// vector<pll>v;


void solve() {
    ll m, n;
    cin >> n >> m;
    vector<int>a(n);
    for(int i=0; i<m; i++) {
        ll p;
        cin >> p;
        p--;
        a[p]++;
    }
    int l = 0, r = m;
    // search space kiska hai? Time ka, i.e. 1 to 2m time tak ke saare tasks complete hore ya nhi
    // if yes then reduce the search space accordingly
    while(l < r) {
        ll mid = (l + r)/2;
        ll time = 0, work = 0;

        // mid time pe saare tasks honge ya nhi, check
        for(int i=0; i<n; i++) {
            if(a[i] <= mid) {
                // free time = time; ye time kaha use hoga? ye time worker dusre tasks krne me
                // spend karega, i.e. 2 hours lega bcz uski expertise nhi hai (hence, /2)
                // mid -> total time, a[i]->cur task time,
                time += (mid - a[i]) / 2;
            } else {
                // work -> agr vo saare tasks khud nhi kr skta to kisi aur ko krne honge
                // work me wahgi store hora ki hume kitna extra time chaiyr
                // vo bnda nhi kr paa rha hai ye task, but jab koi aur krega to kitna time chaiye
                work += a[i] - mid;
            }
        }
        if(time >= work) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l ;
    line;
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