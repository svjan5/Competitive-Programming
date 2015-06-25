#include <bits/stdc++.h>
using namespace std;

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

int main(){
        int n=292;
        printf("%d\n",last_set_bit(n));
        printf("%d\n",leading_zeros(n));
        printf("%d\n",set_count(n));
        set_bit(n,0);
        printf("%d\n", n);
        reset_bit(n,0);
        printf("%d\n", n);
        if(test_bit(n,0)) printf("YES\n");
        else printf("No\n");
        n = set_all(4);
        show_bits(n);
        flip_bit(n,31);
        show_bits(n);
}
