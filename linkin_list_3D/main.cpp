#include <iostream>
#include <cmath>

using namespace std;

struct node
{
    float x, y, z;
    node* next = NULL;
};

struct linkin_list
{
    node* head = NULL;
    node* tail = NULL;
};

void Insert(linkin_list* p, float x, float y, float z)
{
    node *new_node = new node;
    new_node->x = x;
    new_node->y = y;
    new_node->z = z;
    if(p->head == NULL)
    {
        p->head = new_node;
    }
    else
    {
        p->tail->next = new_node;
    }
    p->tail = new_node; 
}

void run()
{
    int n, m;
    float x, y, z;
    linkin_list *A = new linkin_list;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        Insert(A, x, y, z);
    }
    cin >> m;
    linkin_list *B = new linkin_list;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        Insert(B, x, y, z);
    }
    node *pi = new node;
    node *pa = new node;
    pi = B->head;
    while(pi != NULL)
    {
        pa = A->head;
        int j = 0;
        while(pa != NULL)
        {
            if(pa->x == pi->x && pa->y == pi->y && pa->z == pi->z)
            {   
                cout << j << endl;
                break;
            }
            pa = pa -> next;
            j++;
        }
        if(pa == NULL)
        {
            cout << "KHONG\n";
        }
        pi = pi -> next;
    }

}


int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}