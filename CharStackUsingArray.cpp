#include <iostream>
#include <string.h>
using namespace std;

int SIZE = 20;

class char_stack
{
    char arr[SIZE];
    int top;

public:
    char_stack()
    {
        top = -1;
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = '0';
        }
    }
    ~char_stack()
    {
        //  delete []arr;
    }
    char pop();
    void push(char d);
    char peek();
    bool isEmpty();
    bool isFull();
    void display();
    bool validate(char *);
    bool match(char, char);
};

void char_stack::push(char d)
{
    if (top == SIZE - 1)
    {
        cout << "\nStack is full..";
    }
    else
    {
        top = top + 1;
        arr[top] = d;
    }
}

char char_stack::pop()
{
    char data = '0';
    if (top == -1)
    {
        cout << "\nStack is empty...";
    }
    else
    {
        data = arr[top];
        top = top - 1;
    }
    return data;
}

bool match(char a, char b)
{
    if ((a == '[') && (b == ']'))
    {
        return true;
    }
    else if ((a == '[') && (b == ']'))
    {
        return true;
    }
    else if ((a == '[') && (b == ']'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validate(char *str)
{
    int i;
    char temp;
    char_stack s;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (s.isEmpty())
            {
                cout << "\nRight parenthesis are more";
                return false;
            }
            else
            {
                temp = s.pop();
                if (!(match(temp, str[i])))
                {
                    cout << "\nMismatched parenthesis are: " << temp << " " << str[i] << "\n";
                    return false;
                }
            }
        }
    }
    if (s.isEmpty())
    {
        cout << "\nParenthesis are matched";
        return true;
    }
    else
    {
        cout << "\nleft parenthesis are more";
        return false;
    }
}
char char_stack::peek()
{
    char data;
    if (top == -1)
    {
        cout << "\nStack is empty...";
        return '0';
    }
    else
    {
        data = arr[top];
        return data;
    }
}

bool char_stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool char_stack::isFull()
{
    if (top == SIZE - 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void char_stack::display()
{
    int i;
    cout << "\n";
    for (i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    char_stack obj;
    obj.push('s');
    obj.push('e');
    obj.push('j');
    obj.push('a');
    obj.push('l');

    obj.display();
    cout << "\nDeleted data: " << obj.pop();
    cout << "\nDeleted data: " << obj.pop();
    cout << "\nDeleted data: " << obj.pop();
    obj.display();

    cout << "\nParenthesis validation: " << validate("{9}");

    return 0;
}