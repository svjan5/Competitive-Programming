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

int max(int x,int y,int z){
        if(x>=y && x>=z) return x;
        else if(y>=x && y>=z) return y;
        else return z;
}

class SegmentTree {         
        private: 
                vi st, A;int n;
                int left (int p) { return p << 1; }                     
                int right(int p) { return (p << 1) + 1; }
                void build(int p, int L, int R) {
                        if (L == R) st[p] = L;
                        else {
                              int mid = (L+R)/2;
                              build(left(p),L,mid);
                              build(right(p),mid+1,R);
                              int p1 = st[left(p)];int p2 = st[right(p)];
                              st[p] = (A[p1] >= A[p2]) ? p1 : p2;
                        } 
                }
                int rmq(int p, int L, int R, int i, int j) {
                        if (i >  R || j <  L) return -1;                
                        if (L >= i && R <= j) return st[p];             
                        int mid = (L+R)/2;
                        int p1 = rmq(left(p) , L ,mid,i,j);
                        int p2 = rmq(right(p),mid+1,R,i,j);
                        if (p1 == -1) return p2;
                        if (p2 == -1) return p1;
                        return (A[p1] >= A[p2]) ? p1 : p2;
                }
                int update_point(int p, int L, int R, int idx, int new_value) {
                        int i = idx, j = idx;
                        if (i > R || j < L) return st[p];
                        if (L == i && R == j){ 
                                A[i] = new_value;
                                return st[p] = L;
                        }
                        int p1, p2,mid = (L+R)/2;;
                        p1 = update_point(left(p) ,   L ,mid ,idx, new_value);
                        p2 = update_point(right(p), mid+1, R ,idx, new_value);
                        return st[p] = (A[p1] >= A[p2]) ? p1 : p2;
                }
        public:
                SegmentTree(const vi &_A) {
                        A = _A; n = (int)A.size();              
                        int x = (int)(ceil(log2(n)));           
                        int max_size = 2*(int)pow(2, x) - 1;    
                        st.assign(max_size, 0);                 
                        build(1, 0, n - 1);                     
                }
                int rmq(int i, int j) {return rmq(1, 0, n - 1, i, j);}
                int update_point(int idx, int new_value) {return update_point(1, 0, n - 1, idx, new_value);}
                void printAll(){
                    printf("Segment tree\n");
                    FOR(i,n) printf("%d ",st[i]);
                    printf("\n");
                }
};


int a[100001];
int cnt[100001];
int start[100001];

int main() {
        int n,q;

        while(scanf("%d",&n) != EOF){
                if(n==0) break;
                scanf("%d\n",&q);
                map<int,int> countmap;
                FOR(i,n){ 
                        scanf("%d",&a[i]);
                        if(countmap.count(a[i]) != 0)
                                countmap[a[i]] += 1;
                        else
                                countmap[a[i]] = 1;
                }
                start[0]=0;
                REP(i,1,n){
                        if(a[i-1]==a[i])
                                start[i] = start[i-1];
                        else
                                start[i] = i;
                }

                FOR(i,n) cnt[i] = countmap[a[i]];
                vi A(cnt,cnt+n);
                SegmentTree st(A);
                /*st.printAll();*/
                // FOR(i,n) printf("%d ", A[i]);printf("\n");
                // FOR(i,n) printf("%d ", cnt[i]);printf("\n");
                // FOR(i,n) printf("%d ", start[i]);printf("\n");

                int cnt1,cnt2,cnt3,i,j;
                while(q--){
                        scanf("%d %d\n",&i,&j);i--;j--;

                        if(a[i]==a[j]) 
                                printf("%d\n",j-i+1);
                        else{
                                cnt1 = cnt[i] + start[i] -i;
                                cnt2 = j - start[j] + 1;
                                cnt3 = st.rmq(start[i] + cnt[i],start[j]-1);
                                cnt3 = (cnt3>=0)?cnt[cnt3]:cnt3;
                                // printf("%d %d %d\n",cnt1,cnt2,cnt3);
                                printf("%d\n",max(cnt1,cnt2,cnt3));
                        }
                }

        }

        return 0;
}