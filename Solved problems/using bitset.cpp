#include <iostream>
#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;
 
int main() {
	int n,nr;
	bitset<32> bs;
	string num,numr;
	while(scanf("%d",&n) != EOF){
		bs = bitset<32>(n);
		num = bs.to_string<char,string::traits_type,string::allocator_type>();
		// cout<<num.size()<<" "<<num<<" ";
 
		// reverse(num.begin(), num.end());
		numr = num.substr(24,8)+num.substr(16,8)+num.substr(8,8)+num.substr(0,8);
 
 
		bs = bitset<32>(string(numr));
		nr = static_cast<int>(bs.to_ulong());
		printf("%d converts to %d\n",n,nr);
	}
 
	return 0;
}