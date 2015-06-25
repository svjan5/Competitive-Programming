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

double p,q,r,s,t,u;



double func(double x){
        double res = p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
        return res;
}

int main() {
        const double EPS = 0.000000001;
        while(scanf("%lf",&p)!=EOF){
                double beg=0,end=1,x,res,mid;
                scanf("%lf %lf %lf %lf %lf",&q,&r,&s,&t,&u);
                // printf("%lf\n",func(.875));

                if((func(beg)<0 && func(end)<0) || (func(beg)>0 && func(end)>0)){
                        printf("No solution\n");
                        continue;
                }
                if(func(beg) == 0 && func(end) == 0){
                        printf("0.0000\n");
                        continue;
                }
                while(true){
                        mid = (beg+end)/2;
                        x = mid;
                        res = func(x);
                        if((res>0 ?res:-res) < EPS)
                                break;
                        if(res > 0)
                                beg = mid;
                        else
                                end = mid;

                }

                printf("%.4lf\n",x);
        }

        return 0;
}