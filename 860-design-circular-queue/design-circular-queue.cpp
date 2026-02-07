#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int head, tail, size, capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        data.resize(k);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        // rear points to the next insertion index, so we take the previous index
        return data[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
