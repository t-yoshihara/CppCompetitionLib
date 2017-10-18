#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>

using namespace std;

//BEGIN CUT HERE

///点加算区間総和（＝ BIT )
struct SegmentTree{

    int n;
    vector<int> data;

    SegmentTree(int n_){
        n=1;
        while(n<n_)n*=2;
        data.resize(n*2-1);
    }

    void add(int vol,int plc){
        plc += n-1;
        data[plc]+=vol;
        while(plc){
            plc=(plc-1)/2;
            data[plc] = data[plc*2+1]+data[plc*2+2];
        }
    }

    int getSum(int a,int b,int k=0,int l=0,int r=n){
        if(r<=a||l>=b)return 0;
        if(r>=a&&l<=b)return data[k];
        return getSum(a,b,2*k+1,l,(l+r)/2) + getSum(a,b,2*k+2,(l+r)/2,r);
    }

};

///点代入区間最大(最小)
struct SegmentTree{

    int n;
    vector<int> data;

    SegmentTree(int n_){
        n=1;
        while(n<n_)n*=2;
        data.resize(n*2-1);
    }

    void init(int vol,int plc){
        plc += n-1;
        data[plc]=vol;
        while(plc){
            plc=(plc-1)/2;
            data[plc] = max(data[plc*2+1] ,data[plc*2+2]);
        }
    }

    int getMax(int a,int b,int k=0,int l=0,int r=n){
        if(r<=a||l>=b)return INT_MIN;
        if(r>=a&&l<=b)return data[k];
        return max(getMax(a,b,2*k+1,l,(l+r)/2), getSum(a,b,2*k+2,(l+r)/2,r));
    }
};


///区間加算区間最大(最小) (StarrySky木)
struct SegmentTree{

    int n;
    vector<int> segAdd;
    vector<int> segDat;

    SegmentTree(int n_){
        n=1;
        while(n<n_)n*=2;
        segAdd.resize(n*2-1);
        segDat.resize(n*2-1);
    }

    void add(int a,int b,int p,int k=0,int l=0,int r=n){
        if(r<=a||l>=b)return;
        if(r>=a&&l<=b){
            segAdd[k]+=p;
            return;
        }
        add(a,b,p,2*k+1,l,(l+r)/2);
        add(a,b,p,2*k+2,(l+r)/2,r);
        segDat[k] = max(segDat[2*k+1]+segAdd[2*k+1],segDat[2*k+2]+segAdd[2*k+2]);
    }

    int getMax(int a,int b,int k=0,int l=0,int r=n){
        if(r<=a||l>=b)return INT_MIN;
        if(r>=a&&l<=b)return segDat[k]+segAdd[k];
        return max(getMax(a,b,2*k+1,l,(l+r)/2), getSum(a,b,2*k+2,(l+r)/2,r)) + segAdd[k];
    }
};


int main(){

    return 0;
}