#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
 
    while ( testCase-- ) {
        int s, a, f;
        scanf ("%d %d %d", &s, &a, &f);
 
        int p [50000 + 5];
        int q [50000 + 5];
 
        for ( int i = 0; i < f; i++ )
            scanf ("%d %d", &p [i], &q [i]);
 
        sort (p, p + f);
        sort (q, q + f);
 
        if ( f % 2 ) printf ("(Street: %d, Avenue: %d)\n", p [f / 2], q [f / 2]);
        else printf ("(Street: %d, Avenue: %d)\n", p [(f - 1) / 2], q [(f - 1) / 2]);
    }
 
    return 0;
}
 