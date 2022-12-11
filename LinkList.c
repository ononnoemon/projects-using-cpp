#include<stdio.h>
struct node
{
    int data;
    struct node* link;
};
void insertAtHead(struct node** head)
{
    struct node* temp = malloc(sizeof(struct node));
    printf("Enter your value");
    scanf(" %d",&temp->data);
    temp->link = *head;
    *head = temp;
}
void display(struct node** head)
{
    struct node* temp = *head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
}
int main()
{
    struct node* head = NULL;
    char ch;

    do
    {
        printf("Enter 1 to insert at head\n ");
        printf("Enter 2 to display LinkedList elements\n ");
        int value;
        scanf("%d",&value);
        switch(value)
        {
        case 1:
            insertAtHead(&head);
            break;
        case 2:
            display(&head);
            break;
        default:
            break;
        }
        printf("Do you want to continue?y/n ");
        getchar();
        scanf("%c",&ch);
    }
    while(ch == 'y');
    return 0;
}
