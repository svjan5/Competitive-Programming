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

int arr[10002][10002];
int pos[1002];
int val[1002];

int main() {

        int n,m,r,ele;

        while(scanf("%d %d\n",&m,&n)!=EOF){
                MEM(arr,0);
                FOR1(i,m){
                        scanf("%d",&r);
                        FOR1(j,r) scanf("%d",&pos[j]);
                        FOR1(j,r){
                                scanf("%d",&ele);
                                arr[i][pos[j]] = ele; 
                        }
                }
                
                FOR1(i,m){
                        for(int j=i;j<=n || j<=m;j++){
                                swap(arr[i][j],arr[j][i]);
                        }
                }
                /*FOR1(i,n){
                        FOR1(j,m)
                                printf("%d ",arr[i][j]);
                        printf("\n");
                }*/

                MEM(pos,0);
                MEM(val,0);
                int index;

                printf("%d %d\n",n,m);
                FOR1(i,n){
                        index=0;
                        FOR1(j,m){
                                if(arr[i][j] != 0){
                                        pos[index] = j;
                                        val[index] = arr[i][j];
                                        index++;
                                }
                                
                        }
                        if(index == 0) printf("0\n\n");
                        else{
                                printf("%d",index);
                                FOR(k,index) printf(" %d",pos[k]);
                                printf("\n");
                                FOR(k,index-1) printf("%d ",val[k]);
                                printf("%d\n",val[index-1]);
                        }

                }
        }

        return 0;
}