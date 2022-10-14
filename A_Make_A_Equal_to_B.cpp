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
#define pb push_back
 
const int N = 405;
int n ; // A[N], B[N];
vector<int>v1(N,0),v2(N,0);

void input() {
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v1.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v2.push_back(a);
    }
}

void clear_global() {
    v1.clear();
    v2.clear();
}

void solve() {
    input();
    int cnt1=0;
    for(int i=0;i<n;i++) {
        cout <<"["<< v1[i]<<","<< v2[i] <<"] , ";
        if(v1[i]!=v2[i]) {
            cnt1++;
        }
    }
    cout <<endl;
    cout<< "cnt1: " << cnt1 <<" ";
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int cnt2=0;
    cnt2++;
    for(int i=0;i<n;i++){
        if(v1[i]!=v2[i]) cnt2++;
    }
    cout<< "cnt2: " << cnt2 <<" ";
    int k=min(cnt1,cnt2);
    cout << endl;
    cout<<k<<endl;
}

int main() {
    int t;
    cin >> t;
    // cout << t<<" ";
    while(t--) {
        // input();
        solve();
        clear_global();
    }
    return 0;
}