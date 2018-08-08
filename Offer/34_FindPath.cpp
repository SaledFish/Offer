/*
二叉树中和为某一值的路径
*/

#include <vector>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void FindPath(BinaryTreeNode *pRoot, int expectedSum, std::vector<int>& path, int currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//如果是叶节点，并且路径上节点值的和等于输入的值
	//则打印出这条路径
	bool isLeaf = pRoot->m_pLeft == nullptr&&pRoot->m_pRight == nullptr;
	if (currentSum == expectedSum&&isLeaf)
	{
		printf("A path is found: ");
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
			printf("%d\t", *iter);

		printf("\n");
	}

	//如果不是叶节点，则遍历它的叶节点
	if (pRoot->m_pLeft != nullptr)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

	//在返回父节点之前，在路径上删除当前节点
	path.pop_back();
}

void FindPath(BinaryTreeNode *pRoot, int expectedSum)
{
	if (pRoot == nullptr)
		return;

	std::vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}