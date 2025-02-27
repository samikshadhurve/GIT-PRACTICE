#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int ltr, rtr;
};

class TBT
{
public:
    node *root, *dummy, *cn;

    TBT()
    {
        root = NULL;
    }

    void insert()
    {
        node *nn = new node;
        cout << "Enter the data: ";
        cin >> nn->data;
        nn->left = nn->right = nullptr;
        nn->rtr = nn->ltr = 1;

        if (root == NULL)
        {
            dummy = new node;
            dummy->data = 999;
            root = nn;
            nn->left = nn->right = dummy;
            dummy->left = dummy->right = nn;
        }
        else
        {

            cn = root;

            while (1)
            {
                if (nn->data < cn->data)
                {
                    if (cn->ltr == 1)
                    {
                        nn->left = cn->left;
                        nn->right = cn;
                        cn->ltr = 0;
                        cn->left = nn;
                        break;
                    }
                    else
                    {
                        cn = cn->left;
                    }
                }
                else
                {
                    if (cn->rtr == 1)
                    {
                        nn->right = cn->right;
                        nn->left = cn;
                        cn->rtr = 0;
                        cn->right = nn;
                        break;
                    }
                    else
                    {
                        cn = cn->right;
                    }
                }
            }
        }
    }

    void inorder()
    {
        cout << "Inorder Traversal: ";
        cn = root;

        while (cn != dummy)
        {
            while (cn->ltr == 0)
            {
                cn = cn->left;
            }
            cout << cn->data << " ";
            while (cn->rtr == 1)
            {
                cn = cn->right;
                if (cn == dummy)
                {
                    return;
                }
                cout << cn->data << " ";
            }
            cn = cn->right;
        }
        cout << endl;
    }

    void preorder()
    {
        cout << "Preorder Traversal: ";

        cn = root;
        while (cn != dummy)
        {

            while (cn->ltr == 0)
            {
                cout << cn->data << " ";
                cn = cn->left;
            }
            cout << cn->data << " ";
            while (cn->rtr == 1)
            {
                cn = cn->right;
                if (cn == dummy)
                {
                    return;
                }
            }
            cn = cn->right;
        }
        cout << endl;
    }

    void postorder()
    {
        cout << "Postorder Traversal: ";
        cn = root;
        int post[30];
        int i = 0;
        while (cn != dummy)
        {
            while (cn->rtr == 0)
            {
                post[i] = cn->data;
                i++;
                cn = cn->right;
            }
            post[i] = cn->data;
            i++;

            while (cn->ltr == 1)
            {
                if (cn == dummy)
                {
                    break;
                }
                cn = cn->left;
            }

            if (cn != dummy)
            {
                cn = cn->left;
            }
        }

        for (int j = i - 1; j >= 0; j--)
        {
            cout << post[j] << " ";
        }
        cout << endl;
    }

    void deleteNode(int key)
    {
        node *temp = root;
        node *parent = NULL;
        bool found = false;

        // Find the node to delete
        while (temp != dummy)
        {
            if (key < temp->data)
            {
                parent = temp;
                temp = temp->left;
            }
            else if (key > temp->data)
            {
                parent = temp;
                temp = temp->right;
            }
            else
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Node with key " << key << " not found!" << endl;
            return;
        }

        // Node with the key found

        // If the node has both left and right children
        if (temp->ltr == 0 && temp->rtr == 0)
        {
            if (temp->left->rtr == 0)
            {
                node *successor = temp->left;

                while (successor->rtr == 0)
                {
                    successor = successor->right;
                }

                temp->data = successor->data;
                temp = successor;
            }
            else
            {
                // The left child has no right thread
                temp->data = temp->left->data;
                temp->ltr = 1;
                temp->left = temp->left->left;
            }
        }
        else
        {
            // Node has only one child or no child
            if (temp->ltr == 1)
            {
                if (parent->left == temp)
                {
                    parent->left = temp->left;
                }
                else
                {
                    parent->right = temp->left;
                }
            }
            else
            {
                if (parent->left == temp)
                {
                    parent->left = temp->right;
                }
                else
                {
                    parent->right = temp->right;
                }
            }
        }

        delete temp;
    }
};

int main()
{
    TBT b;
    int key;
    int choice;

    do
    {
        cout << "\n*****  Menu  *****" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Inorder" << endl;
        cout << "3. Preorder" << endl;
        cout << "4. Postorder" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int c;
            cout << "Enter the number of data you want to insert: ";
            cin >> c;
            for (int i = 0; i < c; i++)
            {
                b.insert();
            }
            break;

        case 2:
            b.inorder();
            break;

        case 3:
            b.preorder();
            break;

        case 4:
            b.postorder();
            break;

        case 5:
            cout << "Enter the key to delete: ";
            cin >> key;
            b.deleteNode(key);
            cout << "Inorder Traversal after deletion:" << endl;
            b.inorder();
            break;

        case 6:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
