#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define FOR(i,n) LOOP(i,0,n-1)
#define FOR1(i,n) LOOP(i,1,n)
#define LOOP(i,a,b) for(int i=a;i<=b;i++)
#define RLOOP(i,a,b) for(int i=a;i>=b;i--)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;


vector<int> Solution::getRow(int A) {
	vector<int> vec;
    	int i, j;
	A++;
	int *arr[A+1];
	for (i = 0; i < A; i++) 
		arr[i] = (int*)malloc(sizeof(int) * (i + 1));
	

	arr[0][0] = 1;
	for (i = 1; i < A; i++) {
		for (j = 0; j <= i; j++) {
			arr[i][j] = arr[i - 1][j] + ( ((j-1)<0)?0:arr[i-1][j-1]);
		}
	}

	for (i = 0; i < A; i++) {
		for (j = 0; j <= i; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	for(i=0;i<A;i++){
		vec =  
	}

	return arr[A-1];
    
}

int* getRow(int A, int *length_of_array) {
	int i, j;
	A++;
	int *arr[A+1];
	for (i = 0; i < A; i++) 
		arr[i] = (int*)malloc(sizeof(int) * (i + 1));
	

	arr[0][0] = 1;
	for (i = 1; i < A; i++) {
		for (j = 0; j <= i; j++) {
			arr[i][j] = arr[i - 1][j] + ( ((j-1)<0)?0:arr[i-1][j-1]);
		}
	}

	for (i = 0; i < A; i++) {
		for (j = 0; j <= i; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	*length_of_array = A;

	return arr[A-1];

}

int main() {
	int i, len, *arr;
	arr = getRow(2, &len);
	for(i=0;i<len;i++)
		printf("%d ", arr[i]);
	return 0;
}

