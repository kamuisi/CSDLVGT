#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int value;
    node* next = NULL;
};

struct linkin_list
{
    node* head = NULL;
    node* tail = NULL;
};

void Insert(linkin_list &p, int k)
{
    node* new_node = new node;
    new_node->value = k;
    if(p.head == NULL)
    {
        p.head = new_node;
    }
    else
    {
        p.tail->next = new_node;
    }
    p.tail = new_node;
}

struct hash_table
{
    linkin_list p;
};

int main()
{
    int M, N, N_0;
    float LOAD;
    int k, hash_value;
    cin >> M >> LOAD >> N;
    hash_table *h = new hash_table[M];
    for(int i = 1; i <= N; i++)
    {
        cin >> k;
        if(( (float)i / (float)M )> LOAD) continue;
        Insert(h[k % M].p, k);
    }
    cin >> N_0;
    vector<int> Find_K(N_0, 0);
    for(int i = 0; i < N_0; i++)
    {
        cin >> Find_K[i];
    }
    for(int i = 0; i < N_0; i++)
    {
        hash_value = Find_K[i] % M;
        node *point = new node;
        point = h[hash_value].p.head;
        int j = 1;
        while(point != NULL)
        {
            if(point->value == Find_K[i])
            {
                cout << j << endl;
                break;
            }
            j++;
            point = point->next;
        }
        if(point == NULL) cout << "KHONG\n";
    }
    return 0;
}