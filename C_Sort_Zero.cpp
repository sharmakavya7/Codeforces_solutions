

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

const int N = 55 ; 

void solve () {
    int n;
    cin>>n;
    int i, last=0, ans=0;
    ll a[n];
    bool v[n+1];

    for(i=0; i<=n; i++){
        v[i]=false;
    }

    for(i=0; i<n; i++){
        cin>>a[i];
    }
    last=-1;
    for(i=n-2; i>=0; i--) {
        if(a[i]>a[i+1]){
            last = i;
            break;
        }
    }

    if(last == -1){
        cout<<"0"; line;
        return;
    }

    for(i=0; i<=last; i++){
        v[a[i]] = true;
    }

    for(i=last+1; i<n; i++) {
        if(v[a[i]] == true){
            last=  i;
        }
    }

    for(i = last; i>=0; i--){
        v[a[i]] = true;
    }

    for(i=1; i<=n; i++) {
        if(v[i]==true){
            ans++;
        }
    }
    cout<<ans; line;
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
