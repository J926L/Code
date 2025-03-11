#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } NodeColor;

typedef struct Node {
    int data;
    NodeColor color;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void leftRotate(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}

void fixViolation(Node **root, Node *z) {
    while (z != *root && z->parent->color == RED) {
        Node *y;
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(Node **root, int data) {
    Node *z = createNode(data);
    Node *y = NULL;
    Node *x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixViolation(root, z);
}

void inorderHelper(Node *root) {
    if (root == NULL)
        return;
    inorderHelper(root->left);
    printf("%d ", root->data);
    inorderHelper(root->right);
}

int main() {
    Node *root = NULL;
    
    // Insert test data
    insert(&root, 7);
    insert(&root, 3);
    insert(&root, 18);
    insert(&root, 10);
    insert(&root, 22);
    insert(&root, 8);
    insert(&root, 11);
    insert(&root, 26);

    printf("Inorder traversal: ");
    inorderHelper(root);
    printf("\n");

    return 0;
}
