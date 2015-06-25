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
inline void flip_bit (int &n,int i){ (test_bit(n,i))?reset_bit(n,i) :set_bit(n,i);}
inline int  set_all      (int size){ return pow(2,size)-1;}
inline void flip           (int &n){ n = ~n;}
inline void show_bits       (int n){ for(int i=31;i>=0;i--) printf("%d",(test_bit(n,i))?1:0);printf("\n");}

int bulb[12];

void switch_bulb(int i,int j){
        flip_bit(bulb[i],j-1);
        flip_bit(bulb[i],j);
        flip_bit(bulb[i],j+1);
        flip_bit(bulb[i-1],j);
        flip_bit(bulb[i+1],j);
}

bool check(int n){
        // FOR1(i,10) show_bits(bulb[i]);
        FOR1(i,10){
                if(test_bit(bulb[n],i))
                        return false;
        }
        return true;
}

int solve(int n,int acc){
        // printf("solve(%d,%d) \n",n,acc );
        
        if(acc > 100) return -1;
        if(n == 10){
                if(check(10))
                        return acc;
                else
                        return -1;
        }

        int bits = 0;
        FOR1(i,10){
                if(test_bit(bulb[n],i)){
                        switch_bulb(n+1,i);
                        bits++;
                }
        }

        return solve(n+1,acc+bits);
}

int main() {
        char c;
        char name[100];
        while(scanf("%s\n",name)!=0){
                if(strcmp(name,"end") == 0) break;
                MEM(bulb,0);

                FOR1(i,10){ 
                        FOR1(j,10){
                                scanf("%c",&c);
                                if(c == 'O') set_bit(bulb[i],j);
                        }
                        scanf("%c",&c);
                }
                
                printf("%s ",name);
                // FOR(i,12) show_bits(bulb[i]);
                int temp[12];
                int minSteps = INF,res;
                for(int counter = 0;counter <= set_all(10);counter++){
                        FOR(i,12) temp[i] = bulb[i];

                        FOR(i,10){
                                if(test_bit(counter,i))
                                        switch_bulb(1,i+1);
                        }

                        // FOR(i,12) show_bits(bulb[i]);
                        res = solve(1,set_count(counter));
                        FOR(i,12) bulb[i] = temp[i] ;

                        // printf("res: %d\n",res);
                        if(res == -1) continue;
                        if(res < minSteps)
                                minSteps = res;
                }
                // minSteps = solve(1,0);
                printf("%d\n", minSteps);

        }
        return 0;
}