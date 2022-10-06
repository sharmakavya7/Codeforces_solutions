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

const int N = 3e5 + 2;
int parent[N];
int n, m;
set<int>st;

int main() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        // parent[i] = -1;
        st.insert(i);
    }

    for(int i=0; i<m; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        // for(int i=l; i<=r; i++) {
        // for(auto it = st.lower_bound(l); it!=st.end() && *it<=r; it++) {
        auto it = st.lower_bound(l);
        while( it!=st.end()) {
            int val = *it;
            it++;
            if(val>r) {
                break;
            }
            if(val!=x) {
                parent[val] = x;
                st.erase(val);
            }
            // it++;
        }
        
    }

    for(int i=1; i<=n; i++) {
        cout<<parent[i]<<" ";
    }
    return 0;
}

// int par = find_parent(l);
        // for(int j=l; j<=r; j++) {
        //     if(parent[j]==-1 && j != x) {
        //         parent[j] = x;
        //     } 
        // }
            // for(int i=1; i<=n; i++) {
    //     if(parent[i]==-1) {
    //         parent[i] = 0;
    //     }
    // }