#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define INF 1000000000

#define pb push_back
#define mp make_pair

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second
#define NUM 10000

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

priority_queue<int> heapR;
priority_queue<int> heapL;


void stablize(){
    int sizeL,sizeR;
    sizeL = heapL.size();
    sizeR = heapR.size();

    if(abs(sizeL - sizeR) == 1)
        return;

    else if(sizeL == sizeR)
        return;

    else{
        int n;
        if(sizeL > sizeR){
            n = heapL.top();heapL.pop();
            heapR.push(-n);
        }
        else{
            n = heapR.top();heapR.pop();
            heapL.push(-n);
        }
    }
}

int getMedian(){
    int sizeL,sizeR;
    sizeL = heapL.size();
    sizeR = heapR.size();
    int k = sizeL + sizeR;
    int pos;

    if(k%2==0)
        pos = k/2;
    else
        pos = (k+1)/2;

    if(sizeL>=pos){
        return heapL.top();
    }
    else{
        return -heapR.top();
    }

}

int main() {
    int n;
    int leftmax,rightmin;

    int sum=0,med;

    FOR(i,NUM){
        scanf("%d",&n);
        
        if(!heapL.empty()) leftmax = heapL.top();
        else leftmax = INF;

        if(!heapR.empty()) rightmin = -heapR.top();
        else rightmin = -1;

        if(n < leftmax)
            heapL.push(n);

        else
            heapR.push(-n);

        stablize();

        med = getMedian();
        /*printf("Median for %d elements: %d ",i+1,med);

        priority_queue<int> Ltemp = heapL;
        priority_queue<int> Rtemp = heapR;
        while(!Ltemp.empty())
            printf(" %d",Ltemp.top()),Ltemp.pop();
        printf("\t\t");
        while(!Rtemp.empty())
            printf(" %d",Rtemp.top()),Rtemp.pop();*/

        // cout<<endl;
        sum = (sum%10000 + med%10000)%10000;

    }

    printf("%d\n",sum);

    return 0;
}