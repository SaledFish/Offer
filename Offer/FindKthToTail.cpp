/*
链表中倒数第k个节点
*/

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
	ListNode *pAhead = pListHead;
	ListNode *pBhead = nullptr;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		pAhead = pAhead->m_pNext;
	}

	pBhead = pListHead;

	while (pAhead->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBhead = pBhead->m_pNext;
	}

	return pBhead;
}

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
	if (pListHead == nullptr || k == 0)
		return nullptr;

	ListNode *pAhead = pListHead;
	ListNode *pBhead = nullptr;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (pAhead->m_pNext != nullptr)
			pAhead = pAhead->m_pNext;
		else
			return nullptr;
	}

	pBhead = pListHead;

	while (pAhead->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBhead = pBhead->m_pNext;
	}

	return pBhead;
}