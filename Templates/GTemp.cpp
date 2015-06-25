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

#define MP make_pair
#define pb push_back
 
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vector<vi > AdjList;
vi dfs_num;
map<int,int> dist;
queue<int> q;
 
void dfs(int u){
	dfs_num[u] = DFS_BLACK;
	printf("%d ",u);
	for(int j=0;j<(int)AdjList[u].size();j++){
		int v=AdjList[u][j];
		if(dfs_num[v]==DFS_WHITE)
			dfs(v);
	}
}
 
void bfs(int s){
	dist[s]=0;
	q.push(s);
 
	while(!q.empty()){
		int u = q.front();q.pop();
		printf("%d ",u);
		for(int j=0;j<(int)AdjList[u].size();j++){
			int v=AdjList[u][j];
			if(!dist.count(v)){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
 
}
 
int main() {
	int t,V,E;
	scanf("%d",&t);
 
	while(t--){
	}
	return 0;
}