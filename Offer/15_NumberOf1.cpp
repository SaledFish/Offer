/*
二进制中1的个数
*/

int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
			count++;
		n = n >> 1;
	}

	return count;
}


int NumberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
			count++;
		flag = flag << 1;
	}
	return count;
}


int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	}
	return count;
}