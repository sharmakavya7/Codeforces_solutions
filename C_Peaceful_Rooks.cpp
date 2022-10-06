#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
# define ll long long
# define pii pair<int,int>

int n, m;
const int N = 1e5 + 2;
vector<pii>mat(N);
vector<bool>visited(N, 0), pathvis(N, 0);
vector<int> adj[N]; 
int ans = 0;

void input() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> mat[i].first >> mat[i].second;
    }
    for(int i=0; i<m; i++) {
        if(mat[i].first != mat[i].second) {
            adj[mat[i].first].push_back(mat[i].second);
            // cout<<"yo";
            ans++;
        }
    }
}

bool dfs(int u) {
    if(!visited[u])  {
        visited[u] = pathvis[u] = true; 
  
        for(auto v : adj[u])  { 
            if (!visited[v] && dfs(v)) 
                return true; 
            else if (pathvis[v]) 
                return true; 
        }
    } 
    pathvis[u] = false;  
    return false; 
} 

void solve() {
    input();
    for(int i=1; i<=n; i++) {
        if(!visited[i] && dfs(i)) {
            // cout << i <<" ";
            ans++;
        }
    }
    cout << ans <<endl;
}

void clear_global() {
    for (int i=1; i<n; i++) {
        visited[i] = 0;
        pathvis[i] = 0;
        ans = 0;
        adj[i].clear();
    }
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