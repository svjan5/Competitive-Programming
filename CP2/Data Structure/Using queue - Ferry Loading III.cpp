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

queue<ii> qL,qR,ferry;
queue<ii> final;

void checkWait(int &clk){
    if(!qL.empty() && qR.empty()){
        if(clk < qL.front().S)
            clk = qL.front().S;
    }
    else if(qL.empty() && !qR.empty()){
        if(clk < qR.front().S)
            clk = qR.front().S;
    }
    else{
        int mint = min(qL.front().S,qR.front().S);
        if(clk < mint)
            clk = mint;
    }
}

void fillLeft(int clk,int n){
    while(!qL.empty() && clk >= qL.front().S && n--){
        ferry.push(ii(qL.front().F,qL.front().S));
        qL.pop();
    }
}

void fillRight(int clk,int n){
    while(!qR.empty() && clk >= qR.front().S && n--){
        ferry.push(ii(qR.front().F,qR.front().S));
        qR.pop();
    }
}

void drop(int clk){
    while(!ferry.empty()){
        final.push(ii(ferry.front().F,clk));
        ferry.pop();
    }
}

int main() {
    int c,n,t,m;
    scanf("%d",&c);
 
    while(c--){
        scanf("%d %d %d\n",&n,&t,&m);

        int arrival;char side[10];
        FOR(i,m){
            scanf("%d %s\n",&arrival,side);
            if(strcmp(side,"left")==0)
                qL.push(ii(i,arrival));
            else
                qR.push(ii(i,arrival));
        }

        enum position{ LEFT,RIGHT };
        position pos=LEFT;
        int clk = 0;

        while(!qL.empty() || !qR.empty()){
            checkWait(clk);

            if(pos==LEFT){
                fillLeft(clk,n);
                clk += t;
                drop(clk);
                pos = RIGHT;
                // printf("L ");
            }
            else{
                fillRight(clk,n);
                clk += t;
                drop(clk);
                pos = LEFT;
                // printf("R ");
            }
        }

        vector<ii> vec;
        while(!final.empty()){
            vec.pb(final.front());
            final.pop();
        }
        sort(vec.begin(),vec.end());

        FOR(i,(int)vec.size()){
            printf("%d\n",vec[i].S);
        }

        /*printf("LEFT\n");
        while(!qL.empty()){
            printf("%d ",qL.front());
            qL.pop();
        }

        printf("\nRIGHT\n");
        while(!qR.empty()){
            printf("%d ",qR.front());
            qR.pop();
        }*/

        if(c!=0)
            cout<<endl;
    }

    return 0;
}