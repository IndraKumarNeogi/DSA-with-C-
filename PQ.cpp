#include<iostream>
using namespace std;
class Node{
    public:
        int data,priority;
        Node* next;
        Node(int d,int p){
            data=d;
            priority=p;
            next=nullptr;
        }
};
class PQ{
    Node* front;
    public:
        PQ(){
            front=NULL;
        }
        void insert(int d,int p);
        void remove();
        void display();
        bool isEmpty();
};
int main(){
    PQ llst;
    while(true){
        int num,item,priority;
        cout<<"1.insert"<<endl;
        cout<<"2.remove"<<endl;
        cout<<"3.display"<<endl;
        cout<<"0.exit"<<endl;
        cout<<"Enter 1/2/3/0:";
        cin>>num;
        switch(num){
            case 1:cout<<"Enter inserting item:";
                cin>>item;
                cout<<"Enter pririty:";
                cin>>priority;
                llst.insert(item,priority);
                break;
            case 2:llst.remove();
                break;
            case 3:llst.display();
                break;
            case 0:exit(0);
        }
    }
    return 0;
}
void PQ::insert(int d,int p) {
    Node* newNode = new Node(d,p);
    if(front==NULL || p<front->priority){
        newNode->next = front;
        front=newNode;
        return;
    }
    Node* temp=front;
    while(temp->next!=NULL && temp->next->priority<=p){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    //cout << "Inserted " << d << " at the beginning.\n";
}
bool PQ::isEmpty(){
    return (front==NULL);
}
void PQ::remove(){
    if(isEmpty()){
        cout<<"Queue is Empty."<<endl;
        return;
    }
    Node* temp = front;
    front=front->next;
    delete(temp);
    //cout << "Inserted " << value << " at the end.\n";
}
void PQ::display() {
    Node* temp = front;
    cout<< "Present Priority Queue is: ";
    if(front==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    while (temp!=NULL) {
        cout << "<"<<temp->data << "," << temp->priority << "> ";
        temp = temp->next;
    }
    cout << "\n";
}