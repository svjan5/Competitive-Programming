#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
 
int gcd(int a, int b){
	if (b==0) return a;
	else return gcd(b,a%b);
}

inline int max_index(int *arr,int n){
        return max_element(arr,arr+n)-arr;
}

enum STR2INT_ERROR { SUCCESS, OVERFLOW, UNDERFLOW, INCONVERTIBLE };
 
void str2int (int &i, char const *s, int base){
    char *end;
    long  l;
    l = strtol(s, &end, base);
    i = l;
}

string numToStr (int Number ){
	ostringstream ss;
    ss << Number;
    return ss.str();
}

int strToNum (const string &Text){
	istringstream ss(Text);
	int result;
	return ss >> result ? result : 0;
}

inline int max(int a,int b,int c){
        if(a>b && a>c) return a;
        if(b>c && b>a) return b;
        else return c;
}

inline int min(int a,int b,int c){
        if(a<b && a<c) return a;
        if(b<c && b<a) return b;
        else return c;
}
 
int main() {
	int t,A,i,i_mod,res;
	char b[255];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&A);
		scanf("%s",b);
		string B(b);
 
		if(A!=0){
			while(B.length() > 9){
				char a[10];
				str2int(i,(B.substr(0,9)).c_str(),10);
				i_mod = i % A;
				sprintf(a, "%i", i_mod);
				B.replace(0,9,a);
			}
 
			str2int(i,B.c_str(),10);
			res = i % A;
			printf("%d\n",gcd(A,res));
		}
		else{
			printf("%s\n",b);
		}
	}
 
	return 0;
}