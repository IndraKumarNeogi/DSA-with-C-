#include<iostream>
using namespace std;
class Node{
    public:
        int coeff,exp;
        Node* next;
        Node(int c,int e){
            coeff=c;
            exp=e;
            next=nullptr;
        }
};
class POLY{
    Node* head;
    public:
        POLY(){
            head=NULL;
        }
        POLY(const POLY& p){
            head=NULL;
            Node*temp=p.head;
            while(temp!=NULL){
                insertTerm(temp->coeff,temp->exp);
                temp=temp->next;
            }
        }
        ~POLY(){
            Node* curr=head;
            while(curr){
                Node* temp=curr;
                curr=curr->next;
                delete temp;
            }
        }
        POLY operator=(const POLY& p);
        void insertTerm(int c,int e);
        void display();
        POLY operator+(const POLY &p);
};
int main(){
    POLY p1,p2,p3;
    p1.insertTerm(10,3);
    p1.insertTerm(5,2);
    p1.insertTerm(2,1);
    p1.insertTerm(-7,0);

    p2.insertTerm(3,3);
    p2.insertTerm(-5,1);
    p2.insertTerm(4,0);

    cout<<"Polinomial 1:";
    p1.display();

    cout<<"Polinomial 2:";
    p2.display();
    
    p3=p1+p2;
    cout<<"Resultant Polynomial:";
    p3.display();

    return 0;
}
void POLY::insertTerm(int c,int e) {
    Node* newNode = new Node(c,e);
    if(!head){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
}
POLY POLY::operator=(const POLY &p){
    Node*temp=p.head;
    while(temp!=NULL){
        insertTerm(temp->coeff,temp->exp);
        temp=temp->next;
    }
    return(*this);
}
POLY POLY::operator+(const POLY& p){
    POLY result;
    Node* p1=head;
    Node* p2=p.head;

    while(p1&& p2){
        if(p1->exp==p2->exp){
            result.insertTerm(p1->coeff+p2->coeff,p1->exp);
           p1= p1->next;
           p2= p2->next;
        }else if(p1->exp>p2->exp){
            result.insertTerm(p1->coeff,p1->exp);
            p1=p1->next;
        }else{
            result.insertTerm(p2->coeff,p2->exp);
            p2=p2->next;
        }
    }
    while(p1){
        result.insertTerm(p1->coeff,p1->exp);
        p1=p1->next;
    }
    while(p1){
        result.insertTerm(p2->coeff,p2->exp);
        p2=p2->next;
    }
    return result;
}
void POLY::display() {
    Node* curr = head;
    while (curr){
        if(curr->exp==0){
            cout<<curr->coeff;
        }else cout<<curr->coeff<<"x"<<curr->exp;
        curr=curr->next;
        if(curr){
            if(curr->coeff>0)cout<<"+";
        }
    }
    cout << "\n";
}