/*
二叉搜索树与双向链表
*/

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode *Convert(BinaryTreeNode *pRootOfTree)
{
	BinaryTreeNode *pLastNodeInList = nullptr;
	ConvertNode(pRootOfTree, &pLastNodeInList);

	//pLastNodeInList指向双向链表的尾节点
	//我们需要返回头结点
	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr&&pHeadOfList->m_pLeft != nullptr)
		pHeadOfList = pHeadOfList->m_pLeft;

	return pHeadOfList;
}