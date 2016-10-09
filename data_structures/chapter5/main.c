#include "Stack.h"
#include "tree.h"
/*
 (A(B(E(K, L), F),C(G),D(H(M),I,J)))
 (a(b,d(e,f(g, h, i)), j))
 (A(b,d(e,f(g, h, i)), j))

 (a(B,d(e,f(g, h, i)), j))
 (a(b,D(e,f(g, h, i)), j))
 (a(b,d(E,f(g, h, i)), j))
 (a(b,d(e,F(g, h, i)), j))
 (a(b,d(e,f(G, h, i)), j))
 (a(b,d(e,f(g, H, i)), j))
 (a(b,d(e,f(g, h, I)), j))
 (a(b,d(e,f(g, h, i)), J))
 (a(b,d(e,f(g, h, i), k), j))
*/
int main()
{
	NodePointer tree;
	NodePointer cptree;
	NodePointer newtree;
	int ret;
	
	printf("请输入广义表：\n");
	ret = getTree(&tree);
	if(!ret)
	{
		printf("getTree error.\n");
		exit(1);
	}
	printf("Output：\n");
	printf("(");
	showTree(&tree);
	printf(")\n");
	
	printf("copy tree: \n");
	copyTree(&cptree, &tree);
	printf("(");
	showTree(&cptree);
	printf(")\n");
	
	ret = isEqual(&tree, &cptree);
	if(ret)
	{
		printf("tree and cp tree is equaled.\n");
	}
	else
	{
		printf("tree and cp tree is not equaled.\n");
	}
	printf("请输入另外一个广义表： ");
	getTree(&newtree);
	ret = isEqual(&tree, &newtree);
	if(ret)
	{
		printf("tree and  new tree is equaled.\n");
	}
	else
	{
		printf("tree and new tree is not equaled.\n");
	}
	
	destoryTree(&tree);
	destoryTree(&cptree);
	return 0;
}
