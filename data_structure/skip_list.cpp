//
// Created by zy_ on 24-3-18.
//
#include <iostream>
using namespace std;
// 构造跳表节点
const int DefaultSize = 100;  // 默认跳表节点的级点数组为100个元素
template <class E,class K>
struct SkipNode {
    E data;
    SkipNode<E,K> * *link;
    SkipNode(int size = DefaultSize) {
        link = new SkipNode<E, K> * [size];
        if (link = NULL) {
            cerr << "存储分配失败!" << endl;
        }
    }
    ~SkipNode() {delete [] link;}
};
// 构造跳表类
template <class E,class K>
class SkipList {
public:
    SkipList(K large,int maxLev = DefaultSize);
    ~SkipList();
    bool Search(const K k1,E & el) const;
    E & getData (SkipNode<E,K> * current){
        if(current != NULL) return &current->data;
        else return NULL;
    }
    bool Insert(const K k1,E & el);
    bool Remove(const K k1,E & el);
private:
    int maxLevel;
    int level;
    K TailKey;
    SkipNode<E,K> *head;
    SkipNode<E,K> *tail;
    SkipNode<E,K> * *last;
    int Level(); // 找到当前修改过之后的跳表的目前级数
    SkipNode<E,K> * SaveSearch(const K k1); // 保存查找路径的查找方法，返回的是目标元素的指针。

    template <class E,class K>
    SkipList <E,K> ::~SkipList() {
        SkipNode <E,K> * next;
        while (head != tail){
            next = head->link[0];
            delete head;
            head = next;
        }
        delete tail;
        delete [] last;
    }
    bool SkipList <E,K> ::Search(const K k1, E &el) const {}
    bool SkipList <E,K> ::SaveSearch(const K k1) {}
    bool SkipList <E,K> ::Insert(const K k1, E &el) {}
    bool SkipList <E,K> ::Remove(const K k1, E &el) {}
    int SkipList <E,K> ::Level() {}
};

// 编写初始化构造方法
// 编写查找、增加、删除节点
// 编写工具函数