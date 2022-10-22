#include "Algorithm.h"


int* Bubble_Sort(int input[], int length) //冒泡排序
{
	int* output = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		output[i] = input[i];
	}
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (output[j] > output[j + 1])
			{
				swap(&output[j], &output[j + 1]);
			}
		}
	}
	return output;
}
int* Selection_Sort(int input[], int length) //选择排序
{
	int* output = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		output[i] = input[i];
	}
	for (int i = 0; i < length - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (output[j] < output[minIndex])
			{
				minIndex = j;
			}
		}
		swap(&output[i], &output[minIndex]);
	}
	return output;
}
int* Insertion_Sort(int input[], int length) //插入排序
{
	int* output = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		output[i] = input[i];
	}

	for (int i = 1; i < length; i++)
	{
		int j;
		int temp = output[i];
		for (j = i - 1; j >= 0 && output[j] > temp; j--)
		{
			output[j + 1] = output[j];
		}
		output[j + 1] = temp;
	}

	return output;
}
int* Shell_Sort(int input[], int length) //Shell排序
{
	int* output = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		output[i] = input[i];
	}
	int gap = length / 2;
	while (gap > 0) {
		for (int i = gap; i < length; i++) //增量为gap的插入排序
		{
			int preIndex = i - gap;
			int current = output[i];
			while (preIndex >= 0 && current < output[preIndex])
			{
				output[preIndex + gap] = output[preIndex];
				preIndex -= gap;
			}
			output[preIndex + gap] = current;
		}
		gap /= 2;
	}
	return output;
}
int* Shell3n_Sort(int input[], int length) //Shell3n排序
{
	int* output = (int*)malloc(sizeof(int) * length);

	for (int i = 0; i < length; i++)
	{
		output[i] = input[i];
	}
	int gap = 1;
	while (gap < length / 3) {
		gap = 3 * gap + 1;
	}
	while (gap > 0) {
		for (int i = gap; i < length; i++) //增量为gap的插入排序
		{
			int preIndex = i - gap;
			int current = output[i];
			while (preIndex >= 0 && current < output[preIndex])
			{
				output[preIndex + gap] = output[preIndex];
				preIndex -= gap;
			}
			output[preIndex + gap] = current;
		}
		gap /= 3;
	}
	return output;
}


int* Merge_Sort(int input[], int length) //归并排序
{
	int* output = (int*)malloc(sizeof(int) * length);

	Divide(input, 0, length - 1, output);

	return output;
}
void Divide(int* array, int begin, int end, int* output) //分算法
{
	if (begin < end)
	{
		int mid = begin + (end - begin) / 2;

		Divide(array, begin, mid, output);
		Divide(array, mid + 1, end, output);
		Conquer(array, begin, mid, end, output);
	}
}
void Conquer(int* array, int begin, int mid, int end, int* output)
{
	int i = begin;
	int j = mid + 1;
	int t = 0;

	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
		{
			output[t++] = array[i++];
		}
		else {
			output[t++] = array[j++];
		}
	}
	while (i <= mid)
	{
		output[t++] = array[i++];
	}
	while (j <= end)
	{
		output[t++] = array[j++];
	}

	t = 0;

	while (begin <= end)
	{
		array[begin++] = output[t++];
	}
}


void ListPermutations(string str)
{
	PermuteWithFixedPrefix(str, 0);
}
void PermuteWithFixedPrefix(string str, int k)
{
	if (k == strlen(str))
	{
		printf("%s\n", str);
	}
	else {
		for (int i = k; i < strlen(str); i++)
		{
			ExchangeCharacters(str, k, i);
			PermuteWithFixedPrefix(str, k + 1);
			ExchangeCharacters(str, k, i);
		}
	}
}
void ExchangeCharacters(string str, int p1, int p2)
{
	char tmp;
	tmp = str[p1];
	str[p1] = str[p2];
	str[p2] = tmp;
}





int fibocir(int n) //斐波那契循环算法
{
	int f1 = 1;
	int f2 = 1;
	int fn = 0;

	if (n == 1 || n == 2)
	{
		return 1;
	}
	for (int i = 1; i <= n - 2; i++)
	{
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}

	return fn;
}
int fibofun(int n) //斐波那契迭代算法
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return fibofun(n - 2) + fibofun(n - 1);
}




bool isPrime(int n)  //素数判断
{
	if (n == 1)
	{
		return false;
	}
	else if (n == 2)
	{
		return 1;
	}
	else {
		for (int i = 2; i <= sqrt(n) + 1; i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}

		return true;
	}
}



double fact(int n)  //阶乘计算
{
	double result = 1;

	for (int i = 1; i <= n; i++)
	{
		result = result * i;
	}

	return result;
}



int digitCount(long int n) //计算数字位数
{
	int result = 0;

	if (n < 0)
	{
		n = -n;
	}
	do
	{
		n = n / 10;
		result++;
	} while (n > 0);

	return result;
}



int gcd(int a, int b) //最大公约数
{
	return (a % b == 0) ? b : gcd(b, a % b);
}

void swap(Item* a, Item* b)
{
	Item temp = *a;

	*a = *b;
	*b = temp;
}



void printCycleSquare(int n)
{
	int i, j, k, a[10][10];

	k = 1;
	for (i = 0; i < n / 2; i++)
	{
		for (j = i; j < n - 1 - i; j++)
		{
			a[i][j] = k++;
		}
		for (j = i; j < n - 1 - i; j++)
		{
			a[j][n - 1 - i] = k++;
		}
		for (j = n - i - 1; j > i; j--)
		{
			a[n - i - 1][j] = k++;
		}
		for (j = n - i - 1; j > i; j--)
		{
			a[j][i] = k++;
		}
	}
	if (n % 2 == 1)
	{
		a[n / 2][n / 2] = k;
	}
	for (i = 0; i <= n - 1; i++)
		for (j = 0; j <= n - 1; j++)
		{
			if (j == n - 1)
			{
				printf("%d\n", a[i][j]);
			}
			else {
				printf("%d\t", a[i][j]);
			}
		}
}




void QuickSort(int* input, int length)
{
	Qsort(input, 0, length - 1);
}
void  Qsort(int* input, int Left, int Right)
{
	int  pivot = Median3(input, Left, Right);
	int i = Left, j = Right;
	if (i < j) {
		while (i != j)
		{
			while (j > i && input[j] >= pivot)--j;
			input[i] = input[j];
			while (i < j && input[i] <= pivot)++i;
			input[j] = input[i];
		}
		input[i] = pivot;
		QuickSort(input, Left, i - 1);
		QuickSort(input, i + 1, Right);
	}
		
}
int Median3(int* input, int Left, int Right)
{
	int  Center = (Left + Right) / 2;
	int arr[3];
	arr[0] = input[Left];
	arr[1] = input[Center];
	arr[2] = input[Right];
	if (arr[0] <= arr[1]) {
		if (arr[1] <= arr[2]) {
			return arr[1];
		}
		else {
			if (arr[0] >= arr[2]) {
				return arr[0];
			}
			else {
				return arr[2];
			}
		}
	}
	else {
		if (arr[1] >= arr[2]) {
			return arr[1];
		}
		else {
			if (arr[0] >= arr[2]) {
				return arr[2];
			}
			else {
				return arr[0];
			}
		}
	}
}