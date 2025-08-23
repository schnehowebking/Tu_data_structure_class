#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * next;
};

Node *createNode(int val){
    Node * newnode = new Node();
    newnode ->data = val;
    newnode->next = NULL;
    return newnode;
}

void printList(Node * head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void searchNode(Node * head, int val){
    Node * temp = head;
    int pos = 1;
    while(temp != NULL){
        if(temp->data==val){
            cout<<"Data Found at position "<<pos<<endl;
            break;
        }
        pos++;
        temp = temp->next;

    }
    if(temp == NULL){
        cout<<"Data Not found."<<endl;

    }
}


void removeNode(Node *&head, int val){
    if(head == NULL){
        return;
    }
    if(head->data== val){
        Node * temp = head;
        head=head->next;
        delete temp;
        return;
    }
    Node *prev;
    Node *curr;
    prev = head;
    curr = head->next;
    while(curr != NULL && curr->data != val){
        prev = curr;
        curr = curr->next;
    }
    if(curr==NULL){
        cout<<"Data is Not Found."<<endl;
    }
    prev->next = curr->next;
    delete curr;

}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    cout<<"Enter the size : ";
        int n;
        cin>> n;
        int val;
        for(int i = 0; i<n; i++){
            cout<<"Enter the "<<i+1<<"th Value: ";
            cin >> val;
            Node * temp = createNode(val);
            if (head==NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
        }
        cout<<"Initial List: ";
        printList(head);
        cout<<endl;

        int delval;
        cout<<"Data To be removed : ";
        cin>>delval;
        removeNode(head, delval);

        cout<<"After Delete List: ";
        printList(head);
        cout<<endl;
        int s_data;
        cout<<"Data to be Search: ";
        cin>>s_data;

        searchNode(head, s_data);



    return 0;

}
