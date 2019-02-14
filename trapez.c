/*
######################################################
#Last change:14.02.2019                              #
#=================                                   #
#Trapez algorithm:                                   #
#=================                                   #
#Definite integral of f(x) function a to b can be    #
#represented as:                                     #
#                                                    #
#f(x)dx=h[1/2*f(a)+f(x1)+...+f(xn-1)+1/2*f(xn)]+error#
#                                                    #
#h=(b-a)/N   h is the step difference between        #
#xi+1 and xi.                                        #
#                                                    #
#points on the f(x) function can be represented as:  #
#                                                    #
#x0=a, xi=a+ih, xn=b                                 #
#                                                    #
#b=Nh+a !!!                                          #
#=================                                   #
######################################################
*/

#include <stdio.h>

typedef struct{
    float a,b,//a and b are the interval of the integral a is the starting point and b is the finishing point.
            h,//h is the difference between two points on the f(x) function.(f(xi+1)-f(xi)).
            n;//Amount of the trapezoid
     integral;//Value of the integral
}integral_t;

void driver_f(integral_t *integral);//This function interacts with the user
float function_f();                 //Arguments of the integral
void n_f(integral_t *integral);     //This function calculates amount of the trapezoid
void integral_f();                  //This function calculates the value of the integral

int main (){
    integral_t integral;
    printf("C implementation of the trapezoidal integration algorithm\n");
}
void driver(integral_t *integral){
    printf("Please enter the starting interval of the integral>>");
    scanf("%f",&(*integral).a);
    printf("Please enter the finishing interval of the integral>>");
    scanf("%f",&(*integral).b);
    printf("Please enter the difference between two points on the function(h)");
    scanf("f",&(*integral).h);
}
void n_f(integral_t *integral){
    (*integral).n=((*integral).b-(*integral).a)/(*integral).h;
}
