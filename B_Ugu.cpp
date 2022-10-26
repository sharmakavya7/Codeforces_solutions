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
 
# define C continue;
# define R return
 
# define D double
# define I insert
# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define pb push_back
# define pf push_front
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvs vector < vs >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >
 
# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair
# define line cout<<"\n";
#define fast ios_base::sync_with_stdio(false); cin.tie(0);

string s;
int n;

void solve() {
    cin >> n >> s;
    int firstOne = -1;
    for(int i=0; i<=n; i++) {
        cout << s[i] ;
    }
    int ans = 0;
    bool flag = 0;
    // while(i <= n) {
    for(int i=0; i<n; i++) {
        
        if(flag == 0) {
            cout <<"i:"<<i<<" s[i]:" << s[i]<<" ";
            if(s[i] == '1' && firstOne == -1) {
                firstOne = i;
                // cout << "yo ";
                cout << "first:"<<firstOne<<" ";
            }
            else if(s[i] == '0' && firstOne < i && firstOne != -1) {
                // cout << s[i] << " ";
                // cout<<" no ";
                i = firstOne;
                // cout <<"i: "<<i << " yha: "<<firstOne <<" ";
                firstOne = -1;
                
                flag = 1;
                ans++;
            }
        }
        if(flag == 1) {
            cout <<"ni:"<<i<<" ns[i]:" << !s[i]<<" ";
            if(!s[i] == '1' && firstOne == -1) {
                firstOne = i;
            }
            else if(!s[i] == '0' && firstOne < i && firstOne != -1) {
                i = firstOne;
                firstOne = -1;
                flag = 0;
                ans++;
            }
        }
        line
        // i++;
    }
    cout << ans; 
    line
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
