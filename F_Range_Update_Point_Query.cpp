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

const int N = 101; 
// int a[N][N];

int f(int x){
    if(x<10)
        return x;
    else 
        return x%10+f(x/10);
}

void solve () {
    int n,q;
    cin >> n >> q;
    vector<int>arr(n+1);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    set<int>s;
    for(int i = 1; i<=n; i++){
        s.insert(i);
    }
    while(q--){
        int cc;
        cin >> cc;
        if(cc == 1){
            int l,r;
            cin >> l >> r;
            while(true){
                auto it = s.lower_bound(l);
                if(it==s.end())
                    break;
                if((*it)>r)
                    break;
                arr[*it] = f(arr[*it]);
                l = (*it)+1;
                if(arr[*it]<10)
                    s.erase(it);
            }
        }
        else{
            int x;
            cin >> x;
            cout << arr[x]; line
        }
    }
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
