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
const int N = 3e5+10;

// int n, k, l, p, q, m, d, x, y;
string s, t;
// vector<pll>v;
// int a[N], b[N], M[N];

void solve() {
    int n,q;
    cin>>n>>q;
 
    // vector<vector<int>> board(n+1,vector<int>(n,0));
    set<int> row,col;
    vector<int> rowa(n+1),cola(n+1);
 
    //storing rows and columns of the blank cells
    for(int i=1;i<=n;i++){
        row.insert(i);
        col.insert(i);
    }
 
    while(q--){
        int t;
        cin>>t;
 
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            // us block me fill krna hai, i.e. fill the vrow and vcol and erase from set

            rowa[x]++;
            cola[y]++;

            row.erase(x);
            col.erase(y);

        } 
        if(t == 2) {
            // delete values, i.e. remove it from vectors and add in set
            int x, y;
            cin >> x >> y;

            rowa[x]--;
            cola[y]--;

            if(rowa[x] == 0) {
                row.insert(x);
            }
            if(cola[y] == 0) {
                col.insert(y);
            }
        }

        if(t ==3) {
            int x1, x2, y1, y2;
            cin>>x1>>y1>>x2>>y2;
            int lb1 = n+1, lb2 = n+2;
            //finding lower bound of the x1, y1,
            // if x1 to x2 not present in the set return the bigger value greater then x2

            if(row.lower_bound(x1) != row.end()) {
                lb1 = *row.lower_bound(x1);    // **
            }
            if(col.lower_bound(y1) != col.end()) {
                lb2 = *col.lower_bound(y1);
            }

            if(lb1 > x2 || lb2 > y2) {
                cout <<"Yes"; line;
            } else {
                cout <<"No"; line;
            }
        }
    }
}

/*
**The set::lower_bound() is a built-in function in C++ STL which returns an 
iterator pointing to the element in the container which is equivalent to k passed in the parameter.
auto it = s.lower_bound(2);
if (it != s.end()) {
    cout << "\nThe lower bound of key 2 is ";
    cout << (*it) << endl;
}
*/

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     // clear_global();
    // }
    solve();
    return 0;
}
