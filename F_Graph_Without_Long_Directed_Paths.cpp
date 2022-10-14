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
# define ll long long
# define pii pair<int,int>
#define pb push_back

const int N = 2e5 + 5;
int n, m, u[N], v;
vector<int>adj[N];
int color[N]={-1};

void input() {
    cin >> n >> m;
    for(int i=0;i<m;i++) {
		cin >> u[i] >> v;
		adj[u[i]].pb(v);
		adj[v].pb(u[i]);
    }
}

void dfs(int node) {
    for(auto i : adj[node]) {
        if(color[i]==-1) {
            color[i] = 1 - color[node];
            dfs(i);
        }
        if(color[i] == color[node]) {
            cout << "NO" <<endl;
            // return;
            exit(0);
        }
    }
}

int main() {
    input();
    memset(color,-1,sizeof color);
    color[1] = 1;
    dfs(1);
    cout << "YES" << endl;
    for(int i=0; i<m; i++) {
        cout << color[u[i]];
    }
    return 0;
}

// basically, check for bipartite graph.
// path len cant be 2 or greater, means if we assign 1 to directed, two 1s can't be same, cant point in the same direction
// means 2 adj nodes cant be of same color.
// refer to yt editorial
