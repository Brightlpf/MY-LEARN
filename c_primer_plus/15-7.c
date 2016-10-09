#include <stdio.h>
#include <stdlib.h>
#define ID	255UL
#define SIZE 255UL<<8
#define ALIGNMENT 03UL << 16
#define BOLD 01UL << 18
#define ITALIC 01UL << 19
#define UNDERLINE 01UL << 20

void init(unsigned int * font);
void showmenu(unsigned long font);
void getinput(unsigned int * input);

char alignment[4][10] = {"left", "right", "center"};
char on_off[2][10] = {"off", "on"};

int main(void)
{
	unsigned int font;
	unsigned int newfont;
	int ch;
	unsigned int input;
	
	init(&font);
	newfont = font;
	//printf("font = %d\n", font);
	showmenu(font);
	
	ch = getchar();
	ch = tolower(ch);
	while(ch != 'q' && ch != EOF)
	{
		while(getchar() != '\n')
			continue;
		switch(ch)
		{
			case 'f':
				printf("please input the id: ");
				getinput(&input);
				newfont &= 0xFFFF00;
				newfont |= input & ID;
				break;
			case 's':
			printf("please input the size: ");
				getinput(&input);
				newfont &= 0xFF00FF;
				newfont |= input<< 8 & SIZE;
				break;
			case 'a':
			printf("please input the alignment: ");
				getinput(&input);
				newfont &= 0xFCFFFF;
				newfont |= input<<16 & ALIGNMENT;
				break;
			case 'b':
			printf("please input the bold: ");
				getinput(&input);
				newfont &= 0xFBFFF;
				newfont |= input<<18 & BOLD;
				break;
			case 'i':
			printf("please input the italic: ");
				getinput(&input);
				newfont &= 0xF7FFFF;
				newfont |= input<<19 & ITALIC;
				break;
			case 'u':
			printf("please input the underline: ");
			    getinput(&input);
				newfont &= 0xEFFFFF;
				newfont |= input<<20 & UNDERLINE;
				break;
			
			default:
				break;
		}
		showmenu(newfont);
		ch = getchar();
	}
	puts("Bye!");
	return 0;
}

void init(unsigned int * font)
{
	*font  = 1 | 12<<8 | 2<<16 ;
}

void showmenu(unsigned long font)
{
	printf("%s %s %s %s %s %s\n", "ID","SIZE", "ALIGNMENT","B","I","U");
	printf("%2d %2d %9s %s %s %s\n\n", font & ID, font>>8&SIZE>>8, alignment[font>>16&03], \
	on_off[font>>18&01], on_off[font>>19&01], on_off[font>>20&01]);
	
	printf("f)change font    s)change size    a)change alignment\n");
	printf("b)toggle bold    i)toggle italic  u)toggle underline\n");
	printf("q)quit\n");
}

void getinput(unsigned int * input)
{
	if(scanf("%d", input) != 1)
	{
		fprintf(stderr, "getinput err\n");
		exit(1);
	}
	while(getchar() != '\n')
		continue;
}
