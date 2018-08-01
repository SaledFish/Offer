#include <stack>
#include <exception>

template<typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template<typename T> void VQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new std::exception("queue is empty");

	T head = stack2.top();
	stack2.pop();

	return head;
}