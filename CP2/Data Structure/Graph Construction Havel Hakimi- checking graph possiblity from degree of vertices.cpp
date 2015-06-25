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


/*Havel-Hakimi Theorem
        To check from given sequence of degree of vertices
        whether it represents simple graph or not*/

int arr[50000];

int main() {

        int n,num;
        bool isGraph;

        while(scanf("%d",&n)!=EOF && n!=0){

                FOR(i,n) scanf("%d",&arr[i]);           /*Input*/
                vi vec(arr,arr+n);

                isGraph = true;

                /*Condition-1 : d[i] >= n then fail*/
                FOR(i,n) if(vec[i]>=n) isGraph = false;

                /*Condition-2 : if there are odd number of odd degrees then fail*/
                int oddCount=0;
                FOR(i,n)
                        if(vec[i]%2==1)
                                oddCount++;

                if(oddCount%2==1)
                        isGraph= false;

                while(isGraph && vec.size() > 1){
                        n = vec.size();
                
                        /*Condition-3: if negative degree then fail*/
                        FOR(i,n) if(vec[i] < 0){
                                isGraph = false;
                                break;
                        }

                        /*Condition-4: if all degrees 0 then success*/ 
                        int zeroCount=0;
                        FOR(i,n) if(vec[i] == 0) zeroCount++;
                        if(zeroCount == n) break;

                        sort(vec.begin(),vec.end());
                        num = vec.back();
                        vec.pop_back();

                        for(int i=vec.size()-1; num-- && i>=0 ;i--)
                                vec[i]--;
                }

                if(isGraph)
                    printf("Possible\n");
                else
                    printf("Not possible\n");

        }

        return 0;
}