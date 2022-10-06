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

const int N = 100005;
int n, m, k, nodes;
vector<int>adj[N], special(N), vis(N, 0);
// bool flag = 1;

void input() {
    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        cin >> special[i];
    }
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// number of edges btw n nodes = n*(n-1) / 2

void dfs(int node) {
    vis[node] = 1;
    nodes++;
    for(auto it:adj[node] ) {
        if(!vis[it]) {
            // nodes++;
            dfs(it);
        }
        // if(special[it]) {
        //     flag &= false;
        // }
    }
}

void solve() {
    input();
    int total = 0, maxi = 0, ans=0;
    for(int i=0; i<k; i++) {
        nodes = 0;
        dfs(special[i]);
        total+=nodes;
        maxi = max(maxi, nodes);
        // flag = true;
        ans += nodes*(nodes-1)/2;
    }
    total = n-total;
    ans += total*(total-1)/2 + maxi*total;
    cout << ans - m << endl;
}

int main() {
    solve();
    return 0;
}