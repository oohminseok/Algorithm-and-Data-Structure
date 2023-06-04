#include <iostream>


void quickSort(int* data, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)
	{
		while (data[i] <= data[key])
		{
			i++;

		}
		while (data[j] >= data[key]&&j>start)
		{
			j--;
		}
		if (i > j)
		{
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else
		{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}


int sorted[8];
void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n)
	{
		if (a[i] <= a[j])
		{
			sorted[k] = a[i];
			i++;
		}
		else
		{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = a[t];
			k++;
		}
	}
	for (int t = m; t <= n; t++)
	{
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main()
{
	//선택정렬
	int number[10]{ 1,10,5,8,7,6,4,3,2,9 };

	int i, j, min, index, temp;

	//시간복잡도 O(n^2)
	for (i = 0; i < 10; ++i)
	{
		min = 9999;
		for (j = i; j < 10; ++j)
		{
			if (min > number[j])
			{
				min = number[j];
				index = j;
			}
		}
		temp = number[i];
		number[i] = number[index];
		number[index] = temp;
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << number[i] << '\n';
	}

	//버블 정렬
	int number2[]{ 1,10,5,8,7,6,4,3,2,9 };
	
	//시간복잡도 O(n^2)
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 9-i; ++j)
		{
			if (number2[j] > number2[j+1])
			{
				temp = number2[j];
				number2[j] = number2[j + 1];
				number2[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << number2[i] << '\n';
	}

	//삽입정렬
	int number3[]{ 1,10,5,8,7,6,4,3,2,9 };

	//시간복잡도 O(n^2)
	for (int i = 0; i < 9; ++i)
	{
		j = i;
		while (number3[j] > number3[j + 1])
		{
			temp = number3[j];
			number3[j] = number3[j + 1];
			number3[j + 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << number3[i] << '\n';
	}

	//퀵정렬
	int number4[]{ 3,7,8,1,5,9,6,10,2,4 };

	//평균적인시간복잡도 O(n*logN)
	//정렬 돼있을떄 시간복잡도 O(n^2)
	quickSort(number4, 0, 10-1);

	for (int i = 0; i < 10; ++i)
	{
		std::cout << number4[i] << '\n';
	}

	//병합정렬
	int number5[8]{ 7,6,5,8,3,5,9,1 };
	mergeSort(number5, 0, 7);
	for (int i = 0; i < 8; ++i)
	{
		std::cout << number5[i];
	}

}