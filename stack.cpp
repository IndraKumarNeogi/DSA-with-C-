#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 5

class Stack{
    int  arr[MAX];
    int top;
    int item;
    public:
    Stack();
    void push();
    void pop();
    void display();
    bool isempty();
    bool isfull();
    void peek();
    void getSize();
};
    Stack::Stack(){
        top=-1;
    }
    void Stack::push(){
        if(isfull()){
            cout<<"Stack Is Full...Cannot Push"<<endl;
        }
        else{
            cout<<"Enter The Value To be Insert:";
            cin>>item;
            top++;
            arr[top]=item;
        }
    }
    void Stack::pop(){
        if(isempty()){
            cout<<"Stack is Empty...Cannot Pop:"<<endl;
        }
        else{
            cout<<"The Deleted Item is :"<<arr[top];
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
    void  Stack::peek(){
        if(!isempty()){
            cout<<"The Top Element is:"<<arr[top]<<endl;
        }
        else{
           cout<<"Stack is Empty.No Top Element:"<<endl; 
        }
    }
    void Stack::getSize(){
        cout<<"The Size Of The Stack is:"<<top+1<<endl;
    }
/*
int main(){
    system("cls");
    int choice;
    int loop=1;
    Stack arr;
    do{
        cout<<endl<<"Enter 1 to Display The Elements Of The Stack:"<<endl;
        cout<<"Enter 2 to Insert a Element in The Stack:"<<endl;
        cout<<"Enter 3 to Delete a Element From The Stack:"<<endl;
        cout<<"Enter 4 to Peek the Element From The Stack:"<<endl;
        cout<<"Enter 5 to Get The Size of the Stack:"<<endl;
        cout<<"Enter 0 to Exit:"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice:";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:
                arr.display();
                break;
            case 2:
                arr.push();
                break;
            case 3:
                arr.pop();
                break;
            case 4:
                arr.peek();
                break;
            case 5:
                arr.getSize();
                break;
            case 0:
                loop=0;
                break;
            default:
                cout<<"Something Error....Invalid Choice"<<endl; 
        }
    }while(loop!=0);
    return 0;
}
*/