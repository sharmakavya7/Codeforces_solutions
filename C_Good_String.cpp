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

const int N = 2e5 + 5;
string s;

void solve() {
    cin >> s;
    int ans = 0, i = 0;
    int n = s.size();
    // if the len is odd or even

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            int cnt=0;
            for(int k=0;k<s.length();k++)
            {
                if(cnt&1 && s[k]==j+'0')
                    cnt++;
                else if(!(cnt&1) && s[k]==i+'0')
                    cnt++;
            }
            if(!(cnt&1) || i==j)
                ans=max(ans,cnt);
        }
    }
    cout<<s.length()-ans<<endl;
}

void clear_global() {
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        clear_global();
    }
    return 0;
}

/*
If the string has odd length, then all characters should be equal to each other; 
otherwise, all characters on odd positions should be equal, and all characters on 
even positions should be equal.

Now, since there are only 10 different types of characters, we can brute force 
all possible combinations of the first and the second character of the string 
we want to obtain (there are only 100 of them) and, for each combination, 
greedily construct the longest possible subsequence of s beginning with those characters in O(n).
*/