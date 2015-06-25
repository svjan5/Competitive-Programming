#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define INF 1000000000

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

int main() {
    int n;

    while(scanf("%d",&n)){
        map<vi,int> mp;
        map<vi,int>::iterator it;

        if(n==0) break;

        FOR(i,n){
            vi vec(5);
            scanf("%d%d%d%d%d",&vec[0],&vec[1],&vec[2],&vec[3],&vec[4]);
            sort(vec.begin(),vec.end());
            if(mp.count(vec) ==0)
                mp[vec]=1;
            else
                mp[vec]++;
        }

        /*for(it=mp.begin();it!=mp.end();it++){
            FOR(i,5)
                printf("%d ",it->F[i]); 

            printf("=> %d\n",it->S);

        }*/

        int max=0,count=0;
        for(it=mp.begin();it!=mp.end();it++){
            if(max<it->S){
                max=it->S;
                count=max;
            }
            else if(max==it->S){
                count += max;
            }
        }

        printf("%d\n",count);
    }

    return 0;
}