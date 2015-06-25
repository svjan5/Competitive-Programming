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

int arr[100][100];

int main() {
        int n;
        // scanf("%d",&t);
        // while(t--){
                scanf("%d",&n);
                FOR(i,n) FOR(j,n){
                        scanf("%d",&arr[i][j]);
                        if(i > 0) arr[i][j] += arr[i-1][j];
                        if(j > 0) arr[i][j] += arr[i][j-1];
                        if(i>0 && j>0) arr[i][j] -= arr[i-1][j-1];
                }

                int maxSubRect = -INF,subRect;
                FOR(i,n) FOR(j,n) REP(k,i,n) REP(l,j,n){
                        subRect = arr[k][l];
                        if(i>0) subRect -= arr[i-1][l];
                        if(j>0) subRect -= arr[k][j-1];
                        if(i>0 && j>0) subRect += arr[i-1][j-1];
                        maxSubRect = (subRect > maxSubRect) ?subRect :maxSubRect;
                }
                printf("%d\n",maxSubRect);

        // }
        return 0;
}