#include<iostream>

using namespace std;

class Node
{
public:
   int data;
   int height;
   Node *left, *right;

   Node(int d)
   {
       data = d;
       height = 1;
       left = NULL;
       right = NULL;
   }
};
Node *root = NULL;


class AVL
{
public:

    Node* maxValue(Node* node)
    {
        Node* temp = node;
        while(temp->right != NULL)
            temp = temp->right;

        return temp;
    }

    int height(Node* node)
    {
        if(node == NULL)
            return 0;
        else
            return node->height;
    }

    int getBalanceFactor(Node* root)
    {
         return height(root->left) - height(root->right);

    }
    struct Node* rightRotation(Node* root)
    {
        cout << "\nRight Rotation" << endl;
        Node* newroot = root->left;

        root->left = newroot->right;
        newroot->right = root;

        root->height = 1 + max(height(root->left), height(root->right) );
        newroot->height = 1+max(height(newroot->left), height(newroot->right) );
        return newroot;
    }

    struct Node* leftRotation(Node* root)
    {
        cout << "\nLeft Rotation" << endl;
        Node* newroot = root->right;

        root->right = newroot->left;
        newroot->left = root;

        root->height = 1 + max(height(root->left), height(root->right) );
        newroot->height = 1+max(height(newroot->left), height(newroot->right) );
        return newroot;
    }

    Node* InsertNode( struct Node *root, int x)
    {
        struct Node* newNode = new Node(x);

        if(root == NULL)
        {
            Node *temp = new Node(x);
                return temp;
        }
        if(x < root->data)
            { //go to the left subtree of current node
                root->left = InsertNode(root->left,x);
            }
        else if(x > root->data)
            {
                root->right = InsertNode(root->right,x);
            }
        else //if equal
            return root;

        //Updating the height
            root->height = 1 + max(height(root->left), height(root->right) );

            //calculating the balance factor
            int balance = getBalanceFactor(root);
        // only {1,0,-1} are allowed
        if(balance > 1)
        { //Right Rotation
            if(x < root->left->data)
                return rightRotation(root);
            else
            { //Left- Right Rotation
                root->left = leftRotation(root->left);
                return rightRotation(root);
            }
        }
        else if(balance < -1)
        {
            //Left Rotation
            if(x > root->right->data)
                return leftRotation(root);
            else
            {
                //Right-Left Rotation
                root->right = rightRotation(root->right);
                return leftRotation(root);
            }
        }
        return root;
    }

    Node* DeleteNode(struct Node* node, int x)
    {
        if (node == NULL)
            return 0;
        if(x < node->data)
        {//left subtree
            node->left = DeleteNode(node->left, x);
        }
        else
            if(x > node->data)
        {
            node->right = DeleteNode(node->right, x);
        }
        else
        { // if equal to node then
            Node* temp = node->right;

            if(node->right == NULL)
            {
                Node* temp2 = node->left;
                delete(node);
                node = temp2;
            }
            else if(node->left == NULL)
            {
                delete(node);
                node = temp;
            }
            else
            {
                //with 2 children
                temp = maxValue(node->left);
                //replace with In-order precessor ->largest value from left subtree
                node->data = temp->data;
                node->right = DeleteNode(node->right, temp->data);
            }
        }
        if(node == NULL)
            return node;

        node->height = 1 + max(height(node->left), height(node->right) );
        int bal = getBalanceFactor(node);

        if(bal > 1)
        {
            if(height(node->left) >= height(node->right))
                return rightRotation(node);
            else
            {
                node->left = leftRotation(node->left);
                return rightRotation(node);
            }
        }
        else if(bal < -1)
        {
            if(height(node->right) >= height(node->left))
                return leftRotation(node);
            else
            {
                node->right = rightRotation(node->right);
                return leftRotation(node);
            }
        }
        return node;
    }

    void deleten(int x)
    {
        root = DeleteNode(root, x);
    }
    void insert(int x)
    {
        root = InsertNode(root, x);
    }

    void inorderTraversal(Node* root)
    {
        if(root == NULL)
            return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);

    }
    void postOrder(Node* root)
    {
        if(root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

};


int main()
{
    AVL altree;
    int data, val;
    cout << "How man times do you want to enter > ";
    cin >> val;
    for(int i = 0; i < val; i++)
    {
        cout << "Enter data: ";
        cin >> data;
        altree.insert(data);

    }
    cout << endl;
    altree.inorderTraversal(root);

    cout << "Enter data to delete: ";
        cin >> data;
        altree.deleten(data);
        altree.inorderTraversal(root);
        cout << "Post Order" << endl;
        altree.postOrder(root);

    return 0;
}



