#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>

template <class T>
class DLL {
public:
    // default constructor
    DLL();

    // destructor
    ~DLL();

    // copy constructor
    DLL(const DLL<T>& other);

    // assignment operator
    DLL<T>& operator=(const DLL<T> &source);

    // clear nodes
    void Clear();

    // pop and return the node at the front of the list
    T Pop();

    void PushFront(T data);

    // append to the back of the list
    void PushBack(T data);

    // is empty
    bool IsEmpty();

    // return size
    int Size();

    // peek the front of the list
    T Peek();

    // get an element with a 1-based index that is converted to a 0 base and return
    T GetAt(int index);

    // remove an element with a 1-based index that is converted to a 0 base and return
    T RemoveAt(int index);

    // display
    void Display();

private:
    struct Node {
        T m_data;
        Node* m_next;
        Node* m_prev;
        Node(T data) {
            m_data = data;
            m_next = nullptr;
            m_prev = nullptr;
        }
    };
    Node* m_head;
    Node* m_tail;
    int m_size;
};

////////////////////////////////////////
/////////// IMPLEMENTATIONS ////////////
////////////////////////////////////////

// default constructor
template <class T>
DLL<T>::DLL() {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

// destructor
template <class T>
DLL<T>::~DLL() {
    Clear();
}

// copy constructor
template <class T>
DLL<T>::DLL(const DLL<T>& other) {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;

    // copy nodes and push them back
    Node* curr = other.m_head;
    while(curr != nullptr) {
        PushBack(curr->m_data); // m_size++ by pushback
        curr = curr->m_next;
    }
}

// assignment operator
template <class T>
DLL<T>& DLL<T>::operator=(const DLL<T> &source) {
    if(this != &source) {
        Clear();
        // steal the guts
        DLL<T> temp = source;
        m_head = temp.m_head;
        m_tail = temp.m_tail;
        m_size = temp.m_size;

        // destruct the temp DLL
        temp.m_head = nullptr;
        temp.m_tail = nullptr;
    }
    return *this;
}

// clear
template <class T>
void DLL<T>::Clear() {
    while(m_head != nullptr) {
        Pop();
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

// pop the element from the front of the list and return
template <class T>
T DLL<T>::Pop() {
    if(IsEmpty()) {
        return T{};
    }

    Node* front = m_head;
    T frontData = m_head->m_data;
    m_head = m_head->m_next;
    
    delete front;
    front = nullptr;
    m_size--;

    return frontData;
}

template <class T>
void DLL<T>::PushFront(T data) {
    Node* newNode = new Node(data);
    newNode->m_next = m_head;
    if(IsEmpty()) {
        m_head = newNode;
        m_tail = newNode;
    } else {
        m_head->m_prev = newNode;
        m_head = newNode;
    }
    m_size++;
}

template <class T>
void DLL<T>::PushBack(T data) {
    Node* newNode = new Node(data);
    newNode->m_next = nullptr;

    // size 0 case
    if(IsEmpty()) {
        newNode->m_prev = nullptr;
        m_head = newNode;
        m_tail = newNode;
    // size 1+ case
    } else {
        newNode->m_prev = m_tail;
        m_tail->m_next = newNode;
        m_tail = newNode;
    }
    m_size++;
}

template <class T>
bool DLL<T>::IsEmpty() {
    if(m_head == nullptr) {
        return true;
    } else {
        return false;
    }
}

template <class T>
int DLL<T>::Size() {
    return m_size;
}

template <class T>
T DLL<T>::Peek() {
    if(IsEmpty()) {
        return T{};
    } else {
        return m_head->m_data;
    }
}

template <class T>
T DLL<T>::GetAt(int index) {
    index--; // converted to 0-base

    if(IsEmpty() || index < 0 || index >= m_size) {
        return T{};
    }

    int getIndex = 0;
    Node* curr = m_head;

    while(getIndex != index) {
        curr = curr->m_next;
        getIndex++;
    }
    return curr->m_data;
}

template <class T>
T DLL<T>::RemoveAt(int index) {
    index--; // convert to 0-base

    if(IsEmpty() || index < 0 || index >= m_size) {
        return T{};
    }
    int rmIndex = 0;
    Node* curr = m_head;

    while(rmIndex != index) {
        curr = curr->m_next;
        rmIndex++;
    }

    if(curr == m_head) {
        m_head = curr->m_next;
        if (m_head == nullptr) { // if empty
            m_tail = nullptr;
        } else {
            m_head->m_prev = nullptr;
        }
    } else if(curr == m_tail) {
        m_tail = curr->m_prev;
        if (m_tail == nullptr) { // if empty
            m_head = nullptr;
        } else {
            m_tail->m_next = nullptr;
        }
    } else { // general case
        curr->m_prev->m_next = curr->m_next;
        curr->m_next->m_prev = curr->m_prev;
    }

    T data = curr->m_data; // get data before deletion
    delete curr;
    curr = nullptr;
    m_size--;
    return data;
}

template <class T>
void DLL<T>::Display() {

    if(!IsEmpty()) {
        Node* curr = m_head;
        while(curr != nullptr) {
            std::cout << curr->m_data;
            curr = curr->m_next;
            if(curr != nullptr) {
                std::cout << "->";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "DLL is empty" << std::endl;
    }
}   

#endif