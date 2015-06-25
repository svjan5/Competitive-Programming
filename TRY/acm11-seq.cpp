#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define mod 1000000007

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef long long ll;
typedef pair<int,int> ii;
int i,cntmax,cntmin,ans1,j;


ll modular_pow(ll base, ll exponent, int modulus)
{
   ll result = 1;
   while (exponent > 0)
   {
       if (exponent % 2 == 1)
           result = (result * base) % modulus;
       exponent = exponent >> 1;
       base = (base * base) % modulus;
   }
   return result;
}



int a [100002];
int n;
int main() {
    int t;
    scanf("%d",&t);
 
    while(t--){
        cntmax=0,cntmin=0;
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    scanf("%d",&a[i]); 
    

    int maxn = *max_element(a,a+n);
    int minn= *min_element(a,a+n);
    int temp = maxn-minn;

    for(i=0;i<n;i++){
        if(a[i]==maxn)
            cntmax++;
        if(a[i]==minn)
            cntmin++;
    }
    //printf("%d %d\n",cntmin,cntmax);
       int j1=0;
    int ans2=0;
    if((cntmin==cntmax) && (cntmin==n)){
        // = (modular_pow(2,n,mod)%mod-1)%mod;
        ans1=n-1;
        ans2=n-1;
    }

    else{
        ans1 = ((modular_pow(2,cntmax,mod)-1)%mod*(modular_pow(2,cntmin,mod)-1)%mod*(modular_pow(2,(n-(cntmin+cntmax)),mod)-1)%mod);
        //int j1=0;
    int ans2=0;

    for(i=0;i<n;i++){
        for(j=j1;j<n;j++){
            if(abs(a[j]-a[i])==temp){
                ans2=(ans2%mod+(n-j+1)%mod)%mod;
                j1=j;
            }
        }
    }
    }
    /*int j1=0;
    int ans2=0;

    for(i=0;i<n;i++){
        for(j=j1;j<n;j++){
            if(abs(a[j]-a[i])==temp){
                ans2=(ans2%mod+(n-j+1)%mod)%mod;
                j1=j;
            }
        }
    }*/
    printf("%d %d\n",ans1,ans2);
}

    return 0;
}