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

int main() {
    int n,a,b;
 
    while(scanf("%d",&n) != EOF){
        priority_queue<int> pq;
        queue<int> que;
        stack<int> stk;
        int pqPoints=0,quePoints=0,stkPoints=0;
        bool impssbl=false;
        int type2Count=0;

        FOR(i,n){
            scanf("%d %d\n",&a,&b);
            /*printf("%d %d\n", a,b);*/

            if(a==1){
                pq.push(b);
                que.push(b);
                stk.push(b);
            }

            else{
                if(pq.top() ==b)
                    pqPoints++;

                if(que.front() ==b)
                    quePoints++;

                if(stk.top() ==b)
                    stkPoints++;

                if(pq.top()!=b && que.front()!=b && stk.top()!=b)
                    impssbl=true;

                pq.pop();
                que.pop();
                stk.pop();
                type2Count++;
            }
        }

        bool ispq,isstk,isque;
        ispq=isstk=isque=false;

        if(!impssbl){

            if(pqPoints == type2Count)
                ispq=true;
            
            if(quePoints == type2Count)
                isque=true;

            if(stkPoints == type2Count)
                isstk=true;


            if( (ispq && isque) || (ispq && isstk) || (isque && isstk) )
                printf("not sure\n");

            else if(ispq)
                printf("priority queue\n");

            else if(isque)
                printf("queue\n");

            else
                printf("stack\n");

        }

        else
            printf("impossible\n");
        

    }

    return 0;
}