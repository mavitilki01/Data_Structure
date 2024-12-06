#include <stdio.h>

typedef struct complex{
	int real;
	int imaginary;
}complex;

	

 int main(){
	complex *object=(complex*)malloc(sizeof(complex));
	
 	printf("Please give the values for complex number: \n");
 	scanf("%d", &(object->real)); scanf("%d", &(object->imaginary));
 
 	printf("Complex number: %d + %di ", object->real, object->imaginary);
 	
 }
