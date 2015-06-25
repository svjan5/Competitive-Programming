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
int seq[10000][10000];
string A,B;

/*input 
1
ABAZDC
BACBAD
*/
/* DP[i][j] => LCS for A[1..i] & B[1..j] */

void printSeq(int i,int j,int res){
        if(res==0) return;
        if(seq[i][j] == 0){
                printSeq(i-1,j-1,res-1);
                printf("%c",B[j-1]);
        }
        else if(seq[i][j] == -1)
                printSeq(i-1,j,res);
        else
                printSeq(i,j-1,res);
}

int main() {
        int t;
        scanf("%d",&t);
        while(t--){
                scanf("\n");
                getline(cin,A);
                getline(cin,B);
        
                int n = A.length();
                int m = B.length();


                // Base case
                FOR(i,n) DP[i][0] = 0;
                FOR(j,m) DP[0][j] = 0;

                LOOP(i,1,n){
                        LOOP(j,1,m){
                                if(A[i-1] == B[j-1]){
                                        DP[i][j] = DP[i-1][j-1] + 1;
                                        seq[i][j] = 0;
                                }
                                else{
                                        if(DP[i-1][j] > DP[i][j-1]){
                                                DP[i][j] = DP[i-1][j];
                                                seq[i][j] = -1;
                                        }
                                        else{
                                                DP[i][j] = DP[i][j-1];
                                                seq[i][j] = 1;
                                        }

                                }
                        }
                }

                printf("%d\n",DP[n][m]);
                LOOP(i,0,n){LOOP(j,0,m) printf("%4d ",DP[i][j]);printf("\n");}
                printf("\n");
                LOOP(i,0,n){LOOP(j,0,m) printf("%4d ",seq[i][j]);printf("\n");}

                printSeq(n,m,DP[n][m]);
        }
        return 0;
}