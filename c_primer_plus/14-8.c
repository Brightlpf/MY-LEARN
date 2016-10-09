#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
#define NUM	12
#define FILENAME  "fly_seat"

 
typedef struct
{
	int num;  
	int booked; 
	char firstname[20];
	char lastname[20];
}Seat;
void init_seat(Seat *ps, int num);
void show_menu(void);
void show_num(Seat *ps, int n);
void show_list(Seat *ps, int n);
void show_list_byalpha(Seat *ps, int n);
int assign_seat(Seat *ps, int num, char firstname[], char lastname[]);
int del_seat(Seat *ps, int num);
int read_from_file(char *filename, Seat *ps, int n);
int save_to_file(char *filename, Seat * ps, int n);

int main(void)
{
	Seat s[NUM];
	int ch;
	int ret;
	char name[2][LEN];
	int num;
	
	init_seat(s, NUM);
	
	if(read_from_file(FILENAME, s, NUM) == -1)
	{
		fprintf(stderr, "read file failed.\n");
		exit(EXIT_FAILURE);
	}
	
	show_menu();
	ch = getchar();
	while(getchar() != '\n');
	
	while(ch != 'q')
	{
		switch(ch)
		{
			case 'a':
				show_num(s, NUM);
				break;
			case 'b':
				show_list(s, NUM);
				break;
			case 'c':
				show_list_byalpha(s, NUM);
				break;
			case 'd':
				printf("Please enter your first name: ('quit' to leave!)");
				ret = scanf("%s", name[0]);
				if(ret != 1)
				{
					printf("Sorry, input error, try again.\n");
					break;
				}
				if(strncmp(name[0], "quit", 4) == 0)
				{
					printf("Bye.");
					exit(EXIT_SUCCESS);
				}
				printf("Please enter your last name: ('quit' to leave!)");
				ret = scanf("%s", name[1]);
				if(ret != 1)
				{
					printf("Sorry, input error, try again.\n");
					break;
				}
				if(strncmp(name[1], "quit", 4) == 0)
				{
					printf("Bye.\n");
					exit(EXIT_SUCCESS);
				}
				ret = assign_seat(s,NUM, name[0],name[1]);
				if(ret == -1)
				{
					printf("book failed.\n");
					break;
				}
				ret = save_to_file(FILENAME, s, NUM);
				if(ret == -1)
				{
					printf("save to file failed\n");
					break;
				}
				while(getchar() != '\n');
				break;
			case 'e':
				printf("Please input your seat number: ");
				ret = scanf("%d", &num);
				if (ret != 1)
				{
					printf("input error.\n");
					break;
				}
				ret = del_seat(s, num);
				if(ret == -1)
				{
					printf("del seat failed\n");
					break;
				}
				ret = save_to_file(FILENAME, s, NUM);
				if(ret == -1)
				{
					printf("save to file failed\n");
					break;
				}
				while(getchar() != '\n');
				break;
			case 'f':
				printf("Bye.\n");
				return 0;
			default:
				//show_menu();
				break;
		}
		show_menu();
		ch = getchar();
		while(getchar() != '\n');
	}
	return 0;
}

void init_seat(Seat *ps, int num)
{
	int i;
	
	if (NULL == ps)
	{
		fprintf(stderr, "init failed.\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < num ; i++)
	{
		ps[i].num = i;
		ps[i].booked = 0;
		strcpy(ps[i].firstname, "");
		strcpy(ps[i].lastname, "");
	}
	
}

void show_menu(void)
{
	printf("To choose a function, enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
}

void show_num(Seat * seat, int n)
{
	int i;
	int count = 0;
	
	printf("Empty seat: \n");
	for(i = 0; i < n; i++)
	{
		if(seat[i].booked == 0)
		{
			count++;
			printf("%d\t", seat[i].num);
		}
		if(count % 6 == 0 && seat[0].num != 0)
		{
			printf("\n");
		}
	}
	printf("total : %d\n", count);
}

void show_list(Seat *ps, int n)
{
	int i;
	
	if (NULL == ps)
	{
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < n; i++)
	{
		if(ps[i].booked == 0)
			printf("seat %d: empty\n", i);
		else	
			printf("seat %d: booked.\n", i);
	}
}
void show_list_byalpha(Seat *ps, int n)
{
	show_list(ps, n);
}
int assign_seat(Seat *ps, int num, char firstname[], char lastname[])
{
	int i;
	
	if (NULL == ps|| NULL == firstname || NULL == lastname)
	{
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < num; i++)
	{
		if(ps[i].booked == 0)
		{
			ps[i].booked = 1;
			strcpy(ps[i].firstname, firstname);
			strcpy(ps[i].lastname, lastname);
			return ps[i].num;
		}
	}
	printf("booked full\n");
	return -1;
}
int del_seat(Seat *ps, int num)
{
	if (NULL == ps)
	{
		exit(EXIT_FAILURE);
	}
	if(num < 0 || num >NUM)
	{
		return -1;
	}
	ps[num].booked = 0;
	strcpy(ps[num].firstname, "");
	strcpy(ps[num].lastname, "");
	return 0;
}
int read_from_file(char *filename, Seat *ps, int n)
{
	FILE * fp;
	int num;
	int booked;
	char firstname[LEN];
	char lastname[LEN];
	int i;
	
	fp = fopen(filename, "r");
	if(NULL == fp)
	{
		fprintf(stderr, "open file failed\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < n; i++)
	{
		if(fscanf(fp, "%d", &num) != 1)	return -1; 	
		if(fscanf(fp, "%d", &booked) != 1)	return -1; 
		if(booked == 1)
		{
			if(fscanf(fp, "%s", firstname)!= 1)	return -1;
			if(fscanf(fp, "%s", lastname)!= 1)		return -1;
		}
		
		
		ps[i].num = num;
		ps[i].booked = booked;
		if(booked == 1)
		{
			strcpy(ps[i].firstname, firstname);
			strcpy(ps[i].lastname, lastname);
		}
	}
	fclose(fp);
	return 0;
}

int save_to_file(char *filename, Seat * ps, int n)
{
	FILE * fp;
	int i;
	
	fp = fopen(filename, "w+");
	if(NULL == fp)
	{
		fprintf(stderr, "open file failed\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < n; i++)
	{
		fprintf(fp, "%d", ps[i].num);	
		fprintf(fp, "%c", ' ');
		fprintf(fp, "%d", ps[i].booked); 
		fprintf(fp, "%c", ' ');
		fprintf(fp, "%s", ps[i].firstname);	
		fprintf(fp, "%c", ' ');
		fprintf(fp, "%s", ps[i].lastname);
		fprintf(fp, "%c", '\n');
	}
	if(i != n )
	{
		printf("save failed\n");
		exit(EXIT_FAILURE);
	}
	printf("save success.\n");
	fclose(fp);
	return 0;
}
