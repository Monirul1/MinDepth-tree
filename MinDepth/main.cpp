#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* leftNode, *rightNode;
};

int findMinimumHeight (node* root);

node *newNode (int data);

int main ()
{
    node *root = newNode(1);
    
    root->leftNode = newNode(8);
    root->rightNode = newNode(3);
    root->rightNode->rightNode = newNode(11);
    root->rightNode->leftNode = newNode(12);
    root->leftNode->leftNode  = newNode(4);
    root->leftNode->rightNode = newNode(5);
    root->leftNode->leftNode->leftNode = newNode(9);
    root->leftNode->leftNode->rightNode = newNode(6);
    
    cout << "Minimum depth of this Binary Tree is: " << findMinimumHeight(root) << endl << endl;
    
    return 0;
}

node *newNode (int data)
{
    node *temp = new node;
    temp -> data = data;
    temp->leftNode = temp->rightNode = NULL;
    return temp;
    
}

int findMinimumHeight (node* root)
{
    if (root==NULL)
        return 0;
    
    if (root->leftNode == NULL)
        findMinimumHeight(root->rightNode);
    if (root->rightNode == NULL)
        findMinimumHeight(root->leftNode);
    
    if (root -> rightNode == NULL && root -> leftNode == NULL)
        return 1;
    else
        return min(findMinimumHeight(root->leftNode), findMinimumHeight(root->rightNode))+1;
}
