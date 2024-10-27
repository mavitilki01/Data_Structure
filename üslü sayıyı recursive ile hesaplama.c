#include <stdio.h>

int exponent(int, int);

int main (){
	int power, base, result;
	
	printf("Enter the base:");
	scanf("%d", &base);
	printf("Enter the power:");
	scanf("%d", &power);
	if(power==0)
		result = 1;
	else
		result = exponent(base,power);
	printf("the result is %d", result);
	
}

int exponent(int base, int power){
	if(power==1)
		return(base);
	else
		return(base*exponent(base,power-1));
}





