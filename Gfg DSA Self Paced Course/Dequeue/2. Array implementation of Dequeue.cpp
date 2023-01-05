//Major Functions of Dequeue are:
// 1. insertFront()
// 2. insertRear()
// 3. deleteFront()
// 4. deleteRear()
// 5. getFront()
// 6. getRear()
// 7. size()
// 8. isFull()
// 9. isEmpty()


struct Dequeue{
    int size, cap;
    int *arr;

    Dequeue(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];

    }

 bool isFull() { return (size == cap); }

 bool isEmpty() { return (size == 0); }

 void insertRear(int x)
 {
    if(isFull()) return;
    arr[size] = x;
    size++;
 }

 void deleteRear()
 {
    if(isEmpty()) return;
    size--;
 }

 int getRear()
 {
    if(isEmpty()) return -1;

    else return(size - 1);
 }

 void insertFront(int x)
 {
    if(isFull()) return;
    for(int i = size -1; i>=0; i--)
       arr[i+1] = arr[i];

    arr[0] = x;
    size++;
 }

void deleteFront(){

    if(isEmpty()) return;

    for(int i=0; i<size-1; i++)
      arr[i] = arr[i+1];

    size--;  
}

int getFront(){

    if(isEmpty()) return -1;
    else
    return 0;
}






};