#include <iostream>
#include <string>
using namespace std;

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

    char Peak()
    {
        //returning the element at the top of the stack
        return arr[top];
    }
};

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
            cout << "Stack is already Full"<<endl;
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

    int Peak()
    {
        if(!isEmpty())
        {
            //returning the element at the top of the stack
            return arr[top];
        }
        else
            return NULL;
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
    cout << "Hello, World!";
    string s = "Hello My Name Is Umar";
    cout << "Enter expression: ";
    getline(cin, s);
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());

    cout << s << endl;
    return 0;
}