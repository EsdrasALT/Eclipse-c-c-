#include <stdio.h>
#include <stdlib.h>

// Definição das cores dos nós
typedef enum { RED, BLACK } Color;

// Estrutura do nó da árvore
typedef struct Node {
    int data;
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

// Estrutura da árvore
typedef struct {
    Node* root;
} RedBlackTree;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

// Função para rotacionar à esquerda
void rotateLeft(RedBlackTree* tree, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Função para rotacionar à direita
void rotateRight(RedBlackTree* tree, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        tree->root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

// Função para corrigir a árvore após a inserção
void fixInsert(RedBlackTree* tree, Node* k) {
    Node* u;
    while (k->parent != NULL && k->parent->color == RED) {
        if (k->parent == k->parent->parent->left) {
            u = k->parent->parent->right;
            if (u != NULL && u->color == RED) {
                k->parent->color = BLACK;
                u->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    rotateLeft(tree, k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rotateRight(tree, k->parent->parent);
            }
        } else {
            u = k->parent->parent->left;
            if (u != NULL && u->color == RED) {
                k->parent->color = BLACK;
                u->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rotateRight(tree, k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rotateLeft(tree, k->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

// Função para inserir um novo nó na árvore
void insert(RedBlackTree* tree, int data) {
    Node* node = createNode(data);
    Node* y = NULL;
    Node* x = tree->root;

    while (x != NULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == NULL) {
        tree->root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    fixInsert(tree, node);
}

// Função para realizar uma busca na árvore
Node* search(RedBlackTree* tree, int data) {
    Node* current = tree->root;
    while (current != NULL && data != current->data) {
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

// Função para realizar o travessia in-order da árvore
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Função principal
int main() {
    RedBlackTree tree;
    tree.root = NULL;

    insert(&tree, 10);
    insert(&tree, 20);
    insert(&tree, 30);
    insert(&tree, 15);
    insert(&tree, 25);

    printf("In-order Traversal: ");
    inorderTraversal(tree.root);
    printf("\n");

    int searchValue = 15;
    Node* foundNode = search(&tree, searchValue);
    if (foundNode != NULL) {
        printf("Value %d found in the tree.\n", searchValue);
    } else {
        printf("Value %d not found in the tree.\n", searchValue);
    }

    return 0;
}
