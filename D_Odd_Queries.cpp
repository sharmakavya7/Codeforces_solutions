#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstring>
#include <cstdlib> 
#include <ctime>
#include <sstream>
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <utility>
#include <deque>
#include <queue>
#include <stack>
#include <regex>
using namespace std;
 
# define D double
# define I insert
# define ll long long
# define ld long double

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) (v).begin() , (v).end() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >

# define F first
# define S second
# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false); cin.tie(0);

// two coprimes' gcd = 1
ll __gcd(ll a,ll b) { if(a!=0)return __gcd(b%a,a); return b; }
bool comp(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second); }
void print(vector<int> vec){ for(int i=0; i<vec.size(); i++) {cout << vec[i]<<" ";} cout<<endl;}
void printv(ll v[], ll n) { for(int i=0; i<n; i++) { cout << v[i] <<" "; } line;}

const int mod = (int)1e9+7;
const ll N = 2e5 + 2 ;  

vector<pair<string, int>> process_queries(vector<string>& database, vector<string>& queries, int m) {
    unordered_map<string, int> user_cnt;
    unordered_map<string, string> short_actual, short_user_id;
    for (string& s : database) {
        string user_id, short_url, actual_url;
        stringstream ss(s);
        ss >> user_id >> short_url >> actual_url;
        short_actual[short_url] = actual_url;
        short_user_id[short_url] = user_id;
    }
    vector<pair<string, int>> result;
    for (string& s : queries) {
        string short_url = s, actual_url = short_actual[short_url],
         user_id = short_user_id[short_url];
        string key = user_id + "|" + short_url;
        user_cnt[key]++;
        int count = user_cnt[key];
        result.emplace_back(actual_url, count);
    }
    return result;
}



int main() {
    fast;
    // ll t;
    // cin >> t;
    // while(t--) {
    //     solve();
    //     // clear_global();
    // }
    // solve();
    int m = 1; // number of users
    int q = 2; // number of queries
    vector<string> database = {
        "0 tezos google",
        "0 rakkl facebook",
        "0 crona hack",
        "0 hakkr hack",
    };
    vector<string> requests = {
        "rakkl",
        "crona"
    };
    vector<pair<string, int>> result = process_queries(database, requests, m);
    for (pair<string, int>& p : result) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
