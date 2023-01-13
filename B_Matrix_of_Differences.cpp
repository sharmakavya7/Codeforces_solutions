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
// pii b[N];
// vector<ll> a[N];
// ll vis[N];

int mat[N][N] = {0};

void rev(int i,  int n) {
    int p = 0, q = n-1;

    while(p < q) {
        int temp = mat[i][p];
        mat[i][p] = mat[i][q];
        mat[i][q] = temp;
        p++, q--;
    }
}

void solve () {
    int n;
    cin >> n;
    int dum = n*n;
    int num = 1;
    // int mat[n][n] = {0};
    bool flag = 0;
    for(int i=0; i<n*n; i++) {
        if(i % 2 == 0) {
            mat[i/n][i%n] = num;
            num++;
        }
        else {
            mat[i/n][i%n] = dum;
            dum--;
        }
    }
    if(n % 2 == 0) {
        for(int i=1; i<n; i+=2) {
            rev( i, n);
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<mat[i][j] <<" ";
        }
        line;
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
/*
for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(flag = 0) {
                mat[i][j] = num;
                num++;
                flag = 1;
            } 
            else if(flag == 1){
                mat[i][j] = dum;
                dum--;
                flag = 0;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<mat[i][j] <<" ";
        }
        line;
    }
*/