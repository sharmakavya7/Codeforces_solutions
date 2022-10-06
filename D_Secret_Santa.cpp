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

int n, m;
const int N = 2e5 + 2;
unordered_map<int,set<int>>mp;
int a[N] = {}, b[N] = {}, vis[N] = {0};
int fulfilled = 0;

void solve() {

    cin >> n;

    stack<int> notyetgifted;
    vector<int>giftedby(n+1, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin>>x;

        a[i]=x;

        if(vis[x])  {
            b[i]=-1;
        }
        else  {
            fulfilled++;
            giftedby[x]=i;
            vis[x]=1;
            b[i]=x;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            notyetgifted.push(i);
        }
    }

    if(notyetgifted.size() == 1) {
        int z = notyetgifted.top();
        // cout << z << " ";
        if(b[z]==-1) {
            b[z]=a[z];
            b[giftedby[a[z]]]=z;
        }
    }

    int last;
    for (int i = 1; i <= n ; i++) {
        if (b[i] != -1) {
            continue;
        }
        int z = notyetgifted.top();
        notyetgifted.pop();

        if (i == z) {
            if(!notyetgifted.empty()) {
                b[i] = notyetgifted.top();
                notyetgifted.pop();
                notyetgifted.push(z);
                last =i;
            }
            else {
                b[i]=z;
                swap(b[i],b[last]);
            }
        }
        else {
            b[i] = z;
            last =i;
        }
    }
    cout << fulfilled << endl;
    for(int i=1; i<=n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

void clear_global_variables() {
    fulfilled = 0;
    for(int i=1; i<=n; i++) {
        vis[i] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        solve();
        clear_global_variables();
    }
    return 0;
}


    // stack<int>st;
    // for(int i=1; i<=n; i++) {
    //     if(!vis[i]) {
    //         // cout << "i: "<< i <<" ";
    //         st.push(i);
    //     }
    // }
    // int last = 0;
    // for(int i=1; i<=n; i++) {

    //     if(st.size()==1) {
    //         int topi = st.top();
    //         if(a[topi] == -1) {
                
    //         }
    //     }
        
    //     if(a[i]==-1) {
    //         int topi = st.top();
    //         st.pop();
    //         // 2 6 3 7 4 1 5  (3 wrong)
    //         if(topi == i && !st.empty()) {
    //             a[i] = st.top();
    //             last = i;
    //             st.pop();
    //             st.push(topi);
    //         }
    //         // 2 5 4 6 3 1 6    (6 wrong)
    //         else if(topi == i && st.empty()) {
    //             a[i] = topi;
    //             swap(i, a[last]);
    //         }
    //         else {
    //             a[i] = topi;
    //             last = i;
    //         }
    //     }
    // }
    // 6 4 7 2 3 5 1
    // for(int i=1; i<=n; i++) {
    //     cout << a[i] << " ";
    // }