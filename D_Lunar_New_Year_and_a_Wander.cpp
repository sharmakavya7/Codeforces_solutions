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

const int N = 100002;
// int vis[N] = {0};
vector<int>adj[N];


// void dfs(int node) {

//     cout<<node<<" ";
//     vis[node] = 1;
//     st.erase(node);
//     // put all neighbours
//     for(int i:adj[node]) {
//         if(!vis[i])
//             st.insert(i);
//     }
//     // filter those neighbours who are already visited
//     while(vis[*st.begin()]==1) {
//         // st.erase(st.find(*st.begin()));     // vo index uda do
//         st.erase(st.begin());
//     }
//     // call DFS for the rest
//     if(st.size()>0) {
//         dfs(*st.begin());
//     }
// } 

int main() {
    int n, m;
    cin >> n >> m;

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // dfs(1);
    // for(int i=0; i<n; i++) {
    //     sort(adj[i].begin(), adj[i].end());
    // }
    // for(int i=1; i<=n; i++) {
    //     if(!vis[i]) {
    //         dfs(i);
    //     }
    // }
    // BFS kinda
    set<int> st;
    st.insert(1);
    vector<bool> vis(n+1,0); 
    while(!st.empty()) {

        int u=*st.begin();
        vis[u]=1;
        st.erase(u);
        cout<<u<<" ";

        for(int v:adj[u]) {
            if(!vis[v]) 
                st.insert(v);
        }
    }
    return 0;
}
/*
1 2 10 3 4 8 11 5 6 12 14 18 7 13 15 
20 23 25 19 27 22 28 26 29 30 31 32 
34 35 36 9 37 38 17 39 40 41 42 43 
44 45 46 47 49 50 24
*/