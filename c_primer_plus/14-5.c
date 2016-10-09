#include <stdio.h>
#include <stdlib.h>
#define N 20
#define CSIZE 4

typedef struct
{
	char first_name[N];
	char last_name[N];
}Name;

typedef struct
{
	Name name;
	float score[3];
	float av_score;
}Student;

void display(Student *stu);
int get_score(float score[], int n);
float get_avscore(Student *stu);
float set_avscore(Student *stu);

int main(void)
{
	Student s[CSIZE];
	int ch, num;
	int i, j;
	
	//init student's name randly
	srand(time(NULL));
	for(i = 0; i < CSIZE; i++)
	{
		num = rand() % 10 + 1;
		for(j = 0; j < num; j++)
		{
			ch = rand() % 26 + 'a';
			s[i].name.first_name[j] = (char)ch;
			ch = rand() % 26 + 'a';
			s[i].name.last_name[j] = (char)ch;
		}
		s[i].name.first_name[j] = '\0';
		s[i].name.last_name[j] = '\0';
	}
	
	for(i = 0; i < CSIZE; i++)
	{
		get_score(s[i].score, 3);
		set_avscore(&s[i]);
	}
	
	for(i = 0; i < CSIZE; i++)
	{
		display(&s[i]);
		printf("\n\n");
	}
	
}

void display(Student *stu)
{
	printf("name: %s %s ", stu->name.first_name, stu->name.last_name);
	printf("score1：%4.2f score2: %4.2f score3: %4.2f\n", stu->score[0], stu->score[1], stu->score[2]);
	printf("average score: %.2f\n", stu->av_score);
}

int get_score(float score[], int n)
{
	if (score == NULL || n <= 0)
	{
		return -1;
	}
	
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("score%d: ", i);
		scanf("%f", &score[i]);
	}
	return 0;
}

float get_avscore(Student *stu)
{
	if(NULL == stu)
	{
		return -1;
	}
	return stu->av_score;
}

float set_avscore(Student *stu)
{
	if(NULL == stu)
	{
		return -1;
	}
	
	int i;
	float sum = 0;
	
	for(i = 0; i < 3; i++)
	{
		sum += stu->score[i];
	}
	return stu->av_score = sum/3;
}
