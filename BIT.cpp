#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>

using namespace std;

//BEGIN CUT HERE
// 1-indexed (1-n)

struct BIT{
    vector<LL> dat;
    int n;
    BIT(int _n){
        n=_n;
        dat.resize(n+1);
    }

    LL add(int x,int w){ for(int i=x;i<=n;i+=i&-i)dat[i]+=w; }
    LL get_sum(int l,int r){ return get_sum(r)-get_sum(l-1); }
    LL get_sum(int x){
        LL res=0;
        for(int i=x;i>0;i-=i&-i){
            res+=dat[i];
        }
        return res;
    }

};

//END CUT HERE

int main(){
    int N;cin>>N;
    BIT bit(N);
    for(int i=1;i<=N;i++)bit.add(i,i);
    cout<<bit.get_sum(N)<<endl;
    cout<<bit.get_sum(N/2,N)<<endl;
    return 0;

}