inline int getint(){
	int num=0;
	char c=getchar_unlocked();
	while(!(c>='0' && c<='9'))
		c=getchar_unlocked();
 
	while(c>='0' && c<='9'){
		num=(num<<3)+(num<<1)+(c-'0');
		c=getchar_unlocked();
	}
	return num;
}

void gi(int *p){
    register int c = gc(),x=0;
    bool neg = false;
    while((c<48 || c>57) && (c!='-')) c = gc();
    if(c=='-'){
        neg = true;
        c = gc();
    }
    while(c>=48&&c<=57){
        x = (x<<1) + (x<<3) + c-48;
        c = gc();
    }
    if(neg) x = -x;
    *p = x;
}