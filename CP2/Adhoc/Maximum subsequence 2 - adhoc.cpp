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

int main() {
        int n,a;
        int sum,len;
        vi vec;

        while(scanf("%d",&n)!=EOF){
                if(n==0) break;
                vec.clear();
                sum=0;len=0;

                FOR(i,n){
                        scanf("%d",&a);
                        if(a==0) continue;
                        vec.pb(a);
                        len++;
                        sum+=a;
                }
                if(sum == 0) printf("0");
                else{
                        FOR(i,len-1) printf("%d ",vec[i]);
                        printf("%d",vec[len-1]);    
                }
                printf("\n");
                // printf("\nmaxLen:%d maxSum:%d\n",maxLen,maxSum );
        }

        return 0;
}