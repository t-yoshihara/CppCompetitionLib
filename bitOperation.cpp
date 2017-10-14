#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

///デバッグ用///
string to_binString(unsigned int val)
{
    if( !val )
        return std::string("0");
    std::string str;
    while( val != 0 ) {
        if( (val & 1) == 0 )  // val は偶数か？
            str.insert(str.begin(), '0');  //  偶数の場合
        else
            str.insert(str.begin(), '1');  //  奇数の場合
        val >>= 1;
    }
    return str;
}
///

int main(){
    int N=8;
    for(int i=1;i<N;i++){
        for(int comb = (1<<i)-1;comb<(1<<N);comb = ((comb&~(comb+(comb&-comb)))/(comb&-comb)>>1)|comb+(comb&-comb)){
             cout<<to_binString(comb)<<endl;
        }
    }
    return 0;
}