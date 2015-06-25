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

int mor[1000];
int aft[1000];

int main() {
        int n,d,r;
        while(scanf("%d %d %d\n",&n,&d,&r)!=EOF){
                if(!n && !d && !r) break;
                FOR(i,n) scanf("%d",&mor[i]);
                FOR(i,n) scanf("%d",&aft[i]);

                sort(mor,mor+n);
                sort(aft,aft+n);

                int otcost=0;
                int mtime,atime,total;
                FOR(i,n){
                        mtime = mor[i];
                        atime = aft[n-i-1];
                        total = mtime + atime;
                        if(total > d)
                                otcost += (total - d)*r;
                }
                printf("%d\n",otcost);
        }
        return 0;
}