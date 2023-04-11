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
    SinglyLinkedList(): head(nullptr), size(0) {
    }
    int get(int index) {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        SinglyLinkedListNode *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        SinglyLinkedListNode *temp = new SinglyLinkedListNode(val);
        temp->next = head;
        head = temp; 
        size++;
    }
    void addAtTail(int val) {
        SinglyLinkedListNode *temp = head;
        for (int i = 0; i < size-1; ++i)
        {
            temp = temp->next;
        }
        SinglyLinkedListNode *tail = new SinglyLinkedListNode(val);
        temp->next = tail;
        size++;
    }
    void addAtIndex(int index, int val) {
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
        SinglyLinkedListNode *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
    }
    SinglyLinkedListNode* head;
    unsigned int size;
};


int main()
{
    SinglyLinkedListNode a = SinglyLinkedListNode(10);
    cout << "Fight!!!" << endl;
    return 0;
}