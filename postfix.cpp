#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define MAX 20
char infix[100];
char postfix[100],ch;
char val;

class Stack{
    int  arr[MAX];
    int top;
    int val;
    public:
    Stack();
    void push(char);
    void pop();
    void display();
    bool isempty();
    bool isfull();
    char peek();
    void getSize();
};
    Stack::Stack(){
        top=-1;
    }
    void Stack::push(char val){
        if(isfull()){
            cout<<"Stack Is Full...Cannot Push"<<endl;
            exit(1);
        }
        else{
            top++;
            arr[top]=val;
        }
    }
    void Stack::pop(){
        if(isempty()){
            cout<<"Stack is Empty...Cannot Pop:"<<endl;
            exit(1);
        }
        else{
            top--;
        }
    }
    bool Stack::isempty(){
        return (top==-1);
    }
    bool Stack::isfull(){
        return (top==MAX-1);
    }
    void Stack::display(){
        if(isempty()){
            cout<<"Stack is empty..Cannot Display:";
            cout<<endl;
        }
        else{
            cout<<"The Elements Of The Array Is:";
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
        }
    }
    char  Stack::peek(){
        if(!isempty()){
            return arr[top];
        }
        else{
           cout<<"Stack is Empty.No Top Element:"<<endl; 
        }
    }
// for operator precdence check....
int precedence(char ch){
    if(ch=='^' || ch=='$')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else 
        return 0;
}
// for checking Alphanumeric...
int isAlphanumeric(char ch){
    if(ch >='a' && ch <='z')
        return 1;
    else if(ch >='A' && ch <='Z')
        return 1;
    else if(ch>='0' && ch <='9')
        return 1;
    else 
        return 0;
}

//for checking operater...
int isOperater(char ch){
    if(ch=='^' || ch=='$')
        return 1;
     else if(ch=='*' || ch=='/')
        return 1;
    else if(ch=='+' || ch=='-')
        return 1;
    else 
        return 0;
}
// Operand checking.....
int isOperand(char ch){
    if(isAlphanumeric(ch))
        return 1;
    else 
        return 0;
}
//infix to postfix function.....
void InfixtoPostfix(){
    int i=0,j=0;
    Stack s;
    while(infix[i]!='\0'){
        char ch=infix[i];
        if(isOperand(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='('){
            s.push(ch);
            }
        else if(ch==')'){
            while(s.peek()!='('){
                postfix[j++]=s.peek();
                s.pop();
            }
            s.pop();
        }
        else if(isOperater(ch)){
            if(!s.isempty() && s.peek()!='(' && precedence(ch) <= precedence(s.peek())){
                postfix[j++]=s.peek();
                s.pop();
            }
            s.push(ch);
        }
        else{
            cout<<"Invalid Expression..."<<endl;
        }
        i++;
    }
    while(!s.isempty()){
        postfix[j++]=s.peek();
        s.pop();
    }
    postfix[j]='\0';
}
/*
int operation(int a, int b, char op){
    if(op=='+')
        return b+a;
    else if(op=='-')
        return b-a;
    else if(op=='*')
        return b*a;
    else if(op=='/')
        return b/a;
    else if(op=='^')
        return pow(b,a);
}
*/
//int postfixEval()

int main(){
cout<<"Enter Your Infix Expression:";
cin>>infix;
InfixtoPostfix();
cout<<"The Postfix Expression is:"<<postfix<<endl;
return 0; 
}