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
# define pii pair<int,int>
# define pip pair<int, pii>

int n;
const int N = 2e5 + 2;
vector<pair<int,int>>adj[N];
vector<int>bad(N);
vector<int>vis(N,0), res;
int last=-1, cnt, ans;

void input() {
    cin >> n;

    for(int i=1; i<=n; i++) {
        int x, y, t;
        cin >> x >> y >> t;

        adj[x].push_back(make_pair(y,t));
        adj[y].push_back(make_pair(x,t));
    }
}

void dfs(int node, bool parent) {
    vis[node] = 1;

    for(auto i : adj[node]) {
        // cout << "last: " <<last<<" ";
        if(!vis[i.first]) {
            if(i.second==2) {
                last = i.first;
            }
            dfs(i.first, i.second==2);
        }
    }
    // vis[node] = 0;
    if(last!=-1 && parent) {
        // cnt++;
        ans = last;
        res.push_back(ans);
        last = -1;
    }
}

void solve() {
    dfs(1, 0);  
    cout << res.size() << endl;
    for(int i:res) {
        cout << i <<" ";
    }
}

int main() {
    input();
    solve();
    return 0;
}