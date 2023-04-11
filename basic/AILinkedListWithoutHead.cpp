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
    ListNode* head;  // 头指针
public:
    LinkedList() {  // 构造函数，初始化头指针
        head = NULL;
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
        if (pos < 1) {
            cout << "插入位置不合法" << endl;
            return;
        }
        ListNode* p = head;
        int i = 1;
        while (p && i < pos - 1) {
            p = p->next;
            i++;
        }
        if (!p && i < pos - 1) {
            cout << "插入位置不合法" << endl;
            return;
        }
        ListNode* q = new ListNode(val);
        if (pos == 1) {  // 特殊处理在头部插入节点的情况
            q->next = head;
            head = q;
        } else {
            q->next = p->next;
            p->next = q;
        }
    }
    void remove(int pos) {  // 在任意位置删除节点
        if (!head || pos < 1) {
            cout << "删除位置不合法" << endl;
            return;
        }
        ListNode* p = head;
        if (pos == 1) {  // 特殊处理删除头节点的情况
            head = head->next;
            delete p;
            return;
        }
        int i = 1;
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
        ListNode* p = head;
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
// 单链表是由一系列节点构成的链式结构，每个节点包含两个成员：一个数据域和一个指针域。指针域指向链表中的下一个节点，而最后一个节点的指针域则指向NULL。

// 单链表可以分为带头节点的单链表和不带头节点的单链表。带头节点的单链表是在链表的头部添加一个特殊的节点，这个节点不包含任何数据，仅仅起到一个标记的作用。不带头节点的单链表则没有这个特殊节点。

// 带头节点的单链表的优点是可以避免在对链表进行插入和删除操作时，需要判断当前节点是否是头节点的情况，因为头节点的位置不会发生改变。另外，如果链表为空，头节点可以直接指向NULL，这样可以避免对空链表进行特殊处理。

// 不带头节点的单链表则需要特殊处理空链表的情况，同时在对链表进行插入和删除操作时，需要特别注意第一个节点的位置，因为它没有前驱节点。同时，如果需要对空链表进行插入操作，就需要创建一个新的节点，并将链表的头指针指向它。

// 总的来说，带头节点的单链表更为常见，因为它可以简化链表操作的实现，并且可以避免一些特殊情况的判断。