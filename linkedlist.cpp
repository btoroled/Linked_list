//
// Created by Benjamin Toro Leddihn on 7/04/26.
//

#include "linkedlist.h"
#include <iostream>


using namespace std;

template<typename T>
class LinkedList {
    private:
    struct Node {
        T value;
        Node *next;

        Node(const T& val): value(val), next(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    LinkedList(): head(nullptr), tail(nullptr){}

    bool empty() {
        if (head!= nullptr && head->next != nullptr)
            return true;
    }

    int size() {
        int count =0;
        while (head != nullptr) {
            count++;
        }
        return count;
    }

    void clear() {
        Node* temp;
        while (head != nullptr) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    Node reverse(Node* head) {
        Node* temp1;
        Node* temp2;

        if (head != nullptr) {
            temp1 = head->next;
            head->next = nullptr;
            while (temp1 != nullptr) {
                temp2 = temp1->next;
                temp1->next = head;
                head = temp1;
                temp1 = temp2;
            }
        }
        return head;
    }

    void pop_front(Node* head) {
        Node* temp;
        temp = head->next;
        delete head;
        head = temp;
    }

    void pop_back(Node* head) {
        while (head->next != nullptr) {
            head = head->next;
            delete head;
        }
    }




};
