#include <iostream>
#include <cstdio>
using namespace std;
 
int fi(int n)
     {
       int result = n;
       for(int i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }
 
int main() {
	int t,n,i,tot;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		tot=n;
 
		/*for(i=2;i<=n;i++){
			if(n%i==0){
				tot = tot*(i-1)/i;
			}
			while(n%i==0){
				n=n/i;
			}
		}*/
 
		printf("%d\n",fi(n));
	}
	return 0;
}