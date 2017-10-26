#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
void interpolation();

int main(int argc, char *argv[]) {
	interpolation();
	getch();
	return 0;
}

//page 104
void interpolation(){	
	int degree =  0;
	double b =0;
	double x =0;
	double derivation = 0;
	double integral =0;
	int i;
	
	printf("Enter the degree of the polynomial: ");
	scanf("%d",&degree);
	
	printf("Enter value for independent variable (x): ");
	scanf("%lf",&x);
	
	double coefficients[degree+1];
	
	for(i = degree; i >= 0; i--){
		printf("\nEnter A(%d): ",i);
		scanf("%lf",&coefficients[i]);
	} 
	
	b = coefficients[degree];
	printf("\nB(%d): %f ", degree, coefficients[degree]);
	
	for(i = degree-1; i >= 0; i--){
		b = coefficients[i] + b*x;
		printf("\nB(%d): %f", i, b);
	}
	
	printf("\n\nThe value of P(%f): %f", x, b);		
	
	printf("\n\n--------------------");
	
	derivation = degree * coefficients[degree];
	printf("\nD(%d): %f ", degree-1, derivation);
	
	for(i = degree-1; i >= 1; i--){
		derivation = i*coefficients[i] + derivation*x;
		printf("\nD(%d): %f", i-1, derivation);
	}
	
	printf("\n\nThe value of P'(%f): %f", x, derivation);
	
	printf("\n\n--------------------");
	
	integral = coefficients[degree]/(degree+1);
	
	printf("\nI(%d): %f ", degree+1, integral);
	
	for(i = degree; i >= 1; i--){
		integral = coefficients[i-1]/i + integral*x;
		printf("\nI(%d): %f", i, integral);
	}
	
	integral = 0 + integral * x;
	
	printf("\n\nThe value of I(%f): %f", x, integral);	
}
