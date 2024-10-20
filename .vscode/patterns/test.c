#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next ;

}
int main(){
    int x,y,z;
    struct node *var1 = NULL;
    struct node *var2 = NULL;
    struct node *var3 = NULL;

    var1 = (struct node *)malloc(sizeof(struct node));
    var2 = (struct node *)malloc(sizeof(struct node));
    var3 = (struct node *)malloc(sizeof(struct node));
    

    var1 -> data = x;
    var2 -> data = y;
    var3 -> data = z;
    var1->next = var2;
    var2->next = var3;
    var3-> next = NULL;

    int head = var1;
    int temp;
    temp =  head;

    while ((temp!=NULL))
    {
        /* code */
        printf("%d",temp->next);
        temp = temp -> data;
    }
    


}