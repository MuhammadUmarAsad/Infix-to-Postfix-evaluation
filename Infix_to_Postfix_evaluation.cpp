#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//character stack class
class StackChar
{
    char *arr;
    int top;
    int maxSize;

public:
    //constructor
    //size of array will be 30 else what user gives
    StackChar(int ms = 30)
    {
        arr = new char[ms];
        maxSize = ms;
        top = -1;
    }

    //checking if the stack is empty or not
    bool isEmpty()
    {
        return top < 0;
    }

    //checking if the stack is full or not
    bool isFull()
    {
        return top == (maxSize - 1);
    }

    void Push(char element)
    {
        if (!isFull())
        {
            //pushing the character in the array
            arr[++top] = element;
        }
    }

    char Pop()
    {
        /*list is not empty and we have to remove
            * the element at the top and 
            * return the element 
            */
        char element = ' ';
        if (!isEmpty())
        {
            element = arr[top];
            arr[top] = -1;
            top--;
        }
        return element;
    }

    void Clear()
    {
        //reinitilazing the stack from the start
        top = -1;
    }

    //returns the value of the peak element to n if stack is not empty
    void peak(char *n)
    {
        if (isEmpty())
        {
        }

        *n = arr[top];
    };
};

//integer stack class
class StackInt
{
    int *arr;
    int top;
    int maxSize;

public:
    //constructor
    //size of array will be 30 else what user gives
    StackInt(int ms = 30)
    {
        arr = new int[ms];
        maxSize = ms;
        top = -1;
    }

    //checking if the stack is empty or not
    bool isEmpty()
    {
        return top < 0;
    }

    //checking if the stack is full or not
    bool isFull()
    {
        return top == (maxSize - 1);
    }

    void Push(int element)
    {
        if (!isFull())
        {
            //pushing the character in the array
            arr[++top] = element;
        }
        else
            cout << "Stack is already Full" << endl;
    }

    int Pop()
    {
        /*list is not empty and we have to remove
        * the element at the top and 
        * return the element 
        */
        int element = NULL;
        if (!isEmpty())
        {
            element = arr[top];
            arr[top] = -1;
            top--;
        }
        return element;
    }

    void Clear()
    {
        //reinitilazing the stack from the start
        top = -1;
    }

    //returns the value of the peak element to n if stack is not empty
    void peak(int *n)
    {
        if (isEmpty())
        {
            return;
        }
        *n = arr[top];
    };
};

//checks the opening brackets
bool isOpeningBracket(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

//checks closing brackets
bool isClosingBracket(char c)
{
    return (c == ')' || c == '}' || c == ']');
}

//checks if character is a operator or not
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

//checking the precedence of the operators to see if we have to remove operators form stack or not
bool correctPrecedence(char top, char o)
{
    return (isOpeningBracket(o) || isOpeningBracket(top) || ((o == '/' || o == '*') && (top == '+' || top == '-')) || (o == '^' && top != '^'));
}

//in development feature to check all kinds of brackets
void isSqClBracket(char bracket)
{
    if(bracket == ']')
    {

    }
}

void isFlClBracket(char bracket)
{
    if(bracket == '}')
    {

    }
}
void isCClBracket(char bracket)
{
    if(bracket == ')')
    {

    }
}


//Infix to Postfix Class
class InfixToPostfix
{
    //variables to use in Infix to postfix Evaluation
    StackInt outputStack;
    string number;
    double above, below, result;

    //variables to use in Infix to postfix conversation
    StackChar operatorStack;
    string postFixTerm = "", temp = "";
    char temp_char = ' ', temp_char_1 = ' ';

//public functions
public:
    string InfixToPostfixConversation(string infixExpression)
    {

        for (int i = 0; i <= infixExpression.size(); i++)
        {
            if (isdigit(infixExpression[i]))
            {
                temp += infixExpression[i];
            }
            else
            {
                //appending the number to the postfixterm from the temo
                //and adding a whitespace in after it
                postFixTerm += temp;
                postFixTerm += " ";
                temp = "";

                operatorStack.peak(&temp_char);
                if (temp_char == ' ' || correctPrecedence(temp_char, infixExpression[i]))
                {
                    operatorStack.Push(infixExpression[i]);
                }

                else if (isClosingBracket(infixExpression[i]))
                {
                    temp_char_1 = operatorStack.Pop();
                    while (!isOpeningBracket(temp_char_1))
                    {
                        postFixTerm += temp_char_1;
                        postFixTerm += ' ';
                        temp_char_1 = operatorStack.Pop();
                    }
                }

                else
                {
                    if (!correctPrecedence(temp_char, infixExpression[i]) || infixExpression[i] == temp_char)
                    {
                        postFixTerm += operatorStack.Pop();
                        postFixTerm += ' ';
                        operatorStack.Push(infixExpression[i]);
                    }

                    if (!correctPrecedence(temp_char, infixExpression[i]))
                    {
                        while (!operatorStack.isEmpty() && !correctPrecedence(temp_char, infixExpression[i]))
                        {
                            postFixTerm += operatorStack.Pop();
                            postFixTerm += ' ';
                            operatorStack.peak(&temp_char);
                        }
                        operatorStack.Push(infixExpression[i]);
                    }
                }
            }
        }
        return postFixTerm;
    }

    double PostfixEvaluation(string postfixExpression)
    {
        
        for (int i = 0; i < postfixExpression.size(); i++)
        {
            if (isdigit(postfixExpression[i]))
            {
                number += postfixExpression[i];
            }
            else if (postfixExpression[i] == ' ' && number != "")
            {
                    outputStack.Push(stod(number));
                    number = "";
                
            }

            else if (isOperator(postfixExpression[i]))
            {
                above = outputStack.Pop();
                below = outputStack.Pop();

                if (postfixExpression[i] == '+')
                {
                    result = below + above;
                }
                else if (postfixExpression[i] == '-')
                {
                    result = below - above;
                }
                else if (postfixExpression[i] == '*')
                {
                    result = below * above;
                }
                else if (postfixExpression[i] == '/')
                {
                    result = below / above;
                }
                else if (postfixExpression[i] == '^')
                {
                    result = pow(below, above);
                }
                outputStack.Push(result);
            }
        }
        return result;
    }
};

//Function to remove the all the white spaces form the expression
template <typename T, typename P>
T remove_if(T beg, T end, P pred)
{
    T dest = beg;
    for (T itr = beg; itr != end; ++itr)
        if (!pred(*itr))
            *(dest++) = *itr;
    return dest;
}

int main()
{
    InfixToPostfix p;
    string infix;
    string postfix;
    double result;
    cout << "Enter the infix expression:  ";
    getline(cin, infix);
    infix.erase(remove_if(infix.begin(), infix.end(), ::isspace), infix.end());
    cout << "The infix without spaces is :  " << infix << endl;
    postfix = p.InfixToPostfixConversation(infix);
    cout << "The PostFix Expression is :  " << postfix << endl;
    result = p.PostfixEvaluation(postfix);
    cout << "The evaluated answer is :" << result << endl;

    return 0;
}