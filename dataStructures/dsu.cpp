//RITIK RAI
#include <bits/stdc++.h>
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

class Dsu {
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    Dsu(int siz) {
        n=siz;
        parent=vector<int>(n);
        rank=vector<int>(n);
        for(int i=0; i<n; i++) {
            parent[i]=i;
            rank[i]=1;
        }
    }
    void unionSet(int a, int b) {
        a=findSet(a);
        b=findSet(b);
        if(a!=b) {
            if(rank[a]<rank[b]) {
                swap(a,b);
            }
            parent[b]=a;
            rank[a]+=rank[b];
            // if(rank[a]==rank[b]) { // or rank[a]+=rank[b] for keeping size of group information
            //     rank[a]++;
            // }
        }
    }
    int findSet(int r) {
        if(r==parent[r]) {
            return r;
        }
        return parent[r]=findSet(parent[r]);
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    Dsu* dsu=new Dsu(n);
    while(m--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        dsu->unionSet(a,b);
        vector<int> visitedSet(n);
        vector<int> sizes;
        for(int i=0; i<n; i++) {
            int set=dsu->findSet(i);
            if(!visitedSet[set]) {
                sizes.push_back(dsu->rank[set]);
                visitedSet[set]=1;
            }
        }
        sort(sizes.begin(),sizes.end());
        for(auto x:sizes) {
            cout<<x<<" ";
        }
        cout<<endl;
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