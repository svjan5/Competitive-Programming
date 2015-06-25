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

int DP[10000][10000];
int dim[10000];

int main() {
        int t,n;
        scanf("%d",&t);
        while(t--){
                scanf("%d",&n);
                FOR1(i,n+1) scanf("%d",&dim[i]);

                // Base case
                FOR(i,n) DP[i][i] = 0;  /*For single matrix no mul needed*/

                LOOP(len,2,n){
                        LOOP(i,1,n+1-len){
                                int j = i-1+len;
                                DP[i][j] = INF;
                                LOOP(k,i,j-1){
                                        DP[i][j] = min( DP[i][j],
                                                        DP[i][k] + DP[k+1][j] + dim[i]*dim[k+1]*dim[j+1]);
                                }
                        }
                }

                FOR1(i,n){FOR1(j,n) printf("%4d ",DP[i][j]);printf("\n");}
                printf("%d\n", DP[1][n]);
        }
        return 0;
}