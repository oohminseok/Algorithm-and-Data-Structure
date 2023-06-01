#include <iostream>

const int STACK_SIZE = 10;

struct Stack
{
    int container[STACK_SIZE]{};
    int top = -1;
};

enum Command
{
    PUSH=1,
    POP=2
};

void PrintInfo();
void ProcessUserInput(Stack& stack);
void Push(Stack& stack, int value);
void Pop(Stack& stack);
void PrintStack(Stack& stack);

int main2()
{

    Stack myStack;

    while (true)
    {
       PrintInfo();
       ProcessUserInput(myStack);
       PrintStack(myStack);
    }
   

}

void PrintInfo()
{
    std::cout << "1:push,2:pop" << std::endl;
    std::cout << "__________________" << std::endl;
}

void ProcessUserInput(Stack& stack)
{
    int command;

    std::cin >> command;

    switch (command)
    {
        case PUSH:
        {
            int value;
            std::cout << "    push value?";
            std::cin >> value;
            Push(stack, value);
            break;
        }

        case POP:
        Pop(stack);
        break;

        default:
        std::cout << "Invalid Command!" << std::endl;
        break;


    }
}

void Push(Stack& stack,int value)
{
    if (stack.top>=STACK_SIZE-1)
    {
        std::cout << "STACK is full!!" << std::endl;
        return;
    }

    stack.container[++stack.top] = value;
}

void Pop(Stack& stack)
{
    if (stack.top<0)
    {
        std::cout << "STACK is empty" << std::endl;
        return;
    }

    std::cout << stack.container[stack.top--] << "is pop!" << std::endl;
}

void PrintStack(Stack& stack)
{
    std::cout << "----stack----" << std::endl;

    //stack is empty
    if (stack.top < 0)
    {
        std::cout << "STACK is empty!" << std::endl;
        return;
    }

    for (int i = stack.top; i >= 0; --i)
    {
        std::cout << stack.container[i] << std::endl;
    }
    std::cout << "----stack----" << std::endl;
}
