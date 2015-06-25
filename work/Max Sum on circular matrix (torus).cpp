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
#define FOR1(i,n) REP1(i,1,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int T, N;
int A[500][500];
 
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        
        FOR(i,N) FOR(j,N){
                scanf("%d", &A[i][j]);
                A[i + N][j] = A[i][j + N] = A[i + N][j + N] = A[i][j];
        }

        FOR(i,2*N) FOR(j,2*N){
                if(i > 0) A[i][j] += A[i - 1][j];
                if(j > 0) A[i][j] += A[i][j - 1];
                if(i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
        }

        int ans = -1000000;
        FOR(i,N) FOR(j,N) REP(k,i,i+N) REP(l,j,j+N){
                        int cur = A[k][l];
                        if(i > 0) cur -= A[i-1][l];
                        if(j > 0) cur -= A[k][j-1];
                        if(i > 0 && j > 0) cur += A[i-1][j-1];
                        ans = max(ans, cur);
        }

        printf("%d\n", ans);
    }
}