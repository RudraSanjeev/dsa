#include <bits/stdc++.h>
using namespace std;

template <typename T, int M>
class Btree
{
public:
    struct Node
    {

        vector<T> keys;
        vector<Node *> children;
        bool leaf;

        Node(bool isLeaf) : leaf(isLeaf)
        {
            keys.reserve(M - 1);
            children.reserve(M);
        }
    };

    Node *root;

    Btree() : root(nullptr) {}

    void insert(const T &key)
    {

        if (root == nullptr)
        {
            root = new Node(true);
            root->keys.push_back(key);
            return;
        }
        Node *node = root;
        Node *parent = nullptr;

        while (!node->leaf)
        {

            parent = node;
            int i = 0;
            while (i < node->keys.size() && key > node->keys[i])
            {
                ++i;
            }
            node = node->children[i];
        }
        // if leaf node
        int i = 0;
        while (i < node->keys.size() && key > node->keys[i])
        {
            ++i;
        }
        node->keys.insert(node->keys.begin() + i, key);
        if (node->keys.size() == M - 1)
        {
            split(node, parent);
        }
    }

    void split(Node node, Node parent)
    {

        int mid = node->keys.size() / 2;

        Node *left = new Node(node->leaf);
        Node *right = new Node(node->leaf);

        left->keys.assign(node->keys.begin(), node->keys.begin() + mid);
        right->keys.assign(node->keys.begin() + mid + 1, node->keys.end());

        if (!node->leaf)
        {

            left->children.assign(node->children.begin(), node->children.begin() + mid);
            right->children.assign(node->children.begin() + mid + 1, node->children.end());
        }

        if (parent == nullptr)
        {

            root = new Node(false);
            root->keys.push_back(node->keys[mid]);
            root->children.push_back(left);
            root->children.push_back(right);
        }
        else
        {
            int i = 0;

            while (i < node->keys.size() && parent->keys[i] < node->keys[mid])
            {
                ++i;
            }

            /*vector<int>vect{1,2,3,5};
              vect.insert(vect.begin() + 3, 4);*/
            /*OutPut: 1 2 3 {4} 5
              index   0 1 2  3  4 */

            parent->keys.insert(parent->keys.begin() + i, node->keys[mid]);
            parent->children.erase(parent->children.begin() + i);

            // merging  children value
            parent->children.insert(parent->children.begin() + i, left);
            parent->children.insert(parent->children.begin() + i + 1, right);
        }
        node->keys.erase(node->keys.begin() + mid);
        node->children.erase(node->children.begin() + mid + 1);

        delete node;
    }

    bool search(const T &key)
    {

        Node *node = root;

        while (node != nullptr)
        {
            int i = 0;
            while (i < node->keys.size() && key > node->keys[i])
            {
                ++i;
            }
            if (i < node->keys.size() && key == node->keys[i])
            {
                return true;
            }
            node = node->leaf ? nullptr : node->children[i];
        }
        return false;
    }
    void print()
    {
        if (root != nullptr)
        {
            print(root);
        }
    }
    void print(const Node *node, int depth = 0)
    {

        if (node != nullptr)
        {
            for (int i = 0; i < depth; i++)
            {
                cout << " ";
            }
            for (auto key : node->keys)
            {
                cout << key << ' ';
            }
            cout << '\n';

            if (!node->leaf)
            {
                for (auto child : node->children)
                {
                    print(child, depth + 1);
                }
            }
        }
    }
};

signed main()
{

    Btree<int, 2> t;
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
    t.print();

    std::cout << "Is in the tree? " << std::boolalpha << t.search(4) << '\n';
    std::cout << "Is in the tree? " << std::boolalpha << t.search(17) << '\n';
}