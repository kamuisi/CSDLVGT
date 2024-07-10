#include <iostream>
#include <cmath>

struct Point {
    float x, y, z;
    Point* next;
};

Point* createList(int n) {
    Point* head = nullptr;
    Point* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Point* newPoint = new Point();
        std::cin >> newPoint->x >> newPoint->y >> newPoint->z;
        newPoint->next = nullptr;
        if (head == nullptr) {
            head = newPoint;
            tail = newPoint;
        } else {
            tail->next = newPoint;
            tail = newPoint;
        }
    }
    return head;
}

void findPointsInRange(Point* head, float b, float e) {
    bool found = false;
    Point* current = head;
    while (current != nullptr) {
        float distance = std::sqrt(std::pow(current->x, 2) + std::pow(current->y, 2) + std::pow(current->z, 2));
        if (distance >= b && distance <= e) {
            std::cout << current->x << " " << current->y << " " << current->z << "\n";
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "KHONG" << std::endl;
    }
}

void deleteList(Point* &head) {
    while (head != nullptr) {
        Point* temp = head;
        head = head->next;
        delete temp;
    }
}

void run() {
    int n;
    float b, e;
    std::cin >> n;
    Point* head = createList(n);
    std::cin >> b >> e;
    findPointsInRange(head, b, e);
    deleteList(head);
}

int main() {
    run();
    return 0;
}
