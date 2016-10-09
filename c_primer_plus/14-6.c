#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 20
#define PLYNUM 19

typedef struct
{
	char first[N];
	char last[N];
}Name;

typedef struct 
{
	int num;
	Name name;
	int count_play;
	int count_hit;
	int count_run;
	int count_rbi;
	float hit_rate;
}Softball;

int init_player(Softball player[], int num);
void err_proc(const char * str);
void get_word(const char src[], char (*word)[7][20], int n);
void save_struct(char (*word)[20], int n, Softball *playerinfo );
void show_player_info(Softball * player, int number);
void cal_hitrate(Softball * player);
int main(void)
{
	Softball player[PLYNUM];
	Softball player_temp;
	int ret;
	FILE *fp;
	char line[256];
	int i;
	char word[7][20];
	
	//初始化球员信息
	ret = init_player(player, PLYNUM);
	if( ret != 0)
	{
		err_proc("Init player error");
	}
	ret = init_player(&player_temp, 1);
	if( ret != 0)
	{
		err_proc("Init player_temp error");
	}
	//打开文件
	if((fp = fopen("ballinfo", "r")) == NULL)
	{
		err_proc("Open ballinfo failed!");
	}
	/*
	//读取信息到buffer,但是从bufer中更难处理数据，一次从文件中读取一个字节效率又太低？
	while((ret = fread(buffer, sizeof(char), BUFSIZ, fp)) !=0)
	{
		
	}
	*/
	while(fgets(line, 256, fp) != NULL)
	{

	 //将文件中数据存储到二维数组
		get_word(line, &word, 7);
	//将二维数组中数据存储到结构体
		save_struct(word, 7, &player_temp);
	//将临时结构体的数据加到最终结构体中
		for(i = 0; i < PLYNUM; i++)
		{
			if(player_temp.num == i)
			{
				strcpy(player[i].name.first, player_temp.name.first);
				strcpy(player[i].name.last, player_temp.name.last);
				player[i].count_play += player_temp.count_play;
				player[i].count_hit += player_temp.count_hit;
				player[i].count_run += player_temp.count_run;
				player[i].count_rbi += player_temp.count_rbi;
			}
		}
	}
	#ifdef DEBUG
	for(i = 0; i < PLYNUM; i++)
	{
		show_player_info(&player[i], i);
	}
	#endif
	printf("num:name			playtimes	hittimes	runtimes	rbitimes\n");
	for(i = 0; i < PLYNUM; i++)
	{
		cal_hitrate(&player[i]);
	}
	
	for(i = 0; i < PLYNUM; i++)
	{
		show_player_info(&player[i], i);
	}	
	fclose(fp);
	
	return 0;
}
int init_player(Softball player[], int num)
{
	int i;
	if(player == NULL)
	{
		return -1;
	}
	for(i = 0; i < num; i++)
	{
		player[i].num = 0;
		strncpy(player[i].name.first, "\0", 1);
		strncpy(player[i].name.last, "\0", 1);
		player[i].count_play = 0;
		player[i].count_hit = 0;
		player[i].count_run = 0;
		player[i].count_rbi = 0;
	}
	return 0;
}

void err_proc(const char * str)
{
	fprintf(stderr, str);
	exit(EXIT_FAILURE);
}

void show_player_info(Softball * player, int number)
{	
	printf("%d:	%s %s	%d	%d	%d	%d	%.2f%%\n", 
	number, player->name.first, player->name.last, player->count_play, player->count_hit, player->count_run, \
	player->count_rbi, player->hit_rate * 100);
}

void cal_hitrate(Softball * player)
{
	if(player->count_play == 0)
	{
		err_proc("cal_hitrate err");
	}
	player->hit_rate = player->count_hit * 1.0 / player->count_play;
}

void get_word(const char src[], char (*word)[7][20], int n)
{
	int i = 0;
	int j = 0;
	int index_src = 0;
	
	if(src == NULL || *word == NULL)
	{
		err_proc("get word err");
	}
	
	for(i = 0; i < n; i++)
	{
		//skip space
		while(isspace(src[index_src]))
		{
			index_src++;
		}
		for(j =0; src[index_src]!=' ' && src[index_src]!= '\n' && src[index_src] != EOF; j++, index_src++ )
		{
			(*word)[i][j] = src[index_src];
		}
		(*word)[i][j] = '\0';
	}
}

void save_struct(char (*word)[20], int n, Softball *playerinfo )
{
	int  j;
	int num = 0;
	
	if(word == NULL || n < 0)
	{
		err_proc("save_struct err");
	}
	#ifdef DEBUG
			printf("%d: get word : %s\n", __LINE__, str);
	#endif
	
	for(j = 0; j < strlen(word[0]); j++)
		num = num * 10 + word[0][j] - '0';
	playerinfo->num = num;
	strcpy(playerinfo->name.first, word[1]);
	strcpy(playerinfo->name.last, word[2]);
	
	num = 0;
	for(j = 0; j < strlen(word[3]); j++)
		num = num * 10 + word[3][j] - '0';
	playerinfo->count_play = num;
	
	num = 0;
	for(j = 0; j < strlen(word[4]); j++)
		num = num * 10 + word[4][j] - '0';
	playerinfo->count_hit = num;
	
	num = 0;
	for(j = 0; j < strlen(word[5]); j++)
		num = num * 10 + word[5][j] - '0';
	playerinfo->count_run = num;
	
	num = 0;
	for(j = 0; j < strlen(word[6]); j++)
		num = num * 10 + word[6][j] - '0';
	playerinfo->count_rbi = num;
}
