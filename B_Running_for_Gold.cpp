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

// int n;
// const int N = 50005;
// int athlete[N][N];
int n;
const int N = 50005;
int athlete[50005][8];
// vector<vector<int>>athlete(N, vector<int>(N));
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        // for(int i=1; i<=n; i++) { 
        //     vector<int> row;
        //     for(int j=1; j<=n; j++){
        //         int temp;
        //         cin>>temp;
        //         row.push_back(temp);
        //     }
        //     athlete.push_back(row);
        // }
        for(int i=1; i<=n ;i++) {
            for(int j=1; j<=5; j++) {
                cin >> athlete[i][j];
            }
        }
        // stores the athelete who is overall max
        int maxi = 1;
        int cnt = 0;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // compare every athlete with the winner(maxi) till now
        // if the cur one comes less, then update that with maxi
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=5; j++) {
                // pq.push({athlete[i][j], i});
                if(athlete[i][j] < athlete[maxi][j]) {
                    cnt++;
                }
                if(cnt >= 3) {
                    maxi = i;
                }
                // cout << maxi << " ";
            }
            cnt = 0;
        }

        // we have ans in maxi but now we'll compare it with each athlete again
        // because maybe there had been an athlete who was lesser than the maxi, vo ab winner ho jaega na

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=5; j++) {
                if(athlete[maxi][j] > athlete[i][j]) {
                    // cout << "m: "<< maxi <<" ";
                    // maxi = -1;
                    // break;
                    cnt++;
                    // cout << "a: "<<athlete[maxi][i]<<","<<athlete[i][j]<< " c: " << cnt <<" ";
                    if(cnt >= 3) {
                        maxi = -1;
                        break;
                    }
                }
            }
            cnt = 0;
        }
        cout<< maxi <<endl;       
    }
    cout<<endl;
    return 0;
    // cout<< "Hello world";
}