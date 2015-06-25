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
typedef vector<int> vi;

int arr[10000];
int compCount=0;

int getPivotPos(int beg,int end){
	int mid = (beg+end)/2;
	if((arr[beg] < arr[mid] && arr[mid] < arr[end]) || (arr[end] < arr[mid] && arr[mid] < arr[beg]))
		return mid;
	else if((arr[mid] < arr[beg] && arr[beg] < arr[end]) || (arr[end] < arr[beg] && arr[beg] < arr[mid]))
		return beg;
	else
		return end;
}

int partition(int beg,int end,int pivot){
	compCount += end-beg;

	int i,j,p;
	swap(arr[beg],arr[pivot]);					/*Made pivot as the first element of the array*/

	p = arr[beg];
	i = j = beg+1;

	while(j<=end){
		if(arr[j]<p){							/*if found an element less than pivot then swap is needed and i is increased by 1*/
			swap(arr[i],arr[j]);
			i++;
		}
		j++;
	}

	swap(arr[beg],arr[i-1]);					/*Finally bring pivot to its sorted correct position*/
	return i-1;									/*Return the correct position of pivot*/
}

void quickSort(int beg,int end){
	if(beg==end || beg>end)
		return;
	int pivot = getPivotPos(beg,end);
	// printf("Hello\n");

	int n = partition(beg,end,pivot);
	quickSort(beg,n-1);
	quickSort(n+1,end);
}


int main() {
	int n;
	scanf("%d",&n);
	FOR(i,n) scanf("%d",&arr[i]);			/*Inputting data*/

	quickSort(0,n-1);

	// FOR(i,n) printf("%d ",arr[i]);
	cout<<compCount;

	return 0;
}