#include <iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node* next;
};

class Stack
{
    public:
    int count;
    Node* top;
    
    Stack():count(0),top(NULL)
    {}
    
    void push(char datain)
    {
        Node* t = new Node();
        t->data = datain ;
        t->next = top ;
        top = t;
        count++;
    }
    
    char pop()
    {
        if(empty())
            return '\0';
        else
        {
            Node* t = top;
            char dataout = t->data;
            top = t->next;
            delete t;
            count--;
            return dataout;
        }
       
    }
    
    bool empty()
    {
        return count==0;
    }
    
    char t()
    {
         if (!empty()) {
            return top->data;
        }
        return '\0';
    }
    
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    Stack operators;
    string postfix;
    
    for (char c : infix) {
        if (isalnum(c))
        {
            postfix += c;
        } 
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')') 
        {
            while (!operators.empty() && operators.t() != '(')
            {
                postfix += operators.t();
                operators.pop();
            }
            operators.pop(); // Remove the '('
        } 
        else 
        {
            while (!operators.empty() && precedence(c) <= precedence(operators.t()))
            {
                postfix += operators.t();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) 
    {
        postfix += operators.t();
        operators.pop();
    }
    
    return postfix;
}

int main() 
{
     string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}