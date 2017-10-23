#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
void bisection(double a, double b);

int main(int argc, char *argv[]) {
	bisection(6.0, 6.8);
	getch();
	return 0;
}

double f(double x){
	return pow(x,2)-(10*x)+23;
} 

void bisection(double a, double b){
		
	int iteration=0;
	double c = 0;	
	do
	{
		c = (a+b)/2.0;
		printf("Iteration %d: f(c) is %.10lf \n", ++iteration, f(c));
		if (f(c) == 0.0)
			break;
		else if(f(c) * f(a) <0)
			b=c;
		else
			a=c;
	}
	while(1==1);
	printf("\nThe zero is: %.10lf",c);
	printf("\nNumber of iterations: %d",iteration);
}
	

