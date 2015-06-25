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
typedef vector<int> vi;)


/*NOTE: 
    Update operation adds value to range it doesn't replace it 
    Index begins from 0
*/

class Fenwick{
        int *m, *mt, N;
        public:
        Fenwick(int n){
                N = n;
                m = new int[N];
                mt = new int[N];
                memset(m, 0, sizeof(int)*N);
                memset(mt, 0, sizeof(int)*N);
        }

        Fenwick(int a[], int n){
                N = n;
                m = new int[N];
                mt = new int[N];
                memset(m, 0, sizeof(int)*N);
                memset(mt, 0, sizeof(int)*N);
                for(int i=0;i<N;++i){
                        m[i] += a[i];
                        if((i|(i+1))<N) m[i|(i+1)] += m[i];
                }
        }

        void range_update(int r, int d){
                if(r<0) return ;
                for(int i=r;i>=0;i=(i&(i+1))-1) mt[i] += d;
                for(int i=r|(r+1);i<N;i|=i+1) m[i] += d*(r-(i&(i+1))+1);
        }

        void range_update(int l, int r, int d){
                range_update(r, d);
                range_update(l-1, -d);
        }

        int range_query(int r){
                if(r<0) return 0;
                int res = 0;
                for(int i=r;i>=0;i=(i&(i+1))-1) res += m[i] + mt[i]*(i-(i&(i+1))+1);
                for(int i=r|(r+1);i<N;i|=i+1) res += mt[i]*(r-(i&(i+1))+1);
                return res;
        }

        int range_query(int l, int r){
                return range_query(r) - range_query(l-1);
        }
};

int main()  {
        Fenwick FT(10);
        FOR(i,10) printf("%d ",FT.range_query(i,i));
        printf("\n");

        FT.range_update(0,9,1);
        FOR(i,10) printf("%d ",FT.range_query(i,i));
        printf("\n");

        printf("%d\n", FT.range_query(1,8));
        return 0;
}