#include<stdio.h>
square(float a){
     float  y= a * a;
      	return (y);
}
main(){
    float a,b;
    scanf("%d", &a);
    b = square(a);
    printf("Square = %d\n", b);
}

