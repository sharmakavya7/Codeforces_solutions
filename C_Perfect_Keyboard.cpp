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

set<int>adj[N];
int vis[N];
void dfs(int u,int p){
    char c = u + 'a';
    vis[u] = 1;
    cout << c;
    for(auto v:adj[u]) {
        if(v==p) 
            continue;
        if(vis[v]==1)   
            continue;
        dfs(v,u);
    }
}
void solve () {
    string s;
    cin>>s;
    for(int i=1;i<s.size();i++){
        int x=s[i-1]-'a';
        int y=s[i]-'a';
        adj[x].insert(y);
        adj[y].insert(x);
    }
    int root=0;
    int cnt=0;
    bool ok=false;
    for(int i=0;i<26;i++){
        if(adj[i].size()==1) {
            cnt++;
            ok=true;
            root=i;
        }
        if(adj[i].size()>2){
            ok=ok&false;
        }
    }
    if(cnt!=2)  
        ok=false;
    if(s.size()==1) 
        ok=true;

    if(ok){
        cout<<"YES"; line;
        dfs(root,-1);
        for(int i=0;i<26;i++){
            if(vis[i]==0)   {
                char c=i+'a';
                cout<<c;
            }
            vis[i]=0;
            adj[i].clear();
        }
        line;
    }
    else{
        cout<<"NO"; line;
        for(int i=0; i<26; i++) {
            vis[i]=0;
            adj[i].clear();
        }
    }
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

