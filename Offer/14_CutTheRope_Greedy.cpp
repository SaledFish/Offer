/*
�����ӣ�̰���㷨
*/

#include <cmath>

int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	//�����ܶ�ļ�ȥ����Ϊ3�����Ӷ�
	int timesOf3 = length / 3;

	//���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����Ӷ�
	//��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2�����Σ���Ϊ2*2>3*1

	if (length - timesOf3 * 3 == 1)
		timesOf3 -= 1;

	int timesOf2 = (length - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3))*(int)(pow(2, timesOf2));
}