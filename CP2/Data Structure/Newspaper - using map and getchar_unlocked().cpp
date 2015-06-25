#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define pb push_back
#define mp make_pair

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> ii;

int main() {
    int t,k,n;
    scanf("%d\n",&t);
    map<char,int> cost;
    LL total;

    while(t--){
        total=0;
        cost.clear();
        char c;
        int val;
        
        scanf("%d\n",&k);
        FOR(i,k){
            scanf("%c %d\n",&c,&val);
            cost.insert(mp(c,val));
        }

        scanf("%d\n",&n);
        FOR(i,n){
            c = getchar_unlocked();
            while(c!='\n' && c!=EOF){                   //c!=EOF is for last input line
                total += cost[c];
                c = getchar_unlocked();
            }
        }

        double dollars= total/100.0;
        printf("%.2lf$\n",dollars);

        /*map<char,int>:: iterator it;
        for(it=cost.begin();it!=cost.end();it++)
            printf("%c %d\n",it->F,it->S );*/

    }
    return 0;
}