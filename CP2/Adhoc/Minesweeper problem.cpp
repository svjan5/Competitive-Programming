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


char mines[101][101];
char final[101][101];

int dr[] = {0,1,-1,0,1,-1,1,-1};
int dc[] = {1,0,0,-1,1,-1,-1,1};
int n,m;

void computeValue(int x,int y){
    int x1,y1;
    int count=0;

    if(mines[x][y]=='*'){
        final[x][y]='*';
        return;
    }

    FOR(i,8){
        x1 = x+dr[i];
        y1 = y+dc[i];

        if(x1<0 || y1<0 || x1>=n || y1>=m)
            continue;

        else{
            if(mines[x1][y1]=='*')
            count++;
        }
    }
    final[x][y] = '0'+count;
}


int main() {
    int count=0;

    while(true){
        char c;
        count++;

        scanf("%d %d\n",&n,&m);
        if(n==0 && m==0)
            break;

        if(count!=1) cout<<endl;

        FOR(i,n) {
            FOR(j,m) scanf("%c",&mines[i][j]);
            scanf("%c",&c);
        }

        FOR(i,n) FOR(j,m) computeValue(i,j);
        

        printf("Field #%d:\n",count);
        FOR(i,n){
            FOR(j,m){
                printf("%c",final[i][j]);
            }
            cout<<endl;
        }
        // 
    }
    return 0;
}