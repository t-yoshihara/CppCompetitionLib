#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
using namespace std;

typedef string::const_iterator State;
class ParseError{};

int factor(State &begin);

int number(State &begin){
    int ret=0;

    while(isdigit(*begin)){
        ret*=10;
        ret+=*begin -'0';
        begin++;
    }
    return ret;
}

int term(State &begin){
    int ret=factor(begin);

    while(true){
        if(*begin=='*')ret*=factor(++begin);
        else if(*begin=='/')ret/=factor(++begin);
        else break;
    }
    return ret;
}

int expression(State &begin){
    int ret=term(begin);
    while(true){
        if(*begin=='+')ret+=term(++begin);
        else if(*begin=='-')ret-=term(++begin);
        else break;
    }
    return ret;
}

int factor(State &begin){
    int ret;
    if(*begin=='('){
        ret=expression(++begin);
        begin++;
    }else{
        ret =number(begin);
    }
    return ret;
}

int main(){

    int N;
    cin>>N;
    cin.ignore();
    string s[N];
    REP(i,N)getline(cin,s[i]);
    REP(i,N){
        State begin=s[i].begin();
        cout<<expression(begin)<<endl;
    }

    return 0;
}