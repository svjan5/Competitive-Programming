#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define REP(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int arr[] = { -7,10,9,2,3,8,8,1 };
int H[10000];
int P[10000];

void seqPrint(int n){
        if(P[n] == -1){
                printf("%d ",arr[n]);
                return;
        }
        seqPrint(P[n]);
        printf("%d ",arr[n]);
}

int LIS(int n){                                                 /*Longest increasing sequence ENDING at i*/
        if(n==0) return H[0] = 1;
        if(H[n] != -1) return H[n];
        int res=-1;

        FOR(i,n)
        if((arr[i]<arr[n]) && LIS(i)+1 > res){
                res = LIS(i)+1;
                P[n] = i;
        }
        
        return H[n] = res;
}

int main() {
        int n = sizeof(arr)/sizeof(arr[0]);
        MEM(H,-1);MEM(P,-1);
        int maxlis = -1,maxBeg;

        FOR(i,n){
                if(LIS(i) > maxlis){
                        maxlis = LIS(i);
                        maxBeg = i;
                }
        }

        FOR(i,n) printf("%d ",H[i]);printf("\n");
        printf("Length of LIS is %d\n",maxlis );
        seqPrint(maxBeg);
        return 0;
}