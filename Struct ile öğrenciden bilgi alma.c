#include <stdio.h>


struct student {
	int id;
	char name[25];
	float grade;
};
float calculate(int,int);
int main(){
	struct student ogrenci;
	int final;
	int midterm;
	printf("Enter your id:");
	scanf("%d",&ogrenci.id);
	printf("Enter your first name:");
	scanf("%s",ogrenci.name);
	printf("Enter your midterm:");
	scanf("%d",&midterm);
	printf("Enter your final:");
	scanf("%d",&final);
	float result = calculate(midterm,final);
	printf("Result: %f", result);
	
}

float calculate(int vize, int final){
	return(vize*0.4+final*0.6);
	
};

