#include "bintree.h"

int main(void)
{
	BtreePointer tree;
	
	tree = create();
	printf("show vlr: ");
	show_vlr(tree);
	printf("\nshow vlr recycle: ");
	show_vlr_c(tree);
	printf("\nshow lvr: ");
	show_lvr(tree);
	printf("\nshow lvr recycle: ");
	show_lvr_c(tree);
	printf("\nshow lrv : ");
	show_lrv(tree);
	printf("\nshow lrv recycle: ");
	show_lrv_c(tree);
	printf("\nshow level: ");
	show_level(tree);
	printf("\ntotal node: %d\n", sum_node(tree));
	
	destory(tree);
	return 0;
}
