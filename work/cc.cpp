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

int gcd(int a, int b){
        if (b==0) return a;
        else return gcd(b,a%b);
}

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

class SegmentTree {         
        private: 
                vi st, A;
                int n;
                int left (int p) { return p << 1; }                     
                int right(int p) { return (p << 1) + 1; }

                void build(int p, int L, int R) {                        
                        if (L == R) st[p] = A[L];
                        else {
                              int mid = (L+R)/2;
                              build(left(p),L,mid);
                              build(right(p),mid+1,R);

                              int p1 = st[left(p)];
                              int p2 = st[right(p)];
                              st[p] = gcd(p1,p2);
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
                        return gcd(p1,p2);
                }
                
                int update_point(int p, int L, int R, int idx, int new_value) {
                        int i = idx, j = idx;
                        if (i > R || j < L)
                                return st[p];

                        if (L == i && R == j) {
                                A[i] = new_value;               
                                return st[p] = A[L];
                        }
                        int p1, p2;
                        int mid = (L+R)/2;
                        p1 = update_point(left(p) ,   L ,mid ,idx, new_value);
                        p2 = update_point(right(p), mid+1, R ,idx, new_value);
                        return st[p] = gcd(p1,p2);
                }

        public:
                SegmentTree(const vi &_A) {
                        A = _A; n = (int)A.size();              
                        int x = (int)(ceil(log2(n)));           
                        int max_size = 2*(int)pow(2, x) - 1;    
                        st.assign(max_size, 0);                 
                        build(1, 0, n - 1);                     
                }
                ~SegmentTree() {}

                int rmq(int i, int j) { 
                        return rmq(1, 0, n - 1, i, j);          
                }

                int update_point(int idx, int new_value) {
                    return update_point(1, 0, n - 1, idx, new_value); 
                }
                void printAll(){
                    printf("Segment tree\n");
                    FOR(i,n) printf("%d ",st[i]);
                    printf("\n");
                    delete this;
                }
};
  
int a[100001];

int main() {
        int t,n,q;
        int l,r;
        int leftq,rightq,res;
        scanf("%d",&t);
        while(t--){
                n = getint();
                q = getint();
                FOR(i,n) a[i] = getint();
                vi A(a,a+n);
                SegmentTree st(A);

                FOR(i,q){
                        l = getint();r = getint();
                        l--;r--;
                        leftq = st.rmq(0,l-1);
                        rightq = st.rmq(r+1,n-1);
                        if(leftq == -1) res = rightq;
                        else if(rightq == -1) res = leftq;
                        else res = gcd(leftq,rightq);

                        printf("%d\n",res);
                }
                // FOR(i,n) printf("%d ",st.rmq(i,i) );
                // printf("RMQ(1,1)%d\n", );
                // st.printAll();
        }
        return 0;
}
