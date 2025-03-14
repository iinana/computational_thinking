#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int d, Node* n) : data(d), next(n) {}
};

// Node* partition(Node* head, int x) {
//     Node* before_head = new Node(-1, nullptr);
//     Node* after_head = new Node(-1, nullptr);

//     Node* before = before_head;
//     Node* after = after_head;

//     Node* curr = head;
//     while (curr) {
//         if (curr->data < x) {
//             before->next = curr;
//             before = before->next;
//             while (before->next && before->next->data < x) {
//                 before = before->next;
//             }
//             curr = before->next;
//             before->next = nullptr;
//         } else {
//             after->next = curr;
//             after = after->next;
//             while (after->next && after->next->data > x) {
//                 after = after->next;
//             }
//             curr = after->next;
//             after->next = nullptr;
//         }
//     }

//     before->next = after_head->next;
//     return before_head->next;
// }

Node* partition(Node* head, int x) {
    Node* curr = head;
    Node* left = nullptr;
    Node* mid = nullptr;
    Node* right = nullptr;

    while (curr) {
        if (curr->data < x) {
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

Node* lst_to_linked(vector<int> lst) {
    Node *out = new Node(lst[0], nullptr);
    Node *point = out;

    for (int i = 1; i < lst.size(); i++) {
        point->next = new Node(lst[i], nullptr);
        point = point->next;
    }

    return out;
}

void print_linked(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> lst = {3, 5, 8, 5, 10, 2, 1};
    Node* head = lst_to_linked(lst);
    Node* res = partition(head, 5);
    print_linked(res);
}