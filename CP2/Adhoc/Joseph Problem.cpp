#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007


int main(){

    map<int,int>mem;
    int k,p,m,dead,size;
    while ((cin>>k)&&k){

        if(mem[k]){
            cout<<mem[k]<<endl;
            continue;
        }

        p = k*2;

        m = k;                              /*m value cannot be less than k*/
        while(true){
            size=p;                         /*count of number of people present*/
            dead=(m-1)%size;                /*Index of person that is to be killed*/
            while (dead>=k && size>=k){
                size--;
                dead = (dead+m-1)%size;
            }

            if (size==k){                   /*If solution is found then store that result*/
                mem[k]=m;                   /*Storing the result for future use*/
                break;
            }
            m++;                            /*Trying other value of m*/
        }
        cout << m << endl;
    }
}