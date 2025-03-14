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
    Node* first = head; // fast node
    Node* second = head; // slow node
    while (first) {
        first = first->next->next; // even number인 것 guarantee되어있으므로 문제X
        second = second->next;
    }
    first = head; // first는 head에, second는 middle node에
    while (second) {
        Node* pointer = first->next;
        first->next = second; // current node 다음에 second 잇기
        first = pointer; // first 다음으로 넘기기

        pointer = second->next;
        if (!pointer) break;
        second->next = first; // current node 다음에 first 잇기
        second = pointer; // second 다음으로 넘기기
    }
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
