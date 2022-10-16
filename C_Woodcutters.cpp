#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

const int N = 1e5 + 5;
int n, ans=1;
vector<pii> trees(N);
ll xi[N], height[N];

int main() {
    fast;
    cin >> n;
    for(int i=0; i<n; i++) {
        int u, v;
        cin >> xi[i] >> height[i];
    }
    xi[n] = INT_MAX;
    for(auto i=1; i<n; i++) {

        // left
        int leftDis = (xi[i] - xi[i-1]);
        // right
        int rightDis = (xi[i+1]- xi[i]);

        if(leftDis > height[i]) {
            // cout <<"left: " << xi[i]<<" ";
            ans++;
        }
        else if(rightDis > height[i]) {
            // cout << "rightDis: " << rightDis<<" h[i]:" << height[i] <<" ";
            // cout << "right: " << xi[i]<<" ";
            xi[i] += height[i];
            ans++;
            // cout << xi[i]<<" ";
        }
    }
    cout << ans << endl;
    return 0;
}

// SIMPLE GREEDY APPROACH (EASAY TO MEDIUM)
// 1st tree will always fall to its left
// 2nd on, we'll check if if it falls to left or right
// left me falling is easy, we dont have to deal with any edge case cz it doesn't make
// our answer less optimal, mtlb vo left me girega to koi aur tree ka fall harm nhi hoga, SIMPLe!!
// For right, if a tree falls to its right, we have to update the last left cooridate accordingly


// idk why making a 2D vector didn't work lol
/*
for(auto i=1; i<n; i++) {
        int xi = trees[i].first;
        int height = trees[i].second;
        // left
        int leftDis = (xi - trees[i-1].first);
        // right
        int rightDis = (trees[i+1].first - xi);
        // cout << xi<<" "<< height<<" "<<trees[i].first<<" " << leftDis<<" ";
        if(leftDis > height) {
            ans++;
            cout<< "yo ";
        }
        else if(rightDis > height) {
            cout<< "yooo ";
            xi += height;
            ans++;
        }
    }
*/