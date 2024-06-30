// link list project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    int arr[];
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* list_head;
    int max = -85;
    LinkedList() {
        list_head = nullptr;
    }

    bool empty() {
        return (list_head == nullptr);
    }
    void insert(int value) {
        Node* newNode = new Node(value);

        if (empty()) {
            list_head = newNode;
        }
        else {
            Node* temp = list_head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = list_head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int remove() {
        if (empty()) {
            return 0;
        }
        else {
            int e = list_head->data;
            Node* prev = list_head;
            list_head = list_head->next;
            delete prev;
            return e;
        }
    }
    void search_value(int values) {
        Node* temp = list_head;
        while (temp != nullptr) {
            if (temp->data == values) {
                cout << temp->data << " was in the link list ,  and " << temp->next << " is the addres" << endl;
            }
            temp = temp->next;
        }
    }
    int counters() {
        int counter = 0;
        Node* temp1 = list_head;

        while (temp1 != nullptr) {
            temp1 = temp1->next;
            counter++;
        }

        return counter;
    }
    int* createSortedArrayFromLinkedList() {
        int size = counters();
        int* arr = new int[size];
        Node* temp = list_head;
        int i = 0;
        while (temp != nullptr) {
            arr[i] = temp->data;
            temp = temp->next;
            i++;
        }

        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(arr[i], arr[minIndex]);
        }

        return arr;
    }

    void printSortedArray() {
        int size;
        int* sortedArr = createSortedArrayFromLinkedList();

        for (int i = 0; i < counters(); i++) {
            std::cout << sortedArr[i] << " ";
        }
        std::cout << std::endl;

        delete[] sortedArr;
    }
    void average() {
        int sum = 0;
        Node* temp = list_head;
        while (temp != nullptr) {
            sum += temp->data;
            temp = temp->next;
        }
        cout << (sum / counters());
    }
};
    
    int main() {
        LinkedList myLinkedList;
        myLinkedList.insert(50);
        myLinkedList.insert(10);
        myLinkedList.insert(30);
        myLinkedList.insert(20);
        myLinkedList.insert(5);
        cout << "the elements of link list are : ";
        myLinkedList.display();
        myLinkedList.createSortedArrayFromLinkedList();
        cout << "sorted link list : ";
        myLinkedList.printSortedArray();
        myLinkedList.search_value(10);
        myLinkedList.search_value(50);
        myLinkedList.remove();
        myLinkedList.remove();
        myLinkedList.display();
        cout << "the average of values of link list is : ";
        myLinkedList.average();
        return 0;

    }


