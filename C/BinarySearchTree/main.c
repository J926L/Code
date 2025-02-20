#include <stdio.h>
#include <stdlib.h>

/* 二叉树节点结构 */
typedef struct Node {
    int data;               // 节点数据
    struct Node* left;      // 左子树
    struct Node* right;     // 右子树
} Node;

/* 创建新节点 */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* 插入节点 */
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

/* 查找最小值的节点 */
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

/* 删除节点 */
Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* 查找节点 */
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (root->data < value)
        return search(root->right, value);

    return search(root->left, value);
}

/* 中序遍历 */
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* 前序遍历 */
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* 后序遍历 */
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* 打印菜单 */
void printMenu() {
    printf("\n二叉搜索树操作菜单:\n");
    printf("1. 插入节点\n");
    printf("2. 删除节点\n");
    printf("3. 查找节点\n");
    printf("4. 中序遍历\n");
    printf("5. 前序遍历\n");
    printf("6. 后序遍历\n");
    printf("7. 退出程序\n");
}

int main() {
    Node* root = NULL;  // 树的根节点
    int choice, value;
    
    while (1) {
        printMenu();
        printf("请输入您的选择: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("请输入要插入的值: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("请输入要删除的值: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("请输入要查找的值: ");
                scanf("%d", &value);
                Node* result = search(root, value);
                if (result != NULL) {
                    printf("值 %d 存在于树中\n", value);
                } else {
                    printf("值 %d 不存在于树中\n", value);
                }
                break;
            case 4:
                printf("中序遍历结果: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("前序遍历结果: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("后序遍历结果: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("无效选择！请重试。\n");
        }
    }

    return 0;
}
