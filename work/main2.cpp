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

int lis[100000];
int arr[100000];
int n;

int LIS(){
	lis[0] = 1;
	REP(i,1,n){
		lis[i] = 0;
		FOR(j,i) if(lis[j]>lis[i] && arr[j]<=arr[i]) lis[i] = lis[j];
		lis[i]++;
	}
	return lis[n-1];
}

int main() {
        int t;
        scanf("%d",&t);
        while(t--){
        	scanf("%d",&n);
                FOR(i,n) scanf("%d",&arr[i]);
                printf("LIS = %d\n",LIS());
                FOR(i,n) printf("%d ",lis[i]);printf("\n");
        }
        return 0;
}