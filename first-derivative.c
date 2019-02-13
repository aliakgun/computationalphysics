/*
****************************************
*Simetrik farklý 1. türev              *
*f'(xi)=[f(xi+h)-f(xi-h)]/2h + O(h^2)  *
*O(h^2) is error.                      *
*h^2 azaldýkça hatanýn azalacaðý açýkça*
*görülmektedir.                        *
****************************************
*/
#include<stdio.h>
#include<math.h>

typedef struct{
    float h,xi;
    }derivative_t;

float functionf(float x);//Our function for calculation the derivative.
void driverf(derivative_t *derivative);//Function for interacting user and program.
float derivativef(derivative_t *derivative);//Calculates derivative of the function.

int main(){
    float x;
    derivative_t derivative;
    printf("First order derivative calculator for f(x)=x^2 function\n");
    printf("The derivative is f'(xi)=[f(xi+h)-f(xi-h)]/2h + O(h^2)\nO(h^2) is the error of the calculation."
           "Decreasing h decresaes the error.\nError is proportional to the h^2\n");
    driverf(&derivative);
    printf("The derivative is equal to %f\n",derivativef(&derivative));
}
void driverf(derivative_t *derivative){
    printf("Please enter the h\n");
    scanf("%f",&(*derivative).h);
    printf("Please enter the xi, derivative of the function will be calculated at this point\n");
    scanf("%f",&(*derivative).xi);
}
float functionf(float x){
    return x*x;
}
float derivativef(derivative_t *derivative){
    return (functionf((*derivative).xi+(*derivative).h)-functionf((*derivative).xi-(*derivative).h))/(2.0f*(*derivative).h);
}
/*
*********************************************************
*x^2 ve x^3'ün getirdiği hatalar birbirinden farklı     *
*x^2 yüksek h değerlerinde bile verimli sonuçlar veriyor*
*bu durumu irdele farklı fonksiyonlar dene.             *
*********************************************************
*/
