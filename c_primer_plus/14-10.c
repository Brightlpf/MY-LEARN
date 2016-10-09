#include <stdio.h>
#include <stdlib.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void showmenu(void);

int main(void)
{
	double number1, number2;
	int ch;
	double (* pfun)(double , double);
	double result;
	
	showmenu();
	ch = getchar();
	while(getchar()!= '\n')
		continue;
	while(ch != EOF)
	{
		switch(ch)
		{
			case '+':
				pfun = add;
				break;
			case '-':
				pfun = subtract;
				break;
			case '*':
				pfun = multiply;
				break;
			case '/':
				pfun = divide;
				break;
			default:
				//
				break;
		}
		printf("enter opt1: ");
		scanf("%lf", &number1);
		printf("enter opt2: ");
		scanf("%lf", &number2);
		while(getchar() != '\n')
			continue;
		result = pfun(number1, number2);
		printf("%.2f %c %.2f = %.2f\n", number1, ch, number2, result);
		showmenu();
		ch = getchar();
		while(getchar()!= '\n')
			continue;
	}
}

double add(double a, double b)
{
	return a+b;
}
double subtract(double a, double b)
{
	return a - b;
}
double multiply(double a, double b)
{
	return a * b;
}
double divide(double a, double b)
{
	if (b == 0)
	{
		printf("divice called failed.\n");
		exit(1);
	}
	return a/b;
}

void showmenu(void)
{
	printf("Select operator please:\n");
	printf("+) \n");
	printf("-) \n");
	printf("*) \n");
	printf("/) \n");
}
