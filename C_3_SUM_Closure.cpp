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

// Make all elements of an Array equal by adding and subtracting 1 in single operation
void solve() {
    int n, ans=0;
	cin >> n;
	vector<ll> a;
	int pos=0, neg=0, z=0;
	map<ll,ll> mp;
	for(int i=0; i<n; i++) {
        ll p;
        cin >> p;
        if(p > 0) {
            pos++;
        }
        else if(p < 0) {
            neg++;
        }
        else z++;

        if(!(p==0 && z>2)) a.push_back(p);
        mp[p]++;
    }

    if(pos > 2 || neg > 2) {
        cout<<"NO"; line;
        return;
    }

    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            for(int k=j+1; k<a.size(); k++){
                if(!mp[a[i] + a[j] + a[k]]){
                    cout<<"NO"; line;
                    return;
                }
            }
        }
    }
    cout<<"YES"; line;
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