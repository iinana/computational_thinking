// Weave a linked list
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    int val;
    Node* next; 
    Node(int e): val(e), next(nullptr) {}
    Node(int e, Node* n): val(e), next(n) {}
};

class LinkedList {
public:
    Node* head;
    int size;
    LinkedList(): head(nullptr), size(0) {}
    LinkedList(vector<int>& l) {
        head = new Node(l[0]);
        size = l.size();
        Node* curr = head;
        for (int i = 1; i < size; ++i) {
            curr->next = new Node(l[i]);
            curr = curr->next;
        }
    }

    int is_empty() {
        return (size == 0);
    }

    void append(int d) {
        Node* end = new Node(d);
        if (head == nullptr) {
            head = end;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = end;
    }

    void print() {
        Node* curr = head;
        string out = "";
        while (curr != nullptr) {
            out += to_string(curr->val);
            curr = curr->next;
            if (curr != nullptr)
                out += "->";
        }
        cout << out << endl;
    }
};

Node* weave(Node* head) {
    Node* fast = head->next;
    Node* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* prev = slow;
    slow = slow->next;
    prev->next = nullptr;

    fast = head;
    Node *out = nullptr;
    while (fast && slow) {
        if (out) {
            out->next = fast;
            out = out->next;
        } else out = fast;
        fast = fast->next;

        out->next = slow;
        out = out->next;
        slow = slow->next;
    }
    out->next = nullptr;
    head = out;
    return head;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        vector<int> v;
        for (int i = 1; i < argc; ++i) {
            v.push_back(stoi(argv[i]));
        }
        LinkedList l(v);
        weave(l.head);
        l.print();
    }
}
