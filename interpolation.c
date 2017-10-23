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
}
