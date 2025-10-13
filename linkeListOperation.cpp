//হhh
include<bits/stdc++.h>
#include<conio.h>
using namespace std;

//create generic node
struct node
{
    int data;
    struct node* next;
};
//all functions prototype
void insertion_at_head(int value,struct node* &head);
void insertion_at_tail(int value,struct node* &head);
int countingLength(struct node* &head);
void insertion_at_specific_position(int position,int value,struct node* &head);
void insertion_after_value(int key,int value,struct node* &head);
void delete_at_tail(struct node* &head);


//insertion at tail
void insertion_at_tail(int value,struct node* &head)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}//at tail

//insertion at head
void insertion_at_head(int value,struct node* &head)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}
//insertion at specific position
void insertion_at_specific_position(int position,int value,struct node* &head)
{
    int length=countingLength(head);
    struct node* newNode=(struct node*)malloc(sizeof(struct node*));
    newNode->data=value;
    struct node* temp=head;

    if(position<=0 || position>length)
    {
        cout<<"\tThe Linked List is Underflow"<<endl;
        return;
    }
    else if(position==1)
    {
        newNode->next=head;
        head=newNode;
        return;
    }
    else if(position>1 || position<length )
    {
        position--;
        for(int i=1; i<position; i++)
        {
            temp=temp->next;
        }

        newNode->next=temp->next;
        temp->next=newNode;
        return;
    }
    else if(position==length)
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
//insertion after value
void insertion_after_value(int key,int value,struct node* &head)
{
    //int position=1;
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    struct node* temp=head;
    if(head==NULL){
        cout<<"\tLinked List is Empty"<<endl;
        return;
    }
    while(temp->data!=key){
        temp=temp->next;
        if(temp==NULL)
            break;
    }
    if(temp==NULL){
        cout<<"\t"<<key<<" is not found"<<endl;
        return;
    }
    else if(temp->next==NULL){
        temp->next=newNode;
        newNode->next=NULL;
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;

}

//Deletion from tail
void delete_at_tail(struct node* &head)
{
    struct node* temp =head;
    if(head==NULL)
    {
        cout<<"\tThe Linked List is Empty"<<endl;
        return;
    }
    else if(head->next==NULL)
    {
        cout<<"\t"<<temp->data<<" is deleted"<<endl;
        free(temp);
        head=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        cout<<"\t"<<temp->next->data<<" is deleted"<<endl;
        free(temp->next);
        temp->next=NULL;
    }

}

//deletion from head
void delete_at_head(struct node* &head){

    if(head==NULL){
        cout<<"\tThe Linked List is Empty"<<endl;
        return;
    }
    else if(head->next==NULL){
        cout<<"\t"<<head->data<<" is deleted"<<endl;
        free(head);
        head=NULL;
    }
    else{
        struct node* temp=head;
        temp=temp->next;
        cout<<"\t"<<head->data<<" is deleted"<<endl;
        free(head);
        head=temp;
    }
}

//delete at specific position
void delete_at_specific_position(int position,struct node* &head){
    int length=countingLength(head);
    struct node* temp=head;
    struct node* deleteNode;
    if(position<=0 || position>length){                             // if invalid position
        cout<<"\tThis is invalid position"<<endl;
        return;
    }
    else if(head->next==NULL){                                     //have only head
        cout<<"\t"<<head->data<<" is deleted"<<endl;
        free(head);
        head=NULL;
    }
    else if(length==position){                                          //delete last element
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        deleteNode=temp->next;
        temp->next=NULL;
        free(deleteNode);
        cout<<"\t"<<temp->data<<" is deleted"<<endl;
    }
    else if(position==1){                                                //delete from first
        deleteNode=temp;
        temp=temp->next;
        cout<<"\t"<<deleteNode->data<<" is deleted"<<endl;
        free(deleteNode);
        head=temp;
    }
    else{                                                                       // delete from middle
        for(int i=1;i<=position-2;i++){
        temp=temp->next;
    }
    deleteNode=temp->next;
    cout<<"\t"<<temp->next->data<<" is deleted"<<endl;
    temp->next=temp->next->next;
    free(deleteNode);
    }
}
//deletion by value
void deletion_by_value(int key,struct node* &head){
    struct node* temp=head;
    struct node* deleteNode;

    if(temp->next==NULL && temp->data==key){
        cout<<"\t"<<temp->data<<" is deleted"<<endl;
        free(temp);
        head=NULL;
        return;
    }
    if(temp->next==NULL && temp->data!=key){
        cout<<"\t"<<key<<" is Not Found"<<endl;
        return;
    }
    else if(temp->data==key){
        deleteNode=temp;
         cout<<"\t"<<deleteNode->data<<" is deleted"<<endl;
         head=temp->next;
         free(deleteNode);
         return;
    }
    while(temp->next->data!=key){
        temp=temp->next;
        if(temp->next==NULL){
            break;
        }
    }
    if(temp->next==NULL){
        cout<<"\t"<<key<<" is Not Found"<<endl;
        return;
    }
    deleteNode=temp->next;
    temp->next=temp->next->next;
    cout<<"\t"<<deleteNode->data<<" is deleted"<<endl;
    free(deleteNode);

}

//update by position
void update_by_position(int position,int value,struct node* &head){
    struct node* temp=head;
    int length=countingLength(head);
    if(position<=0 || position>length || head==NULL){
        cout<<"\tInvalid Position or Empty Linked List"<<endl;
        return;
    }
    for(int i=2;i<=position;i++){
        temp=temp->next;
    }
    temp->data=value;
    cout<<"\t"<<temp->data<<" is updated"<<endl;
}

//update by value
void update_by_value(int key,int value,struct node* &head){
    struct node* temp=head;

    while(temp->data!=key){
        temp=temp->next;
       if(temp==NULL){
            break;
        }
    }
    if(temp==NULL){
        cout<<"\t"<<key<<" is not found"<<endl;
        return;
    }
    temp->data=value;
    cout<<"\t"<<temp->data<<" is updated"<<endl;

}

//search by unique value
void search_by_unique_value(int key,struct node* head){
   // struct node* temp=head;
   int i=1;
   while(head->data!=key){
    head=head->next;
        i++;
        if(head==NULL){
            break;
        }
   }
   if(head==NULL){
        cout<<"\t"<<key<<" Not Found"<<endl;
        return;
   }
   cout<<"\tValue of "<<key<<" position is "<<i<<endl;
}

//reverse linked list
void reverse_linked_list(struct node* &head){
    struct node* prev=NULL;
    struct node* current=head;
    if(head==NULL){
        cout<<"\tLinked List is Empty"<<endl;
        return;
    }
    struct node* next=head->next;
    while(true){
        current->next=prev;
        prev=current;
        current=next;
        if(current==NULL) break;
        next=next->next;
    }
    head=prev;
}
//counting length
int countingLength(struct node*  &head)
{
    int length=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
//print linked list
void display(struct node* head)
{
    if(head==NULL)
    {
        cout<<"\tThis Linked List is Empty"<<endl;
    }
    else
    {
        struct node* current=head;
        cout<<"\t";
        while(current!=NULL)
        {
            cout<<current->data;
            if(current->next!=NULL)
            {
                cout<<" ---> ";
            }
            current=current->next;
        }
        cout<<endl;
    }
}
int main()
{


    cout<<"\t_______________________________________"<<endl;
    cout<<"\t\t LINKED LIST OPERATION"<<endl;
    cout<<"\t---------------------------------------"<<endl;
    cout<<"\tChoice 01: Insertion at Tail"<<endl;
    cout<<"\tChoice 02: Insertion at Head"<<endl;
    cout<<"\tChoice 03: Insertion at Specific Position"<<endl;
    cout<<"\tChoice 04: Insertion after Value"<<endl;
    cout<<"\tChoice 05: Deletion at Head"<<endl;
    cout<<"\tChoice 06: Deletion at Tail"<<endl;
    cout<<"\tChoice 07: Deletion at Specific Position"<<endl;
    cout<<"\tChoice 08: Deletion by Value"<<endl;
    cout<<"\tChoice 09: Search by Unique Value"<<endl;
    cout<<"\tChoice 10: Search by Duplicate Value"<<endl;
    cout<<"\tChoice 11: Count Length"<<endl;
    cout<<"\tChoice 12: Print Linked List"<<endl;
    cout<<"\tChoice 13: Update by Value"<<endl;
    cout<<"\tChoice 14: Update by Position"<<endl;
    cout<<"\tChoice 15: Reverse Linked List"<<endl;
    cout<<"\tChoice 00: Exit "<<endl<<endl;

    struct node* head=NULL;
    int choice,value,position;
    cout<<"\tNext Choice : ";
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            cout<<"\tEnter Value : ";
            cin>>value;
            insertion_at_tail(value,head);
            break;
        case 2:
            cout<<"\tEnter Value : ";
            cin>>value;
            insertion_at_head(value,head);
            break;
        case 3:
            cout<<"\tEnter Position : ";
            cin>>position;
            cout<<"\tEnter Value : ";
            cin>>value;
            insertion_at_specific_position(position,value,head);
            break;
        case 4:
            cout<<"\tEnter Key : ";
            cin>>position;
            cout<<"\tEnter Value : ";
            cin>>value;
            insertion_after_value(position,value,head);
            break;
         case 5:
            delete_at_head(head);
            break;
        case 6:
            delete_at_tail(head);
            break;
        case 7:
            if(head==NULL){
                cout<<"\tThe Linked List is Empty"<<endl;
                break;
            }
            cout<<"\tEnter Position : ";
            cin>>position;
            delete_at_specific_position(position,head);
            break;
        case 8:
             cout<<"\tEnter Key : ";
             cin>>value;
             deletion_by_value(value,head);
             break;
        case 9:
            cout<<"\tEnter Key : ";
            cin>>value;
            search_by_unique_value(value,head);
            break;
        case 11:
            cout<<"\tThe Length of Linked List is : "<<countingLength(head)<<endl;
            break;
        case 12:
            display(head);
            break;
        case 13:
            cout<<"\tEnter Key : ";
            cin>>position;
            cout<<"\tEnter Value : ";
            cin>>value;
            update_by_value(position,value,head);
            break;
        case 14:
            cout<<"\tEnter Position : ";
            cin>>position;
            cout<<"\tEnter Value : ";
            cin>>value;
            update_by_position(position,value,head);
            break;
        case 15:
            reverse_linked_list(head);
            break;
        default:
            break;
        }//switch
        cout<<"\tNext Choice : ";
        cin>>choice;
    }//loop
    cout<<endl;
    cout<<"\tSuccessfully Exited !"<<endl;
    getch();
}
