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

const int N = 102;
vector <pii> adj;
bool vis[N];

void dfs(int src) {
	pii x = adj[src];
	vis[src] = true;
	
	for(int i=0; i< (int)adj.size(); i++) {
		pair <int, int> y = adj[i];
		if(vis[i])
			continue;
        // cout << x.first<<" " << x.second <<" " << y.first<< " " << y.second<<" ";
		if((x.first>y.first && x.first<y.second)||(x.second>y.first && x.second<y.second))
			dfs(i);
	}
}

int main()
{
	int t;  // number of quries
	cin>>t;
	int x, y, q;
	while(t--) {
		cin>>q>>x>>y;
		if(q==1) {
			adj.push_back({x,y});
		}
		else {
            x--, y--;
            // cout <<"x: " << x << " y: " << y <<" ";
            // OH BOIIII, vis bhi to clear karrrr!!!!!
			for(int i=0; i<N; i++) {
                vis[i] = 0;
            }
			dfs(x);
			if(vis[y])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}

  													  	  				 	  			
// visualize them as directed edges, call dfs form a, if that dfs 
// visits every node(through given conditions) and reaches b, then we can say, 
// intervals can be merged(or whatsoever)
