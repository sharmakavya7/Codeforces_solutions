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

string s;

void solve() {
    cin >> s;
    int findAB = s.find("AB");
    int BANextToAB = s.find("BA" , findAB+2); 
    // cout<<findAB<<" ";
    int findBA = s.find("BA");
    int ABNextToBA = s.find("AB", findBA+2);
    // cout<<findAB+1<<" "<<findBA <<" ";

    if((findAB != -1 && BANextToAB != -1) || (findBA != -1 && ABNextToBA != -1) ) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" <<endl;
}

int main() {
    solve();
    return 0;
}

// s.find(str) function basically finds the first occ of string str in s
// if string not dound, it returns -1

// see i have 2 cases, 
// 1. I will either find AB next to BA
// 2. Or I will find BA next to AB
// If either of them gives me true, I return YES