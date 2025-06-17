#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 5

class Queue{
    int arr[MAX];
    int front,rear;
    int item;
    public:
    Queue();
    void enqueue();
    void dequeue();
    bool isfull();
    bool isempty();
    void getSize();
    void peek();
    void display();
};
    Queue::Queue(){
        front=-1;
        rear=-1;
    }
    void Queue::enqueue(){
        if(!isfull()){
            cout<<"The Elements To be Inserted:";
            cin>>item;
            rear++;
            arr[rear]=item;
        }
        else{
            cout<<"Queue is Full...cannot Insert:"<<endl;
        }
    }
    void Queue::dequeue(){
        if(!isempty()){
            front++;
            cout<<"Deleted Item is:"<<arr[front];
        }
        else{
            cout<<"Queue is Empty..Cannot Dequeue:"<<endl;
        }
    }
    void Queue::display(){
        if(!isempty()){
            cout<<"The Elements of the Stack is:";
            for(int i=front+1;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }
            else{
                cout<<"Queue is Empty ..cannot Display:";
                cout<<endl;
            }
    }
    bool Queue::isempty(){
        return (front==rear);
    }
    bool Queue::isfull(){
        return (rear==MAX-1);
    }
    void Queue::peek(){
        if(!isempty()){
            cout<<"The Top Element is:"<<arr[front+1]<<endl;
        }
        else{
            cout<<"Queue is Empty.No Top Element:"<<endl;
        }
    }
    void Queue::getSize(){
        cout<<"The Size Of The Queue is:"<<rear-front<<endl;
    }
    int main(){
    system("cls");
    int choice;
    int loop=1;
    Queue arr;
    do{
        cout<<endl<<"Enter 1 to Display The Elements Of The Queue:"<<endl;
        cout<<"Enter 2 to Insert a Element in The Queue:"<<endl;
        cout<<"Enter 3 to Delete a Element From The Queue:"<<endl;
        cout<<"Enter 4 to Peek the Element From The Queue:"<<endl;
        cout<<"Enter 5 to Get The Size of the Queue:"<<endl;
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
                arr.enqueue();
                break;
            case 3:
                arr.dequeue();
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