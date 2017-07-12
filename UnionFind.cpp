struct UnionFind{
    vector<int> parent;
    UnionFind(int n){
        REP(i,n)parent.push_back(-1);
    }

    int find(int x){
        if(parent[x]<0)return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return;
        if(parent[y]<parent[x])swap(x,y);
        parent[x]+=parent[y];
        parent[y]=parent[x];
    }

    bool same(int x,int y){
        return find(x)==find(y);
    }

};
