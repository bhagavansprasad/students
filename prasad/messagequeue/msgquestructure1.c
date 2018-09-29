#include"stdio.h"
#include"stdlib.h"
#include"string.h"
int i;
struct node
{
char *name;
struct node *next;
};

struct node *h=NULL,*new,*temp,*prev;

add_node(char *str)
{
int len;
new=(struct node *)malloc(sizeof(struct node));
new->name=(char *)malloc(sizeof(len=strlen(str)));
strcpy((new->name),str);
new->next=NULL;
if(h==NULL)
{
h=new;
return 0;
}
for(temp=h;temp->next!=NULL;temp=temp->next);
temp->next=new;
return 0;
}
delete_node(char *str)
{
if(h==NULL)
{
printf("There are no messages in mesg queue\n");
return 0;
}

for(temp=prev=h;temp!=NULL;prev=temp,temp=temp->next)
{
i=strcmp((temp->name),str);
if(i==0)
{
if(temp==h)
{
h=temp->next;
free(temp->name);
free(temp);
return 0;
}
prev->next=temp->next;
free(temp->name);
free(temp);
return 0;
}
}
}
display()
{
for(temp=h;temp!=NULL;temp=temp->next)
printf("--->%s \n",temp->name);
}

main()
{
char str1[]="prasad";
char str2[]="manikanta";
char str3[]="harsha";
char str4[]="pavan";
char str5[]="manju";
char str6[]="vamsi";
add_node(str1);
add_node(str2);
add_node(str3);
add_node(str4);
add_node(str5);
add_node(str6);
display();
printf("\n");
delete_node(str1);
delete_node(str4);
delete_node(str6);
display();
}

