#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Node
{
public:
   char data;
   Node* left, *right;

   Node(char x)
   {
       data = x;
       left = NULL;
       right = NULL;
   }
};
    bool isOperator(char data)
    {
        return (data == '+' || data == '-' || data == '/' ||data == '^' || data == '*');
    }

    bool isDigit(char ch)
    {
        return ( (ch!=')') && (ch!='(') && (ch!='+') && (ch!='-') && (ch!='=') && (ch!='*') && (ch!='/'));
    }

    int convert(char ch){	//converting character to integer
	return (ch - '0');
}

    double eval(int right, int left, char x){	//evaluate

	double res = 0;
	switch (x){
	case '+':
	    res = left+right;
	break;

	case '-':
	    res = left-right;
	break;

	case '*':
	    res = left*right;
	break;

	case '/':
	    res = left/right;
	break;
	}
	return res;
}

    void inorder(Node* root)
    {
        if(root == NULL)
            return;

            inorder(root->left);
            cout << root->data;
            inorder(root->right);
    }

    int evaluate(Node *exp)
    {
        int result;

        if(exp == NULL)
            return 0;
        int left = evaluate(exp->left);
        int right = evaluate(exp->right);

        if(!isDigit(exp->data) )
            return eval(right, left, exp->data);

        else
            return convert(exp->data);
    }


    Node* exTree(string exp)
    {
        stack<Node*> st;
        Node* node;

        for(int i = 0; i < exp.length(); i++)
        {

            char ch = exp[i];

            if(ch == ' ')
                continue;

            else if(isOperator(exp[i]) )
            {
                //new binary tree to save exp tree
                node = new Node(ch);

                Node* rc, *lc;

                rc = st.top(); //saving the top value for right child
                st.pop();

                lc = st.top(); //for left child
                st.pop();

                node->left = lc;
                node->right = rc;

                st.push(node);

            }
            else
            { //if it is Operand push it in stack of new bin tree
                Node* node1 = new Node(ch);
                //temp = create(exp[i]);
                st.push(node1);
            }
        }
        //node = st.top(); //root of exp tree
        //st.pop();

        return st.top();
    }


int main()
{
    string exp;
    cout << "Enter Expression: ";
    cin >> exp;
    Node* root;
    cout << "Infix: " << exp;
    root = exTree(exp);
    cout << endl;
    cout << "Arithmetic Expression Tree: ";
    inorder(root);
    cout << "\nEvaluating" << endl;
    cout << evaluate(root);

    return 0;
}
