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

/**************************************************RANGED MAXIMUM QUERY**************************************************/
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

  
int main() {
        int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
        vi A(arr, arr + 7);                      // copy the contents to a vector
        SegmentTree st(A);

        printf("idx    0, 1, 2, 3, 4,  5, 6\n");
        printf("A is {18,17,13,19,15, 11,20}\n");
        printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));             // answer = index 2
        printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));             // answer = index 5
        printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));             // answer = index 4
        printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));             // answer = index 0
        printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));             // answer = index 1
        printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));             // answer = index 5

        printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
        printf("Now, modify A into {18,17,13,19,15,100,20}\n");
        st.update_point(5, 100);                    // update A[5] from 11 to 100
        printf("These values do not change\n");
        printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));                            // 2
        printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));                            // 4
        printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));                            // 0
        printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));                            // 1
        printf("These values change\n");
        printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));                         // 5->2
        printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));                         // 5->4
        printf("RMQ(4, 5) = %d\n", st.rmq(4, 5));                         // 5->4

        return 0;
}
