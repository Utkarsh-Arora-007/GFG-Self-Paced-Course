#include<bits/stdc++.h>
using namespace std;

class MinHeap{

    int *arr;
    int size;
    int capacity;

    public:

    MinHeap(int c)
    {
        size = 0;
        capacity = c;
        arr = new int[c];
    }

    int left(int i) { return (2*i+1); }
    int right(int i) { return (2*i+2); }
    int parent(i) { return(i-1)/2; }

    void insert(int x)
    {
        if(size == capacity) return;
        size++;
        arr[size-1] = x;
        
        for(int i = size-1;  i!=0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void minHeapify(int i)
    {
        int lt = left(i);
        int rt = right(i);
        int smallest = i;
        if(lt < size && arr[lt] < arr[i])
            smallest = lt;
        if(rt < size && arr[rt] < arr[smallest])
            smallest = rt;

        if(smallest!=i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }        
    }

  //Bottom-most and right-most Internal Node
  //Use the normal class and then use minHeapify function and buildHeap function only in order to solve build heap problem specifically.
  //Works on the assumption that the lower levels must be already heapified.

   //Time complexity of Build heap seems to be O(nlogn) but after very careful and tight analysis we get to know that it is O(n)
   //because of the formula that the number of nodes at the specific level can be given be : Ceil (n/2^h+1) , where h is the level of the node starting from downwards as the starting level, the loweset level is marked as h=0, then going upwards the h increases accordingly.
   
  void buildHeap()
  {
    for(int i =(size-2)/2; i>=0; i--)
    {
        minHeapify(i);
    }
  }  


    int extractMin()
    {
        if(size <= 0)
        return INT_MAX;

        if(size == 1)
        {
            size--;
            minHeapify(0);
        }

        swap(arr[0],arr[size-1]);
        size--;
        minHeapify(0);

        return arr[size];
    }


    void decreaseKey(int i, int x)
    {
        arr[i] = x;
        while(i!=0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

int main()
{
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.deleteKey(0);
    h.insert(15);
    h.insert(20);

    cout<<h.extractMin()<<endl;
    h.decreaseKey(2,1);
    cout<<h.extractMin()<<endl;


    //for build heap problem

    MinHeap h(12);
    return 0;
}

