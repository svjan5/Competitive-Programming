#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef long long LL;
typedef pair<int,int> ii;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

/* This function calculates (ab)%c */
int modulo(int a,int b,int c){
    LL x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

/* Fermat's test for checking primality, the more iterations the more is accuracy */
bool Fermat(LL p,int iterations){
    if(p == 1){ 									// 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        LL a = rand()%(p-1)+1; 						/* choose a random integer between 1 and p-1 ( inclusive )*/
        if(modulo(a,p-1,p) != 1){ 					/* modulo is the function we developed above for modular exponentiation.	*/
            return false; 							/* p is definitely composite */
        }
    }
    return true; 									/* p is probably prime */
}
 

vector<bool> sieve(int largest){
    vector<bool> is_prime(largest+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= largest; ++i) {
        if (is_prime[i]) {
            for (int j = 2*i; j <= largest; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
	int t,n;
	scanf("%d",&t);
 
	while(t--){
        vector<bool> prime = sieve(10000);
        FOR(i,100){
            if(prime[i])
                printf("%d\n",i);
            
        }
	}
	return 0;
}