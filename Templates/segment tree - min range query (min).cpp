#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;



class SegmentTree {         
        private: 
                vi st, A;
                int n;
                int left (int p) { return p << 1; }                     
                int right(int p) { return (p << 1) + 1; }

                void build(int p, int L, int R) {                        
                        if (L == R) st[p] = L;
                        else {
                              int mid = (L+R)/2;
                              build(left(p),L,mid);
                              build(right(p),mid+1,R);

                              int p1 = st[left(p)];
                              int p2 = st[right(p)];
                              st[p] = (A[p1] <= A[p2]) ? p1 : p2;
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
                        return (A[p1] <= A[p2]) ? p1 : p2;
                }
                
                int update_point(int p, int L, int R, int idx, int new_value) {
                        int i = idx, j = idx;
                        if (i > R || j < L)
                                return st[p];

                        if (L == i && R == j) {
                                A[i] = new_value;               
                                return st[p] = L;
                        }
                        int p1, p2;
                        int mid = (L+R)/2;
                        p1 = update_point(left(p) ,   L ,mid ,idx, new_value);
                        p2 = update_point(right(p), mid+1, R ,idx, new_value);
                        return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
                }

        public:
                SegmentTree(const vi &_A) {
                        A = _A; n = (int)A.size();              
                        int x = (int)(ceil(log2(n)));           
                        int max_size = 2*(int)pow(2, x) - 1;    
                        st.assign(max_size, 0);                 
                        build(1, 0, n - 1);                     
                }

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
                }
};


  
int main() {
        int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         
        vi A(arr, arr + 7);                      
        SegmentTree st(A);

        printf("idx    0, 1, 2, 3, 4,  5, 6\n");
        printf("A is {18,17,13,19,15, 11,20}\n");
        printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));             
        printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));             
        printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));             
        printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));             
        printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));             
        printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));             

        printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
        printf("Now, modify A into {18,17,13,19,15,100,20}\n");
        st.update_point(5, 100);                    
        printf("These values do not change\n");
        printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));                            
        printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));                            
        printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));                            
        printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));                            
        printf("These values change\n");
        printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));                         
        printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));                         
        printf("RMQ(4, 5) = %d\n", st.rmq(4, 5));                         

        return 0;
}
