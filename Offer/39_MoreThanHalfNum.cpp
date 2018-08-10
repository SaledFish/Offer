/*
数组中出现次数超过一半的数字
*/
#include <exception>

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Parameters");

	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}

	++small;
	Swap(&data[small], &data[end]);

	return small;
}

int MoreThanHalfNum(int *numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
		return 0;

	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}

	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;

	return result;
}