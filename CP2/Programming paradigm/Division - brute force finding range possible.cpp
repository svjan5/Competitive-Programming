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

int arr[10];

bool checkDigit(int n){
        int count=0;
        while(n>0){
                count++;
                n = n/10;
        }
        if(count == 5)
                return true;
        else
                return false;
}

bool checkDistinct(int n){
        int d;
        if(!checkDigit(n)) arr[0]=1;

        while(n>0){
                d = n%10;
                n = n/10;
                if(arr[d]==1)
                        return false;
                arr[d]=1;
        }
        return true;
}

int main() {
        int n,num;
        bool exist;
        int count =0;
        while(scanf("%d",&n)!=EOF){
                exist = false;
                if(n==0) break;
                if(count != 0){
                        printf("\n");
                }



                for(int i=1234; i<=98765 ;i++){
                        MEM(arr,0);
                        if(checkDistinct(i)){
                                num = n * i;
                                if(checkDistinct(num) && checkDigit(num)){
                                        printf("%d / %.5d = %d\n",num,i,n);
                                        exist=true;
                                }
                        }
                }

                if(!exist) printf("There are no solutions for %d.\n",n);
                count++;

        }

        return 0;
}