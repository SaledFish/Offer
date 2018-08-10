/*
礼物的最大价值
*/
#include <algorithm>

int getMaxValue_solution(const int *values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0)
		return 0;

	int **maxValue = new int*[rows];
	for (int i = 0; i < rows; ++i)
		maxValue[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int left = 0;
			int up = 0;

			if (i > 0)
				left = maxValue[i - 1][j];
			if (j > 0)
				up = maxValue[i][j - 1];

			maxValue[i][j] = std::max(left, up) + values[i*cols + j];
		}
	}

	int maxValues = maxValue[rows - 1][cols - 1];

	for (int i = 0; i < rows; ++i)
		delete[]maxValue[i];
	delete[]maxValue;

	return maxValues;
}


int getMaxValue_solution2(const int *values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0)
		return 0;

	int *maxValues = new int[cols];
	for(int i=0;i<rows;++i)
		for (int j = 0; j < cols; ++j)
		{
			int left = 0;
			int up = 0;

			if (i > 0)
				up = maxValues[j];
			if (j > 0)
				left = maxValues[j - 1];

			maxValues[j] = std::max(left, up) + values[i*cols + j];
		}

	int maxValue = maxValues[cols - 1];
	delete[]maxValues;
	return maxValue;
}