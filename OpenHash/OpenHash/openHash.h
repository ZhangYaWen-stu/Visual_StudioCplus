//
// Created by zhouhan on 2023/5/13.
//
#include "Node.h"
#include "Assistance.h"

#ifndef INC_14_OPENHASH_OPENHASH_H
#define INC_14_OPENHASH_OPENHASH_H

template<typename Key>
class OpenHash{
private:
    Node<Key>** posi; //散列表中的元素节点
    int elem_num;         //散列表总共有多少个数据元素
    int divide;

    int Hash(Key key);    //自定义哈希函数
public:
    OpenHash(Key key[], int elem_num, int divi);
    void Insert_key(Key key);
    bool Delete_key(Key key);
    void show_hash();
    bool Is_empty(Node<Key>* node);
};

template<typename Key>
OpenHash<Key>::OpenHash(Key key[], int elem_num_, int divi) {
    int position;
    elem_num = elem_num_;
    posi = new Node<Key>*[divi];
    Node<Key>* hash_node;
    divide = divi;
    for(int j = 0; j < divi; j++)
    {
        posi[j] = nullptr;
    }
    for(int i = 0; i < elem_num; i++)
    {
        position = Hash(key[i]);
        hash_node = new Node<Key>(key[i]);
        hash_node->next = posi[position];
        posi[position] = hash_node;
    }
}

template<typename Key>
void OpenHash<Key>::Insert_key(Key key) {
    int position;
    posi = new Node<Key>*[divide];
    position = Hash(key);
    Node<Key>* hash_node;
    hash_node = new Node<Key>(key);
    hash_node->next = posi[position];
    posi[position] = hash_node;
}

template<typename Key>
bool OpenHash<Key>::Delete_key(Key key) {

    int position;
    position = Hash(key);
    if(Is_empty(posi[position]))
        return false;
    else
    {
        Node<Key>* p,q;
        p = posi[position];
        for(p = posi[position]; p->next!= nullptr;p = p->next)
        {
            if(p->next->data == key)
            {
                q = p->next;
                p->next = p->next->next;
                delete q;
                return true;
            }
            else
                return false;
        }
    }
}

template<typename Key>
bool OpenHash<Key>::Is_empty(Node<Key> *node) {

    if(!node)
        return true;
    else
        return false;
}

template<typename Key>
int OpenHash<Key>::Hash(Key key)
{
    return (key % elem_num >= 0) ? (key % elem_num) : (key % elem_num + elem_num);
}



template<typename Key>
void OpenHash<Key>::show_hash() {
    Node<Key>* p = nullptr;
    for(int i = 0; i < divide; i++) {
        if (!Is_empty(posi[i])) {
            for (p = posi[i]; p != nullptr; p = p->next) {
                cout << p->data;
                cout << " || ";
            }
        }
        else {
            cout << " |||||||||||| ";
        }
    }
}

#endif //INC_14_OPENHASH_OPENHASH_H
