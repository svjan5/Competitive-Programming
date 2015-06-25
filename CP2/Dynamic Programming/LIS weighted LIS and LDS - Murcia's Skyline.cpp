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

int H1[10000];
int H2[10000];
int arr[10000];
int wt[10000];
int N;

int LIS(int n){
        if(n==N-1) return H1[n] = wt[n];
        if(H1[n] != -1) return H1[n];
        int res=wt[n];

        for(int i=n+1;i<N;i++)
        if((arr[i]>arr[n]) && LIS(i)+wt[n] > res)
                res = LIS(i)+wt[n];
        
        return H1[n] = res;
}

int LDS(int n){
        if(n==N-1) return H2[n] = wt[n];
        if(H2[n] != -1) return H2[n];
        int res=wt[n];

        for(int i=n+1;i<N;i++)
        if((arr[i]<arr[n]) && LDS(i)+wt[n] > res)
                res = LDS(i)+wt[n];
        
        return H2[n] = res;
}

int main() {
        int t,index=1;
        scanf("%d",&t);
        while(t--){
                scanf("%d",&N);
                FOR(i,N) scanf("%d",&arr[i]);
                FOR(i,N) scanf("%d",&wt[i]);
                MEM(H1,-1);MEM(H2,-1);
                int maxlis=0,maxlds=0;
                FOR(i,N) maxlis = (maxlis < LIS(i)) ?LIS(i) :maxlis;
                FOR(i,N) maxlds = (maxlds < LDS(i)) ?LDS(i) :maxlds;

                if(maxlis >= maxlds)
                        printf("Case %d. Increasing (%d). Decreasing (%d).\n",index++,maxlis,maxlds);
                else
                        printf("Case %d. Decreasing (%d). Increasing (%d).\n",index++,maxlds,maxlis);
                // FOR(i,N) printf("%d ",H1[i]);printf("\n");
                // FOR(i,N) printf("%d ",H2[i]);printf("\n");
        }
        return 0;
}