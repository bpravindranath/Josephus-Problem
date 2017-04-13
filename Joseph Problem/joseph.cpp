///************************************************************************
//COSC 501                                      Programming Assignment 4
//Barnabas Ravindranath                                 12/6/16
//Program Name:  MAZE
// 
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
using namespace std;

struct Soldier {
    string name;
    int num;
};

struct QueueNode {
    Soldier data;
    QueueNode *link;
};
typedef QueueNode* queueptr;

class Queue {
public:
    Queue();
    void add(Soldier soldier);
    void add(string name, int num);
    Soldier remove();
    bool empty() const;

private:
    queueptr front;
    queueptr back;

};

int main() {
    Queue joseph;
    queueptr temp;
    Soldier soldier;
    int num, num_1, x = 0;
    string name;



    cout << "How Many Soldierds: ";
    cin >> num;


    cout << "Type in " << num << " Soldier's Name: ";
    while (x < num) {
        cin >> soldier.name;
        soldier.num = (x + 1);
        joseph.add(soldier.name, soldier.num);
        
        x++;
    }
    cout << "Enter the Position: ";
    cin >> num_1;
    int count = 1, p_count = 0;

    
    while (!joseph.empty()) {
       
            if (count % num_1 == 0) {
                if (p_count == (num - 1)){
                    soldier = joseph.remove();
                    cout << "The Survivor is: ";
                    cout << soldier.name << "(" << soldier.num << ")" << endl;
                    break;
                }
                soldier = joseph.remove();
                cout << soldier.name << "(" << soldier.num << ")" << endl;
                p_count++;
                
            } else {
                joseph.add(joseph.remove());

            }

            count++;
        }
    



    return 0;
}

Queue::Queue() : front(NULL), back(NULL) {

}

bool Queue::empty() const {
    return (back == NULL);
}

Soldier Queue::remove() {
    if (empty()) {
        cout << "Error: Removing an Item from an Empty Queue" << endl;
        exit(1);
    }
    Soldier result = front->data;

    queueptr discard;
    discard = front;
    front = front->link;
    if (front == NULL) back = NULL;
    delete discard;
    return result;

}

void Queue::add(Soldier soldier) {
    if (empty()) {
        front = new QueueNode;
        front->data = soldier;
        front->link = NULL;
        back = front;
    } else {
        queueptr temp;
        temp = new QueueNode;
        temp->data = soldier;
        temp->link = NULL;
        back->link = temp;
        back = temp;
    }
}

void Queue::add(string name, int num) {
    Soldier item = {name, num};
    if (empty()) {
        front = new QueueNode;
        front->data = item;
        front->link = NULL;
        back = front;
    } else {
        queueptr temp;
        temp = new QueueNode;
        temp->data = item;
        temp->link = NULL;
        back->link = temp;
        back = temp;
    }
}

