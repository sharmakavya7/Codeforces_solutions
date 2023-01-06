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
void printv(ll v[], int n) { for(int i=1; i<=n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5 + 2 ; 

void solve () {
    string s;
    int n;cin >> n;
    cin >> s;
    
    // int n = s.size();

    int cnt = 1;
    int cntL = 0, cntR = 0, pos = -1;
    bool flag = false, flag2 = false;

    for( int i= 1 ; i<n; i++) {
        if(s[i-1] == 'R' && s[i] == 'L') {
            // flag = true;
            cout <<"0"; line;
            return;
            // break;
        }
        if (s[i - 1] == 'L' && s[i] == 'R') {
            pos = i;
        }
    }
    cout << pos; line;
    // cout << i <<" ";
    
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
if(s[0] == 'L') {
        for( ; i<n; i++) {
            if(s[i] == 'L') {
                cout <<"i:" << i <<" ";
                continue;
            }
        }
        for( ; i<n; i++) {
            if(s[i] == 'R') {
                cntR++;
                idR = i ;
            }
            if(s[i] == 'L') {
                cntL++;
            }
        }
        if(cntL == 0 && cntR != 0) {
            cout << idR ; line;
            return;
        }
        else if(cntR == 0) {
            cout << -1; line;
            return;
        }
    }
    else if(s[0] == 'R') {
        for( i=0; i<n;i++) {
            if(s[i] == 'R') {
                continue;
            }
        }
        for( ; i<n; i++) {
            if(s[i] == 'L') {
                cntL++;
                idR = i ;
            }
            if(s[i] == 'L') {
                cntL++;
            }
        }
        if(cntR == 0 && cntL != 0) {
            cout << idR ; line;
            return;
        } else if(cntL == 0) {
            cout << -1; line; return;
        }
    }

    int cnt = 1;
    int cntL = 0, cntR = 0, idR, i=0;

    if(s[0] == 'R') {
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') {
                cntL++;
                cout << 0; line;
                return;
            }
        }
        cout << "-1"; line;
    } else {
        if(s[1] == 'R') {
            cout << "aa1"; line;
            return;
        }
        int i=1;
        for( i=1; i<n; i++) {
            if(s[i] == 'L') {
                continue;
            }
        }
        for( ; i<n; i++) {
            if(s[i] == 'R') {
                cntR++;
            }
            if(s[i] == 'L') {
                cntL++;
            }
        }
        if(cntL) {
            cout <<"0" ; line;
            return;
        } else {
            if(s[1] == 'R') {
                cout << "1"; line;
            } else {
                cout <<"-1"; line;
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(s[i] == 'R') {
            cntR++;
            while(s[i] != 'L' && i < n) {
                i++;
                if(s[i] == 'L') {
                    flag = true;
                    break;
                }
            }
        } else {
            cntL++;
            flag2 = true;
        }
        if(flag == true) {
            break;
        }
    }
    if(flag == true) { // R ke baad ek L mil gya
        cout << "0"; line;
        return;
    } 
    else if(cntL == 0 || cntR == 0) {
        cout << "-1"; line;
        return;
    }
*/