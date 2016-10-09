#include "Stack.h"
#define DIR 8
#define EXIT_ROW 11
#define EXIT_COL 14

typedef struct {
	short int vert;
	short int horiz;
}Offsets; //表示移动方向数据结构


Offsets move[DIR] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};//共8个方向

void showpath(Stack * st);// 输出走出迷宫的路径

int maze[12][15] = {
	{0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
	{0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1},
	{1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
	{1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1},
	{0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1},
	{0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},
	{0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0}
};//迷宫， 0 表示可以通过， 1表示不可以通过

int main()
{
	Stack *pst;
	int mark[12][15]; //1表示走过的位置
	int i, j;
	Element current; //当前位置
	Element next; //下一个位置
	int success = 0; //成功标识
	
	pst = initStack();
	if(NULL == pst)
	{
		printf("initStack failed.\n");
		exit(1);
	}
	
	/*初始化标记为0*/
	for(i = 0; i < 12; i++)
		for(j = 0; j < 15; j++)
			mark[i][j] = 0;
	
	//起点入栈，并记录足迹
	current.row = 0;
	current.col = 0;
	current.dir = 0;
	PUSH(pst, current);
	mark[current.row][current.col] = 1;
	
	while(!isEmpty(pst)) //栈不空
	{
		int dirc;
		
		if(current.row == EXIT_ROW && current.col == EXIT_COL)  //当前位置就是出口
		{
			printf("Congraturation! you find the way!\n");
			success = 1;
			showpath(pst);
			break;
		}

		for(dirc = 0; dirc < DIR; dirc++) //遍历各个方向
		{
			//根据当前的方向计算下一个坐标
			current.dir = dirc;
			next.row = current.row + move[current.dir].vert;
			next.col = current.col + move[current.dir].horiz;
			
			//如果下一个坐标不合法就跳到下一个方向
			if(next.row < 0 || next.col < 0 || mark[next.row][next.col] == 1 || next.row > 11 || next.col > 14 ||
				maze[next.row][next.col] == 1)
			{
				if(dirc == DIR -1)  //如果所有方向的下一个位置都不合法，就退栈
				{
					POP(pst, &current);//如果起点位置被退栈说明迷宫无解
					printf("pop: row = %d, col = %d\n", current.row, current.col);
					getTop(pst, &current); //重新设置当前位置
					break;
				}
				continue;
			}
		
			if(maze[next.row][next.col] == 0)//下一个位置合法，入栈，记录足迹，重新设置当前位置
			{
				current = next;
				PUSH(pst, current);
				printf("push: row = %d, col = %d\n", current.row, current.col);
				mark[current.row][current.col] = 1;
				break;
			}
		
		}
	}
	
	if(!success)
	{
		printf("There is no way to go, Bye.\n");
	}
	
	return 0;
}

void showpath(Stack * st)
{
	Element path[st->top + 1];
	int i = 0;
	int count = 0;
	while(!isEmpty(st))
	{
		POP(st, &path[i++]);
	}
	while(i--)
	{
		printf("(%d, %d) -> ", path[i].row, path[i].col);
		if(count++ % 5 == 4)
			printf("\n");
	}
	printf("success.\n");
}
