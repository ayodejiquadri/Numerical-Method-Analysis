#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//page 82
double f(double x);
double gauss_seidel_iteration(double x, double y, double z);

int main(int argc, char *argv[]) {
	gauss_seidel_iteration(1, 2, 2);
	getch();
	return 0;
}

//equation for x_i
double equation_one(double y, double z){
	return (7 + y - z)/4.0;
}
//equation for y_i
double equation_two(double x, double z){
	return (21 + 4*x + z)/8.0;
}
//equation for z_i
double equation_three(double x, double y){
	return (15 + 2*x - y)/5.0;
}

double gauss_seidel_iteration(double x, double y, double z){
	double x_i = 0;
	double y_i = 0;
	double z_i = 0;
	int iteration = 0;
	
	do {
		
		x_i = equation_one(y,z);
		
		y_i = equation_two(x_i,z);
		
		z_i = equation_three(x_i, y_i);
		
		printf("Iteration %d: x = %.8f, y = %.8f, z = %.8f \n", ++iteration, x_i, y_i, z_i);
		
		if(x_i == equation_one(y_i, z_i) && y_i == equation_two(x_i, z_i) && z_i == equation_three(x_i, y_i))
			break;
		else
			y = y_i;
			z = z_i;			
	}
	while(1==1);
	
	printf("\nThe solution is: x = %.8f, y = %.8f, z = %.8f", x_i, y_i, z_i);
	printf("\nNumber of iterations: %d",iteration);
	
}
