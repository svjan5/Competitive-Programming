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

int chess[11][11];
int n,m;

int mark(char piece){
    switch(piece){
        case 'k':
            if(m%2==0)
                return m/2*n;
            else if(n%2==0)
                return m*n/2;
            else
                return floor(m/2.0)*floor(n/2.0)+ceil(m/2.0)*ceil(n/2.0);
            break;
        case 'r':
        case 'Q':
            return min(m,n);
        case 'K':
            return ceil(m/2.0)*ceil(n/2.0);
    }
}

int main() {
    int t;
    scanf("%d\n",&t);
    char piece;

    while(t--){
        MEM(chess,0);
        scanf("%c ",&piece);
        scanf("%d %d\n",&n,&m);
        // printf("%d %d\n",n,m );
        printf("%d\n",mark(piece));
    }
    return 0;
}