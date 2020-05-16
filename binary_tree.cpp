#include <iostream>

using namespace std;

typedef struct binaryTree {

    int data;

    struct binaryTree* left;
    struct binaryTree* right;
};

class BSTOperations {
    private:
        binaryTree* getMinvalueNode (binaryTree* root) {
           binaryTree* temp = root;

            while(temp && temp->left != NULL)
                temp = temp->left;

            return temp;
        }

    public:
        BSTOperations() {  }

        binaryTree* getNode(int data) {
            binaryTree* temp = new binaryTree();
            temp->data = data;
            temp-> left = NULL;
            temp-> right = NULL;

            return temp;
        }

        binaryTree* insertNode (binaryTree* root, int data);

        binaryTree* deleteNode(binaryTree* root, int data);

        void prefix_display_recursive(binaryTree* root);

        void postfix_display_recursive(binaryTree* root);

        void infix_display_recursive(binaryTree* root);


        void prefix_display_iterative(binaryTree* root);

        void postfix_display_iterative(binaryTree* root);

        void infix_display_iterative(binaryTree* root);

};


binaryTree* BSTOperations::insertNode(binaryTree* root, int data) {
    
    // Check if root is NULL
    if(root == NULL) {
        return getNode(data);
    }

    if(root->data > data)
        root->left = insertNode(root->left, data);
    else 
        root->right = insertNode(root->right, data);

    // If it is than make new node and declare it as root
    return root;
}

binaryTree* BSTOperations::deleteNode (binaryTree* root, int data) {
    if(root == NULL) {
        cout<<"Element not found"<<endl;
        return root;
    }

    //Recursive calls to delete
    if(root->data > data) 
        root->left = deleteNode(root->left, data);

    else if(root->data < data)
        root->right = deleteNode(root->right, data);

    // We have proper match
    // Now lets check how many nodes do we have
    else {
        binaryTree* temp =NULL;
        if(root->left != NULL && root->right != NULL) {
            // First find first successor of root node
            temp = getMinvalueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        else {
            temp = root;
            if(root-> right == NULL) 
                root = root->left;

            if (root->left == NULL)
                root = root->right;

            delete(temp);
            temp = NULL;

        }

    }
    return root;
}


void BSTOperations::infix_display_recursive(binaryTree* root) {

    if(root == NULL)
        return;

    infix_display_recursive(root->left);
    cout<<root->data<<" ";
    infix_display_recursive(root->right);
}

void BSTOperations::prefix_display_recursive(binaryTree* root) {

    if(root == NULL)
        return;

    cout<<root->data<<" ";
    infix_display_recursive(root->left);
    infix_display_recursive(root->right);
}

void BSTOperations::postfix_display_recursive(binaryTree* root) {

    if(root == NULL)
        return;

    infix_display_recursive(root->left);
    infix_display_recursive(root->right);
    cout<<root->data<<" ";
}

int main() {
    BSTOperations BSTobj;
    binaryTree *root = NULL;
    root = BSTobj.insertNode(root,6);
    root = BSTobj.insertNode(root,4);
    root = BSTobj.insertNode(root,2);
    root = BSTobj.insertNode(root,9);
    root = BSTobj.insertNode(root,10);
    root = BSTobj.insertNode(root,5);
    root = BSTobj.insertNode(root,1);
    root = BSTobj.insertNode(root,11);


    BSTobj.infix_display_recursive(root);
    cout<<endl;
    root = BSTobj.deleteNode(root,6);
    BSTobj.infix_display_recursive(root);
        cout<<endl;

        cout<<root->data<<endl;


    return 0;
}