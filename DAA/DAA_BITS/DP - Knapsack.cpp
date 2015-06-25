#include <bits/stdc++.h>
using namespace std;

/* Input 
4 8
1 5 3 4 
15 10 9 5
*/

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
int val[10000];
int wt[10000];

int main() {
        int n,W;
        scanf("%d",&n);
        scanf("%d",&W);
        FOR1(i,n) scanf("%d",&wt[i]);
        FOR1(i,n) scanf("%d",&val[i]);

        // base cases
        FOR(i,W) DP[0][i] = 0;  /*capacity = 0*/
        FOR(i,n) DP[i][0] = 0;  /*no item left n=0*/

        LOOP(i,1,n){
                LOOP(j,1,W){
                        if(j < wt[i]) 
                                DP[i][j] = DP[i-1][j];
                        else
                                DP[i][j] = max( DP[i-1][j], 
                                		DP[i-1][j-wt[i]] + val[i]
					      );
                }
        }

        // Display DP table
        FOR(i,n){FOR(j,W) printf("%d ",DP[i][j]);printf("\n");}
        printf("%d\n", DP[n][W]);
        return 0;
}