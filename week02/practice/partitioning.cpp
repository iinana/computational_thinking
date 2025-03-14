#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int d) : val(d), next(nullptr) {}
    Node(int d, Node* n) : val(d), next(n) {} 
};

class LinkedList {
public:
    Node* head;
    int size;
    LinkedList(): head(nullptr), size(0) {}
    LinkedList(Node* h) {
        head = h;
        Node* curr = h;
        size = 0;
        while (curr) {
            size++;
            curr = curr->next;
        }
    }
    LinkedList(vector<int>& l) {
        size = l.size();
        if (size == 0) head = nullptr;
        else {
            head = new Node(l[0]);
            Node* curr = head;
            for (int i = 1; i < size; i++) {
                curr->next = new Node(l[i]);
                curr = curr->next;
            }
        }
    }

    int is_empty() {
        return size == 0;
    }

    void append(int d) {
        if (is_empty()) {
            head = new Node(d);
        } else {
            Node* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = new Node(d);
        }
    }

    void print() {
        Node* curr = head;
        string out = "";
        while (curr) {
            out += to_string(curr->val);
            if (curr->next != nullptr)
                out += "->";
            curr = curr->next;
        }
        cout << out << endl;
    }
};

// Node* partition(Node* head, int x) {
//     Node* init_l = new Node(-1, nullptr);
//     Node* init_r = new Node(-1, nullptr);
//     Node* left = init_l;
//     Node* right = init_r;

//     Node* curr = head;
//     while (curr) {
//         if (curr->val < x) {
//             left->next = curr;
//             left = left->next;
//         } else {
//             right->next = curr;
//             right = right->next;
//         }
//         curr = curr->next;
//     }

//     right->next = nullptr;
//     left->next = init_r->next;
//     return init_l->next;
// }

Node* partition(Node* head, int x) {
    Node* curr = head, *left = nullptr;
    Node* right = nullptr;
    Node* mid = nullptr;

    while (curr) {
        if (curr->val < x) {
            if (left) {
                left->next = curr;
                left = left->next;
            } else head = left = curr;
        } else {
            if (right) {
                right->next = curr;
                right = right->next;
            } else mid = right = curr;
        }
        curr = curr->next;
    }

    if (left) left->next = mid;
    else head = mid;
    if (right) right->next = nullptr;
    return head;
}

int main() {
    vector<int> v = {3, 5, 8, 5, 10, 2, 1};
    LinkedList l(v);
    Node* res = partition(l.head, 5);
    LinkedList result(res);
    result.print();
}