//#include "iostream"
#include "cmath"
#include "stdio.h"


double mul(double a, double b, double c){
    double res = a *b * c;
    return(res);
}


double mean(double a, double b, double c){

    double res = pow(mul(a, b, c), 1.0/3.0);    //pow (^1/3)

    return(res);
}


int main(){

 double a1, a2, b1, b2, c1, c2;

    a1 = 2;
    b1 = 4;
    c1 = 8;

    a2 = 1.5;
    b2 = 7.2;
    c2 = 9.3;


    printf("Der geometrische Mittelwert von %.6f, %.6f und %.6f ist: %.6f\n", a1, b1, c1, mean(a1, b1, c1));
    printf("Der geometrische Mittelwert von %.6f, %.1f und %.6f ist: %.6f\n", a2, b2, c2, mean(a2, b2, c2));

    return(0);
}

