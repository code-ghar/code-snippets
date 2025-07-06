//RITIK RAI
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <limits>
#include <numeric>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <tuple>
#include <chrono>    
#include <random>

using namespace std;
#define uint            unsigned long long int // uint64_t
#define ll              long long int
#define ld              long double
#define int             long long int //int64_t
#define endl            '\n'
#define vint            vector<int>
#define vvint           vector<vector<int>>
#define sz(x)           ((int)(x).size())
#define pb              push_back
#define ub              upper_bound
#define lb              lower_bound
#define bin             binary_search
#define all(x)          x.begin(),x.end()
#define rall(x)         x.rbegin(),x.rend()
#define F               first
#define S               second
#define f(i,a,b)        for(int i=(a);i<(b);i++)
#define rf(i,a,b)       for(int i=(a);i>(b);i--)
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define preci(x, y)     fixed << setprecision(y) << x
#define vmin            min_element
#define vmax            max_element
#define PI              3.1415926535897932384626433832795 // atan(1.0)*4.0;
#define uid(a,b)        uniform_int_distribution<int>(a,b)(rng)
mt19937 rng             (chrono::steady_clock::now().time_since_epoch().count());
 
const int inff  = LLONG_MAX;
const int minff = LLONG_MIN;
const int inf   = 1e18;
const int pmod  = 998244353;
const int mod   = 1e9 + 7;
const int maxm  = 2e6 + 3;
const int maxN  = 1e5 + 3;
int T = 1;
 
#ifndef ONLINE_JUDGE
    void _print(int t) {cout << t;} void _Print(int t) {cerr << t;}
    void _print(long double t) {cout << t;} void _Print(ld t) {cerr << t;}
    void _print(double t) {cout << t;} void _Print(double t) {cerr << t;}
    void _print(char x) {cout << '\'' << x << '\'';} void _Print(char x) {cerr << '\'' << x << '\'';}
    void _print(const char *x) {cout << '\"' << x << '\"';} void _Print(const char *x) {cerr << '\"' << x << '\"';}
    void _print(const string &x) {cout << '\"' << x << '\"';} void _Print(const string &x) {cerr << '\"' << x << '\"';}
    void _print(bool x) {cout << (x ? "true" : "false");} void _Print(bool x) {cerr << (x ? "true" : "false");}
    template<typename T, typename V> void _print(const pair<T, V> &x) {cout << '{'; _print(x.first); cout << ','; _print(x.second); cout << '}';}
    template<typename T> void _print(const T &x) {int f = 0; cout << '['; for (auto &i : x) cout << (f++ ? "," : ""), _print(i); cout << "]";}
    template<typename T, typename V> void _Print(const pair<T, V> &x) {cerr << '{'; _Print(x.first); cerr << ','; _Print(x.second); cerr << '}';}
    template<typename T> void _Print(const T &x) {int f = 0; cerr << '['; for (auto &i : x) cerr << (f++ ? "," : ""), _Print(i); cerr << "]";}
    #define trace(...) __f1(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1> void __f1(const char* name, Arg1&& arg1) { cout << name << " : "; _print(arg1); cout<<"\n"; }
    template <typename Arg1, typename... Args> void __f1(const char* names, Arg1&& arg1, Args&&... args) { const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : "; _print(arg1); cout << " | "; __f1(comma + 1, args...); }
    #define Trace(...) __f2(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1> void __f2(const char* name, Arg1&& arg1) { cerr << name << " : "; _Print(arg1); cerr<<"\n"; }
    template <typename Arg1, typename... Args> void __f2(const char* names, Arg1&& arg1, Args&&... args) { const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : "; _Print(arg1); cerr << " | "; __f2(comma + 1, args...); }
    #define debug if(rr!=1){cout<<endl<<"-------------------------------"<<endl<<endl<<endl;}cout<<"TEST ::::::: ";trace(rr); // if(rr!=1){cerr<<endl<<"-------------------------------"<<endl<<endl<<endl;}cerr<<"TEST ::::::: ";Trace(rr);
#else
    #define trace(...)
    #define Trace(...)
    #define debug
#endif


void floydWarshall(vector<vector<int>> &matrix){ // any src,dest shortest path
    int V=matrix.size();
    for(int k=0; k<V; k++) {
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(i==j) matrix[i][j]=0;
                if(matrix[i][k]==-1 || matrix[k][j]==-1) continue;
                if(matrix[i][j]==-1) matrix[i][j]=matrix[i][k]+matrix[k][j];
                else matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
}


class BellmanFord {
public:
    int V, E, src; // number of nodes, edges and starting node
    vector<vector<int>> edges; // {from, to, weight}
    const int INF = 100000000;
    
    BellmanFord(int V, vector<vector<int>> &edges) {
        this->V=V;
        this->edges=edges;
        this->E=edges.size();
    }
    
    vector<int> singleSourceShortestPath(int src, vector<int> & d, vector<int> & par) {
        d = vector<int>(V, INF);
        par = vector<int>(V, -1);
        d[src] = 0;
        int cycleReach=-1;
        
        for (int i = 0; i < V; i++){
            cycleReach=-1;
            for (auto e : edges){
                int node=e[0], child=e[1], weight=e[2]; 
                if (d[node] < INF && (d[child] > d[node] + weight)){
                    d[child] = d[node] + weight;
                    par[child] = node;
                    cycleReach = child;
                }
            }
        }
        if(cycleReach != -1) { // negative cycle detected
            d.clear(); 
        }
        return d;
    }
};


class Dijkstra {
    const int INF = 1000000000;
    vector<vector<pair<int, int>>> adj;

    void dijkstra(int s, vector<int> & d, vector<int> & par) {
        int n = adj.size();
        d.assign(n, INF);
        par.assign(n, -1);

        d[s] = 0;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while (!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if (d_v != d[v])
                continue;

            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    par[to] = v;
                    q.push({d[to], to});
                }
            }
        }
    }
};




void solve()
{

}

 
signed main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    T = 1;
    // cin >> T;
    for(int rr = 1; rr <= T; rr++)
    {
        solve();
    }
}