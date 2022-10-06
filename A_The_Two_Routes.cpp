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

const int N = 500;

// vector<int>adj[N];
int adj[N][N];
int level[N];
int vis[N];
// vector<int>adjBus[N];
int n, m;


int main() {
    cin>>n>>m;
	level[n]=-1;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	queue<int> q;
	q.push(1);
	vis[1]=1;
	level[1]=0;
    // cout<<q.front().first<<" ";   
    while(!q.empty()) {
        // int node = q.front().first;
        // int t = q.front().second;
        int node = q.front();
        q.pop();

        for(int i=1; i<=n; i++) {
            // rail not present, bus does
            if((!adj[1][n] && adj[node][i]) || (adj[1][n] && !adj[node][i]) ) {
                // cout<<adj[node][i]<<" "<<adj[1][n]<<" ";
                if(!vis[i]) {
                    // q.push({i, t+1});
                    q.push(i);
                    level[i] = level[node] + 1;
                    vis[i] = 1;
                }
            }
        }
        // time = max(t, time);
    }
    cout<<level[n]<<endl;
    return 0;
}
// pata nhi bhai pair of queue se kyu nhi hua