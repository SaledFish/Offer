/*
¸´ÔÓÁ´±íµÄ¸´ÖÆ
*/

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pSibling;
};

void CloneNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		ComplexListNode *pClone = new ComplexListNode();
		pClone->m_nValue = pNode->m_nValue;
		pClone->m_pNext = pNode->m_pNext;
		pClone->m_pSibling = nullptr;

		pNode->m_pNext = pClone;

		pNode = pClone->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		ComplexListNode *pClone = pNode->m_pNext;
		if (pNode->m_pSibling != nullptr)
			pClone->m_pSibling = pNode->m_pSibling->m_pNext;

		pNode = pClone->m_pNext;
	}
}

ComplexListNode *ReconnectNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	ComplexListNode *pClonedHead = nullptr;
	ComplexListNode *pClonedNode = nullptr;

	if (pNode != nullptr)
	{
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode != nullptr)
	{
		pClonedHead->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pClonedHead;
}

ComplexListNode *Clone(ComplexListNode *pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}