/*
二叉搜索树的后序遍历序列
*/

bool VerifySquenceOfBTS(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
		return false;

	int root = sequence[length - 1];

	//在二叉搜索树种左子树节点的值小于根节点的值
	int i = 0;
	for (; i < length - 1; i++)
	{
		if (sequence[i] > root)
			break;
	}

	//在二叉搜索树种右子树节点的值大于根节点的值
	int j = i;
	for (; j < length - 1; ++j)
	{
		if (sequence[j] < root)
			return false;
	}

	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
		left = VerifySquenceOfBTS(sequence, i);

	//判断右子树是不是二叉搜索树
	bool right = true;
	if (i < length - 1)
		right = VerifySquenceOfBTS(sequence + i, length - i - 1);

	return (left&&right);
}