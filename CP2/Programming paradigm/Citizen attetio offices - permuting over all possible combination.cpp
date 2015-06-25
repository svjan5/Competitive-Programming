#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define REP11(i,a,b) for(i=a;i<=b;i++)
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

map<int,ii> coord;
vector<pair<ii,int> > vec(25);

int main() {
        int t,n,index=0;
        map<int,ii>::iterator it;
        FOR(i,5) FOR(j,5) coord[index++] = ii(i,j);
        /*for(it=coord.begin();it!=coord.end();it++){
                printf("%d -> (%d,%d)\n",it->F,it->S.F,it->S.S);
        }*/

        scanf("%d",&t);
        while(t--){
                scanf("%d",&n);
                int a,b,c;
                int res[5];
                vec.clear();
                FOR(i,n){
                        scanf("%d%d%d",&a,&b,&c);
                        vec[i] = (mp(ii(a,b),c));
                }
                /*FOR(i,n) printf("%d %d %d\n",vec[i].F.F,vec[i].F.S,vec[i].S);
                printf("\n");*/

                int ind[6],globalMin=INF,minSum;
                int x,y,dist,distmin;
                REP11(ind[1],0,20) REP11(ind[2],ind[1]+1,21) REP11(ind[3],ind[2]+1,22) REP11(ind[4],ind[3]+1,23) REP11(ind[5],ind[4]+1,24){
                        minSum=0;
                        FOR(j,n){
                                distmin=INF;
                                a = vec[j].F.F;
                                b = vec[j].F.S;
                                c = vec[j].S;
                                FOR1(i,5){
                                        x = coord[ind[i]].F;
                                        y = coord[ind[i]].S;
                                        dist = c*(abs(x-a) + abs(y-b));
                                        if(dist < distmin)
                                                distmin = dist;
                                }
                                minSum += distmin;
                        }
                        if(minSum < globalMin){
                                globalMin = minSum;
                                FOR(i,5) res[i] = ind[i+1];
                        }
                        
                        /*FOR1(i,5) printf("%d ",ind[i]);
                        printf(" globalMin: %d\t\t minSum: %d",globalMin,minSum);
                        printf("\n");*/
                }
                printf("%d",res[0]);
                REP(i,1,5) printf(" %d",res[i]);printf("\n");
        }

        return 0;
}