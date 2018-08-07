/*
��������˳��ʹ����λ��ż��ǰ��
*/

void ReorderOddEven(int *pData, unsigned int length)
{
	if (pData == nullptr || length == 0)
		return;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		//����ƶ�pBegin��ֱ����ָ��ż��
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;

		//��ǰ�ƶ�pEnd��ֱ����ָ������
		while (pBegin < pEnd && (*pEnd & 0x1) == 0)
			pEnd--;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}