#include<stdio.h>

int compute(int a, int m, int n){
    int r, y = 1;
    while (m > 0)
    {
        r =  m % 2;
        if(r == 1) y = (y*a) % n;

        a = (a*a) % n;
        m = m / 2;
    }
    return y;
    
}

int main(){
    int p = 23, q = 5;
    int a, b;
    int A,B;

    a = 6;
    A =  compute(q,a,p);

    b =  15;
    B = compute(q,b,p);

    int keyA = compute(B,a,p);
    int keyB = compute(A,b,p);

    printf("Alices secret key is %d\nBobs Secret key is %d\n",keyA,keyB);
}