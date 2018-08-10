/*
1~n整数中1出现的次数
*/

//本题书中的方法不够直观，不够好，采用的另一种 O(logN)的算法

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
		return 0;

	int count = 0;
	int base = 1;
	int round = n;

	while (round > 0)
	{
		int weight = round % 10;
		round /= 10;
		count += round*base;

		if (weight == 1)
			count += (n%base) + 1;
		else if (weight > 1)
			count += base;

		base *= 10;
	}
	return count;
}