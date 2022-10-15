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

int n, ans;
string s;
// Just find if that subsequence is present in s or not
// which subseq are we talking about?
// we have passed a multiple of 8 which has 3 digits in it, 
// if that number(subseq) is present in the given number(string) s, it means, YES we can modify s
int solve(int x) {
    string a = to_string(x);
    int j = 0;
    for(int i=0; i<s.size(); i++) {
        if(a[j]==s[i])
            j++;
        if(j==a.size())
            return true;
    }
    return false; 
}

int main() {
    cin >> s;
    n = s.size();
    for(int i=0; i<n; i++) {
        if(s[i] == '0') {
            cout << "YES" << endl;
            cout << "0";
            return 0;
        }
    }
    for(int i=0; i<999; i+=8) {
        if(solve(i)) {
            cout << "YES" <<endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "NO"<<endl;
    return 0;
}


// recursive:
// bool solve(int i, int num) {
    
//     if(num % 8 == 0 && num>0) {
//         ans = num;
//         // cout<<ans<<" ";
//         return true;
//     }
//     // NOTE:
//     // to avoid checking all the cases, mtlb all the subsequences, we'll check only those subseq
//     // who have 3 digits. That will reduce our time complexity, how?
//     // if we calc all the subsq then recursion tree ke through 2^n hoga
//     // but if we only find subq of len 3, then we'll consider only those combination, viz.
//     // nC0 + nC1 + nC2 + nC3 ~ n^3
//     // So, T.C: O(n^3), which is better than O(2^n)
//     if(i >= n || num>999) {
//         return false;
//     }
//     // not pick
//     bool not_pick = solve(i+1, num);

//     if(num != -1) {
//         num = num*10+ s[i]-'0';
//     }
//     // cout << num <<" ";
//     // pick
//     bool pick = solve(i+1, num);
    
//     return pick || not_pick;
// }
/*
int main() {
    cin >> s;
    n = s.size();
    for(int i=0; i<n; i++) {
        if(s[i] == '0') {
            cout << "YES" << endl;
            cout << "0";
            return 0;
        }
    }
    if(solve(0, 0)) {
        cout << "YES";
        line;
        cout << ans << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
*/