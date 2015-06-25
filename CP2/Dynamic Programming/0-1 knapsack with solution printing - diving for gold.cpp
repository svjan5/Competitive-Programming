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

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int DP[101][1001];
int taken[101][1001];

int wt[30];
int val[30];
int maxVal,maxSeq;

int Knapsack(int n,int W){
        if(n<0) return 0;
        if(W==0) return 0;
        if(DP[n][W]!=-1) return DP[n][W];
        if(wt[n] > W) return DP[n][W] = Knapsack(n-1,W);
        int res1 = Knapsack(n-1,W);
        int res2 = Knapsack(n-1,W-wt[n]) + val[n];
        taken[n][W] = (res2 > res1) ?1 :0;
        DP[n][W] = max(res1,res2);
        return DP[n][W];
}

int main() {
        int t,w,n;
        bool blnk = false;
        while(scanf("%d %d %d",&t,&w,&n)!=EOF){
                if(blnk) printf("\n"); blnk=true;

                FOR(i,n) scanf("%d %d",&wt[i],&val[i]);
                FOR(i,n) wt[i] *= w*3;
                MEM(DP,-1);MEM(taken,0);

                printf("%d\n",Knapsack(n-1,t));
                int mark[n];MEM(mark,0);
                int count=0;

                for(int i=n-1,j=t;i>=0;i--){
                        if(taken[i][j]){
                                mark[i] = 1;
                                count++;
                                j -= wt[i];
                        }
                }
                printf("%d\n", count);
                FOR(i,n) if(mark[i]) printf("%d %d\n",wt[i]/3/w,val[i]);
        }
        return 0;
}