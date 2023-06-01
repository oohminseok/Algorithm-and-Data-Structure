#include <iostream>

//2. 동적 queue
class Queue
{
private:
	struct queueList
	{
		int number;
		queueList* next;
	};

public:
	queueList* head;
	queueList* tail;
	queueList* temp;
	int mCount;
	int mNumber;

public:
	Queue() :head{}, tail{}, temp{}, mCount{}, mNumber{}
	{

	}
	~Queue()
	{
		while (head != nullptr)
		{
			if (head == tail)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
				temp = nullptr;
			}
			else if (head != tail)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
		}
	}

public:
	void Push()
	{
		std::cout << "push value?";
		std::cin >> mNumber;
		std::cout << std::endl;

		if (head == nullptr)
		{
			queueList* mPointer = new queueList;
			head = mPointer;
			tail = mPointer;
		}
		if (mCount < 10)
		{
			temp = head;
			++mCount;
			tail->number = mNumber;
			std::cout << std::endl;
			tail->next = new queueList;

			for (int i = 0; i < mCount; ++i)
			{
				std::cout << temp->number;
				temp = temp->next;
			}
			temp = head;
			tail = tail->next;
			std::cout << std::endl;
		}
	}

	void Pop()
	{
		if (0 < mCount)
		{
			std::cout << "pop value?";
			std::cout << head->number;
			temp = head;
			--mCount;
			head = head->next;
			delete temp;
			temp = head;
			std::cout << std::endl;

			for (int i = 0; i < mCount; ++i)
			{
				std::cout << head->number;
				head = head->next;
			}
			std::cout << std::endl;
			head = temp;
		}
		temp = nullptr;
		if (mCount == 0)
		{
			std::cout << "queue is empty" << std::endl;
		}
	}
};


int main()
{

	Queue queue;
	int number;
	while (true)
	{
		std::cout << "1:push,2:pop,3:exit" << std::endl;
		std::cin >> number;
		if (number == 1)
		{
			queue.Push();
		}
		if (number == 2)
		{
			queue.Pop();
		}
		if (number == 3)
		{
			break;
		}
	}
}


