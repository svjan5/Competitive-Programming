#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define FOR(i,n) LOOP(i,0,n-1)
#define FOR1(i,n) LOOP(i,1,n)
#define LOOP(i,a,b) for(int i=a;i<=b;i++)
#define RLOOP(i,a,b) for(int i=a;i>=b;i--)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int a[10000];
int DP[10000];
int seq[10000];

int main() {
        int t,n,P;
        scanf("%d",&t);
        while(t--){
                scanf("%d",&n);
                FOR(i,n) scanf("%d",&a[i]);
                scanf("%d",&P);

                sort(a, a+n);
                // Base case
                DP[0] = 0;
                seq[0] = -1;

                LOOP(i,1,P){
                        DP[i] = INF;
                        FOR(j,n){
                                if(i-a[j] < 0) break;
                                if(DP[i] > DP[i-a[j]]) {
                                        DP[i] = DP[i-a[j]];
                                        seq[i] = j;
                                }
                        }
                        DP[i] += 1;
                }

                LOOP(i,0,P) printf("%d ",DP[i]);
                printf("\n");
                LOOP(i,0,P) printf("%d ",seq[i]);


                int i = P;
                printf("\n");
                while(i>0){
                        printf("%d ",a[seq[i]]);
                        i -= a[seq[i]];
                }
        }
        return 0;
}