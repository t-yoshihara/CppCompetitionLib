uni[MAX_N];

int find(int x){
    if(uni[x]<0)return x;
    return uni[x]=find(uni[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(uni[x]<uni[y]){
        uni[x]+=uni[y];
        uni[y]=x;
    }else{
        uni[y]+=uni[x];
        uni[x]=y;
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

//
//fill_n(uni,MAX_N,-1);
//