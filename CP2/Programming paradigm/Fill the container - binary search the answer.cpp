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

int ves[1000];
// int con[1000000];
int n,m;

int simulate(int cap){
        int maxcap = -1;
        int con,i=0,filled;
        FOR(j,m){
                // printf("i:%d j:%d max:%d\n",i,j,maxcap );
                con = cap;
                while( ves[i]<=con  && i<n ){
                        con -= ves[i];
                        i++;
                }
                filled = cap-con;
                if(maxcap < filled) 
                        maxcap = filled;
        }

        if(i < n)
                return -1;
        else
                return maxcap;
}

int main() {
        int sum,beg,end,mid,res;
        while(scanf("%d%d",&n,&m)!=EOF){
                sum = 0;
                FOR(i,n){
                        scanf("%d",&ves[i]);
                        sum += ves[i];
                }
                // FOR(i,n) printf("%d ",ves[i]);
                // printf("\n");
                // res = simulate(6);
                beg = sum/m - 1;
                end = sum;
                while(true){
                        mid = (beg+end)/2;
                        res = simulate(mid);
                        if(beg >= end) break;
                        if(res == -1)                  /*Not possible*/
                                beg = mid+1;
                        else
                                end = mid;
                }
                printf("%d\n",res);
        }
        return 0;
}