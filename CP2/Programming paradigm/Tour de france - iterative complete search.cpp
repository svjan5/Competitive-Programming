#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

#define INF 1000000000
#define MOD 1000000007

#define pb push_back
#define mp make_pair

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int front[10];
int rear[10];
double res[100];

int main() {
        int f,r;
        while(scanf("%d",&f)!=EOF){
                if(f==0) break;
                scanf("%d",&r);
                FOR(i,f) scanf("%d",&front[i]);
                FOR(i,r) scanf("%d",&rear[i]);
                int index=0;
                FOR(i,f) FOR(j,r) res[index++] = (double)rear[j] / (double)front[i];
                sort(res,res+index);
                // FOR(i,index) printf("%lf\n",res[i]);
                double spread,maxSpread = 0;
                FOR(i,index-1){
                        spread = res[i+1] / res[i];
                        if(maxSpread < spread)
                                maxSpread = spread;
                }
                printf("%.2lf\n",maxSpread);

                
        }

        return 0;
}