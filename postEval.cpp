#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define MAX 20
char postfix[100],ch,val;

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

int isdigit(char ch){
    return (ch>='0'&&ch<='9');
}

int calculate(int op1,int op2,char x){
    if(x=='^')
        return pow(op1,op2);
    if(x=='*')
        return op1*op2;
    if(x=='/')
        return op1/op2;
    if(x=='+')
        return op1+op2;
    if(x=='-')
        return op1-op2;
}
int evaluatePostfix(){
    int i=0,op1,op2,ans;
    Stack s;
    while(postfix[i]!='\0'){
        char ch=postfix[i];
        if(isdigit(ch))
            s.push(ch-'0');
        else {
            op2=s.top();
            s.pop();
            op1=s.top();
            s.pop();
            ans=calculate(op1,op2,ch);
            s.push(ans);
        }
        s.display();
        i++;
    }
    return s.top();
}
int main(){
    cout<<"Enter postfix exp.:";
    cin>>postfix;
    cout<<"After evaluation:"<<evaluatePostfix();
    return 0;
}