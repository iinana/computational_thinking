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

void delete_middle(Node*& n) {
    n->val = n->next->val;
    n->next = n->next->next;
}

int main() {
    vector<int> l = {1, 2, 3, 4, 5, 6};
    LinkedList link(l);
    delete_middle(link.head->next->next->next);
    link.print();
}