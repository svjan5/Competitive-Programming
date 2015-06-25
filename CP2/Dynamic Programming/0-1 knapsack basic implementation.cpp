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

int DP[100][1000];
int wt[] = {10, 20, 30};
int val[] = {60, 100, 120};


int Knapsack(int n,int W){
        if(n<0) return 0;
        if(W==0) return 0;
        if(DP[n][W]!=-1) return DP[n][W];
        if(wt[n] > W) return DP[n][W] = Knapsack(n-1,W);
        return DP[n][W] = max(Knapsack(n-1,W),
                             Knapsack(n-1,W-wt[n]) + val[n]);
}

int main() {
        int n = sizeof(wt)/sizeof(int);
        MEM(DP,-1);
        printf("0-1 Knapsack result: %d\n",Knapsack(n-1,50));
        return 0;
}