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
		while (data[j] >= data[key] && j > start)
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

int main()
{
	//퀵정렬
	int number4[]{ 3,7,8,1,5,9,6,10,2,4 };

	//평균적인시간복잡도 O(n*logN)
	//정렬 돼있을떄 시간복잡도 O(n^2)
	quickSort(number4, 0, 10 - 1);

	for (int i = 0; i < 10; ++i)
	{
		std::cout << number4[i] << '\n';
	}
}


