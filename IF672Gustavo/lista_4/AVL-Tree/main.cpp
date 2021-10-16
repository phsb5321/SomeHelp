#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
    int children;
};

int getChildren(Node *root)
{
    if (root == nullptr)
        return 0;
    return root->children + 1;
}

int height(Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    node->children = 0;
    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    int helper = 0;
    helper += getChildren(y->right) +
              getChildren(y->left);
    y->children = helper;

    helper = 0;
    helper += getChildren(x->right) +
              getChildren(x->left);
    x->children = helper;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    int helper = 0;
    helper += getChildren(x->right) +
              getChildren(x->left);
    x->children = helper;

    helper = 0;
    helper += getChildren(y->right) +
              getChildren(y->left);
    y->children = helper;

    return y;
}

int getBalance(Node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key)
{
    if (node == nullptr)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int helper = 0;
    helper += getChildren(node->right) +
              getChildren(node->left);
    node->children = helper;

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int search(Node *root, int value, int index = 0)
{
    if (root == nullptr)
        return pow(-10, 5);
    if (root->key == value && root->left == nullptr)
    {
        return index;
    }
    else if (root->key == value)
    {
        index += getChildren(root->left);
        return index;
    }
    //    else if (root->left == nullptr && root->right == nullptr)
    //        return pow(-10, 5);

    if (value < root->key)
    {
        index = search(root->left, value, index);
    }
    else
    {
        if (root->left != nullptr)
            index += getChildren(root->left);
        index += search(root->right, value, 1);
    }
    return index;
}

int main()
{
    Node *root = nullptr;
    string str_builder;

    int num_of_cases;
    cin >> num_of_cases;
    int query;
    int input;
    for (int a = 0; a < num_of_cases; a++)
    {
        cin >> query >> input;
        switch (query)
        {
        case 1:
            root = insert(root, input);
            break;
        case 2:
            int index = search(root, input);
            if (index < 0)
                str_builder += "Data tidak ada\n";
            else
                str_builder += to_string(index + 1) + "\n";
            break;
        }
    }

    cout << str_builder;
    return 0;
}
