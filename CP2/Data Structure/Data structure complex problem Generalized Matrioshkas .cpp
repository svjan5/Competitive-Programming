#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define INF 1000000000

#define pb push_back
#define mp make_pair

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

vi vec;

bool func(int beg,int end,int pval){
    vector < pair<int,ii> > con;
    

    // printf("( %d , %d , %d )\n",beg,end,pval);

    if((end-beg+1)%2!=0) 
        return false;

    if(beg <0 || end<0 || beg>end){
        // printf("Hello\n");
        return true;
    }

    while(beg<end){
        int head = vec[beg];
        int headIndex = beg;
        bool endgot=false;
        if(head>0) return false;

        for(int i=beg+1;i<=end;i++){
            if(abs(vec[i]) > abs(head))
                return false;
            else if(vec[i] == -head){
                beg = i+1;
                con.pb(mp(-head,ii(headIndex,i)));
                endgot = true;
                break;
            }
        }
        if(!endgot)
            return false;
    }

    /*FOR(i,(int)con.size()){
        printf("con :%d (%d,%d) \n",con[i].F,con[i].S.F,con[i].S.S );
    }*/

    int sum=0;
    FOR(i,(int)con.size())
        sum += con[i].F;

    // printf("sum %d\n",sum);

    // printf("Over( %d , %d , %d )\n\n",beg,end,pval);

    if(sum >= pval)
        return false;

    else{
        bool res = true;
        FOR(i,(int)con.size()){
            // printf("(%d %d %d ) calls (%d %d %d )\n", );
            res = res && func( (con[i].S.F) + 1 , con[i].S.S -1 ,con[i].F);
        }
        return res;
    }

}

int main() {
    string line;
    int ele;

    while(getline(cin,line)){
        if(line.length() ==0)
            continue;
        vec.clear();
        istringstream iss(line);

        while(iss>>ele){
            vec.pb(ele);
        }

        if( ((int)vec.size())%2 == 0 && func(0,vec.size()-1,INF))
            printf(":-) Matrioshka!\n");
        else
            printf(":-( Try again.\n");

        // FOR(i,(int)vec.size())
        //     printf("%d ",vec[i]);

        // cout<<endl;
    }
    return 0;
}