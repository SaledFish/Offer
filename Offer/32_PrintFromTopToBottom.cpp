/*
从上到下打印二叉树
*/

#include <deque>
#include <queue>
#include <stack>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void PrintFromTopToBottom(BinaryTreeNode *pTreeRoot)
{
	if (!pTreeRoot)
		return;

	std::deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pTreeRoot);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		printf("%d", pNode->m_nValue);

		if (pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft);

		if (pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);
	}
}


//分层打印二叉树
void Print(BinaryTreeNode *pRoot)
{
	if (pRoot == nullptr)
		return;

	std::queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);
	int nextLevel = 0;
	int toBePrinted = 1;
	while (!nodes.empty())
	{
		BinaryTreeNode *pNode = nodes.front();
		printf("%d", pNode->m_nValue);
		
		if (pNode->m_pLeft != nullptr)
		{
			nodes.push(pNode->m_pLeft);
			++nextLevel;
		}

		if (pNode->m_pRight != nullptr)
		{
			nodes.push(pNode->m_pRight);
			++nextLevel;
		}
		nodes.pop();
		--toBePrinted;
		if (toBePrinted == 0)
		{
			printf("\n");
			toBePrinted = nextLevel;
			nextLevel = 0;
		}


	}
}

//之字形打印二叉树
void Print(BinaryTreeNode *pRoot)
{
	if (pRoot == nullptr)
		return;

	std::stack<BinaryTreeNode*> levels[2];
	int current = 0;
	int next = 1;

	levels[current].push(pRoot);
	while (!levels[0].empty() || !levels[1].empty())
	{
		BinaryTreeNode *pNode = levels[current].top();
		levels[current].pop();

		printf("%d", pNode->m_nValue);

		if (current == 0)
		{
			if (pNode->m_pLeft != nullptr)
				levels[next].push(pNode->m_pLeft);
			if (pNode->m_pRight != nullptr)
				levels[next].push(pNode->m_pRight);
		}
		else
		{
			if (pNode->m_pRight != nullptr)
				levels[next].push(pNode->m_pRight);
			if (pNode->m_pLeft != nullptr)
				levels[next].push(pNode->m_pLeft);
		}

		if (levels[current].empty())
		{
			printf("\n");
			current = 1 - current;
			next = 1 - next;
		}
	}
	
}