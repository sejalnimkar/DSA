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

class queue
{
    BTnode *q[10];
    int front, rear;

public:
    queue()
    {
        front = rear = -1;
    }

    void add(BTnode *data)
    {
        if (front == -1)
        {
            front = 0;
        }

        else if (rear == 9)
        {
            cout << "\nQueue is full";
            return;
        }
        rear = rear + 1;
        q[rear] = data;
        return;
    }

    BTnode *remove()
    {
        BTnode *ptr;
        if ((front == -1) || (front == 9))
        {
            cout << "\nQueue is empty";
            return NULL;
        }
        ptr = q[front];
        front = front + 1;
        return ptr;
    }

    int isEmpty()
    {
        if (front == -1 || front == rear + 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
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

    void insert(int data)
    {
        BTnode *new_node = new BTnode(data);
        BTnode *temp;
        queue q;
        if (root == NULL)
        {
            root = new_node;
            return;
        }

        temp = root;
        q.add(temp);

        while (!q.isEmpty())
        {
            temp = q.remove();
            if (temp->get_left() == NULL)
            {
                temp->set_left(new_node);
                break;
            }
            else
            {
                q.add(temp->get_left());
            }

            if (temp->get_right() == NULL)
            {
                temp->set_right(new_node);
                break;
            }
            else
            {
                q.add(temp->get_right());
            }
        }
    }

    void level_trav()
    {
        BTnode *temp = root;
        queue q;
        if (root == NULL)
        {
            cout << "\nTree is empty";
        }
        q.add(temp);
        while (!q.isEmpty())
        {
            temp = q.remove();
            cout << temp->get_data() << " ";
            if (temp->get_left() != NULL)
            {
                q.add(temp->get_left());
            }
            if (temp->get_right() != NULL)
            {
                q.add(temp->get_right());
            }
        }
        return;
    }

    void swap(BTnode *p)
    {
        BTnode *t;
        t = p->get_left();
        p->set_left(p->get_right());
        p->set_right(t);
    }

    void mirror_image()
    {
        BTnode *ptr = root;
        if (root == NULL)
        {
            cout << "\nTree is empty";
            return;
        }
        queue q;
        q.add(ptr);
        while (!q.isEmpty())
        {
            ptr = q.remove();
            swap(ptr);
            if (ptr->get_left() != NULL)
            {
                q.add(ptr->get_left());
            }
            if (ptr->get_right() != NULL)
            {
                q.add(ptr->get_right());
            }
        }
        return;
    }

    int isIdentical(BinaryTree bt)
    {
        BTnode *ptr1 = root;
        BTnode *ptr2 = bt.get_root();
        queue q1;
        queue q2;
        if ((ptr1 == NULL) || (ptr2 == NULL))
        {
            cout << "\nInvalid";
            return 0;
        }
        q1.add(ptr1);
        q2.add(ptr2);
        while ((!q1.isEmpty()) && (!q2.isEmpty()))
        {
            ptr1 = q1.remove();
            ptr2 = q2.remove();
            if (ptr1->get_data() != ptr2->get_data())
            {
                return 0;
            }

            if (ptr1->get_left() != NULL)
            {
                q1.add(ptr1->get_left());
            }
            if (ptr1->get_right() != NULL)
            {
                q1.add(ptr1->get_right());
            }

            if (ptr2->get_left() != NULL)
            {
                q2.add(ptr2->get_left());
            }
            if (ptr2->get_right() != NULL)
            {
                q2.add(ptr2->get_right());
            }
        }
        if ((q1.isEmpty()) && (q2.isEmpty()))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    BTnode *del(BTnode *ptr, int key)
    {
        BTnode *temp, *succ;
        if (ptr == NULL)
        {
            cout << "\nInvalid";
            return NULL;
        }
        if (key < ptr->get_data())
        {
            ptr->set_left(del(ptr->get_left(), key));
        }
        else if (key > ptr->get_data())
        {
            // ptr = ptr->set_right(del(ptr->get_right(), key));
        }
    }
};

int main()
{
    BinaryTree obj, obj2;
    obj.insert(40);
    obj.insert(50);
    obj.insert(60);
    obj.insert(70);
    obj.insert(80);
    obj.insert(90);
    obj.insert(100);
    // obj.inorder(obj.get_root());
    obj.level_trav();
    // obj.mirror_image();
    // obj.inorder(obj.get_root());

    obj2.insert(40);
    obj2.insert(50);
    obj2.insert(60);
    obj2.insert(70);
    obj2.insert(80);
    obj2.insert(90);
    obj2.insert(100);
    cout << "\n2nd object: ";
    obj2.level_trav();

    if (obj.isIdentical(obj2))
    {
        cout << "\nthe binary trees are identical ";
    }
    else
    {
        cout << "\nthe binary trees are not identical ";
    }

    return 0;
}