#ifndef BIGINTEGER_H
#define BIGINTEGER_H

struct node
{
    int data;
    struct node*next;
};
 struct BigInteger
{
    struct node* h;
    int length;
    int sign;
};

struct node* createNode(struct node*,int );
struct BigInteger initialize(char*);
struct BigInteger add(struct BigInteger ,struct BigInteger );
struct BigInteger sub(struct BigInteger ,struct BigInteger );
struct BigInteger mul(struct BigInteger ,struct BigInteger );
struct BigInteger div1(struct BigInteger ,struct BigInteger );
void display(struct BigInteger );
void show(struct node*);

#endif