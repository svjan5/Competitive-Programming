#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

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

int arr[101];

inline int getint(){
    int num=0;
    char c=getchar_unlocked();
    while(!(c>='0' && c<='9'))
        c=getchar_unlocked();
 
    while(c>='0' && c<='9'){
        num=(num<<3)+(num<<1)+(c-'0');
        c=getchar_unlocked();
    }
    return num;
}

int main() {
    int n;

    while(scanf("%d",&n)){
        MEM(arr,0);
        if(n==0)
            break;

        int temp;

        FOR(i,n){
            temp = getint();
            arr[temp]++;
        }

        bool enteredOnce=false;

        FOR1(i,100){
            if(arr[i]!=0 && !enteredOnce){
                printf("%d",i);
                FOR(i,arr[i]-1)
                    printf(" %d",i);

                enteredOnce=true;
                continue;
            }

            FOR(j,arr[i]){
                printf(" %d",i);
            }
        }
        cout<<endl;
        
    }
    return 0;
}