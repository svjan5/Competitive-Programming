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

int arr[20];
int val[20];

void processPowerSet(int size,int maj){
        /*size of power set of a set with size
        n is (2**n -1)*/
        unsigned int pow_set_size = pow(2, size);
        int counter, j,sum;

        /*Run from counter 000..0 to 111..1*/
        for(counter = 0; counter < pow_set_size; counter++){
                sum=0;
                for(j = 0; j < size; j++){
                        if(counter & (1<<j))
                                sum += arr[j];
                }
                
                if(sum >= maj){
                        // printf("sum: %d => ",sum);
                        for(j = 0; j < size; j++){

                                if(counter & (1<<j)){
                                        // printf("%d ",j+1);
                                        if( ((sum - arr[j]) < maj) && arr[j] < maj )
                                                val[j]++;
                                }
                        }
                        // printf("\t\t");
                        // FOR(i,size) printf("%d ",val[i]);
                        // printf("\n");
                }
        }
}

int main() {
        int t,n,sum,maj;
        scanf("%d",&t);

        while(t--){
                sum=0;
                MEM(val,0);
                scanf("%d",&n);
                FOR(i,n){
                        scanf("%d",&arr[i]);
                        sum += arr[i];
                }
                maj = sum/2 +1;
                processPowerSet(n,maj);
                FOR(i,n) printf("party %d has power index %d\n",(i+1),val[i]);
                printf("\n");
        }

        return 0;
}