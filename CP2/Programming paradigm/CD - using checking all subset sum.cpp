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

inline  int last_set_bit    (int n){ return (!n) ?-1 : __builtin_ctz(n);}
inline  int leading_zeros   (int n){ return (!n) ?32 : __builtin_clz(n);}
inline  int set_count       (int n){ return __builtin_popcount(n);}
inline void set_bit  (int &n,int i){ n |= 1<<i;}
inline void reset_bit(int &n,int i){ n &= ~(1<<i);}
inline bool test_bit  (int n,int i){ return (n & (1<<i))!=0;}
inline int  set_all      (int size){ return pow(2,size)-1;}
inline void flip           (int &n){ n = ~n;}
inline void show_bits       (int n){ for(int i=31;i>=0;i--) printf("%d",(test_bit(n,i))?1:0);printf("\n");}


int cd[20];

int main() {
        int n,m;
        while(scanf("%d",&n)!=EOF){
                scanf("%d",&m);
                FOR(i,m) scanf("%d",&cd[i]);
                // printf("%d\n",n-solve(m-1,n,counter));
                // printf("counter :%d\n", counter);

                int minDiff=INF,diff,sum;
                int seq;
                for(int counter=0;counter <= set_all(m);counter++){
                        sum = 0;
                        FOR(j,m){
                                if(test_bit(counter,j))
                                        sum += cd[j];
                        }
                        if(sum <= n){
                                diff = n - sum;
                                if(diff < minDiff){
                                        minDiff = diff;
                                        seq = counter;
                                }
                        }
                }
                FOR(j,m) if(test_bit(seq,j)) printf("%d ",cd[j]);
                printf("sum:%d\n", n - minDiff);

        }

        return 0;
}