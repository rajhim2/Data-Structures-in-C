#include <stdio.h>
#include <stdlib.h>
struct node{
int info;
struct node *link;
};
struct node *start=NULL;
void display(struct node *start);
void count (struct node *start);
void search (struct node *start,int item);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data, int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int position);
struct node *del(struct node *start,int data);
struct node *delatpos(struct node *start,int position);
struct node *reverse(struct node *start);
int main()
{
    int choice,data,item,position;
    while(1)
    {
        system("cls");
        printf("1.Display\n");
        printf("2.Count\n");
        printf("3.Search\n");
        printf("4.Add to EmptyList or Add at beginning\n");
        printf("5.Add at an end\n");
        printf("6.Add after node\n");
        printf("7.Add before node\n");
        printf("8.Add a node at a given position\n");
        printf("9.Delete Node\n");
        printf("10.Delete Node at a given position\n");
        printf("11.Reverse the linked list\n");
        printf("12.Quit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
    }
    switch(choice)
    {
    case 1:
        display(start);
        break;
    case 2:
        count(start);
        break;
    case 3:
        printf("Enter the element to be searched \n");
        scanf("%d",&data);
        search(start,data);
        break;
    case 4:
        printf("Enter the element to be inserted\n");
        scanf("%d",&data);
        start=addatbeg(start,data);
        break;
    case 5:
        printf("Enter the element to be inserted\n");
        scanf("%d",&data);
        start=addatend(start,data);
        break;
    case 6:
        printf("Enter the element to be inserted\n");
        scanf("%d",&data);
        printf("Enter the element after which to insert:\n");
        scanf("%d",&item);
        start=addafter(start,data,item);
        break;
    case 7:
        printf("Enter the element to be inserted\n");
        scanf("%d",&data);
        printf("Enter the element before which to insert");
        scanf("%d",&item);
        start=addbefore(start,data,item);
        break;
    case 8:
        printf("Enter the element to be inserted\n");
        scanf("%d",&data);
        printf("Enter the position at which the element is to be inserted\n");
        scanf("%d",&position);
        start=addatpos(start,data,position);
        break;
    case 9:
        printf("Enter the element to be deleted\n");
        scanf("%d",&data);
        start=del(start,data);
        break;
    case 10:
        printf("Enter the position at which the element is to be deleted \n");
        scanf("%d",&position);
        start=delatpos(start,position);
        break;
    case 11:
        start=reverse(start);
        break;
    case 12:
        exit(1);
    default:
        printf("Wrong Choice\n");
    }
    getch();
}
void display (struct node *start){
struct node *p;
if(start==NULL){
    printf("The List is empty");
    return;
    }
p=start;
while(p!=NULL)  //here also try to think that why we can't write while(p->link!=NULL)
{
    printf("%d ",p->info); //Print the info part of the node to which p is pointing.
    p=p->link;
}
}
void count(struct node *start)
{
struct node *p;
int count=0;
if (start==NULL){         //
    printf("The list has %d elements",count);
    return;
}
p=start;
while(p!=NULL){
    p=p->link;
    count++;
}
printf("The list has %d elements",count);
}
void search(struct node *start, int item){
struct node *p;
p=start;
int pos=1;
while(p!=NULL){
    if(p->info==item)
    {
        printf("The element %d is found at %d position",p->info,item);
        return;
    }
    p=p->link;
    pos++;
}
printf("\nElement is not found in the list");
}
struct node *addatbeg(struct node *start, int data){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->info=data;
temp->link=start;
start=temp;    //Also analyze the situation what will happen if the order of the statements is reversed.
return (start);
}
struct node *addatend(struct node *start, int data){
struct node *temp,*p;
temp=(struct node *)malloc(sizeof(struct node));
p=start;
temp->info=data;
while(p!=NULL)  //We can also write the loop as while(p->link!=NULL)
    p=p->link;
p->link=temp;
temp->link=NULL;
return (start);
}
struct node *addafter(struct node *start, int data,int item){ //int item is the element after which insertion will be done.
struct node *temp,*p;  //int data is the element to be inserted.
temp=(struct node *)malloc(sizeof(struct node));
p=start;
while(p!=NULL)
{
    if(p->info==item)
    {
     temp->info=data;
     temp->link=p->link;
     p->link=temp;
     return(start);
     }
    p=p->link;
}
printf("The element %d is not present in the list",item);
return (start);
}
struct node *addbefore(struct node *start, int data ,int item)
{
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    p=start;
    if(start==NULL)
    {
        printf("The list is empty\n");
        return (start);
    }
    if(start->info==item)
    {
        temp->info=data;
        temp->link=start;
        start=temp;
        return (start);
    }
    while(p!=NULL)
    {
        if(p->link->info==item)
        {
            temp->info=data;
            temp->link=p->link;
            p->link=temp;
        }
        p=p->link;
    }
        printf("Element %d is not found in the list",item);
        return (start);
}
struct node *addatpos(struct node *start, int data,int position)
{
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    p=start;
    int i;
    temp->info=data;
    if(position==1)
    {
        temp->link=start;
        start=temp;
        return (start);
    }
    for(i=1;i<position-1&&p!=NULL;i++)
        p=p->link;
    if(p==NULL)
        printf("The list contain less than %d elements\n",position);
    else
    {
        temp->link=p->link;
        p->link=temp;
    }
    return (start);
}
struct node *del(struct node *start,int data)
{
 struct node *temp,*p;
 temp=(struct node *)malloc(sizeof(struct node));
 if(start==NULL)
 {
     printf("The list is Empty");
     return (start);
 }
 if(start->info==data) /*Deletion of the first node */
 {
     temp=start;
     start=start->link;
     free(temp);
     return (start);
 }
 p=start;
 while(p!=NULL)
 {
     if(p->link->info==data)
     {
         temp=p->link;
         p->link=temp->link;
         free(temp);
         return (start);
     }
     p=p->link;
 }
 printf("Element %d not found in the list");
return (start);
}
struct node *delatpos(struct node *start,int position)
{
 struct node *temp,*p;
 temp=(struct node *)malloc(sizeof(struct node));
 int i;
 if(position==1)
 {
     temp=start;
     start=start->link;
     free(temp);
     return (start);
 }
 p=start;
 for(i=1;i<position-1 && p!=NULL;i++)
        p=p->link;
if(p==NULL)
printf("There are more than %d elements",position);
else
{
    temp=p->link;
    p->link=temp->link;
    free(temp);
    return (start);
}
return (start);
}
struct node *reverse(struct node *start)
{
 struct node *current,*next,*prev;
 prev=NULL;
 current=start;
 while(current!=NULL)
 {
     next=current->link;
     current->link=prev;
     prev=current;
     current=next;
 }
 start=prev;
 return(start);
}
