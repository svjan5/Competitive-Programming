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

char str[51];


/*****************************************ABOUT STRCMP FUNCTION IN C++***************************************
strcmp(str1,str2)
if Return value if < 0 then it indicates str1 is less than str2
if Return value if > 0 then it indicates str2 is less than str1
if Return value if = 0 then it indicates str1 is equal to str2
*/
int main() {

    while(true){
        scanf("%s",str);

        if(strcmp(str,"#")==0){
            break;
        }

        char temp[51];
        strcpy(temp,str);
        next_permutation(str,str+strlen(str));


        if(strcmp(temp,str)<0)          /*if original string is less than successsor*/
            printf("%s\n",str);
        else
            printf("No Successor\n");
    }
    return 0;
}