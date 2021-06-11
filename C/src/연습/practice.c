
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;
TreeNode n1 = { 1, NULL, NULL};
TreeNode n2 = { 4, &n1, NULL};
TreeNode n3 = { 16, NULL,NULL};
TreeNode n4 = { 25, NULL, NULL};
TreeNode n5 = { 20, &n3, &n4};
TreeNode n6 = { 15, &n2, &n5};
TreeNode *root = &n6;

int top = -1;
TreeNode *stack[SIZE];

TreeNode *pop();
void inorder_iter(TreeNode *root);
void push(TreeNode *p);
void inorder_MID(TreeNode *root);
void inorder_TOP(TreeNode *root);
void inorder_BOTTOM(TreeNode *root);



int main(void)
{
    printf("반복을 사용한 중위순회\n");
    inorder_iter(root);
    printf("\n\n");

    printf("전위순회\n");
    inorder_TOP(root);
    printf("\n\n");

    printf("준위순회\n");
    inorder_MID(root);
    printf("\n\n");

    printf("후위순회\n");
    inorder_BOTTOM(root);
    printf("\n\n");
}


void inorder_iter(TreeNode *root)
{
    while(1){
        for(; root; root = root->left)
            push(root);
        root=pop();
        if(!root)break;
        printf("[%d]", root->data);
        root = root->right;
    }
}

void push(TreeNode *p)
{
    if(top<SIZE -1)
        stack[++top]=p;
}

TreeNode *pop()
{
    TreeNode *p = NULL;
    if(top>=0)
        p=stack[top--];
    return p;
}

void inorder_TOP(TreeNode *root){
    if(root != NULL){
        printf("[%d]", root->data);
        inorder_TOP(root->left);
        inorder_TOP(root->right);
    }
}

void inorder_MID(TreeNode *root){
    if(root != NULL){
        inorder_MID(root->left);
        printf("[%d]", root->data);
        inorder_MID(root->right);
    }
}


void inorder_BOTTOM(TreeNode *root){
    if(root != NULL){
        inorder_BOTTOM(root->left);
        inorder_BOTTOM(root->right);
        printf("[%d]",root->data);
    }
}