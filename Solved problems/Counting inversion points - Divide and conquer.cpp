#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(LL i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(LL i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

typedef long long LL;

LL arr[100000];
 
LL sort_Count(LL beg,LL end){
    if(beg>=end)                            /*Base Condition*/
        return 0;
 
    LL mid=(beg+end)/2;
    LL n = end-beg+1;
    LL temp[n];
 
    LL left  = sort_Count(beg,mid);                    /*Sorting first half*/
    LL right = sort_Count(mid+1,end);              /*Sorting second half*/
 
    LL i=beg,j=mid+1,k=0;
    LL splitCount=0;

    while(i<=mid && j<=end){                /*Combine step*/
        if(arr[i]<arr[j]){
            temp[k++]=arr[i];
            i++;
        }
        else{
            temp[k++] = arr[j];
            splitCount += mid-i+1;
            j++;
        }
    }
 
    if(i<=mid){
        for(;i<=mid;i++)
            temp[k++]=arr[i];
    }
 
    else if(j<=end){
        for(;j<=end;j++)
            temp[k++] = arr[j];
    }
 
    FOR(i,n) arr[beg+i]=temp[i];
    return left+right+splitCount;
}
 
LL main() {
    LL n;
    scanf("%d",&n);
    prLLf("%d\n",n);
    FOR(i,n) scanf("%d",&arr[i]);
 
    prLLf("%lld\n",sort_Count(0,n-1));
 
    // FOR(i,n) prLLf("%d ",arr[i]);
    return 0;
}