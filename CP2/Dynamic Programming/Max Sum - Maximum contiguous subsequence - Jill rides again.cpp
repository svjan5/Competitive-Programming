#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define FOR(i,n) REP(i,0,n)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int arr[20001];
int start[20001];
int H[20001];
int n;

int kadane(int *temp,int &beg,int &end){
        int sum,maxSum;
        maxSum = temp[0];
        beg = 0;end=0;sum = temp[0];
        bool newstart;
        printf("maxSum:%d \n",maxSum );
        REP(i,1,n){
                newstart = true;
                if((sum+temp[i]) >= temp[i]){
                        sum = sum + temp[i];
                        newstart = false;
                }
                else
                        sum = temp[i];
                if(sum > maxSum){
                        if(newstart){
                                beg = i;
                                end = i;
                                maxSum = sum;
                        }
                        else{
                                end = i;
                                maxSum = sum;
                        }
                }
        }
        return maxSum;
}

int main() {
        int t,index=1;
        scanf("%d",&t);
        while(t--){
                scanf("%d",&n);
                arr[0]=0;n--;
                FOR1(i,n) scanf("%d",&arr[i]);
                
                MEM(start,0);

                H[1] = arr[1];
                start[1] = 1;

                REP1(i,2,n){
                        if( (H[i-1]+arr[i]) >= arr[i]){
                                H[i] = H[i-1] + arr[i];
                                start[i] = start[i-1];
                        }
                        else{
                                H[i] = arr[i];
                                start[i] = i;
                        }
                }

                int maxSum=-INF,maxLen=0,maxl,maxr;
                int len;
                FOR1(i,n){
                        len = i-start[i]+1;
                        if(maxSum < H[i]){
                                maxSum = H[i];
                                maxLen = len;
                                maxl = start[i];
                                maxr = i;
                        }
                        else if( (maxSum == H[i]) && (len > maxLen) ){
                                maxLen = len;
                                maxl = start[i];
                                maxr = i;
                        }
                }

                // FOR1(i,n) printf("%d ",H[i]);printf("\n");
                // FOR1(i,n) printf("%d ",start[i]);printf("\n");

                // printf("maxSum:%d\tmaxLen:%d\tmaxl:%d\tmaxr:%d\n",maxSum,maxLen,maxl,maxr );
                if(maxSum < 0) printf("Route %d has no nice parts\n",index++);
                else printf("The nicest part of route %d is between stops %d and %d\n",index++,maxl,maxr+1);
        }
        return 0;
}