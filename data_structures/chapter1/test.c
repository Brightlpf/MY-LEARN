void powerset(int arr[], int index, int n)
{
	//从第index个元素到第n-1个元素， 依次设置状态为 0和1， 每个元素构成2个分支
	if(index == n) //当判断完所有元素的状态后输出数组
	{
		//输出arr中所有状态为1的元素
	}
	else
	{
		arr[index] = 1;   //元素选中分支
		powerset(arr, index+1, n); //从下一个元素开始， 也有选中和不选中2中状态
		arr[index] = 0;  //元素未选中分支
		powerset(arr, index+1, n);
	}
}