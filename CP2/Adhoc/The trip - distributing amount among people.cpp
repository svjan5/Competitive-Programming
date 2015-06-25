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

long double num[1005];

int main() {
        LL n;
        long double sum,avg,possum,negsum;

        while(scanf("%lld",&n)>0 && n>0){
                possum = negsum = sum = 0;
                FOR(i,n) scanf("%Lf",&num[i]);
                FOR(i,n) sum += num[i];
                avg = sum/n;

//(floor((total - payments[i])*100))/100
                FOR(i,n){
                        if(num[i]-avg > 0)
                                possum += (floor((num[i]-avg)*100))/100;
                        else
                                negsum += (floor((avg-num[i])*100))/100;
                }
                // printf("%Lf %Lf %Lf\n",avg,possum,negsum );
                printf("$%.2Lf\n",max(possum,negsum));
        }

        return 0;
}