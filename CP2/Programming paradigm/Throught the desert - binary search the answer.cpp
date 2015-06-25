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

#define EPS 1e-9

vector<pair<long int,pair<char,long int> > > path;

bool simulate(double fuel){
        long int dist,cost;
        char cmmd;
        double initFuel = fuel;
        double rate=0,leak=0,pos=0;
        
        FOR(i,(long int)path.size()){
                dist = path[i].F;
                cmmd = path[i].S.F;
                cost = path[i].S.S;
                fuel -= (dist-pos)/100.0*rate + (dist-pos)*leak;
                pos = dist;
                // printf("Path: %ld => %c %ld\t    ",dist,cmmd,cost );
                // printf("fuel:%lf pos:%ld rate:%ld leak:%ld\n",fuel,pos,rate,leak );
                if(fuel<0) return false;
                switch(cmmd){
                        case 'f':
                                rate = cost;
                                break;
                        case 'l':
                                leak++;
                                break;
                        case 's':
                                fuel = initFuel;
                                break;
                        case 'm':
                                leak=0;
                                break;
                        case 'g':
                                break;
                }
        }
        return true;
}

int main() {
        long int dist,cost,index=0;
        char cmmd[20];
        char c;
        while(scanf("%ld Fuel consumption %ld\n",&dist,&cost) != EOF){
                if(dist == 0 && cost == 0) break;
                path.clear();
                printf("%ld Fuel consumption %ld\n",dist,cost);
                path.pb(mp(dist,mp('f',cost)));
                while(true){
                        scanf("%ld %s",&dist,cmmd);
                        if(strcmp(cmmd,"Fuel")==0){
                                scanf("%s %ld\n",cmmd,&cost);
                                path.pb(mp(dist,mp('f',cost)));
                        }
                        else if(strcmp(cmmd,"Leak")==0){
                                scanf("%c",&c);
                                path.pb(mp(dist,mp('l',0)));
                        }
                        else if(strcmp(cmmd,"Gas")==0){
                                scanf("%s \n",cmmd);
                                path.pb(mp(dist,mp('s',0)));
                        }
                        else if(strcmp(cmmd,"Mechanic")==0){
                                scanf("%c",&c);
                                path.pb(mp(dist,mp('m',0)));
                        }
                        else if(strcmp(cmmd,"Goal")==0){
                                scanf("%c",&c);
                                path.pb(mp(dist,mp('g',0)));
                                printf("%ld %s %ld\n",dist,cmmd,cost);
                                break;
                        }
                        printf("%ld %s %ld\n",dist,cmmd,cost);
                }
                /*FOR(i,(int)path.size()){
                        printf("%ld => %c - %ld\n",path[i].F,path[i].S.F,path[i].S.S );
                }*/

                /*double beg,end,mid,ans=0.0;
                beg = 0; end = 10000.0;

                while(fabs(end-beg) > EPS){
                        mid = (beg+end)/2.0;
                        if(simulate(mid)){
                                end = mid;
                                ans = mid;
                        }
                        else
                                beg=mid;
                }
                if(index==0)printf("%.3lf",ans);
                else printf("\n%.3lf",ans);
                index++;*/
        }

        return 0;
}