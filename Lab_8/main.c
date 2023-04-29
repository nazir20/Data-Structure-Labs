#include <stdio.h>
#include <stdlib.h>

/* Düğüm Yapısı */
struct Node{

    int data;
    struct Node *right;
    struct Node *left;

};

/* Fonksiyon Prototipleri */
struct Node *createNode(int data); 
struct Node *insertRight(struct Node *root, int data);
struct Node *insertLeft(struct Node *root, int data);
void inorderTraversal(struct Node *root);
void preorderTraversal(struct Node *root);
void postorderTraversal(struct Node *root);

int main(void) {
    
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("| - - - - - - - - - - - İkili Ağacı - - - - - - - - - - - - |\n");
    printf("| - - - - - - - - - - Düğüm Sayısı: 14 - - - - - - - - - - -|\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    
    struct Node *root = createNode(27); 
    insertLeft(root, 18);
    insertRight(root, 39);

    /* Kök Düğüm'ün sol tarafın'daki düğümler */
    insertLeft(root->left, 14);
    insertRight(root->left, 22);

    insertLeft(root->left->left, 2);
    insertRight(root->left->left, 17);
    insertLeft(root->left->left->right, 15);

    insertLeft(root->left->right, 12);
    insertRight(root->left->right, 24);
    insertLeft(root->left->right->right, 23);

    /* Kök Düğüm'ün sağ tarafın'daki düğümler */

    insertLeft(root->right, 29);
    insertRight(root->right, 42);
    insertRight(root->right->left, 34);
    
    
    printf("\n-*-*-*-*-* Inorder Traversal -*-*-*-*-*\n");
    inorderTraversal(root);

    printf("\n\n\n-*-*-*-*-* Preorder Traversal -*-*-*-*-*\n");
    preorderTraversal(root);

    printf("\n\n\n-*-*-*-*-* Postorder Traversal -*-*-*-*-*\n");
    postorderTraversal(root);
    
    return 0;
}

struct Node *createNode(int data){

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
    
}

struct Node *insertRight(struct Node *root, int data){

    root->right = createNode(data);
    return root->right;
    
}

struct Node *insertLeft(struct Node *root, int data){

    root->left = createNode(data);
    return root->left;
    
}

/*  
* @inorder Traversal:
* 1. İlk olarak, sol alt ağaç'taki tüm düğümler gezinmeli
* 2. Daha sonra, kök düğüm
* 3. En son, sağ alt ağaç'taki tüm düğümleri gezinmeli
*/
void inorderTraversal(struct Node *root){

    if(root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d -> ", root->data);
    inorderTraversal(root->right);
    
}


/*  
* @preorder Traversal:
* 1. İlk olarak, kök düğüm
* 2. Daha sonra, sol alt ağaç'taki tüm düğümler gezinmeli
* 3. En son, sağ alt ağaç'taki tüm düğümleri gezinmeli
*/
void preorderTraversal(struct Node *root) {
    
    if (root == NULL) 
        return;
    
    printf("%d -> ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}


/*  
* @postorder Traversal:
* 1. İlk olarak, sol alt ağaç'taki tüm düğümler gezinmeli
* 2. Daha sonra, sağ alt ağaç'taki tüm düğümler gezinmeli
* 3. En son, kök düğüm
*/
void postorderTraversal(struct Node *root) {
    
    if (root == NULL) 
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->data);
    
}
