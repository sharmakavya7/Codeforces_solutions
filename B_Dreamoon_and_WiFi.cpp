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
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

const int mod = (int)1e9+7;
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(int v[], int n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5+10;

ll n, k, l, p, q, m, d, a, b, x;
string s, t;
// vector<int> v1, v2;
int v[N], v1[N], v2[N];
 
// KAFI AJEEB QUES

void solve() {
    cin >> s >> t;
    int n = s.size();
    int destination = 0;
    for(int i=0; i<n; i++) {
        // if(s[i] == '+') {
        //     destination+=1;
        // } else {
        //     destination-=1;
        // }
        destination += (s[i] == '+' ? 1 : -1);
    }
    // cout << destination << " ";
    int temp_dest = 0, guess = 0;

    for(int i=0; i<n; i++) {
        // if(t[i] == '?') {
        //     guess++;
        // } else if(t[i] == 1) {
        //     temp_dest++;
        // } else {
        //     temp_dest--;
        // }
        if(t[i] == '?') {
            guess++;
        }
        else 
            temp_dest += (t[i] == '+' ? 1 : -1);
    }
    double ans;
    int distance_between = destination - temp_dest;

    if((distance_between + guess) % 2 != 0 || guess < abs(distance_between)) {
        cout << "0.000000000000"; line;
        // ans = 0;
        return;
    }
    else
    {
        int m = (guess + abs(distance_between))/2 ; 
        int c = 1 ;
        for(int i=0; i<m; i++)
            c *= guess-i ;
        for(int i=2;i<=m;i++)
            c /= i ;
        ans = (double)c/(1<<guess) ;
    }
 
    printf("%.12f\n", ans) ;
}

int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     clear_global();
    // }
    solve();
    return 0;
}

/*
confusion
int plus = 0, plus1 =0 , min = 0, min1 = 0, ques = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '+') {
            plus+=1;
        } else {
            min-=1;
        }
    }
    for(int i=0; i<n; i++) {
        if(t[i] == '+') {
            plus1+=1;
        } else if(t[i] == '-'){
            min1-=1;
        } else {
            ques++;
        }
    }
    if(plus == plus1 && min == min1) {
        cout << 1.0 , 0; return;
    } 
    int need = 0;
    if(plus < plus1) {
        need += (plus - plus1);
    } 
    if(min1 - min) {
        need += (min - min1);
    }
    if(need > ques) {
        cout << "0.000000000000"; return;
    }
    cout << 0.5;

*/