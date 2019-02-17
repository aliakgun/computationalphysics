/*
***************************************
*Last change:17.02.2019               *
*======================               *
*f(x)dx=h/3[f(x0)+4f(x1)+2f(x2)+...   *
*+4f(x3)+2f(x4)+...+2f(xn-2)+4f(xn-1)+*
*...+f(xn)]                           *
*======================               *
*x0=a>>Starting point of the integral *
*xn=b>>Finishing point of the integral*
*                                     *
*xi=a+ih (i=0,1,2,3,...n).            *
*xn=a+nh=b                            *
*                                     *
*b-a=nh                               *
*                                     *
*n=(b-a)/h                            *
*h is the step size.                  *
*n is the step number.                *
***************************************
*/

typedef struct{
    double a,b,h,n,result;
}integral_t;

#include<stdio.h>

void driver_f(integral_t *integral);      //This function interacts with the user.
float function_f(float x);                //Function for calculating the integral(f(x)).
float calculator_f(integral_t *integral); //This function calculates the value of the integral.
void step_f(integral_t *integral);        //This function calculates the number of the step for the integral.

int main(){
    printf("Simpsons algorithm for calculating definite integrals\n");
    integral_t integral;
    driver_f(&integral);
    printf("Result is %f>>>",calculator_f(&integral));
}

void driver_f(integral_t *integral){
    printf("Please enter the initial point of the interval>>>");
    scanf("%lf",&(*integral).a);
    printf("Please enter the finishing point of the interval>>>");
    scanf("%lf",&(*integral).b);
    printf("Please enter the step size(b-a=nh h is the step size of the integral)>>>");
    scanf("%lf",&(*integral).h);
}

float function_f(float x){
    return x;
}

void step_f(integral_t *integral){
    (*integral).n=((*integral).b-(*integral).a)/(*integral).h;
}

float calculator_f(integral_t *integral){
    step_f(integral);
    (*integral).result=(((*integral).h)/3.0)*(function_f((*integral).a)+function_f((*integral).b));
    for(float i=1;i<(*integral).n;++i){
            if((int)i%2!=0){
                (*integral).result=(*integral).result+((*integral).h*function_f(i*(*integral).h))/(3.0/4.0);
            }else{
                (*integral).result=(*integral).result+((*integral).h*function_f(i*(*integral).h))/(3.0/2.0);
            }
    }

    return (*integral).result;
}
