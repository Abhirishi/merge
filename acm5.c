#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
   int data;
   struct node* next;

};
void print(struct node *head)
{

struct node *ptr=head;
while(ptr)
{
    printf("%d  ",ptr->data);
    ptr=ptr->next;

}
printf("\n");
}
struct node *merge(struct node *head1,struct node *head2)
{
   struct node *head;
   if(head1==NULL)
   {
       return head2;
   }
   else if(head2==NULL)
   {
       return head1;
   }
     if(head1->data<=head2->data)
        {
            head=head1;

            head->next=merge(head1->next,head2);
        }
        else
        {
            head=head2;
            head->next=merge(head1,head2->next);
        }
        return head;
}
int main()
{
    struct node *head1,*head2,*ptr1,*ptr2,*head=NULL;
    int n=9,d;
    printf("enter element of first list");

    head1=(struct node*)malloc(sizeof(struct node*));
    scanf("%d",&d);
      head1->data=d;
          ptr1=head1;
    while(n--)


    {
        printf("enter element greater than or equal to previous");
       scanf("%d",&d);
        ptr2=(struct node*)malloc(sizeof(struct node*));
       ptr1->next=ptr2;
       ptr2->next=NULL;
       ptr2->data=d;
       ptr1=ptr2;
    }
     printf("enter element for list 2");

    head2=(struct node*)malloc(sizeof(struct node*));
    scanf("%d",&d);
      head2->data=d;
          ptr1=head2;
          n=9;
    while(n--)


    {
        printf("enter element greater than or equal to previous");
       scanf("%d",&d);
        ptr2=(struct node*)malloc(sizeof(struct node*));
       ptr1->next=ptr2;
       ptr2->next=NULL;
       ptr2->data=d;
       ptr1=ptr2;
    }
    print(head1);
    print(head2);
    head=merge(head1,head2);
    print(head);

}
