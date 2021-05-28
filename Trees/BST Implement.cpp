#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root;
class BST
{
public:
    void InsertNode()
    {

        struct Node *newNode = new Node();


        cout << "Enter Value:  ";
        cin >> newNode->data;

        newNode->right = NULL;
        newNode->left = NULL;

        struct Node *temp1;
        struct Node *temp2;

        if(root == NULL)
        {
            root = newNode;
            cout << newNode->data << " is the root of the tree" << endl;
        }
        else
        {
            temp1 = root;
            temp2 = NULL;

            while(root != 0)
                {
                    temp2 = temp1;
                    if(newNode->data < temp2->data)
                    {
                        temp1 = temp1->left;

                        if(temp1 == NULL)
                        {
                            temp2->left = newNode;
                            cout << newNode->data << " Inserted to the left of " <<temp2->data << endl;

                            return;
                        }
                    }
                    else
                    {
                        temp1 = temp1->right;
                        if(temp1 == NULL)
                        {
                            temp2->right = newNode;
                            cout << newNode->data << " Inserted to the right of " <<temp2->data << endl;

                            return;
                        }
                    }
                }
        }
    }

    int SearchNode(int key)
    {
        int flag = 0;
        while(root != NULL)
        {
            if(key > root->data)
                root = root->right;

            else if(key < root->data)
                root = root->left;
            else
                flag = 1;

        }
        //cout << key << " Not Found" <<endl;

        if(flag == 1)
            cout << "Found" <<endl;
        else
            cout  << "Not Found" <<endl;
    }

    Node* deleteNode(int data, Node* root)
    {

        if(root == NULL)
            return root;

        if(data > root->data)
        {
           root->right = deleteNode(data, root->right);

        }
        else if(data < root->data)
        {
            root->left = deleteNode(data, root->left);

        }
        else
        {
            //1 CHILD

            if(root->left == NULL)
            {
                Node* temp = root->right;
               // root->data = temp->data;
                delete(root);
                return temp;
            }
            else if(root->right == NULL)
            {
                Node* temp = root->left;
                //root->data = temp->data;
                delete(root);
                return temp;
            }
            //2 CHILDREN
            //successor
            Node* temp = minVal(root->right);

            root->data = temp->data;
            root->right = deleteNode(temp->data, root->right);
            }
            return root;
    }


    Node* minVal(Node* root)
    {
        while(root->left != NULL)
        {
            root = root->left;

        }
        return root;
    }


     void inOrder(Node *root)
        {
            if(root == NULL)
                return;

            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }

    void deletee(int dat, Node* root)
    {
        root = deleteNode(dat, root);
    }

};

int main()
{
    BST bin;
    bin.InsertNode();
    bin.InsertNode();
    bin.InsertNode();
    bin.InsertNode();

    int dat;
    cout << "Enter to delete: ";
    cin >> dat;
    bin.deletee(dat, root);

    bin.inOrder(root);
}
