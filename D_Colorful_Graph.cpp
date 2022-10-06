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

const int N = 1e5 + 2;
int n, m, maxi, mini = 1e6;
// vector<int>adj[N];
int color[N];
// unordered_map<int, int>count; 
set<int>st[N];
int maxCard=-1;

void input() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> color[i];
        mini = min(mini, color[i]);
    }
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        if(color[u] == color[v]){
            continue;
        }
        st[color[v]].insert(color[u]);
        st[color[u]].insert(color[v]);
    }
}

void solve() {    
    for(int i=1; i<=n; i++) {
        if(maxi < (int)st[i].size()) {
            maxi = (int)st[i].size();
            maxCard = i;
        }
    }
    if(maxCard == -1) {
        maxCard = mini;
    }
    // cout << maxi << " " << mini << " ";
    cout << maxCard << endl;
}

int main() {
    input();
    solve();
    return 0;
}
/*
What's the catch, inserting in a set? 
- There were no duplicate edges connected and we only calculated the number of edges 
all nodes are connected to, whosoever is the max, return it.
- If all are same in size, return the smallest (color) edge.
*/
/*
struct mycompare {
    bool operator()(const pip &p1, const pip &p2) {
    return (p1.first<p2.first || (p1.first==p2.first && p1.second.first>p2.second.first));
    }
};
priority_queue<pip, vector<pip>, mycompare>count;
*/