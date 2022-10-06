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

// const int N = 1e5+2;
int parent[100001];

int find_parent(int node) {
	if(parent[node] < 0) {
		return node;
	}
	return parent[node] = find_parent(parent[node]);
}

void join(int a, int b) {
	int p1 = find_parent(a);
	int p2 = find_parent(b);

	if(p1==p2) {
		return;
	}
	if(parent[p1] > parent[p2]) {
		swap(p1, p2);
	}
	parent[p1] += parent[p2];
	parent[p2] = p1;
}

int main() {
	int n, q;
	cin >> n >> q;

	for(int i=1; i<=n; i++) {
		parent[i] = -1;
	}

	for(int i=1; i<=q; i++) {
		int query;
		cin >> query;
		if(query == 1) {
			int u, v;
			cin >> u >> v;
			join (v, u);
		}
		else if(query == 2) {
			int u;
			cin >> u;
			int p1 = find_parent(u);     // p1: -5
			// swap(p1, u);
            int temp = p1;               // 
            parent[p1] = u;              // p[p1] = u
			parent[u] = p1;              // p[u]: -5
			
		}
		// else if(query == 3) {
        else {
			int u;
			cin >> u;
			cout<<find_parent(u)<<endl;
		}
	}
	return 0;
}