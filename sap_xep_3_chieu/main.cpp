#include <iostream>
#include <cmath>

using namespace std;
struct Node {
    double x, y, z;
    Node* next;
    
    Node(double x, double y, double z) : x(x), y(y), z(z), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    
    void insert(double x, double y, double z) {
        Node* newNode = new Node(x, y, z);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void sort() {
        if (!head || !head->next) return;

        head = mergeSort(head);
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->x << " " << temp->y << " " << temp->z << endl;
            temp = temp->next;
        }
    }

private:
    Node* head;

    Node* mergeSort(Node* node) {
        if (!node || !node->next) return node;

        Node* middle = getMiddle(node);
        Node* nextOfMiddle = middle->next;
        middle->next = nullptr;

        Node* left = mergeSort(node);
        Node* right = mergeSort(nextOfMiddle);

        return merge(left, right);
    }

    Node* getMiddle(Node* node) {
        if (!node) return node;

        Node* slow = node;
        Node* fast = node->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;

        if (compareNodes(left, right) <= 0) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    int compareNodes(Node* a, Node* b) {
        if (a->x < b->x) return -1;
        if (a->x > b->x) return 1;
        if (a->y < b->y) return -1;
        if (a->y > b->y) return 1;
        if (a->z < b->z) return -1;
        if (a->z > b->z) return 1;
        return 0;
    }
};

void run() {
    int n;
    cin >> n;

    LinkedList list;
    
    for (int i = 0; i < n; ++i) {
        double x, y, z;
        cin >> x >> y >> z;
        list.insert(x, y, z);
    }

    list.sort();
    list.print();
}
int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}