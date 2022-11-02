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
# define mp make_pair
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}

const int N = 1e5 + 2;

ll n, m, k;
string s;
vector<int>a;
int cnt = 0, sum = 0;
int matrix[5][5];

void solve() {
    int resi = 0, resj = 0;
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=5; j++) {
            cin >> matrix[i][j];
            int t = matrix[i][j];
            if(t == 1) {
                resi = i;
                resj = j;
            }
        }
    }
    int difi = abs(resi-3);
    int difj = abs(resj - 3);
    cout << difi + difj; line;
}


int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    // }
    solve();
    return 0;
}
