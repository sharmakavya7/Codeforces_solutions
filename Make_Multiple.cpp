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
ll __gcd(ll a,ll b) {
	if(a!=0)return __gcd(b%a,a);
	return b;
}

const int N = 3e5 + 2;
ll a, b;
// int a[N];

void input() {
    cin >> a >> b;
}

void solve() {
    input();
    if(b % a == 0) {
        // cout << a <<" " << b<<" ";
        cout <<"YES"; line;
        return;
    }  
    if(b%a==0)  {
        cout << "YES";line;
        return;
    } 
    else { 
        if (b>2*a) { 
            cout <<"YES"; line;
        }
        else {
            cout <<"NO"; line;
        }
    } 
    // if(a + 1 == b && a > 1) {
    //     cout << a << " " << b<<" ";
    //     cout <<"NO"; line;
    //     return;
    // }
    // while(b % a != 0) {
    //     b++; a++;
    // }
    // cout << a <<" " << b<<" "; line
}

// 10 -> YES
// 11 -> YES
// 12 -> YES

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}