#include <iostream>
using namespace std;

class BTnode
{
    int data;
    BTnode *left;
    BTnode *right;

public:
    BTnode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    BTnode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    void set_data(int d)
    {
        data = d;
    }

    void set_left(BTnode *l)
    {
        left = l;
    }
    void set_right(BTnode *r)
    {
        right = r;
    }
    int get_data()
    {
        return data;
    }
    BTnode *get_left()
    {
        return left;
    }
    BTnode *get_right()
    {
        return right;
    }
};

class BinaryTree
{
    BTnode *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    BTnode *create_node(int d)
    {
        BTnode *n = new BTnode(d);
        return n;
    }

    void set_root(BTnode *n)
    {
        root = n;
    }

    BTnode *get_root()
    {
        return root;
    }

    void preorder(BTnode *n)
    {
        if (n == NULL)
        {
            //   cout<<"\nEmpty";
            return;
        }

        cout << n->get_data() << " ";
        preorder(n->get_left());
        preorder(n->get_right());
    }

    void inorder(BTnode *n)
    {
        if (n == NULL)
        {
            return;
        }
        inorder(n->get_left());
        cout << "\n"
             << n->get_data();
        inorder(n->get_right());
    }
};

class BST
{
    BTnode *root;

public:
    BST()
    {
        root = NULL;
    }

    void set_root(BTnode *n)
    {
        root = n;
    }

    BTnode *get_root()
    {
        return root;
    }

    void preorder(BTnode *n)
    {
        if (n == NULL)
        {
            //   cout<<"\nEmpty";
            return;
        }

        cout << n->get_data() << " ";
        preorder(n->get_left());
        preorder(n->get_right());
    }

    void inorder(BTnode *n)
    {
        if (n == NULL)
        {
            return;
        }
        inorder(n->get_left());
        cout << " " << n->get_data();
        inorder(n->get_right());
    }

    void insert(int key)
    {
        BTnode *new_node, *ptr, *par;
        new_node = new BTnode(key);

        if (root == NULL)
        {
            root = new_node;
            return;
        }

        ptr = root;

        while (ptr != NULL)
        {
            par = ptr;
            if (key < ptr->get_data())
            {
                ptr = ptr->get_left();
            }
            else if (key > ptr->get_data())
            {
                ptr = ptr->get_right();
            }
            else
            {
                cout << "Duplicate value...error";
                return;
            }
        }

        if (key < par->get_data())
        {
            par->set_left(new_node);
        }
        else
        {
            par->set_right(new_node);
        }
        return;
    }

    int find_minimum(BTnode *ptr)
    {
        // non_recursive function BTnode *ptr=root
        //  It is a parameter less function
        // replace last else with the foll. code
        //  while(ptr->get_left()!=NULL)
        //  {
        //      ptr=ptr->get_left();
        //  }
        //  return ptr->get_data();

        if (ptr == NULL)
        {
            return -1;
        }

        else if (ptr->get_left() == NULL)
        {
            return ptr->get_data();
        }

        else
        {
            return find_minimum(ptr->get_left());
        }
    }

    int find_maximum(BTnode *ptr)
    {
        if (ptr == NULL)
        {
            return -1;
        }

        else if (ptr->get_right() == NULL)
        {
            return ptr->get_data();
        }

        else
        {
            return find_maximum(ptr->get_right());
        }
    }

    BTnode *search(BTnode *ptr, int key)
    {
        if (ptr == NULL)
        {
            return NULL;
        }

        if (ptr->get_data() == key)
        {
            return ptr;
        }

        else if ((key) < (ptr->get_data()))
        {
            return search(ptr->get_left(), key);
        }

        else if ((key) > (ptr->get_data()))
        {
            return search(ptr->get_right(), key);
        }
    }

    int height(BTnode *ptr)
    {
        int hl, hr;

        if (ptr == NULL)
        {
            return 0;
        }

        hl = height(ptr->get_left());
        hr = height(ptr->get_right());

        if (hl > hr)
        {
            return 1 + hl;
        }
        else
        {
            return 1 + hr;
        }
    }

    void mirror(BTnode *n)
    {
        if (n == NULL)
        {
            return;
        }
        else
        {
            BTnode *temp;
            mirror(n->get_left());
            mirror(n->get_right());

            temp = n->get_left();
            n->set_left(n->get_right());
            n->set_right(temp);
        }
    }
};
int main()
{

    BST t1;
    int key;

    t1.insert(10);
    t1.insert(4);
    t1.insert(5);
    t1.insert(11);
    t1.insert(2);
    t1.insert(12);
    cout << "\nInorder display of tree: ";
    t1.inorder(t1.get_root());
    t1.mirror(t1.get_root());
    cout << "\nAfter mirroring the tree: ";
    t1.inorder(t1.get_root());

    // cout << "\n Maximum element in BST: " << t1.find_maximum(t1.get_root());
    // cout << "\n Minimum element in BST: " << t1.find_minimum(t1.get_root());

    cout << "\nEnter value to search: ";
    cin >> key;
    BTnode *res = t1.search(t1.get_root(), key);
    if (res == NULL)
    {
        cout << "\nNode with " << key << " not found\n";
    }
    else
    {
        cout << "\nNode with " << key << " found at " << res;
    }
}
// cout << "\nHeight : " << t1.height(t1.get_root());

//     return 0;
// }
