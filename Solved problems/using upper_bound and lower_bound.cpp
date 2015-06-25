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

#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define ub upper_bound
#define lb lower_bound

/*
        Lower bound: first element that is greater-or-equal.
        Upper bound: first element that is strictly greater.
*/
int main() {
                /* 0 1 2 3 4 5 6 7 8 9 10*/
        int A[] = {3,4,4,4,4,5,7,7,7,7,8};
        int n = ARRAY_SIZE(A);
        printf("lb(2):%d  ub(2):%d\n",lb(A,A+n,2)-A , ub(A,A+n,2)-A);
        printf("lb(4):%d  ub(4):%d\n",lb(A,A+n,4)-A , ub(A,A+n,4)-A);
        printf("lb(5):%d  ub(5):%d\n",lb(A,A+n,5)-A , ub(A,A+n,5)-A);
        printf("lb(7):%d  ub(7):%d\n",lb(A,A+n,7)-A , ub(A,A+n,7)-A);
        printf("lb(8):%d  ub(8):%d\n",lb(A,A+n,8)-A , ub(A,A+n,8)-A);
        printf("lb(9):%d  ub(9):%d\n",lb(A,A+n,9)-A , ub(A,A+n,9)-A);
        return 0;
}
