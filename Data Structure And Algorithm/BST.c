#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the Binary Search Tree (BST)
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insertion into a Binary Search Tree (BST)
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return newNode(data);
    }

    // If data is less than the root, insert it in the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is greater than the root, insert it in the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Search for a value in the BST
struct Node* search(struct Node* root, int key) {
    // Base case: root is null or key is present at the root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's data, search the right subtree
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than root's data, search the left subtree
    return search(root->left, key);
}

// Find the node with the minimum value (used for deletion)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Deletion of a node in the BST
struct Node* delete(struct Node* root, int key) {
    // Base case: If the tree is empty
    if (root == NULL) {
        return root;
    }

    // If the key to be deleted is smaller than the root's data, go to the left subtree
    if (key < root->data) {
        root->left = delete(root->left, key);
    }
    // If the key to be deleted is greater than the root's data, go to the right subtree
    else if (key > root->data) {
        root->right = delete(root->right, key);
    }
    // If the key is the same as the root's data, this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = delete(root->right, temp->data);
    }

    return root;
}

// In-order traversal (left, root, right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal (root, left, right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (left, right, root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Driver program to test the above functions
int main() {
    struct Node* root = NULL;

    // Inserting nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traversals
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorder(root);
    printf("\n");

    // Searching for a value in the BST
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Node with key %d found in the BST.\n", key);
    } else {
        printf("Node with key %d not found in the BST.\n", key);
    }

    // Deleting a node from the BST
    printf("\nDeleting node with key 20\n");
    root = delete(root, 20);
    printf("In-order traversal after deletion: ");
    inorder(root);
    printf("\n");

    printf("\nDeleting node with key 30\n");
    root = delete(root, 30);
    printf("In-order traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
