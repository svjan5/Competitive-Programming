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

int pirates[1024000];

int main() {
        int t,times,n,a,b,q;
        char ch;
        scanf("%d",&t);
        string subseq;

        FOR(caseNum,t){
                scanf("%d\n",&n);
                string seq;
                FOR(i,n){
                        scanf("%d\n",&times);
                        cin>>subseq;
                        FOR(j,times) seq += subseq;
                }
                int len = seq.length();
                FOR(i,len) pirates[i] = (seq[i]=='0')?0 :1;

                vi A(pirates,pirates+len);
                FenwickTree FT(A);

                // FOR(i,len) printf("%d",FT.rsq(i,i));printf("\n");

                int quesCount=1;
                scanf("%d\n",&q);
                printf("Case %d:\n",caseNum+1);
                while(q--){
                        scanf("%c %d %d\n",&ch,&a,&b);
                        switch(ch){
                                case 'F':
                                        REP1(i,a,b) if(FT.rsq(i,i)==0) FT.update(i,1);
                                        break;
                                case 'E':
                                        REP1(i,a,b) if(FT.rsq(i,i)==1) FT.update(i,-1);
                                        break;
                                case 'I':
                                        REP1(i,a,b) (FT.rsq(i,i)==0)?FT.update(i,1) :FT.update(i,-1);
                                        break;
                                case 'S':
                                        printf("Q%d: %d\n",quesCount++,FT.rsq(a,b));
                                        break;
                        }

                        // printf("Query %c %d %d \n",ch,a,b);
                        // FOR(i,len) printf("%d ",FT.rsq(i,i));printf("\n");
                }
                // cout<<seq<<endl;
        }

        return 0;
}