#include <bits/stdc++.h>
#define INF 10000
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,n) REP(i,1,n)
typedef long long LL;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > iii;
 
int shop[27][27];
int dist[27][27];
int xdest,ydest;
int dr[] = {0,1,-1,0};
int dc[] = {1,0,0,-1};
 
priority_queue<iii> pq;
 
void dijkstra(int xint,int yint){
	int x,y;
	pq.push(make_pair(0,make_pair(xint,yint)));
	dist[xint][yint]=0;
	while(!pq.empty()){
		iii front = pq.top();pq.pop();
		int d=front.first;
		ii u=front.second;
		if(d==dist[u.first][u.second]){
			REP(i,0,3){
				x = u.first+dr[i];
				y = u.second+dc[i];
				if(shop[x][y] != -1){
					if(dist[u.first][u.second]+shop[x][y] < dist[x][y]){
						dist[x][y] = dist[u.first][u.second]+shop[x][y];
						pq.push(make_pair(dist[x][y],make_pair(x,y)));
					}
				}
			}
		}
	}
 
}
 
int main() {
	int r,c;
	int xint,yint;
	char ch;
 
	while(scanf("%d %d\n",&c,&r)){
		if(c==0 && r==0) break;
		memset(shop,-1,sizeof(shop));
		REP(i,0,26) REP(j,0,26) dist[i][j]=10000;
 
		FOR(i,r){
			FOR(j,c){
				scanf("%c",&ch);
				if(ch=='X')
					shop[i][j]=-1;
				else if(ch=='S'){
					shop[i][j]=0;
					xint=i;yint=j;
				}
				else if(ch=='D'){
					shop[i][j]=0;
					xdest=i;ydest=j;
				}
				else{
					shop[i][j] = ch-'0';
				}
			}
			scanf("%c",&ch);
		}
 
		dijkstra(xint,yint);
		printf("%d\n",dist[xdest][ydest]);
 
		/*REP(i,0,r+1){
			REP(j,0,c+1){
				printf("%d ",shop[i][j]);
			}
			printf("\n");
		}*/
 
	}
	return 0;
}