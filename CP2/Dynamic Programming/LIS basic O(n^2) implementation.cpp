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

int DP[100];
int prev[100];
int arr[] = {-7,10,9,2,3,8,8,1};

void seqPrint(int n){
        if(prev[n] == -1){
                printf("%d ",arr[n]);
                return;
        }
        seqPrint(prev[n]);
        printf("%d ",arr[n]);
}

int main() {
        int N = sizeof(arr)/sizeof(int);
        int maxLength = 1, bestEnd = 0;
        DP[0] = 1;
        prev[0] = -1;

        for (int i = 1; i < N; i++){
                DP[i] = 1;
                prev[i] = -1;
                for (int j = i - 1; j >= 0; j--) 
                        if (DP[j] + 1 > DP[i] && arr[j] < arr[i]){
                                DP[i] = DP[j] + 1;
                                prev[i] = j;
                        }

                if (DP[i] > maxLength){
                        bestEnd = i;
                        maxLength = DP[i];
                }
        }

        printf("LIS: %d\n",arr[bestEnd]);
        seqPrint(bestEnd);printf("\n");
        return 0;
}