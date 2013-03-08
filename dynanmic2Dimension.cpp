void dynanmic2Dimension()
{
	//方法1：c++方式
	//分配
	int **b=new int*[row];       //分配一个指针数组，将其首地址保存在b中
	for(i=0;i<row;i++)             //为指针数组的每个元素分配一个数组
		b[i]=new int[col];
	//释放
	//需先释放指针数组的每个元素指向的数组，然后再释放该指针数组
	for(i=0;i<row;i++)
	{
		delete [col]b[i];
		b[i]=NULL;
	}
	delete [row]b;
	b=NULL;
	//方法2：先定义一个一维数组的类型，然后再用该类型定义一个一维数组（实际上已经成为二维的）相当于递归定义
	//分配
	typedef int array[COL];       //使用typedef定义一个具有COL个元素的数组类型
	array *a;  //定义二维数组,与一维数组相同
	a=new array[row]; //为该一维数组（实际上二维）申请空间
	//释放
	//该方法定义的动态二维数组的释放只需以下语句即可
	delete[] a;
	a=NULL;
}