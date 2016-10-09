#include "sort.h"
#include <stdlib.h>

static int median(Element arr[], int left, int mid, int right);
static void mergeArray(Element arr[], int left, int mid, int right, Element temp[]);
static void rmSort(Element arr[], int left, int right, Element temp[]);
static void adjust(Element arr[], int root, int n);
//将元素e,按照key插入到有序数组中，当前数组有序个数为i
void insert(Element arr[], int i, Element e)
{
	if(i == LENGTH)
	{
		fprintf(stderr, "array is fulled.\n");
		return;
	}
	//find the posision
	while(i >= 0 && e.key < arr[i].key)
	{
		arr[i+1] = arr[i];
		i--;
	}
	//insert
	arr[i+1] = e;
}

void insertSort(Element arr[], int n)
{
	int i;
	
	for(i = 1; i < n; i++)
	{
		insert(arr, i-1, arr[i]);
	}
}

//折半插入排序
void insertSort_im1(Element arr[], int n)
{
	int i;
	
	for(i = 1; i < n; i++)
	{
		int left = 0;
		int right = i -1;
		int mid = 0;
		int j;
		Element temp = arr[i];//保存值，不然移动数组时会被覆盖
		//查找插入位置
		while(left <= right)
		{
			mid = (left + right)/2;

			if(arr[i].key >= arr[mid].key)//关键字相同时放在这能保持排序的稳定性
			{
				left = mid + 1;
			}
			else
			{
				right = mid -1;
			}				
		}
		//移动元素，存储新插入的元素
		for(j = i -1; j > right; j--)
			arr[j+1] = arr[j];
		//插入
		arr[right+1] = temp;
	}
}
/*
void insertSort_im2(List plist)
{
	Node * pnode = plist;//pnode 用于遍历有序表
	Node * tail = plist->link;//tail 指向有序表尾
	Node * current;//current 指向无序表
	
	
	if(!tail)//空表
	{
		return;
	}
	
	while(current = tail->link)
	{
		//查找插入位置
		while(pnode != tail && current->e.key >= pnode->link->e.key)
		{
			pnode = pnode->link;
		}
		if(pnode != tail)
		{
			tail->link = current->link;//删除当前结点
			current->link = pnode->link;//将当前结点插入有序表
			pnode->link = current;
		}
		//如果pnode == tail说明当前结点是最大结点
		else
		{
			tail = tail->link;//更新尾节点
		}
		pnode = plist;//重置遍历结点
	}
}
*/
void insertNode(List plist, Node * pnode)//有序表上插入一个结点
{
	Node * prev = plist;
	Node * current = prev->link;
	
	if(!pnode)
		return;
	while(current&& pnode->e.key >= current->e.key)
	{
		prev = current;
		current = current->link;
	}
	pnode->link = prev->link;
	prev->link = pnode;
}

void insertSort_im2(List plist)
{
	Node * current = plist->link;
	
	plist->link = NULL;//重置为空表,表示有序表
	while(current)
	{
		Node * temp;
		
		temp = current->link;  //需要保存下一个连接，因为下面插入结点的函数会修改current的内容
		insertNode(plist, current);
		current = temp;
	}
}

void quickSort(Element arr[], int left, int right)
{
	int mid;
	
	if(left < right)
	{
		mid = partition(arr, left, right);
		quickSort(arr, left, mid-1);
		quickSort(arr, mid+1, right);
	}
}

int partition(Element arr[], int left, int right)
{
	Element base;
	Element temp;
	int min;
	
	base = arr[left];
	min = left;
	
	while(left < right)
	{
		while(arr[right].key >= base.key && right > left)
			right--;
		while(arr[left].key <= base.key && left < right)
			left++;
		if(left != right)
		{
			temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
		}
	}
	arr[min] = arr[left];
	arr[left] = base;
	
	return left;
}

void quickSort_im(Element arr[], int left, int right)
{
	int mid;
	
	if(left < right)
	{
		mid = partition_im(arr, left, right);
		quickSort(arr, left, mid-1);
		quickSort(arr, mid+1, right);
	}
}

int partition_im(Element arr[], int left, int right)
{
	Element base;
	Element temp;
	int min, mid;
	
	mid = (left + right)/2;
	min = median(arr, left, mid, right);//选择三者中的中间值
	//min = left;
	base = arr[min];
	
	//将中轴元素与左端点元素交换位置
	if(min != left)
	{
		temp = arr[min];
		arr[min] = arr[left];
		arr[left] = arr[min];
		min = left;
	}
	
	while(left < right)
	{
		while(arr[right].key >= base.key && right > left)
			right--;
		while(arr[left].key <= base.key && left < right)
			left++;
		if(left < right)
		{
			temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
		}
	}

	arr[min] = arr[left];
	arr[left] = base;
		
	return left;
}

static int median(Element arr[], int left, int mid, int right)
{
	int ret;
	
	if((arr[left].key - arr[mid].key) * (arr[left].key - arr[mid].key) <= 0)
		ret = left;
	else if ((arr[mid].key - arr[left].key) * (arr[mid].key - arr[right].key) <= 0)
		ret = mid;
	else
		ret = right;
	
	return ret;
}

void mergeSort(Element arr[], int n)
{
	Element temp[n];
	
	rmSort(arr, 0, n -1, temp);
}

void rmSort(Element arr[], int left, int right, Element temp[])
{
	int mid = (left + right)/2;
	
	if(left >= right)
		return;
	rmSort(arr, left, mid, temp);
	rmSort(arr, mid + 1, right, temp);
	mergeArray(arr, left, mid, right, temp);
}

void mergeArray(Element arr[], int left, int mid, int right, Element temp[])
{
	int i, j, k;//i for list1, j for list2, k for list3
	
	i = left;
	j = mid+1;
	k = 0;
	
	while(i <= mid && j <= right)
	{
		if(arr[i].key <= arr[j].key)
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	
	while(j <= right)
		temp[k++] = arr[j++];
	
	while(i <= mid)
		temp[k++] = arr[i++];
	//此处是要将temp中从【0， K）区间的	元素拷贝到arr中
	for(i = 0; i < k; i++)
		arr[left+i] = temp[i];
}

void heapSort(Element arr[], int n)
{
	int i;
	Element temp;
	
	//由低向上构建大根堆
	for(i = n/2; i >= 1; i--)
	{
		adjust(arr, i, n);
	}

	for(i = n; i > 1; i--)
	{
		//将第一个元素和最后一个元素交换
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
		//结点数量减一，重新调整堆
		adjust(arr, 1, i-1);
	}
}

static void adjust(Element arr[], int root, int n)
{
	int child = 2 * root;
	Element temp = arr[root];
	int key = arr[root].key;
	
	while(child <= n)
	{
		//查找关键字更大的孩子
		if(child < n && arr[child].key < arr[child + 1].key)
			child++;
		if(key > arr[child].key)
			break;
		arr[root] = arr[child];
		root = child;
		child = child * 2;
	}
	arr[root] = temp;
}
