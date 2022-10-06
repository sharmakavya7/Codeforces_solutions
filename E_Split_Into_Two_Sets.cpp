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

int n;
const int N = 2e5 + 2;
vector<int>adj[N];
int color[N] = {-1};
// int vis[N] = {0};
bool flag = true;

void input() {
    // cin >> n;
    for(int i=1; i<=n; i++) {
        int u, v;
        cin >> u >> v;
        flag = true;
        if( u == v ) flag = false;
        adj[u].push_back(v);
        adj[v].push_back(u);

        // if(adj[u].size() != 2 || adj[v].size() != 2 ) 
        //     flag = false;
    }

}

void dfs(int node) {
    for(int i:adj[node]) {
        // cout << " ncol(" <<i<<"): " << color[i] << " ";
        if(color[i] == color[node]) {
            flag = false;
            // cout << " fl: "<<flag;
        }
        else if(color[i]==-1) {
            color[i] = 1 - color[node];
            // cout << " color("<< i<<"): " << color[i];
            dfs(i);
        }
    }
}

int main () {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) {
            adj[i].clear();
            color[i] = -1;
        }
        input();
        // flag = true;
        
        for(int i=1; i<=n; i++) {
            if(adj[i].size() != 2) {
                flag = false;
            }
        }
        for(int i=1; i<=n; i++) {
            if(color[i]==-1) {
                // cout<<" i: "<< i << " ";
                color[i] = 1;
                // cout<<"color("<<i<<"): "<<color[i]<<" ";
                dfs(i);
            }
        }
        // cout<<" final: "<<flag<<" ";
        cout << (flag ? "YES" : "NO");
        cout << endl;
    }
    return 0;
}

/*  
Greedy wont work, why?
1 2 
4 5 
2 3 
take this example
greedy ke through agr kia to false aaega, why?
s1: [1,2] [4,5]  
S2: [2,3] [3,4] (can't cz repeating)
1 ---- 2 ---- 3 ---- 4 ---- 5
   1      2     1/2      1 
            (not possible)
mtlb if we traverse every pair ek ek krke, to hum greedily unko sets assign kr rhe hai
and we're also checking agr repeation nhi ho ra to usi me daalo wrna put it in diff one
BUT BUT
instead if we visualize it as edges connecting the nodes, we can simply assign 
one edge as 1 and the other one as 2 ( basically alternate edges )
and if it is possible to assign alternating sets to all the edges, then say true, else false
What idea comes into mind for this algo?
BIPARTITE GRAPH ( Use it then, damn it!!! )
False conditions:
1. degree of any node should not be greater than or equal to 3
2. Odd nodes in a cycle will also give false
*/


// ALTERNATE SOLUTION
// int dfs(int node) {
//     vis[node] = 1;

//     for(auto i : adj[node]) {
//         if(!vis[i])
//             return 1 + dfs(i);
//     }
//     return 1;
// }

// void input() {
//     cin >> n;
//     bool flag = 1;
//     for(int i=1; i<=n; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);

//         if(adj[u].size() >= 3 || adj[v].size() >= 3 ) {
//             flag = 0;
//             // return;
//         }
//     }
//     if(!flag) {
//         cout << "NO" << endl;
//         return;
//     }
//     for(int i=1; i<=n ;i++) {
//         if(!vis[i]) {
//             if( dfs(i)%2 ) {
//                 cout << "NO" << endl;
//                 return;
//             }
//         }
//     }
//     cout << "YES" <<endl;
// }