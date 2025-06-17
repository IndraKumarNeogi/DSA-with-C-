#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int value){
            data=value;
            next=nullptr;
        }
};
class CLL{
    Node* last;
    public:
        CLL(){
            last=NULL;
        }
        /*~CLL(){
            while(head!=NULL){
                Node *temp=head;
                head=head->next;
                delete(temp);
            }
        }*/
        void insertAtBeginning(int value);
        void insertAtEnd(int value);
        void deleteFromBeginning();
        void deleteFromEnd();
        void display();
        //bool search(int value);
        void deleteItem(int);
};
int main(){
    CLL llst;
    while(true){
        int num,item;
        cout<<"1.insertAtBeginning"<<endl;
        cout<<"2.insertAtEnd"<<endl;
        cout<<"3.deleteFromBeginning"<<endl;
        cout<<"4.deleteFromEnd"<<endl;
        cout<<"5.deleteItem"<<endl;
        cout<<"6.display"<<endl;
        cout<<"7.search"<<endl;
        cout<<"0.exit"<<endl;
        cout<<"Enter 1/2/3/4/5/6/7/0:";
        cin>>num;
        switch(num){
            case 1:cout<<"Enter inserting item:";
                cin>>item;
                llst.insertAtBeginning(item);
                break;
            case 2:cout<<"Enter inserting item:";
                cin>>item;
                llst.insertAtEnd(item);
                break;
            case 3:llst.deleteFromBeginning();
                break;
            case 4:llst.deleteFromEnd();
                break;
            case 5:cout<<"Enter deleting item:";
                cin>>item;
                llst.deleteItem(item);
                break;
            case 6:llst.display();
                break;
            /*case 7:cout<<"Enter searching item:";
                cin>>item;
                cout<< llst.search(item)<<endl;
                break;*/
            case 0:exit(0);
        }
    }
    return 0;
}
void CLL::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    if(last==NULL){
        newNode->next=newNode;
        last=newNode;
        cout << "Inserted " << value << " at the beginning.\n";
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}
void CLL::insertAtEnd(int value){
    Node* newNode = new Node(value);
    if(!last){
        newNode->next=newNode;
    }else{
        newNode->next=last->next;
        last->next=newNode;
    }
    last=newNode;
    cout << "Inserted " << value << " at the end.\n";
}
void CLL::deleteFromBeginning(){
    if(!last){
        cout << "List is empty. Cannot delete.\n";
        return;
    }else if(last->next==last){
        delete(last);
        last=NULL;
    }else{
        Node* temp=last->next;
        last->next=temp->next;
        delete(temp);
    }
    cout << "Deleted from the beginning.\n";
}
void CLL::deleteFromEnd(){
    if(!last){
        cout << "List is empty. Cannot delete.\n";
    }
    else if(last->next->data==last->data){
        delete(last);
        last=NULL;
    }
    else{
        Node* current=last;
        while(current->next->data!=last->data){
            current=current->next;
        }
        current->next=last->next;
        delete(last);
        last=current;
    }
    cout << "Deleted from the End.\n";
}
void CLL::deleteItem(int value){
    if(last==NULL){
        cout << "List is empty. Cannot delete.\n";
        return;
    }
    Node* current=last;
    while(current->next->data!=value){
        current=current->next;
        if(current==last){
            cout<<"Item Not found.\n"<<endl;
            return;
        }
    }
    Node* temp=current->next;
    current->next=current->next->next;
    delete(temp);
    last=current;
    cout << "Deleted the Item.\n";
}
/*bool CLL::search(int value) {
    Node* current = head;
    while (current!=NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}*/
void CLL::display() {
    if(last==NULL){
        cout<<"Empty List.\n"<<endl;
        return;
    }
    Node* current = last->next;
    cout<< "Present Circular LinkedList is: ";
    do{
        cout << current->data << " ";
        current = current->next;
    }while(current!=last->next);
    cout << "\n";
}