class MyCircularQueue {
    int front,rear,currsize,size;
    int *arr;
public:
    MyCircularQueue(int k) {
        size = k;
        currsize =0;
        front = rear =-1;
        arr = new int[size];        
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            front = rear =0;
        }else{
            rear =  (rear+1)%size;
        }
        arr[rear] = value;
        currsize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            front=rear=-1; // i.e query become empty
        }else{
            front = (front+1)%size;
        }

        currsize--;
        return true;

        
    }
    
    int Front() {
         return (isEmpty()? -1: arr[front]);        
    }
    
    int Rear() {
        return (isEmpty()? -1: arr[rear]);        
    }
    
    bool isEmpty() {
        return currsize == 0;
    }
    
    bool isFull() {
        return currsize == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */