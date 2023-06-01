#include <iostream>

//1.동적 stack
class Stack
{
private:
	struct stackList
	{
		int number;
		stackList* next;
	};

private:
	stackList* mTop;
	stackList* mTemp;
	int mCount;
	int mNumber;

public:
	Stack() :mTop{}, mTemp{}, mCount{}, mNumber{}
	{

	}
	~Stack()
	{
		if (mTop != nullptr)
		{

			for (int i = 0; i < mCount; ++i)
			{
				mTemp = mTop;
				mTop = mTop->next;
				delete mTemp;
			}
			mTop = nullptr;
			mTemp = nullptr;
		}
	}

public:
	void Push()
	{
		std::cout << "push value?";
		std::cin >> mNumber;
		std::cout << std::endl;

		if (mTop == nullptr)
		{
			stackList* mPointer = new stackList;
			mTop = mPointer;
			mPointer->number = mNumber;
			++mCount;

			for (int i = 0; i < mCount; ++i)
			{
				std::cout << mPointer->number;
			}
			std::cout << std::endl;
			return;
		}

		if (0 < mCount)
		{
			stackList* mPointer = new stackList;
			mPointer->next = mTop;
			mPointer->number = mNumber;
			++mCount;
			mTop = mPointer;

			for (int i = 0; i < mCount; ++i)
			{
				std::cout << mPointer->number;
				mPointer = mPointer->next;
			}
			std::cout << std::endl;
			mPointer = mTop;
		}
	}

	void Pop()
	{
		if (0 < mCount)
		{
			std::cout << "pop value?";
			std::cout << mTop->number;
			std::cout << std::endl;

			mTemp = mTop;
			mTop = mTop->next;
			delete mTemp;
			--mCount;
			mTemp = mTop;

			for (int i = 0; i < mCount; ++i)
			{
				std::cout << mTop->number;
				mTop = mTop->next;
			}
			std::cout << std::endl;
			mTop = mTemp;
		}
		if (mCount == 0)
		{
			std::cout << "stack is empty" << std::endl;
			mTop = nullptr;
			mTemp = nullptr;
		}
	}

};

int main()
{
	Stack stack;
	int number;
	while (true)
	{
		std::cout << "1:push,2:pop,3:exit" << std::endl;
		std::cin >> number;

		if (number == 1)
		{
			stack.Push();
		}
		if (number == 2)
		{
			stack.Pop();
		}
		if (number == 3)
		{
			break;
		}
	}
}
