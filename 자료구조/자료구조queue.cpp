#include <iostream>

const int QUEUE_SIZE = 10;

struct Queue
{
	int container[QUEUE_SIZE]{};
	int head = 0;
	int tail = 0;
};

enum CommandQueue
{
	ENQUEUE = 1,
	DEQUEUE = 2
};

void PrintInfoQueue();
void ProcessUserInputQueue(Queue& queue);
void PrintQueue(Queue& queue);
void PushQueue(Queue& queue,int value);
void PopQueue(Queue& queue);

int main()
{
	Queue myQueue;
	while (true)
	{
		PrintInfoQueue();
		ProcessUserInputQueue(myQueue);
		PrintQueue(myQueue);
	}
}

void PrintInfoQueue()
{
	std::cout << "1.enque,2.dequeue" << std::endl;
	std::cout << "_________________" << std::endl;
}

void ProcessUserInputQueue(Queue& queue)
{
	int command;

	std::cin >> command;

	switch (command)
	{
		case ENQUEUE:
		{
			int value;
			std::cout << "    value?";
			std::cin >> value;
			PushQueue(queue, value);
			break;
		}

		case DEQUEUE:
		PopQueue(queue);
		break;

		default:
		std::cout << "Invalid Command!" << std::endl;
		break;

	}
}

void PrintQueue(Queue& queue)
{
	std::cout << "----queue----" << std::endl;

	int i = queue.head;

	if (queue.head == queue.tail)
	{
		std::cout << "EMPTY" << std::endl;
		return;
	}

	while (i != queue.tail)
	{
		i = (i + 1) % QUEUE_SIZE;
		std::cout << queue.container[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "____" << std::endl;
}

void PushQueue(Queue& queue, int value)
{
	if ((queue.tail +1) % QUEUE_SIZE == queue.head)
	{
		std::cout << "Queue is full!" << std::endl;
		return;
	}
	queue.tail = (queue.tail + 1) % QUEUE_SIZE;
	queue.container[queue.tail] = value;
}

void PopQueue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		return;
	}

	queue.head = (queue.head + 1) % QUEUE_SIZE;
	std::cout << queue.container[queue.head] << "is dequeue!" << std::endl;
}
