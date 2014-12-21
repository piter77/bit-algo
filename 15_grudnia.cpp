#include <iostream>
#include <cstddef>
using namespace std;

struct Node{
    Node * left;
    Node * right;
    Node * parent;
    int value;
};

void  inorder (Node * node)
{
    if (node==nullptr)
        return;

    inorder(node->left);
    cout<<node->value;
    inorder(node->right);
}

Node * find (Node * root, int query)
{
    if (root==nullptr)
        return nullptr;

    if (root->value==query)
        return root;

    if (query<root->value)
        find (root->left, query);

    else
        find (root->right, query);
}



Node * insert (Node * root, int value) // nasze
{
    if (root==nullptr){
        Node * nowy = new node;
        nowy->value=value;
        nowy->parent=nullptr;
        nowy->left=nullptr;
        nowy->right=nullptr;
        return nowy;
    }

    if (value<root->value)
        root->left = insert (root->left, value);
        root->left->parent=root;
    else
        root->right = insert (root->right, value);
        root->right->parent=root;

    return root;
}
