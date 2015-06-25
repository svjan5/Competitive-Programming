/* Is based on concept of finding longest path in a tree*/

#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef long long LL;
typedef pair<int,int> ii;

char laby[1000][1000];
int visited[1000][1000];
int dist[1000][1000];
int R,C,maxm;
ii maxPos;

int dr[] = {0,1,-1,0};
int dc[] = {1,0,0,-1};

void dfsScan(ii pos){
    int x,y;

    visited[pos.first][pos.second] = DFS_BLACK;

    FOR(i,4){
        x = pos.first + dr[i];
        y = pos.second + dc[i];

        if(x<0 || x>R-1 || y<0 || y>C-1)
            continue;

        else if(laby[x][y]=='#' || visited[x][y] == DFS_BLACK)
            continue;

        else{
            dist[x][y] = dist[pos.first][pos.second] + 1;
            
            if(dist[x][y]>maxm){
                maxm = dist[x][y];
                maxPos = ii(x,y);
            }

            dfsScan(ii(x,y));
        }
    }
}
 
int main() {
    int t;
    scanf("%d",&t);
    ii start;
    bool gotStart;

    while(t--){
        gotStart=false;
        scanf("%d %d\n",&C,&R);
        FOR(i,R){
            FOR(j,C){
                scanf("%c",&laby[i][j]);
                if(!gotStart && laby[i][j]=='.'){               /*Find position where to start*/
                    start = ii(i,j);
                    gotStart=true;
                }
            }
            scanf("\n");
        }
        
        memset(visited,DFS_WHITE,sizeof(visited));

        dist[start.first][start.second]=0;                                  /* First Iteration*/
        maxm=0;
        dfsScan(start);
        // printf("mamm= %d => %d %d\n",maxm,maxPos.first,maxPos.second );
        // printf("%d\n",)

        if(maxm!=0){
            memset(visited,DFS_WHITE,sizeof(visited));                      /*Second Iteration*/
            dist[maxPos.first][maxPos.second] = 0;
            maxm=0;
            dfsScan(maxPos);
        }

        printf("Maximum rope length is %d.\n",maxm);
        /*FOR(i,R){
            FOR(j,C)
                printf("%c",laby[i][j]);
            cout<<endl;
        }*/
    }
    return 0;
}