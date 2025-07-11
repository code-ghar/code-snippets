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
 
class FenwickTree {
    int n;
    vector<int> tree;
    public:
 
    FenwickTree(vector<int> &v) {
        n=v.size();
        tree=vector<int>(n+1); // here its 1 based indexing
        for(int i=0; i<n; i++) {
            add(i+1, v[i]);
        }
    }
    void add(int k, int delta) {
        while(k<=n) {
            tree[k]+=delta;
            k += k&-k;
        }
    }
 
    int sum(int k) {
        int s=0;
        while(k>=1) {
            s+=tree[k];
            k -= k&-k;
        }
        return s;
    }
};
 
 
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    FenwickTree ft(v);
 
    while(q--) {
        int type;
        cin>>type;
        if(type==1) {
            int k,u;
            cin>>k>>u;
            ft.add(k,u-v[k-1]);
            v[k-1]=u;
        }
        else {
            int a,b;
            cin>>a>>b;
            cout<<ft.sum(b)-ft.sum(a-1)<<endl;
        }
    }
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