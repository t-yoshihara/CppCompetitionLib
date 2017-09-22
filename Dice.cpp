#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;


//BEGIN CUT HERE
struct Dice{
    int s[6];

    Dice(int top,int front,int right){
        s[0]=top,s[1]=front,s[2]=right,s[3]=7-front,s[4]=7-right,s[5]=7-top;
    }

    void roll(char dir){
        //0:奥向き 1:右向き 2:左向き 3:手前向き
        vector<int> v;
        switch(dir){
            case 'N':
                v = {0,1,5,3};break;
            case 'E':
                v = {0,4,5,2};break;
            case 'W':
                v = {0,2,5,4};break;
            case 'S':
                v = {0,3,5,1};break;
        }
        for(int i=0;i<v.size()-1;i++)swap(s[v[i]],s[v[i+1]]);
    }

    int top(){return s[0];}
    int front(){return s[1];}
    int right(){return s[2];}
    int back(){return s[3];}
    int left(){return s[4];}
    int down(){return s[5];}
};

//END CUT HERE

int main(){

    Dice dice(1,2,3);
    int A[6];REP(i,6)cin>>A[i];
    string s;cin>>s;
    REP(i,s.size())dice.roll(s[i]);

    cout<<A[dice.top()-1]<<endl;

    return 0;
}