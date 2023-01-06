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
void printv(ll v[], int n) { for(int i=1; i<=n; i++) { cout << v[i] <<" "; } line;}

const int N = 2e5 + 2 ; 
pii b[N];
int a[N];
void solve () {
    int n;
    cin >> n;
    // int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    // vector<int>freq(n);
    map<int, int>freq;

    for(int i=0; i<n; i++) {
        freq[a[i]]++;
    }
    if(freq[n] < 1) {
        cout <<"NO"; line
        return;
    }
    // pii b[n];

    for(int i=0; i<n; i++) {
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b, b+n);
    queue<int>q;
    // missing no
    for(int i=1; i<=n; i++) {
        if(freq[i] < 1) {
            q.push(i);
            q.push(i);
        }
    }
    vector<int> v1(n+2), v2(n+2);

    for(int i=0; i<n; i++) {
        if(freq[b[i].first] > 2) {
            cout << "NO"; line
            return;
        }
        else if(freq[b[i].first] == 1) {
            v1[b[i].second] = b[i].first;
            v2[b[i].second] = b[i].first;
            freq[b[i].first] = 0;
        }
    }    
    for(int i=0; i<n; i++) {
        if(freq[b[i].first] == 2) {
            //  missing no se chhote no ka occ agr 2 ya 2 se zyda hai to ans is always no!!
            if(b[i].first < q.front()) {
                cout << "NO"; line;
                return;
            }
            // doubtful
            v1[b[i].second] = b[i].first;
            v2[b[i].second] = q.front();
            q.pop();
            freq[b[i].first] = 3;
        } 
        else if(freq[b[i].first] == 3) {
            if(b[i].first < q.front()) {
                cout << "NO"; line;
                return;
            }
            // doubtful
            v1[b[i].second] = q.front();
            v2[b[i].second] = b[i].first;
            q.pop();
        }
    } 
    cout << "YES"; line;
    for(auto i=0; i<n; i++) {
        cout << v1[i] <<" ";
    }
    line;
    for(auto i=0; i<n; i++) {
        cout << v2[i] <<" ";
    }
    line;
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
int flag =-1;
    for(int i=n; i>0; i--) {
        if(freq[i] == 0) {
            flag = 1;
            continue;
        }
        if(freq[i] >= 2 && flag == 1) {
            cout << "NO"; line;
            break;
        }
    }    
    vector<int>p(n), q(n);

    for(int i=1; i<=n; i++) {
        while(freq[a[i]] != 0) {
            p.push_back(a[i]);
            q.push_back(a[i]);
            freq[a[i]--]; i++;
        }
        
    }
unordered_map<int, int> mp;
    for(auto  i : a) {
        mp[i]++;
    }
    for(auto i = mp.begin(); i!=mp.end(); i++) {
        if(i->second > 2) {
            cout << "NO"; line;
            return;
        }
    }
    vector<int>missing;
    for(int i=1; i<=n; i++) {
        if(mp.find(i) == mp.end()) {
            missing.push_back(i);
        }
    }
*/

