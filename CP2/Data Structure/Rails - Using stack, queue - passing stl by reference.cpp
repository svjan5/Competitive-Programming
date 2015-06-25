#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

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



void fillQueue(queue<int> &que,int n){
    FOR1(i,n) que.push(i);
}

bool fromQueue(stack<int> &stck,queue<int> &que,int ele){

    if(que.empty())
        return false;

    if(ele>=que.front()){

        while(ele != que.front()){
            stck.push(que.front());
            que.pop();
        }

        que.pop();
        return true;
    }

    else
        return false;
    
}

bool check(stack<int> &stck, queue<int> &que,int ele){
    if(!stck.empty()){
        if(stck.top() == ele){
            stck.pop();
            return true;
        }
        else return fromQueue(stck,que,ele);
    }
    else return fromQueue(stck,que,ele);
}

int main() {
    int n,ele;
    bool over,pssbl;
    
    while(scanf("%d",&n) && n!=0){
        over = false;

        while(!over){
            stack<int> stck;
            queue<int> que;
            
            fillQueue(que,n);
            pssbl = true;

            FOR(i,n){
                scanf("%d",&ele);
                if(!ele){
                    over=true;
                    break;
                }
                // printf("Element: %d\n",ele );
                // printf("Stack: %d\n",stck.size());
                // printf("Queue %d\n",que.size());
                if(check(stck,que,ele)==false)
                     pssbl = false;
            }

            if(over) break;

            if(pssbl)
                printf("Yes\n");
            else
                printf("No\n");
        }
        cout<<endl;
    }
    return 0;
}