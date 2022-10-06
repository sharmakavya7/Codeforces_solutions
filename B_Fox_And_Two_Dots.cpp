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

const int N = 100;
int vis[N][N] = {0};
// vector<vector<char>>mat;
char mat[N][N];
int n, m;
bool flag = 0;
int DR[4] = {-1, 0, +1, 0};
int DC[4] = {0, +1, 0, -1};

void dfs(int r, int c, int pi, int pj) {
    vis[r][c] = 1;
    // cout<< mat[r][c]<<" ";
    // cout<<r<<","<<c<<" ";
    for(int k=0; k<4; k++) {
        int nrow = r + DR[k];
        int ncol = c + DC[k];

        if(mat[r][c]==mat[nrow][ncol] &&(nrow!=pi || ncol!=pj)) {
            if(vis[nrow][ncol] ) {
                // cout<<" aao ";
                flag = 1;
                // return;
            }
            else
                dfs(nrow, ncol, r, c);
        } 
    }
}

int main() {
    // input();
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>mat[i][j];
        }
    }
    
    // cout<<" go "<<" ";
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j]) {
                cnt++;
                // cout<< mat[i][j]<<" ";
                dfs(i, j, -1, -1);
                // if(flag==1) {
                //     break;
                // }
            }
        }
    }
    // cout<<cnt<<" ";
    cout << (flag ? "Yes" : "No" );
    // cout<<"No"<<endl;
    return 0;
}