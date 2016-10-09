#include <stdio.h>
#define LENGTH 10   //数组最大长度

typedef struct Element{
	int key;
	/*other field*/
}Element;

typedef struct Node {
	Element e;
	struct Node * link;
}Node;

typedef Node * List;

int seqSearch(Element a[], int k, int n);
int binSearch(Element a[], int k, int n);
void sort(Element a[], int n);
void insertSort(Element arr[], int n);
void insert(Element arr[], int i, Element e);
void insertSort_im1(Element arr[], int n);//改进算法1，折半查找
void insertSort_im2(List plist);//改进算法2， 链表存储
void quickSort(Element arr[], int left, int right);
int partition(Element arr[], int left, int right);
void quickSort_im(Element arr[], int left, int right);//改进的快速排序算法
int partition_im(Element arr[], int left, int right);
void mergeSort(Element arr[], int n);
void heapSort(Element arr[], int n);