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

bool isdigit(char c){
    if(c>='0' && c<='9')
        return true;
    else
        return false;
}

int main() {
    int t;
    map<char,int>prec;
    prec['+'] = 1;
    prec['-'] = 1;
    prec['*'] = 2;
    prec['/'] = 2;

    scanf("%d\n",&t);
    string str;
    // getline(cin,str);

    while(t--){
        string out="";
        stack<char> stk;
        char c;

        while(getline(cin,str)!=0){


            if(str.length()==0)
                break;

            c = str[0];

            // printf("%c\n",c);
            if(isdigit(c))
                out += c;
            
            else{
                if(stk.empty())                           /*If stack is empty push the operator*/
                    stk.push(c);

                else{                                     /*Case when stack is not empty*/
                    if(c==')'){
                        while(stk.top()!='('){
                            out += stk.top();
                            stk.pop();
                        }
                        stk.pop();                         /*Remove '(' from stack*/
                    }

                    else if(c == '('){
                        stk.push(c);                    
                    }

                    else{
                        if(prec[c] > prec[stk.top()])     /*If the precedence of the scanned operator is greater than the precedence of the operator on stack push it*/
                           stk.push(c);

                        else{
                            while(!stk.empty() &&   prec[c]<=prec[stk.top()] ){
                                out += stk.top();
                                stk.pop();
                            }
                            stk.push(c);
                        } 
                    }

                }
            }
            // cout<<c;
            // cout<<out<<endl;
        }

        while(!stk.empty()){
            out += stk.top();
            stk.pop();
        }

        printf("%s\n",out.c_str());
        if(t!=0)
            cout<<endl;
    }
    return 0;
}