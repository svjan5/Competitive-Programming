#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
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


LL arr[320];

// LL mod(LL n){

// }

LL compute(LL n,LL k){
    if(k==1) return 1;

    int m=0;

    for(int i=1; i*i <= k ;i++){
        arr[i-1] = ((k/i) -i +1)%MOD;
        m++;
    }

    
    LL mul1[m];
    LL mul2[m];

    FOR(i,m)
      mul1[i]=1;

    FOR(j,n-2){
        mul2[0]=1;
        FOR1(i,m-1){
            mul2[i] = mul1[i] + mul2[i-1];
        }
            FOR(k,m)
                mul1[k] = mul2[k];
    }


    /*printf("ARR ");
    FOR(i,m)
        printf("%d ",arr[i] );
    cout<<endl;
    FOR(i,n-1){
        FOR(j,m)
            printf("%d ",mul[i][j] );
        cout<<endl;
    }*/

    LL res=0;

    FOR(i,m){
        res = (res%MOD +(mul1[i]%MOD * arr[i]%MOD)%MOD)%MOD;
    }
    
    return res%MOD;
}

int main() {
    int t;
    LL n,k;
    scanf("%d",&t);
 
    while(t--){
        scanf("%lld%lld",&n,&k);

        printf("%lld\n",compute(n,k));

        /*printf("%d\n",m);
        FOR1(i,m){
            printf("%d ",arr[i]);
        }*/

    }

    return 0;
}