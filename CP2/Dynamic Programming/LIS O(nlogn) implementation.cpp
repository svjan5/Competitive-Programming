#include <algorithm>
#include <cstdio>

using namespace std;

int A[1000000], M[1000000], M_id[1000000], P[1000000];

void print(int end) {
        if(end < 0) return;
        print(P[end]);
        printf("%d\n", A[end]);
}

/*  M   - array stores the last value in the subsequence of length i
    M_id- array stores the indexes of those values
    P   - array stores the index in A of the element prior to it in the subsequence*/

int main() {
        int L = 0, L_end = 0;
        for(int i=0;;i++) {
                if(scanf("%d",&A[i])==EOF) break;

                int pos = lower_bound(M, M + L, A[i]) - M;
                M[pos] = A[i];
                M_id[pos] = i;
                P[i] = (pos > 0)? M_id[pos - 1] : -1;
                if(pos == L) {
                        L++;
                        L_end = i;
                }
        }
        printf("%d\n-\n", L);
        print(L_end);
        return 0;
}