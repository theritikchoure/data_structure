using namespace std;
#include<iostream>

// Data structure to store a binary search tree node
struct Node
{
    int data;
    Node *left, *right;
};

//Function for create new node 
Node *New_node(int key)
{
    Node *node = new Node;

    node->data = key;
    node->left = node->right = NULL;

    return node;
}

//Function of Inorder Traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<" "<<root->data<<" ";
    inorder(root->right);
}

//For Minimum value
Node* MinimumValue(Node* curr)
{
    while(curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

//insert function
Node* insert (Node* root, int key)
{
    //if the root is null
    if(root == NULL)
    {
        return New_node(key);
    }

    //if key is less than
    if(key<root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    
    return root;
}


void SearchKey(Node* &curr, int key, Node* &parent)
{
    while(curr!=NULL && curr->data !=key)
    {
        parent = curr;

        if(key<curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
        
    }
}


// function for delete

void deleteNode(Node* &root, int key)
{
    Node* parent = NULL;

    Node* curr = root;

    SearchKey(curr, key, parent);

    //if key is not found in the tree
    if(curr == NULL)
    {
        return;
    }

    //if node to be deleted is leaf node
    if(curr->left == NULL & curr->right == NULL)
    {
        //if node is not a root node 
        if (curr!=root)
        {
            if(parent->left == curr)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }   
        }
        else
        {
            root = NULL;
        }

        free(curr);
    }

    //node to be deleted has two children
    else if(curr->left && curr->right)
    {
        //find its successor node
        Node* successor = MinimumValue(curr->right);

        int val = successor->data;

        deleteNode(root, successor->data);

        curr->data = val;
    }

    //node to be deleted has only one child
    else
    {
        //find child node
        Node* child = (curr->left)? curr->left: curr->right;

        //if node is not a root node
        if(curr!=root)
        {
            if( curr == parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }

        else
        {
            root = child;
        }

        free(curr);
        
    }
    
}

int main()
{
    Node* root = NULL;

    int keys[] = {15, 10, 20, 8, 12, 16};

    for(int key : keys)
    {
        root = insert(root, key);
    }

    // deleteNode(root, 16);
    inorder(root);
}