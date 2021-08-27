#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int MAX_N = 1e5 + 1;
const double eps = 1e-9;
//#define int long long
#define endl "\n"
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define tr(it, a) for (auto it = a.begin(); i != a.end(); it++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

template <class T>
struct node
{
    T data;
    node *left, *right;
    node()
    {
        left = NULL, right = NULL;
    }
};

template <class T>
class BST
{
private:
    node<T> *root;
    node<T> *insert(T key, node<T> *root);
    void preorder(node<T> *root);
    void inorder(node<T> *root);
    node<T> *removeNode(T key, node<T> *root);
    node<T> *findMin(node<T> *root);

public:
    BST();
    ~BST();
    void insert(T key);
    void preorder();
    void inorder();
    void removeNode(T key);
    node<T> *findMin();
};

template <class T>
BST<T>::BST()
{
    root = NULL;
}
template <class T>
BST<T>::~BST()
{
    cout << "This is going to be deleted." << endl;
}

template <class T>
void BST<T>::insert(T key)
{
    if (root)
        root = insert(key, root);
    else
    {
        node<T> *newNode = new node<T>();
        newNode->data = key;
        root = newNode;
    }
}
template <class T>
node<T> *BST<T>::insert(T key, node<T> *root)
{
    if (!root)
    {
        node<T> *newNode = new node<T>();
        newNode->data = key;
        root = newNode;
    }
    else if (key > root->data)
        root->right = insert(key, root->right);

    else if (key < root->data)
        root->left = insert(key, root->left);
    return root;
}
template <class T>
void BST<T>::preorder()
{
    if (root)
        preorder(root);
    else
        cout << "BST is empty." << endl;
}
template <class T>
void BST<T>::preorder(node<T> *root)
{
    if (root)
    {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

template <class T>
void BST<T>::inorder(node<T> *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
}
template <class T>
void BST<T>::inorder()
{
    if (root)
        inorder(root);
    else
        cout << "Tree is empty." << endl;
}

template <class T>
node<T> *BST<T>::findMin()
{
    if (root)
        return findMin(root);
    else
    {
        cout << "Tree is empty." << endl;
        return NULL;
    }
}
template <class T>
node<T> *BST<T>::findMin(node<T> *root)
{
    if (root)
    {
        if (root->left == NULL)
            return root;
        else
            return findMin(root->left);
    }
    else
        return NULL;
}

template <class T>
void BST<T>::removeNode(T key)
{
    if (root)
        root = removeNode(key, root);
    else
        cout << "Tree is empty." << endl;
}
template <class T>
node<T> *BST<T>::removeNode(T key, node<T> *root)
{
    if (root)
    {
        if (key < root->data)
            root->left = removeNode(key, root->left);
        else if (key > root->data)
            root->right = removeNode(key, root->right);
        else if (root->left && root->right)
        {
            node<T> *temp = findMin(root->right);
            root->data = temp->data;
            root->right = removeNode(root->data, root->right);
        }
        else
        {
            node<T> *temp = root;
            if (!root->left)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            delete temp;
        }
        return root;
    }
    else
        return NULL;
}

void solve()
{
    BST<int> *tree = new BST<int>();
    tree->insert(121);
    tree->insert(1);
    tree->insert(433);
    tree->insert(-1);
    // tree->preorder();
    tree->removeNode(433);
    tree->inorder();
    node<int> *mn = tree->findMin();
    if (mn != NULL)
        cout << mn->data << endl;
}
int32_t main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin>>tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
