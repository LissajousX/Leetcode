#include <iostream>
using namespace std;
struct SinglyLinkedListNode {
    int val;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode(): val(0), next(nullptr) {}
    SinglyLinkedListNode(int x): val(x), next(nullptr) {}
    SinglyLinkedListNode(int x, SinglyLinkedListNode *p): val(x), next(p) {}
};

struct SinglyLinkedList
{
    SinglyLinkedList() {
        head = new SinglyLinkedListNode();
        size = 0;
    }
    int get(int index) {
        if (index < 0 || index >= size)
        {
            cout << "Get Failed, Error Index"<<endl;
            return -1;
        }
        SinglyLinkedListNode *temp = head;
        for (int i = 0; i <= index; ++i)
        {
            temp = temp->next;
        }

        cout << "Get list["<< index << "] = " <<  temp->val <<endl;
        return temp->val;
    }

    void addAtHead(int val) {
        SinglyLinkedListNode *temp = new SinglyLinkedListNode(val);
        temp->next = head->next;
        head->next = temp;
        size++;
    }
    void addAtTail(int val) {
        SinglyLinkedListNode *temp = head;
        for (int i = 0; i < size; ++i)
        {
            temp = temp->next;
        }
        SinglyLinkedListNode *tail = new SinglyLinkedListNode(val);
        temp->next = tail;
        size++;
    }
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
        {
            cout << "Add Failed, Error Index"<<endl;
            return;
        }
        SinglyLinkedListNode *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        SinglyLinkedListNode *insert = new SinglyLinkedListNode(val);
        insert->next = temp->next;
        temp->next = insert;
        size++;
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
        {
            cout << "Del Failed, Error Index"<<endl;
            return;
        }
        SinglyLinkedListNode *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        SinglyLinkedListNode *cur = temp->next;
        temp->next = cur->next;
        delete cur;
        size--;
    }
    void printList() {
        SinglyLinkedListNode *temp = head->next;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
private:
    SinglyLinkedListNode* head;
    unsigned int size;
};


int main()
{
    SinglyLinkedList list;
    list.printList();      // --
    list.get(0);           // Get Failed, Error Index
    list.deleteAtIndex(0); // Del Failed, Error Index
    list.addAtHead(0);     //
    list.printList();      // 0
    list.deleteAtIndex(0); // 
    list.printList();      // --
    list.addAtTail(0);     //
    list.printList();      // 0
    list.get(0);           // Get list[0] = 0
    list.addAtIndex(1,3);  //
    list.printList();      // 0 3
    list.addAtIndex(1,1);  //
    list.printList();      // 0 1 3
    list.addAtIndex(2,2);  // 
    list.printList();      // 0 1 2 3
    list.addAtTail(4);     //
    list.printList();      // 0 1 2 3 4
    list.deleteAtIndex(0); // 
    list.printList();      // 1 2 3 4
    list.deleteAtIndex(1); // 
    list.printList();      // 1 3 4
    list.deleteAtIndex(2); // 
    list.printList();      // 1 3
    list.deleteAtIndex(2); // Del Failed, Error Index
    list.printList();      // 1 3
    list.addAtIndex(3, 3); // Add Failed, Error Index
    list.printList();      // 1 3
    return 0;
}