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

/*NOTE: 
    Update operation adds value to range it doesn't replace it 
    Index begins from 0
*/
    
class FenwickTree {
        private:
                vi A,ft;int n;
        public:
                FenwickTree(const vi &_A) {
                        A = _A; n = (int)A.size();              
                        ft.assign(n+1,0);
                        for (int i=0;i<n;i++)
                                update(i, A[i]);                
                }

                void update(int index,int value){
                        index = index + 1;
                        while (index <= n){
                                ft[index] += value;
                                index += index & (-index);
                        }
                }

                int rsq(int index){
                        int sum = 0;
                        index = index + 1;
                        while (index>0){
                                sum += ft[index];
                                index -= index & (-index);
                        }
                        return sum;
                }

                int rsq(int i,int j){
                        return rsq(j) - ((i==0)?0 :rsq(i-1));
                }

};


 
// Driver program to test above functions
int main()
{
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    vector<int> A(freq,freq+n);
    FenwickTree FT(A);
    cout << "Sum of elements in arr[0..5] is "
         << FT.rsq(5);
 
    // Let use test the update operation
    // freq[3] += 6;
    // updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]
         FT.update(3,6);
 
    cout << "\nSum of elements in arr[0..5] after update is "
         << FT.rsq(5)<<endl;
         for (int i = 0; i < n-1; ++i){
                 printf("%d ",FT.rsq(i,i+1));
         }
 
    return 0;
}


