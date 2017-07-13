struct SegmentTree{

    vector<int> data;
    vector<int> lazy;
    int n;

    SegmentTree(int n_){
        n=1;
        while(n<n_)n*=2;
        data.resize(n*2-1);
        lazy.resize(n*2-1);
    }

    void eval(int k,int a,int b){
        data[k]+=lazy[k];
        if(k<n-1){
            lazy[2*k+1]+=lazy[k]/2;///合計なので
            lazy[2*k+2]+=lazy[k]/2;///半分にして追加している
        }
        lazy[k]=0;
    }

    void add(int a,int b,int x,int k,int l,int r){
        eval(k,l,r);

        if(l>=b||r<=a)return;
        if(l>=a&&r<=b){
            lazy[k]+=(r-l)*x;///合計なのでr-lを掛けている
            eval(k,l,r);
            return;
        }
        add(a,b,x,2*k+1,l,(l+r)/2);
        add(a,b,x,2*k+2,(l+r)/2,r);
        data[k]=(data[2*k+1]+data[2*k+2]);///合計なので子ノードの和
    }

    void add(int a,int b,int x){
        add(a,b,x,0,0,n);
    }

    int getSum(int a,int b,int k,int l,int r){
        eval(k,l,r);

        if(l>=b||r<=a)return 0;
        if(l>=a&&r<=b)return data[k];

        return (getSum(a,b,2*k+1,l,(r+l)/2) + getSum(a,b,2*k+2,(r+l)/2,r));///合計なので子ノードの和
    }

    int getSum(int a,int b){
        return getSum(a,b,0,0,n);
    }

};