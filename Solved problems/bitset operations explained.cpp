#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
 
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
 
typedef long long LL;
typedef pair<int,int> ii;
 
int main() {
	bitset<10> a,b,c;
 
/*Intialize*/	
	a = 60;
	b = 50;
 
/*Operations*/
	c = a^b;			
 
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
/*Access each bit*/
	cout << a[5] <<endl;			/*Bits are labelled from left side*/
 
/*Count operation*/
	cout<< a.count()<<endl;			/*Counts the number of set bits in number*/
 
/*Size operation*/
	cout<< a.size()<<endl;			/*Returns the length of the bits*/
 
/*Test operation*/
	FOR(i,(int)c.size())
		cout<< c.test(i) <<", ";	/*Test whether bit is 1 or not return type is boolean*/
	cout<<endl;
 
/*any operation*/
	cout<< a.any()<<endl;			/*Checks whether atleast 1 bit is set then returns true else returns false*/
 
/*all operation*/
	cout<< a.all();					/*Checks whether all bits are set or not*/
 
/*set operation*/
	cout<< a.set()<<endl;				/*set all bits*/
	cout<< a.set(2,0)<<endl;			/*will set 2nd bit to 0*/
	cout<< a.set(2)<<endl;				/*will make 2nd bit 1*/
 
/*reset operation*/
	cout<< a.reset()<<endl;				/*resets all bits*/
	cout<< a.reset(2)<<endl;			/*resets 2nd bit*/
 
/*flip operation*/
	cout<< a.flip()<<endl;				/*flips all bits*/
	cout<< a.flip(2)<<endl;				/*flips 2nd bit*/
 
/*To long integer and To long long*/
	long k = a.to_ulong();				/*Converts to long integer*/
	long long l = a.to_ullong();		/*Converts to long long*/
	cout<<endl<<k<<endl<<l;
	return 0;
}