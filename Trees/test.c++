//try to create tree data structure

#include<iostream>
using namespace std;


class trees{
    public:
       int data;
       int *left;
       int *right;
      trees(int data){
        this->data= data;
        this->left = NULL;
        this->right = NULL;
       }
};

void  insert_inTrees(int data,trees * root){

}