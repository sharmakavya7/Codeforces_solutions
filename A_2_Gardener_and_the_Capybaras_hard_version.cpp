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
    string s;
    cin >> s;
    int n = s.size();
    if(s[0]==s[n-1]){
        string st = s.substr(1,n-2);
        cout<< s[0] <<" "<< st <<" "<< s[n-1] ; line;
    }
    else {
        // a _______ b
        if(s[0] < s[n-1]) {
            string st = s.substr(0,n-2);
            cout<< st <<" " << s[n-2] <<" "<< s[n-1]; line;
        } 
        else {
            // b b _______ a, b b _______ b
            if(s[0] == 'b' && s[1] == 'b') {
                // print everything in middle as 'string b'
                string st = s.substr(1, n-2);
                cout<< s[0] <<" "<< st <<" "<< s[n-1]; line;
            }
            else {
                // b _______ a, a ________ a, 
                string st = s.substr(2, n-2);
                cout << s[0] <<" "<< s[1] <<" "<<st; line;
            }
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
/*
int flag = 0;
    if(s[0] == 'a' && s[n-1] == 'a') {
        cout << s[0] <<" ";
        for(int i=1; i<n-1; i++) {
            cout << s[i];
        }
        cout << " " << s[n-1];
        line;
        return;
    }
    if(s[0] == 'a' && s[n-1] == 'b') {
        int i;
        for(i=0; i<n-2; i++) {
            if(s[i] == 'a') {
                cout << s[i] ;
            }
            else break;
        }
        cout << " ";
        for( ; i<n-1; i++) {
            if(s[i] == 'b') {
                cout << s[i];
            }
            else {
                break;
            }
        }
        cout <<" ";
        for( ; i<n; i++) {

        }
        return;
    }
    if(s[0] == 'b' && s[n-1] == 'b') {
        flag = 3;
    }
    if(s[0] == 'b' && s[n-1] == 'a') {
        flag = 4;
    }
    
    cout << ":("; line;
*/