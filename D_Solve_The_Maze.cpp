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

int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
bool vis[100][100];

bool valid(int x,int y) {
	if(x<=0||x>n||y<=0||y>m)
        return false;
	return true;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>m;
		char maze[51][51];
		for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {

                cin>>maze[i][j];
                vis[i][j]=false;
            }
        }
		for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {

                if(maze[i][j]=='B') {

                    for(int k=0;k<4;k++) {
                        int ci = i+dx[k];
                        int cj = j+dy[k];
                        if(valid(ci,cj)&&maze[ci][cj]=='.')
                            maze[i+dx[k]][j+dy[k]]='#';
                    }
                }
            }
        }
		queue<pair<int,int>>q;
		if(maze[n][m]=='.')
            q.push({n,m});

		while(!q.empty()) {
			int x=q.front().first;
            int y=q.front().second;
            q.pop();
			
            for(int i=0;i<4;i++) {
                int ci=x+dx[i];
                int cj=y+dy[i];
                if(valid(ci,cj)&&!vis[ci][cj]&&maze[ci][cj]!='#') {
                    q.push({ci,cj});
                    vis[ci][cj]=true;
                }
            }
		}
        bool ok=true;
		for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if((maze[i][j]=='G'&&!vis[i][j]) || (maze[i][j]=='B'&&vis[i][j])) {
                    ok=false;break;
                }
            }
        }
		cout<<(ok?"Yes":"No")<<"\n";
		
	}
}