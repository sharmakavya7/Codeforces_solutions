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

const int N = 150002;
// vector<int>adj[N];
vector<string> s(105);  // vector to store n words
int vis[N] = {0};
int pathVis[N] = {0};
int n;

void input() {
    // int n, m;
    cin>>n;

    for(int i=0; i<n; i++) {
        string x;
        cin>>x;
        s[i] = x;
    }
}
// see if a cycle exixt in directed graph
bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<int>adj[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto i:adj[node]) {
        if(!vis[i]) {
            if(dfs(i, vis, pathVis, adj)==false)
                return false;
        }
        // cycle exists
        else if(pathVis[i]) {
            return false;
        }
    }
    pathVis[node] = 0;
    return true;
}

int main() {
    input();



}



//  If there is a rule that character c1 appears before character c2, add an edge from c1 to c2.
// It is possible to order the letters to satisfy the constraints iff there are no directed cycles
//  in this graph. That is, we need to test that the graph is a Directed acyclic graph
// After applying Topological sorting the directed graph will give a valid ordering of the 
// modified alphabet as well. 
// IMPOSSIBLE:
// There is one additional case of the list being invalid. 
// For example, if "Donald" appears before "Don", there is no ordering of letters which will work.