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

const int N = 105;
bool vis[N];
vector<int> adj[N];
int n,m,x,y,t=0;
 
void dfs(int u)
{
	vis[u]=true;
    t++;
	for(int v: adj[u])
		if(!vis[v])
			dfs(v);
}

void input() {
    cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

int main()
{
	input();
	dfs(1);
	if(t==n && m==n)
		cout<<"FHTAGN!\n";
	else
		cout<<"NO\n";
    return 0;
}