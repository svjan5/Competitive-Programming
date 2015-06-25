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

inline int max(int a,int b,int c){
        if(a>b && a>c) return a;
        if(b>c && b>a) return b;
        else return c;
}

inline int min(int a,int b,int c){
        if(a<b && a<c) return a;
        if(b<c && b<a) return b;
        else return c;
}


int main() {
        int t;
        scanf("%d",&t);
        while(t--){
                string A,B;
                scanf("\n");
                getline(cin,A);
                getline(cin,B);
        
                int n = A.length();
                int m = B.length();

                // Base case
                DP[0][0] = 0;              /*empty string requires 0 alignment*/
                LOOP(i,1,m) DP[0][i] = i; /*Filling gap pentalty*/
                LOOP(i,1,n) DP[i][0] = i;

                LOOP(i,1,n){
                        LOOP(j,1,m){
                                DP[i][j] = min(    
                                                DP[i-1][j] + 1,
                                                DP[i][j-1] + 1,
                                                DP[i-1][j-1] + ((A[i-1]==B[j-1]) ?0 :1)
                                           );
                        }
                }
                FOR(i,n+1){FOR(j,m+1) printf("%4d ",DP[i][j]);printf("\n");}
                printf("%d\n", DP[n][m]);
        }
        return 0;
}