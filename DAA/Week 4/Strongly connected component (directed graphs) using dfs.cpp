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
#define VER 875714

#define MP make_pair
#define pb push_back
 
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vector<vi> G(VER+1);
vector<vi> Grev(VER+1);
int visit[VER+1];
int finish[VER+1];
int finish_time;

void dfs1st(int u){                     /*First DFS*/
    int v;

    visit[u] = DFS_BLACK;
    FOR(j,(int)Grev[u].size()){
        v = Grev[u][j];
        if(visit[v]==DFS_WHITE){
            dfs1st(v);
        }
    }
    finish_time++;
    finish[finish_time] = u;
}

int cnt;
void dfs2nd(int u){                     /*Second DFS*/
    int v;
    visit[u] = DFS_BLACK;
    FOR(j,(int)G[u].size()){
        v = G[u][j];
        if(visit[v]==DFS_WHITE){
            cnt++;
            dfs2nd(v);
        }
    }
}


int main() {
    int a,b;

    while(scanf("%d%d",&a,&b)!=EOF){        /*Taking input*/
        if(a==0 && b==0)
            break;
		G[a].pb(b);
    }
    
    int u,v;
    FOR1(i,VER){                            /*Computed G reverse for first DFS*/
        u = i;
        FOR(j,(int)G[i].size()){
            v = G[i][j];
            Grev[v].pb(u);
        }
    }

    MEM(visit,DFS_WHITE);
    MEM(finish,0);
    finish_time = 0;

    FOR1(i,VER)                             /*First DFS on Grev*/
        if(visit[i] == DFS_WHITE)
            dfs1st(i);
    
    /*FOR1(i,VER){                          //Finish time of vertices
        printf("%d => %d\n",i,finish[i]);
    }*/

    vi comp;
    MEM(visit,DFS_WHITE);

    for(int i=VER ; i>0 ; i--){             /*Second DFS on G*/
        if(visit[finish[i]] == DFS_WHITE){
            cnt=1;
            dfs2nd(finish[i]);
            comp.pb(cnt);
        }
    }

    sort(comp.begin(),comp.end());          /*Printing the size of components*/
    FOR(i,(int)comp.size()){
        printf("%d \n",comp[i] );
    }
    return 0;
}