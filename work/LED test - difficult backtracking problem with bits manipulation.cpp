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

/*
gfedcba
0 - 0111111 - 63 
1 - 0000110 - 6
2 - 1011011 - 91
3 - 1001111 - 79
4 - 1100110 - 102
5 - 1101101 - 109
6 - 1111101 - 125
7 - 0000111 - 7
8 - 1111111 - 127
9 - 1101111 - 111
*/
int bin[10] = {63,6,91,79,102,109,125,7,127,111};
int arr[11];
int n;

bool checkLEDassumption(int led,int i){
        if( ((~led) & arr[i]) == 0)
                return true;
        else
                return false;
}

bool solve(int num,int i,int led){
        // printf("Solve(%d,%d,%d)\n",num,i,led);
        
        if(i==n) return true;

        if(!checkLEDassumption(led,i)) 
                return false;


        int seq = bin[num-1];
        seq &= led;

        if((arr[i] & ~seq) != 0)
                return false;

        led &= ~(seq & (~arr[i]));
        

        // printf("arr: "); show_bits(arr[i]);
        // printf("bin: "); show_bits(bin[num-1]);
        // printf("led: "); show_bits(led);
        // printf("seq: "); show_bits(seq);

        return solve(num-1,i+1,led);
        /*if((seq & (~arr[i])) == 0)
        else{
                return solve(num-1,i+1,led);
        }*/
}

int main() {
        int num;
        char c;
        while(scanf("%d\n",&n)!=EOF){
                if(n==0) break;
                FOR(i,n){
                        num=0;
                        FOR(j,7){
                                scanf("%c",&c);
                                if(c == 'Y') set_bit(num,j);
                                // printf("%c",c);
                        }
                        arr[i]=num;
                        scanf("%c",&c);
                }

                bool res = false;
                bool temp;
                for(int i=10;i >= n;i--){
                        temp = solve(i,0,set_all(7));
                        // printf("solve(%d) returned: %d\n",i,temp );
                        res = res|temp;
                }
                // res = solve(10,0,set_all(7));
                if(res) printf("MATCH\n");
                else printf("MISMATCH\n");
        }
        return 0;
}