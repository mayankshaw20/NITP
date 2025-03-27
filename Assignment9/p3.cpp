// Write a program in C to implement Bubble sort to sort a linked list in ascending order.

#include<iostream>
using namespace std;

struct Node{
int data;
Node* next;
    Node(int x){
data=x;
next=NULL;
    }
};
class LinkedList{
    public:
    Node* head;
    LinkedList ():
    head(nullptr){}
    void insert(Node* head, int data){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
        }
        else{
        newnode->next=head;
        head=newnode;}
    }
    void delete_all(Node* head){
        while(head!=NULL){
            Node* temp=head;
            head=head->next;
            free(temp);
        }
    }
    Node* find_tail(Node* head){
        Node* temp=head;
        Node* tail=NULL;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        tail=temp;
        return tail;
    }
    void print_list(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
    }
    void bubble_sort(Node* head,Node* tail){
        if (!head) return; // Check for empty list
        bool swapped = true; // Initialize swapped to true
        while(swapped){
            swapped = false; // Reset swapped for this pass

            Node* ptr1 = head;


            while (ptr1 && ptr1->next){
                if(ptr1->data>ptr1->next->data){
                    swap(ptr1->data,ptr1->next->data);
                    swapped= true;
                }
                ptr1=ptr1->next;
            }
        }
    }
};
int main(){
    LinkedList list ;
    list.insert(5);

    list.insert(3);

    list.insert(8);

    list.insert(1);

    list.insert(4);


    std::cout << "Original list: ";

    list.print_list();


    // Sort the linked list

    list.bubble_sort();


    std::cout << "Sorted list: ";

    list.print_list();


    return 0;

}
}