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

int arr[100][100];
int n;

int kadane(int *temp,int &beg,int &end){
        int sum,maxSum;
        maxSum = temp[0];sum = temp[0];
        beg = 0;end=0;
        bool newstart;
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
        int t;
        // scanf("%d",&t);
        // while(t--){
                scanf("%d",&n);
                FOR(i,n) FOR(j,n){
                        scanf("%d",&arr[i][j]);
                        if(i>0) arr[i][j] += arr[i-1][j];
                }

                int temp[n],left,end;
                int sum,maxSum=-INF;

                FOR(i,n) REP(j,i,n){
                        if(i>0) FOR(k,n) temp[k] = arr[j][k] - arr[i-1][k];
                        else FOR(k,n) temp[k] = arr[j][k];
                        sum = kadane(temp,left,end);
                        if(sum > maxSum){
                                maxSum = sum;
                        }
                }
                printf("%d\n",maxSum);
        // }
        return 0;
}