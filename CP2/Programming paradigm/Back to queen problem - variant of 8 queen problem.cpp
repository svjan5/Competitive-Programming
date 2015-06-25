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

int givenrow[8],row[8],lineCounter,minMove;
int chess[8][8];

bool place(int r, int c) {
        for (int prev = 0; prev < c; prev++)                                    /*check previously placed queens */
                if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))    /*share same row or same diagonal -> infeasible*/
                        return false;
        return true; 
}

void backtrack(int c) {
        if (c == 8) {
                int total=0;
                FOR(i,8){
                        if(givenrow[i] != row[i])
                                total++;
                }
                // printf("possible -> %d\n",total );
                if(total < minMove)
                        minMove = total;
        }

        for (int r = 0; r < 8; r++){                                            /*try all possible row*/
                if (place(r, c)){                                               /*if can place a queen at this col and row*/
                        row[c] = r;
                        backtrack(c + 1);                                       /*put this queen here and recurse*/
                }
        }
}


int main() {
        int t=0;

        while (scanf("%d",&givenrow[0]) != EOF){
                minMove = INF;
                REP(i,1,8) scanf("%d",&givenrow[i]);
                FOR(i,8) givenrow[i]-=1;
                // FOR(i,8) printf("%d ",givenrow[i]);printf("\n");
                memset(row, 0, sizeof row); lineCounter = 0;
                backtrack(0);
                printf("Case %d: %d\n",++t,minMove);
        } 
        return 0;
}