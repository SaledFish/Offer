/*
������������˫������
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

	//pLastNodeInListָ��˫�������β�ڵ�
	//������Ҫ����ͷ���
	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr&&pHeadOfList->m_pLeft != nullptr)
		pHeadOfList = pHeadOfList->m_pLeft;

	return pHeadOfList;
}