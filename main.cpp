//
//  main.cpp
//  zestaw2
//
//  Created by Alexey Valevich on 11/03/2021.
//

#include <iostream>

using namespace std;
struct Node {
    int name;
    Node* next = NULL;
};
struct List {
    Node* head = NULL;
    int size = 0;
    void add(int Name);
    int* toArray();
    int length();
    bool contain(int Name);
    bool remove(int Name);
    void removeAll(int Name);
    bool isEmpty();
    void clear();
    int indexOf(int Name);
    void add(int Name, int ind);
    void removeRep();
    void reverse();
};

void List::removeRep() {
    Node* ptr1 = head;
    Node* ptr2;
    while(ptr1) {
        ptr2 = ptr1;
        while(ptr2->next) {
            if(ptr2->next->name == ptr1->name) {
                Node* temp = ptr2->next;
                delete temp;
                size--;
                ptr2->next = ptr2->next->next;
            }else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int List::indexOf(int Name) {
    Node* temp = head;
    int index = 0;
    bool isFound = false;
    while(temp) {
        if(temp->name == Name) {
            isFound = true;
            break;
        }
        index++;
        temp = temp->next;
    }
    if(isFound)
        return index;
    else
        return -1;
}

void List::clear() {
    Node* temp = head;
    Node* element;
    size = 0;
    while(temp) {
        element = temp->next;
        delete temp;
        temp = element;
    }
    head = NULL;
}

int List::length() {
    return size;
}

bool List::isEmpty() {
    return size == 0;
}

bool List::remove(int Name) {
    if(isEmpty()) {
        return false;
    }
    
    Node* temp = head;
    bool isFound = false;
    if(temp->name == Name) {
        head = temp->next;
        delete temp;
        size--;
        return true;
    }
    
    while(temp) {
        if(temp->next != NULL && temp->next->name == Name) {
            isFound = true;
            break;
        }
        temp = temp->next;
    }
    
    if(isFound) {
        Node* element = temp->next;
        temp->next = temp->next->next;
        delete element;
        size--;
        return isFound;
    }else {
        return isFound;
    }
}

void List::removeAll(int Name) {
    while(remove(Name)) {
        
    }
}


bool List::contain(int Name) {
    Node* temp = head;
    bool isFound = false;
    while(temp) {
        if(temp->name == Name) {
            isFound = true;
        }
        temp = temp->next;
    }
    return isFound;
}

void List::add(int Name, int ind) {
    if(ind < 0 || ind > size) {
        return;
    }
    Node* temp = head;
    if(ind == 0) {
        Node* element = head;
        head = new Node;
        head->name = Name;
        head->next = element;
        size++;
    }else{
        int currIndex = 0;
        while(temp) {
            if(currIndex == ind - 1) {
                Node* element = temp->next;
                temp->next = new Node;
                temp->next->name = Name;
                temp->next->next = element;
                size++;
                break;
            }
            currIndex++;
            temp = temp->next;
        }
    }
}

void List::add(int Name) {
    add(Name, length());
}

int* List::toArray() {
    int* result = new int[size];
    Node* temp = head;
    int iter = 0;
    while(temp) {
        *(result + iter) = temp->name;
        iter++;
        temp = temp->next;
    }
    return result;
}

void List::reverse() {
    Node* NEXT = NULL;
    Node* CURR = head;
    Node* PREV = NULL;
    while(CURR) {
        NEXT = CURR->next;
        CURR->next = PREV;
        PREV = CURR;
        CURR = NEXT;
    }
    head = PREV;
}



int main(int argc, const char * argv[]) {
    List list;
    
    list.add(1);
    list.add(2);
    list.add(1);
    list.add(5);
    list.add(5);
    
//    cout << list.contain(1) << endl;
//    cout << list.contain(5) << endl;
//    cout << list.contain(6) << endl;
    
//    list.removeAll(1);
    
//    list.remove(1);
    
//    list.clear();
    
//    cout << list.indexOf(4) << endl;
    
//    list.add(10, 0);
    
//    list.removeRep();
    
//    list.reverse();
    
    int* arr = list.toArray();
    for(int i = 0; i < list.length(); i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
