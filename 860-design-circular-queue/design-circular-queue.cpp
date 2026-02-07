#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;  // storage for the queue
    int head;          // index of the front element
    int tail;          // index of the next insertion
    int size;          // current number of elements
    int capacity;      // maximum number of elements

public:
    // Constructor: initialize the queue with capacity k
    MyCircularQueue(int k) {
        capacity = k;
        data.resize(k);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    // Insert an element into the queue
    bool enQueue(int value) {
        if (isFull()) return false;      // cannot insert if full
        data[tail] = value;
        tail = (tail + 1) % capacity;   // wrap around
        size++;
        return true;
    }
    
    // Delete an element from the queue
    bool deQueue() {
        if (isEmpty()) return false;     // cannot remove if empty
        head = (head + 1) % capacity;   // wrap around
        size--;
        return true;
    }
    
    // Get the front element
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    // Get the last element
    int Rear() {
        if (isEmpty()) return -1;
        return data[(tail - 1 + capacity) % capacity];
    }
    
    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }
    
    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }
};
