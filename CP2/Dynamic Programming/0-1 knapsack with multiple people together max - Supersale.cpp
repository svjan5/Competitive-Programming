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

int DP[1001][31];
int taken[1001][31];
int mark[1001];
int wt[1001];
int val[1001];
int cap[100];

int Knapsack(int n,int W){
        if(n<0) return 0;
        if(W==0) return 0;
        if(DP[n][W]!=-1) return DP[n][W];
        if(wt[n] > W || mark[n]==1) return DP[n][W] = Knapsack(n-1,W);
        return DP[n][W] = max(Knapsack(n-1,W),
                             Knapsack(n-1,W-wt[n]) + val[n]);
}

void markTaken(int n,int W){
        while(n>=0){
                if(taken[n][W]){
                        mark[n] = 1;
                        W -= wt[n];
                }
                n--;
        }
}

int main() {
        int t,n,m;
        scanf("%d",&t);
        while(t--){
                MEM(DP,-1);MEM(mark,0);
                scanf("%d",&n);
                FOR(i,n) scanf("%d %d",&val[i],&wt[i]);
                scanf("%d",&m);
                FOR(i,m) scanf("%d",&cap[i]);
                int total=0;
                FOR(i,m){
                        MEM(taken,0);
                        total += Knapsack(n-1,cap[i]);
                        markTaken(n-1,cap[i]);
                }
                printf("%d\n",total);
        }
        return 0;
}