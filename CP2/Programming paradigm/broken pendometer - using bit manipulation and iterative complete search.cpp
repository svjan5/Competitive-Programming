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

int digits[100][15];

int main() {

        int t,P,n;
        scanf("%d",&t);

        while(t--){
                scanf("%d %d",&P,&n);
                FOR(i,n) FOR(j,P){
                        scanf("%d",&digits[i][j]);
                }
                /*FOR(i,n){FOR(j,P)
                                printf("%d ",digits[i][j]);
                        printf("\n");
                }*/
                int min_need=INF;
                unsigned int counter,max_range = pow(2,P);
                int index,sum;
                vector<int> vec(15);
                set<int> list;
                bool ispossbl;

                for(counter=0;counter < max_range;counter++){
                        index=0;ispossbl = true;
                        vec.clear();list.clear();

                        FOR(j,P){
                                if(counter & (1<<j))
                                        vec[index++] = j;
                        }

                        set<int>::iterator it;
                        FOR(i,n){
                                sum = 0;
                                FOR(j,index)
                                        sum = sum + pow(2,j)*digits[i][vec[j]];

                                if(list.find(sum) == list.end())
                                        list.insert(sum);
                                else{
                                        ispossbl = false;
                                        break;
                                }

                        }

                        if(ispossbl){
                                if(min_need > index)
                                        min_need=index;
                        }

                        /* print the bits
                        FOR(j,P)
                                if(counter & (1<<j)) 
                                        printf("%d ",1);
                                else
                                        printf("%d ",0);*/

                        /*printf("\n");
                        FOR(i,index) printf("%d ",vec[i]);
                        printf("\t\t %d \n",min_need);*/


                        
                }
                printf("%d\n",min_need);
        }

        return 0;
}