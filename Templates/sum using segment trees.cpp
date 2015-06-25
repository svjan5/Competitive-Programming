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

int getMid(int s, int e) {  return s + (e -s)/2; }
 
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index){
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index){
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss){
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}

void updateValue(int arr[], int *st, int n, int i, int new_val){
    if (i < 0 || i > n-1){
        printf("Invalid Input");
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

int getSum(int *st, int n, int qs, int qe){
    if (qs < 0 || qe > n-1 || qs > qe){
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si){
    if (ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int *constructST(int arr[], int n){
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
 
int pirates[1024000];

int main() {
        int t,times,n,a,b,q;
        char ch;
        scanf("%d",&t);
        string subseq;

        FOR(caseNum,t){
                int index=0;
                scanf("%d\n",&n);
                char subseq[1001];
                FOR(i,n){
                        scanf("%d\n",&times);
                        scanf("%s",subseq);
                        FOR(j,times){
                                FOR(k,(int)strlen(subseq))
                                        pirates[index++] = subseq[k]-'0';
                        }
                }
                int len = index;
                // printf("%d\n", len);
                // FOR(i,len) pirates[i] = (seq[i]=='0')?0 :1;

                // FOR(i,len) printf("%d",pirates[i]);printf("\n");
                // vi A(pirates,pirates+len);
                // FenwickTree FT(A);
                int *st = constructST(pirates, len);

                // FOR(i,len) printf("%d",FT.rsq(i,i));printf("\n");

                int quesCount=1;
                scanf("%d\n",&q);
                printf("Case %d:\n",caseNum+1);
                while(q--){
                        scanf("%c %d %d\n",&ch,&a,&b);
                        switch(ch){
                                case 'F':
                                        REP1(i,a,b) updateValue(pirates,st,len,i,1);
                                        break;
                                case 'E':
                                        REP1(i,a,b) updateValue(pirates,st,len,i,0);
                                        break;
                                case 'I':
                                        REP1(i,a,b) (getSum(st,len,i,i)==0)?updateValue(pirates,st,len,i,1) :updateValue(pirates,st,len,i,0);
                                        break;
                                case 'S':
                                        printf("Q%d: %d\n",quesCount++,getSum(st,len,a,b));
                                        break;
                        }

                        // printf("Query %c %d %d \n",ch,a,b);
                        // FOR(i,len) printf("%d ",FT.rsq(i,i));printf("\n");
                }
                // cout<<seq<<endl;
        }

        return 0;
}