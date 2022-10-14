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
 
# define C continue;
# define R return
 
# define D double
# define I insert
# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define pb push_back
# define pf push_front
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvs vector < vs >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >
 
# define vvpii vector < vector < pii > >
# define F first
# define S second
# define mp make_pair
 
# define pp(n) printf("%.10Lf",n);
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);

const int N = 1e5 + 4;
int n, m, k, s;
vector<int> g[N];
int dis[N][110];
int a[N], vis[N];

void bfs(int x) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	for(int i = 1; i <= n; i++) { 
		if(a[i] == x) { 
            // cout << "yo"<<" ";
            q.push(i); 
            vis[i] = 1; 
            dis[i][x] = 0; 
        }
    }
	while(!q.empty()) {
		int u = q.front(); 
        q.pop();
		for(int v : g[u]) {
			if(!vis[v]) {
				dis[v][x] = dis[u][x]+1;
				// cout << dis[v][x]<<" ";
                q.push(v);
				vis[v] = 1;
			}
		}
	}
}

void input() {
    cin >> n >> m >> k >> s;
	for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
int main() {
	input();
	for(int i = 1; i <= k; i++) {
        bfs(i);
    }
	for(int i = 1; i <= n; i++) {
		int ans = 0;
		sort(dis[i]+1, dis[i]+k+1);
        // for(int i=1; i<=n; i++) {
        //     cout << dis[i] <<" ";
        // }
		for(int j = 1; j <= s; j++) {
			ans += dis[i][j];
		}
		cout << ans << " ";
	}
	line;
	return 0;
}
