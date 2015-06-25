#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define FOR(i,n) REP(i,0,n)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

#define RIGHT 1
#define LEFT -1

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int len[600];
int sum[600];
int mark[600];
int DP[600][10001];
int taken[600][10001];
int counter,N;

int ferry(int n,int left){
        int right = (n==0) ?N :N-(sum[n-1]-(N-left));
        // printf("N:%d ferry(%d,%d,%d) \n",N,n,left,right );
        if(n>=counter) return 0;
        if(left < len[n] && right < len[n]) return DP[n][left] = 0;
        if(DP[n][left]!=-1) return DP[n][left];

        if(left < len[n] && right >= len[n] ) {taken[n][left] = RIGHT;return DP[n][left] = ferry(n+1,left)+1;}
        if(left >= len[n] && right < len[n] ) {taken[n][left] = LEFT;return DP[n][left] = ferry(n+1,left-len[n])+1;}

        int res1 = ferry(n+1,left-len[n])+1;
        int res2 = ferry(n+1,left)+1;

        if(res1 > res2){
                taken[n][left] = LEFT;
                DP[n][left] = res1;
        }
        else{
                taken[n][left] = RIGHT;
                DP[n][left] = res2;
        }
        return DP[n][left];
}

void printChoice(int res,int n,int left){
        if(n >= counter) return;
        if(res == 0) return;

        if(taken[n][left] == LEFT){
                printf("port\n");
                printChoice(res-1,n+1,left-len[n]);
        }
        else{
                printf("starboard\n");
                printChoice(res-1,n+1,left);
        }
}

int main() {
        int t,res;
        scanf("%d",&t);
        while(t--){
                scanf("%d",&N);N *= 100;
                counter=0;

                while(scanf("%d",&len[counter])!=EOF){
                        if(len[counter] == 0) break;
                        if(counter == 0) sum[0] = len[0];
                        else sum[counter] = len[counter] + sum[counter-1];
                        counter++;
                }

                MEM(DP,-1);MEM(taken,0);
                printf("%d\n",res=ferry(0,N));
                if(DP[0][N] != 0) printChoice(res,0,N);
                if(t!=0) printf("\n");
        }
        return 0;
}