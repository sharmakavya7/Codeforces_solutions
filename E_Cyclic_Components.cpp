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

const int N = 2e5 + 2 ; 
vector<int>adj[N];
int vis[N] = {0};
int n, m;

void input() {
    // int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
}

void dfs(int node, bool &flag) {
    vis[node] = 1;

    // every node should have 2 neighbours
    if(adj[node].size()!=2) {     
        flag &= false;
    }

    // we didn't write the complete detect a cycle code here, why?
    // bcz we already know vo nodes hi neeche aaengi jinke 2 neighbours honge, and there
    // is always gonna be a cycle cz sabke 2 edges hai
    for(auto i:adj[node]) {  
        if(!vis[i]) {
            dfs(i, flag);
        }
    }
}

int main() {
    input();
    int cnt=0;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            bool flag = true;
            dfs(i, flag);
            if(flag) {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}