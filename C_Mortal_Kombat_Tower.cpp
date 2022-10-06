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

int n;
const int N = 2e5 + 2 ;
int boss[N];

void input() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>boss[i];
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        input();
        // if boss[0]== 0, then my friend will kill him with no skipPoint, but if boss[0]==1, 
        // then he will have to use a skip point.
        int skipPoint=boss[0];    // 1 or 0

        // if i find a window of 3 ones together, it means there has to be 1 skip point used
        for(int i=1; i<n-2; i++) {
            if(boss[i] && boss[i+1] && boss[i+2]) {
                skipPoint++;
                i+=2;
            }
        }
        cout<<skipPoint<<endl;
    }
    return 0;
}