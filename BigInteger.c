#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BigInteger.h"

void show(struct node*head)
{
    if(!head)return;

    show(head->next);
    printf("%d ",head->data);
}

void display(struct BigInteger a)
{
    if(!a.h)return;
    
    show(a.h);
}

struct node* createNode(struct node*h,int k)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    if(!temp)return NULL;

    temp->data=k;

    if(!h)
    {
        temp->next=NULL;
        h=temp;
        return h;
    }

    struct node*itr=h;
    while(itr->next!=NULL)
    {
        itr=itr->next;
    }

    itr->next=temp;
    temp->next=NULL;
    return h;
    
}

struct BigInteger initialize(char*s)
{
    struct BigInteger a;
    int l=0,i,k;
    l=strlen(s);
    if(s[l-1] <0)
    {
        a.sign=-1;
    }
    printf("Length of array: %d\n",l);
    a.length=l;
    a.h=NULL;
    for(i=0;i<l;i++)
    {
        k=s[l-1-i]-48;
        a.h=createNode(a.h,k);
    }
    return a;
}

struct BigInteger truncate(struct BigInteger a)
{
    //countLastNode(a.h);
   // struct node*itr=a.h;
    //deleteLastNode(a.h);
    return a;
}

int compare(struct BigInteger a,struct BigInteger b)
{
    a=truncate(a);
    b=truncate(b);
    struct node*itr=a.h;
    struct node*ptr=b.h;
    if(a.length < b.length)
    {
       return -1;
    }
    else if(a.length > b.length)
    {
       return 1;
    }
    else
    {
        while(itr->next)
        {
            itr=itr->next;
            ptr=ptr->next;
        }

        if(itr->next==NULL)
        {
            if(itr->data >= ptr->data)
               return 1;
            else 
               return  -1;
        }
    }
}
struct BigInteger add(struct BigInteger a,struct BigInteger b)
{
     struct BigInteger c;
     int carry=0,i,d=0,sum=0,f;
     c.h=NULL;
     c.length=0;
    
     f=compare(a,b);
     if(a.sign==-1)
     {
        
     }
     struct node*first=a.h;
     struct node*second=b.h;
     sum=carry=0;
     while(first || second)
     {
        sum= first->data + second->data +carry;
        if(sum>9)
        {
            carry=1;
            sum=sum%10;
        }
        else
        {
            carry=0;
        }
        c.h=createNode(c.h,sum);
        c.length++;
        first=first->next;
        second=second->next;
        c.length++;
     }
     
     if(carry)
     {
        c.h=createNode(c.h,carry);
        c.length++;
     }
    return c;
}

struct BigInteger sub(struct BigInteger a,struct BigInteger b)
{
   struct BigInteger c;
     int i,d=0,diff=0,flag=0;
     c.h=NULL;
     c.length=0;

     if(a.length < b.length)
     {
        d=b.length-a.length;
        for(i=1;i<=d;i++)
        {
            a.h=createNode(a.h,0);
            a.length++;
        }

     }
     else if(b.length < a.length)
     {
        d=a.length-b.length;

        for(i=0;i<=d;i++)
        {
            b.h=createNode(b.h,0);
            b.length++;
        }
     }
     
     
     struct node*first=a.h;
     struct node*second=b.h;

     while(first)
     {
        if(first->data < second->data)
        {
            first->data+= 10;
            first->next->data-=1;
        }

        diff=first->data-second->data;
        c.h=createNode(c.h,diff);
        first=first->next;
        second=second->next;
     }

     return c;
}