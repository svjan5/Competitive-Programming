#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define pb push_back
#define mp make_pair

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> ii;

struct sheet{
    int front_left;
    int front_right;
    int back_left;
    int back_right;    
};

sheet page[20];

int main() {
    int n;

    while(scanf("%d",&n) && n){
        int numPages = ceil(n/4.0);

        printf("Printing order for %d pages:\n",n);
        
        if(n==1){
            printf("Sheet 1, front: Blank, 1\n");
            continue;
        }

        FOR(i,numPages){
            page[i].front_left=0;
            page[i].front_right=0;
            page[i].back_left=0;
            page[i].back_right=0;
        }

        int count=1;
        // cout<<numPages<<endl;

        for(int i=0 ; i<numPages; i++){
            page[i].front_right = count++;
            page[i].back_left = count++;
        }

        for(int i=numPages-1 ; i>=0; i--){
            if(count<=n)
                page[i].back_right = count++;
            if(count<=n)
                page[i].front_left = count++;
        }


        FOR(i,numPages){
            printf("Sheet %d, front: ",i+1);
            if(page[i].front_left == 0) printf("Blank, ");
            else printf("%d, ",page[i].front_left);
            printf("%d\n",page[i].front_right);

            printf("Sheet %d, back : ",i+1);
            if(page[i].back_left == 0) printf("Blank, ");
            else  printf("%d, ",page[i].back_left);
            if(page[i].back_right == 0) printf("Blank\n");
            else printf("%d\n",page[i].back_right);
        }


    }
    return 0;
}