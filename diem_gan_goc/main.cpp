#include <iostream>
using namespace std;

struct node
{
    int x, y;
    node *next = NULL;
};

struct linkin_list
{
    node *head = NULL;
    node *tail = NULL;
};

void Insert(linkin_list *root, int x, int y)
{
    int a, b;
    node *new_node = new node;
    new_node->x = x;
    new_node->y = y;
    if (root->head == NULL)
    {
        root->head = new_node;
        root->tail = new_node;
        return;
    }
    node *p = new node;
    p = root->head;
    node *buff = new node;
    a = x * x + y * y;
    while (p != NULL)
    {
        b = p->x * p->x + p->y * p->y;
        if (a < b || (a == b && (x < p->x || (x == p->x && y < p->y))))
        {
            new_node->next = p;
            if (buff == NULL)
            {
                root->head = new_node;
            }
            else
            {
                buff->next = new_node;
            }
            return;
        }
        buff = p;
        p = p->next;
    }
    root->tail->next = new_node;
    root->tail = new_node;
}

int main()
{
    linkin_list *A = new linkin_list;
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        Insert(A, x, y);
    }
    node *p = new node;
    p = A->head;
    while (p != NULL)
    {
        cout << p->x << ' ' << p->y << endl;
        p = p->next;
    }
    return 0;
}
