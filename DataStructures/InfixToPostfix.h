#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H
#include "Stack.cpp"

struct InfixToPostfix
{
    InfixToPostfix(char* c) : infix{c}, postfix{} {}
    char* toPostfix();
    int Evaluate();
private:
    bool isCharacter(char c);
    int precidance(char c);
    const char* infix {nullptr};
    char* postfix {nullptr};

};
#endif // INFIXTOPOSTFIX_H
