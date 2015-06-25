#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

/*****************************************************RANGED MINIMUM QUERY**************************************************/

class SegmentTree {         
        private: 
                vi st, A;
                int n;
                int left (int p) { return p << 1; }                     /*same as binary heap operations*/
                int right(int p) { return (p << 1) + 1; }

                /*  L - left end of the array
                    R - right end of the array
                    p - current node of segment tree
                */
                void build(int p, int L, int R) {
                        // If there is one element in array, store it in current node of
                        // segment tree and return
                        if (L == R) st[p] = L;

                        // If there are more than one elements, then recur for left and
                        // right subtrees and store the sum of values in this node
                        else {
                              int mid = (L+R)/2;
                              build(left(p),L,mid);
                              build(right(p),mid+1,R);

                              int p1 = st[left(p)];
                              int p2 = st[right(p)];
                              st[p] = (A[p1] <= A[p2]) ? p1 : p2;
                        } 
                }
                /*
                    p - current node of segment tree
                    L - left end of array
                    R - right end of array
                    i - left end of query requested
                    j - right end of query requested
                */
                int rmq(int p, int L, int R, int i, int j) {
                        if (i >  R || j <  L) return -1;                /*current segment outside query range*/
                        if (L >= i && R <= j) return st[p];             /*Completely inside query range*/

                        /*compute the min position in the left and right part of the interval*/
                        int mid = (L+R)/2;
                        int p1 = rmq(left(p) , L ,mid,i,j);
                        int p2 = rmq(right(p),mid+1,R,i,j);

                        if (p1 == -1) return p2;
                        if (p2 == -1) return p1;
                        return (A[p1] <= A[p2]) ? p1 : p2;
                }
                /*
                    p - current node of segment tree
                    L - left end of array
                    R - right end of array
                    idx - index of the element which is upadated in array
                    new_value - new value of the changed element
                */
                int update_point(int p, int L, int R, int idx, int new_value) {

                        int i = idx, j = idx;

                        /*if the current interval does not intersect the update interval, return this st node value!*/
                        if (i > R || j < L)
                                return st[p];

                        /*if the current interval is included in the update range, update that st[node]*/
                        if (L == i && R == j) {
                                A[i] = new_value;               /*update the underlying array*/
                                return st[p] = L;
                        }

                        /*compute the minimum position in the left and right part of the interval*/
                        int p1, p2;
                        int mid = (L+R)/2;
                        p1 = update_point(left(p) ,   L ,mid ,idx, new_value);
                        p2 = update_point(right(p), mid+1, R ,idx, new_value);

                        /*return the position where the overall minimum is*/
                        return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
                }

        public:
                SegmentTree(const vi &_A) {
                        A = _A; n = (int)A.size();              /*copy content for local usage*/
                        int x = (int)(ceil(log2(n)));           /*Height of segment tree*/
                        int max_size = 2*(int)pow(2, x) - 1;    /*Maximum size of segment tree*/
                        st.assign(max_size, 0);                 /*create large enough vector of zeroes*/
                        build(1, 0, n - 1);                     /*recursive build*/
                }

                int rmq(int i, int j) { 
                        return rmq(1, 0, n - 1, i, j);          /*overloading*/
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
