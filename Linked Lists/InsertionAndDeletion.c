#include <stdio.h>
#include <stdlib.h>
struct node{
int info;
struct node *link;
};
struct node *start=NULL;
struct node *createNode(){
struct node *n;
n=(struct node *)malloc(sizeof(struct node));
return (n);
}
void insertNode(){
struct node *temp,*t;
temp=createNode();
printf("Enter a number");
scanf("%d",&temp->info);
temp->link=NULL;
if(start==NULL)
    start=temp;
 else{
    t=start;
    while(t->link!=NULL)
    t=t->link;
    t->link=temp; //Now in t's link there is temp and temp's link has null already
                  //Thus it means that temp is added at the end.
  }
}
void deleteFirstNode(){
struct node *r;
r=start;
start=start->link;
free(r);
}
void viewList(){
struct node *t;
if (start==NULL)
    printf("List is Empty");
else
{
t=start;
while(t!=NULL)
{
    printf("%d  ",t->info);
    t=t->link;
}
}
}
int menu(){
int ch;
printf("1.Add a value to the list");
printf("\n2.Delete a value from the list");
printf("\n3.View List");
printf("\n4.Exit");
printf("\n\nEnter Your Choice");
scanf("%d",&ch);
return(ch);
}
int main()
{
while(1){
    system("cls");
    switch(menu()){
    case 1:
    insertNode();
    break;
    case 2:
    deleteFirstNode();
    break;
    case 3:
    viewList();
    break;
    case 4:
    exit(0);
    break;
    }
getch();
}
}
