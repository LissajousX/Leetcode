#include <iostream>

using namespace std;

// 定义单链表节点的结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 定义单链表类
class LinkedList {
private:
    ListNode* head;  // 头节点指针
public:
    LinkedList() {  // 构造函数，初始化头节点
        head = new ListNode(0);
    }
    ~LinkedList() {  // 析构函数，释放链表内存
        ListNode* p = head;
        while (p) {
            ListNode* q = p;
            p = p->next;
            delete q;
        }
    }
    void insert(int val, int pos) {  // 在任意位置插入节点
        ListNode* p = head;
        int i = 0;
        while (p && i < pos - 1) {
            p = p->next;
            i++;
        }
        if (!p || i > pos - 1) {
            cout << "插入位置不合法" << endl;
            return;
        }
        ListNode* q = new ListNode(val);
        q->next = p->next;
        p->next = q;
    }
    void remove(int pos) {  // 在任意位置删除节点
        ListNode* p = head;
        int i = 0;
        while (p && i < pos - 1) {
            p = p->next;
            i++;
        }
        if (!p || !p->next || i > pos - 1) {
            cout << "删除位置不合法" << endl;
            return;
        }
        ListNode* q = p->next;
        p->next = q->next;
        delete q;
    }
    void printList() {  // 打印链表
        ListNode* p = head->next;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1, 1);
    list.insert(2, 2);
    list.insert(3, 3);
    list.insert(4, 4);
    list.printList();  // 输出 1 2 3 4
    list.remove(2);
    list.printList();  // 输出 1 3 4
    return 0;
}
