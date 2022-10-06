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

const int N = 2e5 + 4;
int n, ans = 0;
vector<int>adj[N], color(N);

void input() {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int node, int parent) {
    int cur = 1;
    // vis[node] = 1;

    for(int it : adj[node]) {
        if(!color[it]) {
            while(color[node]==cur || color[parent]==cur) {
                cur++;
            }
            color[it] = cur;
            ans = max(ans, cur);
            cur++;
            // ans = max(ans, cur);
            dfs(it, node);
        }
    }
}

void solve() {
    input();
    color[1] = 1;
    dfs(1, -1);
    cout << ans <<endl;
    for(int i=1; i<=n; i++) {
        cout << color[i]<<" ";
    }
}

int main() {
    solve();
    return 0;
}