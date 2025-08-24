#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * next;

};

Node * createNode(int val){
    Node * newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int val) {
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
}

void insertAtPosition(Node* &head, int val, int pos) {
    Node* newNode = new Node();
    newNode->data = val;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

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
    temp->next = newNode;

}

void printNodeList(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void searchNode(Node * head, int val){
    Node * temp = head;
    int pos = 1;
    while(temp != NULL){
        if(temp->data == val){
            cout<<"Data found at position "<<pos<<endl;
            break;
        }
        pos++;
        temp= temp->next;
    }
    if(temp == NULL){
        cout<<"Data not Found."<<endl;
    }

}



void removeNode(Node * &head, int val){
    if(head == NULL){
        return;
    }
    if(head->data == val){
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node * prev;
    Node * curr;
    prev = head;
    curr = head->next;
    while(curr != NULL && curr->data != val){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        cout<<"Data is not Found."<<endl;

    }
    prev->next = curr->next;
    delete curr;
}



int main(){
    Node * head = NULL;
    int n, val;
    cout<<"Enter the size: ";
    cin>>n;
    for(int i = 1; i<=n; i++){
        cout<<"Enter the "<<i<<"th Value: ";
        cin>>val;
        insertAtEnd(head, val);
    }
    cout<<"Initial List: ";
    printNodeList(head);
    cout<<endl;

    int delval;
    cout<<"Data To be removed : ";
    cin>>delval;
    removeNode(head, delval);
    cout<<"After Delete List: ";
    printNodeList(head);
    cout<<endl;


    int s_data;
    cout<<"Data to be Search: ";
    cin>>s_data;
    searchNode(head, s_data);

    cout << "Insert value at beginning: ";
    cin >> val;
    insertAtBeginning(head, val);
    cout << "After inserting at beginning: ";
    printNodeList(head);
    cout<<endl;

    int pos;
    cout << "Insert value and position: ";
    cin >> val >> pos;
    insertAtPosition(head, val, pos);

    cout << "After inserting at position " << pos << ": ";
    printNodeList(head);

    cout<<endl;


    return 0;
}
