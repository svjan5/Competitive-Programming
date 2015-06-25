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
typedef pair<char, int> P;

vector<int> getRow(int n) {
	vector<int> row;
	n++;
	int *a[n];
	for (int i = 0; i < n; i++)
		a[i] = (int*)malloc(sizeof(int) * (i+1));
	a[0][0] = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<i+1; j++){
			a[i][j] = a[i-1][j] + ((j>0) ?a[i-1][j-1] :0);
		}
	}

	for(int i=0; i<n; i++){
		row.push_back(a[n-1][i]);
	}
	return row;
}


int main() {
	int t;
	vector<int> arr =  getRow(5);
	for(int i=0; i<arr.size(); i++)
		printf("%d ", arr[i]);
	return 0;
}