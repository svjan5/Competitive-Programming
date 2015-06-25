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

int g[3][3];

int dr[] = {1,0,0,-1};
int dc[] = {0,1,-1,0};


bool checkZero(){
    FOR(i,3) FOR(j,3) 
        if(g[i][j]==1) 
            return false;
    return true;
}

int adjSum(int x,int y){
    int x1,y1;
    int sum=0;

    FOR(i,4){
        x1 = x+dr[i];
        y1 = y+dc[i];
        if(x1<0 || x1>=3 || y1<0 || y1>=3)
            continue;
        else
            sum += g[x1][y1];
    }
    return sum%2;
}

void F(){
    int temp[3][3];

    FOR(i,3) FOR(j,3) temp[i][j] = adjSum(i,j);
    
    FOR(i,3) FOR(j,3)
        g[i][j] = temp[i][j];
}

int main() {
    int t;
    scanf("%d",&t);
 
    while(t--){
        FOR(i,3) FOR(j,3) scanf("%1d",&g[i][j]);
        int count=0;

        while(!checkZero()){
            count++;
            F();
        }
        if(count==0)
            printf("%d\n",-1);
        else
            printf("%d\n",count-1);
        /*FOR(i,3){
            FOR(j,3)
                printf("%d",g[i][j] );
            cout<<endl;
        }*/
    }
    return 0;
}