/*
二叉树的下一个节点,使用中序遍历
*/


struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
	BinaryTreeNode *m_pParent;
};

BinaryTreeNode *GetNext(BinaryTreeNode *pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode *pNext = nullptr;
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode *pRight = pNode->m_pRight;
		while (pRight != nullptr)
			pRight = pRight->m_pLeft;

		pNext = pRight;
	}
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode *pCurrent = pNode;
		BinaryTreeNode *pParent = pNode->m_pParent;
		while (pParent != nullptr&&pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}