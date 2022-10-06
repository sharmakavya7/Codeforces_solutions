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


using namespace std ;
 
int n, max_allowed ; 
 
const int N = 1e5 + 2 ; 
int cats[N] ; 
vector < int > g[N] ; 
 
void read()
{
	cin >> n >> max_allowed ; 
 
	for ( int node = 1 ; node <= n ; node ++ ) 
		cin >> cats[node] ; 
 
	for (int i=1 ; i < n ; i ++)
	{
		int a, b ; 
		cin >> a >> b ; 
		
		g[a].push_back ( b ) ; 
		g[b].push_back ( a ) ; 
	}
}
 
void dfs ( int node, int parent = 0 ) 
{
	if (cats[node] || cats[parent] > max_allowed)
		cats[node] += cats[parent] ; 
 
	for (auto &i : g[node]) 
	{
		if ( i == parent ) 
			continue ; 
 
		dfs ( i, node ) ; 
	}
}
 
int main()
{
	read() ; 
	dfs ( 1 ) ; 
 
	int ans = 0 ; 
	for ( int node = 2 ; node <= n ; node ++ ) 
	{
		if (g[node].size() > 1)
			continue ; 
 
		ans += (cats[node] <= max_allowed) ; 
	}
 
	cout << ans << "\n" ; 
    return 0;
}

// using namespace std;
// const int N = 1e5 + 2 ; 
// // int ans = 0;
// void dfs (int node, int p, vector<int>&billi, vector<int>adj[], int cnt[]) {
//     if(billi[node]) {
//         cnt[node] += cnt[p] + 1;
//     }
//     for(int i:adj[node]) {
//         if(i==p) continue;
//         dfs(i, node, billi, adj, cnt);
//     }
// }

// int main() {
//     int n,m;
//     cin>>n>>m;
//     vector<int>adj[N], billi(n,0); 
//     for(int i=1; i<=n; i++) {
//         cin>>billi[i];
//     }
//     for(int i=1; i<n; i++) {
//         int u, v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int cnt[N];

//     dfs(1, 0, billi, adj, cnt);
//     int ans = 0;
//     for(int i=2; i<n; i++) {
//         if(adj[i].size()>1) {
//             continue;
//         }
//         if(cnt[i]<m)
//             ans++;
//     }
//     cout<<ans<<endl;
//     return 0;
// }