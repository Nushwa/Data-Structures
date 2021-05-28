#include<iostream>
#include<queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};
struct Node *root;
int count;

class BST
{
public:
void Insert()
{
    struct Node *newNode = new Node();

    cout << "Enter data: ";
    cin >> newNode->data;

    Node* temp1;
    Node* temp2;

    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
    {
        root = newNode;
        cout << "The root of the tree is: " << newNode->data <<endl;
    }
    else
    {
        temp1 = root;
        temp2 = NULL;

        while(root != NULL)
        {
            temp2 = temp1;

            if(newNode->data < temp2->data) //form the left subtree
            {
                temp1 = temp1->left;

                if(temp1 == 0)
                {
                    temp2->left = newNode;
                    cout << newNode->data << " Inserted to the left of " <<temp2->data << endl;
                    return;
                }
            }
            else
            {
                temp1 = temp1->right;
                if(temp1 == 0)
                    {
                       temp2->right = newNode;
                        cout << newNode->data << " Inserted to the right of " <<temp2->data << endl;
                        return;
                    }
            }

        } //end while
    } //end else part

} //end create function

void inorder(struct Node* root)
{
    if(root != NULL)
    {
        //first left subtree or smallest to largest
        inorder(root->left);
        cout << root->data << " " ;
        inorder(root->right);
    }
}

void preorder(struct Node* root)
{
    if(root != NULL)
    {
        //first root and then right nodes
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root)
{
    if(root != NULL)
    {
        //right,left and then root
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
        count++;
    }
}

int levelOrder(struct Node* root)
{
    Node* curr = NULL;
    queue<Node*> que; //using queue operations for this traversal

    que.push(root);

    while(!que.empty() )
    {
        Node* curr = que.front();
        cout << curr->data << " ";
        if(curr->left != 0) //push all the values in same level
            que.push(curr->left);
        if(curr->right != 0)
            que.push(curr->right);

        que.pop();
    }
}
};


class Functions
{
public:
    BST bin;
   int findParent(struct Node* root, int key, int parent)
    {
        //Base case
        if(root == NULL)
        {
            return -1;
        }
        if(root->data == key)
            cout << parent;
        else
        {
            findParent(root->left, key, root->data);
            findParent(root->right, key, root->data);
        }
    }

    int findLevel(struct Node* root, int key, int le)
    {
        if(root == NULL)
            return -1;

        if(root->data == key)
            return le;
        int lev = findLevel(root->left, key, le+1);
        if(lev != -1)
            return lev;

        lev = findLevel(root->right, key, le+1);
    }

    int findDepth(struct Node* root, int key, int dep)
    {
        //Base case
        if(root == NULL)
            return -1;

        if(root->data == key)
            cout <<dep;
        else
        {
            int st = findDepth(root->left, key, dep+1);
            if(st != -1)
                return st;

            st = findDepth(root->right, key, dep+1);
        }
    }

    int FindHeight(struct Node* root)
    {
        //Base case
        if(root == NULL)
            return -1;
        else
        {
            //height = leaf to root
            int lhe = FindHeight(root->left);
            int rhe = FindHeight(root->right);

            if(lhe > rhe)
                return (lhe+1);
            else return (rhe+1);

            cout << lhe+rhe;
        }
    }

    bool Samelevel(struct Node* root, int key1, int key2)
    {
        if(root == NULL)
            return false;

        if(findLevel(root,key1,1) == findLevel(root,key2,1))
            return true;
    }

    void totalNodes()
    {
        cout << "Total Nodes: " << count;
    }
};

int main() {
  BST binTree;
  Functions fn;

  int val, key, key2;
  cout << "\n-----Binary Search Tree-------\n" << endl;

  cout << "Create a Tree: " << endl;

  cout << "Enter the number of values: ";
  cin >> val;
  for (int i = 0; i < val; i++)
    binTree.Insert();

  cout << "-----Traversals-----" << endl;
  cout << "In order" << endl;
  binTree.inorder(root);
  cout << endl;
  cout << "Pre-order" << endl;
  binTree.preorder(root);
  cout << endl;
  cout << "Post-order" << endl;
  binTree.postorder(root);
  cout << endl;
  cout << "Level Order" << endl;
  binTree.levelOrder(root);
  cout << endl;


  return 0;
}
