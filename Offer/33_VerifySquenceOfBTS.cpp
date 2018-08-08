/*
�����������ĺ����������
*/

bool VerifySquenceOfBTS(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
		return false;

	int root = sequence[length - 1];

	//�ڶ������������������ڵ��ֵС�ڸ��ڵ��ֵ
	int i = 0;
	for (; i < length - 1; i++)
	{
		if (sequence[i] > root)
			break;
	}

	//�ڶ������������������ڵ��ֵ���ڸ��ڵ��ֵ
	int j = i;
	for (; j < length - 1; ++j)
	{
		if (sequence[j] < root)
			return false;
	}

	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i > 0)
		left = VerifySquenceOfBTS(sequence, i);

	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < length - 1)
		right = VerifySquenceOfBTS(sequence + i, length - i - 1);

	return (left&&right);
}