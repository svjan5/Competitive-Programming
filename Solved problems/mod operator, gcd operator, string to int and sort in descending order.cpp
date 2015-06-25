int mod(int a,int b){
    return (a%b+b)%b;
}

int gcd(int a, int b){
	if (b==0) return a;
	else return gcd(b,a%b);
}

void str2int (int &i, char const *s, int base){
    char *end;
    long  l;
    l = strtol(s, &end, base);
    i = l;
}

sort(numbers.begin(), numbers.end(), greater<int>());