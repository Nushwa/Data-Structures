#include <iostream>

using namespace std;

class node
{
public:

    int data;
    node *left, *right;

    node(int x)
    {
      data = x;
      left = NULL;
      right = NULL;
    }

};
node *root = NULL;

class binTree
{
public:
    node* Insert(int data, node* root)
    {
        if(root == NULL)
            {
                node* temp = new node(data);
                return temp;
            }
        else if(data < root->data)
        {
            root->left = Insert(data, root->left);
            cout << data << " Inserted to left." <<endl;
        }
        else
        {
            root->right = Insert(data, root->right);
            cout << data << " Inserted to right." <<endl;
        }

       return root;
    }
        void insertt(int data)
        {
            root = Insert(data, root);
        }

        void inOrder(node *root)
        {
            if(root == NULL)
                return;

            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }

        int searchN(int key, node* root)
        {
            if(root == NULL)
            {
                cout << "Tree is Empty" << endl;
                return -1;
            }
            node* temp = root;

            while(temp != NULL)
            {
                if(key > temp->data)
                {
                    if(temp->data == key)
                    {
                        cout << "Found " << key << endl;
                        return 1;
                    }
                    temp = temp->right;
                }
                else
                {
                    if(temp->data == key)
                    {
                        cout << "Found: " << key << endl;
                        return 1;
                    }
                    temp = temp->left;
                }
            }
            cout << "Not Found" << endl;
            return -1;
        }

        node* DeleteN(int x, node* root)
        {
          if(root == NULL)
          return root;

          if(x < root->data)
            root->left = DeleteN(x, root->left);

          else if(x > root->data)
            root->right = DeleteN(x, root->right);
          else
          {
              //1 child
              if(root->left == NULL)
              {
                  node* temp = root->right;
                  cout << "Deleting " << root->data <<endl;
                  delete(root);
                  return temp;
              }
              else if(root->right == NULL)
              {
                  node* temp = root->left;
                  cout << "Deleting " << root->data <<endl;
                  delete(root);
                  return temp;
              }
              // 2 children
              node* temp = minval(root->right);
              //successor
              root->data = temp->data;
              root->right = DeleteN(temp->data, root->right);
          }
          return root;
        }


        node* minval(node* root)
        {
            while(root->left != NULL)
                root = root->left;

            return root;
        }

        node* getLargest(node* root)
        {
            if(root->right != NULL)
                return getLargest(root->right);

            return root;
        }

       node* SecLargest(node* root)
       {

        if(root->right == NULL && root->left != NULL)
            return getLargest(root->left);

        if(root->right != NULL && root->left == NULL)
            return getLargest(root->left);


                cout << "2nd largest: " << root->data << endl;

            SecLargest(root->left);
        }
};

int main()
{
    binTree bn;
    int val, data;

    cout << "Enter the number of times you want to enter values: ";
    cin >> val;
    for (int i = 0; i < val; i++)
    {
        cout << "Enter data: ";
        cin >> data;
        bn.insertt(data);
    }

    bn.inOrder(root);
cout << endl;
    bn.DeleteN(10,root);

    bn.inOrder(root);
    cout << endl;
    bn.searchN(8,root);

    bn.SecLargest(root);


    return 0;
}
