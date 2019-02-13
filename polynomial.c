/*
*************************************************
*This program generates polynomial              *
*Pn(x)=a[0]x^n+a[1]x^(n-1)+a[2]x^(n-2)+...+a[n] *
*n=degree of the polynomial                     *
*p0(x)=a[0]                                     *
*pi(x)=pi-1(x)*x+a[i],i=1,2,3,...,n             *
*We will use this algorithm because power       *
*function is very slow.                         *
*************************************************
*/
#include<stdio.h>
#define SIZE 1000 //Size of the polynomial constants array.
typedef struct{//Struct type definition for the polynomial.
    int degree;
    float x,constanta[SIZE],p;
}polynomial_t;
void driverf(polynomial_t *polynomial);//This function interacts with the user.
void fillf(polynomial_t *polynomial);//This function gets the constants from the user.
float polynomialf(polynomial_t *polynomial);//Calculates the value of the Polynomial
int main(){
    polynomial_t polynomial;
    printf("Polynomial generator\n");
    driverf(&polynomial);
    fillf(&polynomial);
    printf("%.2f\n",polynomialf(&polynomial));
}
void driverf(polynomial_t *polynomial){
    printf("Polynomial form is Pn(x)=a[0]x^n+a[1]x^(n-1)+a[2]x^(n-2)+...+a[n]\n");
    printf("Please enter the degree of the polynomial(n)\n");
    scanf("%d",&(*polynomial).degree);
    printf("Please enter the polynomial variable(x)\n");
    scanf("%f",&(*polynomial).x);
    printf("Please enter the constants of the polynomial as ordered a[0],a[1],...a[n] by using space>>");
}
void fillf(polynomial_t *polynomial){
    for(int i=0;i<=(*polynomial).degree;i++){
        scanf("%f",&(*polynomial).constanta[i]);
    }
}
float polynomialf(polynomial_t *polynomial){
    (*polynomial).p=(*polynomial).constanta[0];
    for(int i=1;i<=(*polynomial).degree;i++){
        (*polynomial).p=((*polynomial).p)*((*polynomial).x)+(*polynomial).constanta[i];
    }
    return ((*polynomial).p);
}
