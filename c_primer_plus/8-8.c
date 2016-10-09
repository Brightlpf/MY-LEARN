#include <stdio.h>
#define ERROR 99999999

void showMenu(void);
void showResult(int num, double result);
int getChoice(void);
double getInput(void);
double add(double opt1, double opt2);
double minus(double opt1, double opt2);
double multiply(double opt1, double opt2);
double divide(double opt1, double opt2);

int main(void)
{
	int choice;
	double result = ERROR;
	double opt1 = 0, opt2 = 0;
	
	printf("Hello dear, Welcome!\n");
	while(1)
	{
		showMenu();
		while((choice = getChoice()) == ERROR)
		{
			printf("sorry, Please enter num from 1~4. \n");
		}
		switch(choice)
		{
			case 1:
				printf("Please input opt1: ");
				opt1 = getInput();
				printf("\nPlease input opt2: ");
				opt2 = getInput();
				result = add(opt1,opt2);
				showResult(1, result);
				break;
			case 2:
				printf("Please input opt1: ");
				opt1 = getInput();
				printf("\nPlease input opt2: ");
				opt2 = getInput();
				result = minus(opt1, opt2);
				showResult(2, result);
				break;
			case 3:
				printf("Please input opt1: ");
				opt1 = getInput();
				printf("\nPlease input opt2: ");
				opt2 = getInput();
				result = multiply(opt1, opt2);
				showResult(3, result);
				break;
			case 4:
				printf("Please input opt1: ");
				opt1 = getInput();
				printf("\nPlease input opt2: ");
				opt2 = getInput();
				result = divide(opt1, opt2);
				if(result == ERROR)
				{
					printf("%s::%s opt2 invalid\n", __FILE__, __LINE__);
				}
				showResult(4, result);
				break;
			default:
				printf("sorry, Please enter num from 1~4.\n");
				break;	
		}
		
	}
	
	return 0;
}

void showMenu(void)
{
	printf("1: add ; 		2: minus	\n");
	printf("3: multiply	;	4: divide	\n");
	printf("Please enter your choice: ");
	return ;
}

void showResult(int num, double result)
{
	switch(num)
	{
		case 1:
			printf("ADD: ");
			break;
		case 2:
			printf("MINUS: ");
			break;
		case 3:
			printf("MULTIPLY: ");
			break;
		case 4:
			printf("DIVIDE: ");
			break;
		default:
			printf("param err!");
			return ;
	}
	printf("The result is %.2f\n\n", result);
}
int getChoice(void)
{
	int choice = 0;
	if(scanf("%d", &choice) !=1)
	{
#ifdef DEBUG
	printf("%s::%D choice invalid\n", __FILE__, __LINE__);
#endif
		while(getchar()!='\n');
		return ERROR;
	}
#ifdef DEBUG
	printf("%s::%d choice = %d\n", __FILE__, __LINE__, choice);
#endif
	return choice;
}

double getInput(void)
{
	double opt;
	if(scanf("%lf", &opt) != 1)
	{
#ifdef DEBUG
	printf("%s::%d param is invalid. Input again \n", __FILE__, __LINE__);
#endif
		while(getchar() != '\n');
		return ERROR;
	}
#ifdef DEBUG
	printf("%s::%d opt = %.2f \n", __FILE__, __LINE__, opt);
#endif
	return opt;
}
double add(double opt1, double opt2)
{
	return opt1 + opt2;
}

double minus(double opt1, double opt2)
{
	return opt1 - opt2; 
}

double multiply(double opt1, double opt2)
{
	return opt1 * opt2;
}

double divide(double opt1, double opt2)
{
	if(opt2 < 0.00001 && opt1 > -0.00001)
	{
#ifdef DEBUG
	printf("%s::%s opt = %.2f opt2 invalid\n", __FILE__, __LINE__);
#endif
		return ERROR;
	}
	return opt1 / opt2;
}
