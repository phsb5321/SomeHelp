#include<iostream>

using namespace std;

void swap(int *x, int *y);

class MinHeap {
    int *harr;
    int capacity;
    int heap_size;
public:
    explicit MinHeap(int capacity);

    void MinHeapify(int);

    static int parent(int i) { return (i - 1) / 2; }

    static int left(int i) { return (2 * i + 1); }

    static int right(int i) { return (2 * i + 2); }

    int extractMin();

    void insertKey(int k);

    int getHeapSize() const;
};


MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}


void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin() {
    if (heap_size <= 0)
        return -1;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}


void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::getHeapSize() const {
    return heap_size;
}


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main() {
    string str_builder;
    int number_of_inputs;
    cin >> number_of_inputs;


    while (number_of_inputs != 0) {
        MinHeap storage(number_of_inputs);
        int sum;
        int cost = 0;

        for (int a = 0; a < number_of_inputs; a++) {
            int helper;
            scanf("%d", &helper);
            storage.insertKey(helper);
        }

        while (storage.getHeapSize() > 1) {
            sum = storage.extractMin();
            sum += storage.extractMin();
            cost += sum;
            storage.insertKey(sum);
        }
        str_builder += to_string(cost) + "\n";
        cin >> number_of_inputs;
    }
    cout << str_builder;
    return 0;
}

