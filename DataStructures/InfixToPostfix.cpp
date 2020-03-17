#include "InfixToPostfix.h"
#include <cstring>

bool InfixToPostfix::isCharacter(char c)
{
    return (c != '+' && c != '-' && c != '*' && c != '/');
}

int InfixToPostfix::precidance(char c)
{
    return (c == '+' || c == '-') ? 1 : 2;
}

char* InfixToPostfix::toPostfix()
{
    Stack<char> stack {};
    postfix = new char[strlen(infix)+2];
    int i{0}, j{0};
    while (infix[i] != '\0')
    {
        if(isCharacter(infix[i])) {postfix[j++] = infix[i++];}
        else
        {
            if(stack.Top() == nullptr || precidance(infix[i]) > precidance(stack.Top()->data))
            {
                stack.push(infix[i++]);
            }
            else
            {
                postfix[j++] = stack.pop();
            }
        }
    }

    while (stack.Top() != nullptr)
    {
        postfix[j++] = stack.pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int InfixToPostfix::Evaluate()
{
    Stack<int> stack {};
    for(int i = 0; postfix[i] != '\0'; ++i)
    {
        if(isCharacter(postfix[i]))
        {
            stack.push(postfix[i] - '0');
        }
        else
        {
            int rhs = stack.pop();
            int lhs = stack.pop();
            int result {0};
            switch (postfix[i])
            {
                case '+': result = lhs + rhs;
                break;
                case '-': result = lhs - rhs;
                break;
                case '*': result = lhs * rhs;
                break;
                case '/': result = lhs / rhs;
                break;
            }
            stack.push(result);
        }
    }

    return stack.Top()->data;
}


