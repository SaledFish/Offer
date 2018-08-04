/*
��������˳��ʹ����λ��ż��ǰ�棬ʹ�ú���ָ�룬ģ�廯���򣬿�ʹ�ö����ж�����
*/

bool isEven(int n)
{
	return (n & 1) == 0;
}

void Reorder(int *pData, unsigned int length, bool(*func)(int))
{
	if (pData == nullptr || length == 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			++pBegin;

		while (pBegin < pEnd&&func(*pEnd))
			--pEnd;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

void ReorderOddEven(int *pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}