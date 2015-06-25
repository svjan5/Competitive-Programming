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

int n;
int arr[8][8];
int mem[1000][1000];

int solve(int row,int col){
        int minScore = INF,res;
        if(mem[row][col]!=-1) return mem[row][col];
        if(set_count(row) == 1 && set_count(col)==1)
                return mem[row][col]=arr[last_set_bit(row)][last_set_bit(col)];

        FOR(i,n){
                FOR(j,n){
                        if(test_bit(row,i) && test_bit(col,j)){
                                reset_bit(row,i);reset_bit(col,j);
                                res = arr[i][j] + solve(row,col);
                                if(minScore > res)
                                        minScore = res;
                                set_bit(row,i);set_bit(col,j);
                        }
                }
        }
        mem[row][col] = minScore;
        return minScore;
}

int main() {
        int t;
        scanf("%d",&t);
        while(t--){
                scanf("%d",&n);
                FOR(i,n) FOR(j,n) scanf("%d",&arr[i][j]);
                int row=set_all(n),col=set_all(n);
                MEM(mem,-1);
                printf("%d\n",solve(row,col));       
        }
        return 0;
}