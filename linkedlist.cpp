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
        Node* next;

        Node(const T& val) : value(val), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    T front(Node* head) {
        if (head == nullptr) return nullptr;
        return head->value;
    }

    T back(Node* head) {
        if (head==nullptr) return nullptr;

        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        return current->value;
    }

    void push_front(const T& value) {
        Node* insert = new Node(value);
        insert->next = head;
        head = insert;
    }

    void push_back(const T& value) {
        Node* insert = new Node(value);
        if (head == nullptr) {
            head = insert;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = insert;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
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

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    void pop_front() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;

        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }

        delete current;
        prev->next = nullptr;
    }

};