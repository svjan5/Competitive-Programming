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
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int arr[10000];
int H1[10000];
int H2[10000];
int N;

int LIS(int n){                                         /*Finds longest increasing sequence STARTING from i*/
        if(n==N-1) return H1[n] = 1;
        if(H1[n] != -1) return H1[n];
        int res=1;

        REP(i,n+1,N)
        if((arr[i]>arr[n]) && LIS(i)+1 > res)
                res = LIS(i)+1;

        return H1[n] = res;
}

int LDS(int n){                                         /*Finds longest decreasing sequence STARTING from i*/
        if(n==N-1) return H2[n] = 1;
        if(H2[n] != -1) return H2[n];
        int res=1;

        REP(i,n+1,N)
        if((arr[i]<arr[n]) && LDS(i)+1 > res)
                res = LDS(i)+1;

        return H2[n] = res;
}

int main() {
        int t;
        scanf("%d",&t);
        while(t--){
                scanf("%d",&N);
                FOR(i,N) scanf("%d",&arr[i]);
                // FOR(i,N) printf("%d ",arr[i]);printf("\n");
                MEM(H1,-1);MEM(H2,-1);

                FOR(i,N) LIS(i);
                FOR(i,N) LDS(i);
                
                int maxVal=0;
                FOR(i,N) maxVal = (maxVal < (H1[i]+H2[i]-1)) ?(H1[i]+H2[i]-1) :maxVal;

                printf("%d\n",maxVal);
                // FOR(i,N) printf("%d ",H1[i]);printf("\n");
                // FOR(i,N) printf("%d ",H2[i]);printf("\n");
        }
        return 0;
}