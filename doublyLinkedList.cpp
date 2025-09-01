#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Create a new node
Node* createNode(int val) {
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Insert at beginning
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = createNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at given position (1-based)
void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, val);
        return;
    }

    Node* newNode = createNode(val);
    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Print list forward
void printNodeList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print list backward (from tail)
void printReverse(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    cout << "List in reverse: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Search for a node
void searchNode(Node* head, int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Data found at position " << pos << endl;
            return;
        }
        pos++;
        temp = temp->next;
    }
    cout << "Data not Found." << endl;
}

// Remove a node with given value
void removeNode(Node*& head, int val) {
    if (head == NULL) return;

    Node* temp = head;

    // If node to delete is head
    if (temp->data == val) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data not Found." << endl;
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    delete temp;
}

int main() {
    Node* head = NULL;
    int n, val;
    cout << "Enter the size: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Enter the " << i << "th Value: ";
        cin >> val;
        insertAtEnd(head, val);
    }
    cout << "Initial List: ";
    printNodeList(head);

    int delval;
    cout << "Data To be removed : ";
    cin >> delval;
    removeNode(head, delval);
    cout << "After Delete List: ";
    printNodeList(head);

    int s_data;
    cout << "Data to be Search: ";
    cin >> s_data;
    searchNode(head, s_data);

    cout << "Insert value at beginning: ";
    cin >> val;
    insertAtBeginning(head, val);
    cout << "After inserting at beginning: ";
    printNodeList(head);

    int pos;
    cout << "Insert value and position: ";
    cin >> val >> pos;
    insertAtPosition(head, val, pos);

    cout << "After inserting at position " << pos << ": ";
    printNodeList(head);

    // Print reverse to check DLL prev links
    printReverse(head);

    return 0;
}
