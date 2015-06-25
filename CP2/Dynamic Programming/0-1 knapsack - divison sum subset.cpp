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

int N,Q,M,D;
LL seq[201];
int DP[201][11];

int solve(int n,int m,LL sum){
        if(n < m) return 0;
        if(m == 0) return (sum%D == 0) ?1 :0;
        return solve(n-1,m,sum) + solve(n-1,m-1,sum+seq[n-1]);
}

int main() {
        int index=1;
        while(scanf("%d %d",&N,&Q)!=EOF){
                if(N==0 && Q==0) break;
                printf("SET %d:\n",index++);
                FOR(i,N) scanf("%lld",&seq[i]);
                FOR(i,Q){
                        scanf("%d %d",&D,&M);
                        MEM(DP,-1);
                        printf("QUERY %d: %d\n",i+1,solve(N,M,0));
                }
        }
        return 0;
}