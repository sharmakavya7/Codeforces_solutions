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

int parent[150002];
vector<int>adj[150002];

int find_parent(int node) {
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}

void join(int a, int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);

    if(p1==p2) {
        return;
    }

    if(parent[p1] > parent[p2] ) {
        swap(p1, p2);
    }
    parent[p1] += parent[p2];
    parent[p2] = p1;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        parent[i] = -1;
    }
    
    for(int i=0; i<n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        join(u ,v);
    }

    // bool flag = true;
    for(int i=1; i<=m; i++) {
        // int size = -find_parent(i);
        int size = -parent[i];
        if(adj[i].size() != size-1 && adj[i].size()!=0) {
            // flag = false;
            // break;
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    // cout<< (flag) ? "Yes" : "No";
    return 0;
}























// DFS (not working soln)
// const int N = 150002;
// vector<int>adj[N];
// int vis[N] = {0};
// int n, m;

// void input() {
//     // int n, m;
//     cin>>n>>m;

//     for(int i=0; i<m; i++) {
//         int u, v;
//         cin>>u>>v;
//         adj[v].push_back(u);
//         adj[u].push_back(v);
//     }
// }

// void dfs(int node, bool flag) {
//     vis[node]=1;

//     for(auto it:adj[node]) {
//         if(!vis[it]) {
//             dfs(it, flag);
//         }
//     }
//     // if cycle exixts
//     // all nodes should be interconnected to eachother
//     if(adj[node].size()!=n-1) {
//         // cout<<"adj[node].size(): "<<adj[node].size()<<" "<<" m:"<<m<<" ";
//         flag&=false;
//     }
// }

// int main() {
//     input();

//     bool flag=true;
//     int component=0;
//     for(int i=1; i<=n; i++) {
//         if(!vis[i]) {
//             component++;
//             dfs(i, flag);
//             if(flag==false) {
//                 break;
//             }
//         }
//     }
//     if(flag==false) {
//         cout<<"NO"<<endl;
//     }   
//     else cout<<"YES"<<endl;
//     return 0;
// }

// // agr vo ek cycle form kr rhe hai to unki adj[node].size()==no of edges  : YES
// // jitni nodes hai us component me, hume uske connections(edges) = no of nodes-1 krne pdenge : YES
// // 