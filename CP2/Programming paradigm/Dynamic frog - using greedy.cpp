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

int rock[1000];

int main() {
        int t,n,cases=1;
        int D,dist;
        char c;
        scanf("%d",&t);

        while(t--){
                scanf("%d %d\n",&n,&D);
                int index=0;
                rock[index++]=0;
                rock[index++]=0;
                FOR(i,n){
                        scanf("%c-%d ",&c,&dist);
                        if(c == 'S')
                                rock[index++] = dist;
                        else{
                                rock[index++] = dist;
                                rock[index++] = dist;   
                        }
                }
                rock[index++] = D;
                rock[index++] = D;
                int maxOdd=0,maxEven=0;
                int diff,curr=0;
                for(int i=0;i<index;i+=2){
                        diff = rock[i]-curr;
                        if(diff > maxEven){
                                maxEven = diff;
                        }
                        curr = rock[i];
                }
                curr =0;
                for(int i=1;i<index;i+=2){
                        diff = rock[i]-curr;
                        if(diff > maxOdd){
                                maxOdd = diff;
                        }
                        curr = rock[i];
                }
                // printf("Even max: %d  Odd max: %d\n",maxEven,maxOdd);
                printf("Case %d: %d\n",cases++,max(maxOdd,maxEven));
        }

        return 0;
}