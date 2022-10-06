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
const int N = 502 ; 
char maze[N][N];
int vis[N][N];
int DR[4] = {-1, 0, +1, 0};
int DC[4] = {0, +1, 0, -1};
int n, m, k, i, j;

void input() {
    cin>>n>>m>>k;
    // vector<vector<int>>maze(m, vector<int>(n,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>maze[i][j];
        }
    }
}

void dfs(int i, int j) {
    vis[i][j] = 1;

    for(int l=0; l<4; l++) {
        int nrow = i + DR[l];
        int ncol = j + DC[l];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && maze[nrow][ncol]=='.' && !vis[nrow][ncol]) 
        {
            dfs(nrow, ncol);
        }
    }
    if(k) {
        maze[i][j] = 'X';
        k--;
    }
}

void print() {
    for(int i=0; i<n; i++) {
        for (int j=0 ; j<m ; j++)
        {
            cout<<maze[i][j];
        }
        cout<<endl;
    }
}

int main() {
    input();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(maze[i][j]=='.')
                dfs(i, j);
        }
    }
    
    
    print();
    return 0;
}