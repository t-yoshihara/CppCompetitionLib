#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;


//BEGIN CUT HERE
int inf = 1e9;

struct edge{int to, cap, rev;};

vector<edge> G[100000];
bool used[100000];

void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}

int dfs(int v,int t,int f){
    if(v==t)return f;
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        edge &e = G[v][i];
        if(!used[e.to]&&e.cap>0){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int flow = 0;
    while(true){
        memset(used,false,sizeof(used));
        int f = dfs(s,t,inf);
        if(f==0)return flow;
        flow +=f;
    }
}


//END CUT HERE


int main(){

    int n;cin>>n;
    REP(i,n){
        int u,v,cap;
        cin>>u>>v>>cap;
        add_edge(u,v,cap);
    }

    cout<<max_flow(1,n)<<endl;

    return 0;
}