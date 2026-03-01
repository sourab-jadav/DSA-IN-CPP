class Heap
{
    int heapsize;
    Heap(int n)
    {
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    void buildheap(int arr[], int i)
    {
        int largest = i;
        int l = this->left(i);
        int r = this->right(i);
        if (l < heapsize && arr[l] > arr[i])
        {
            largest = l;
        }
        if (r < heapsize && arr[r] > arr[i])
        {
            largest = r;
        }
        if (i != largest)
        {
            swap(arr[i], arr[largest]);
            buildheap(arr, largest);
        }
    }
    void buildmaxheap(int arr[], int n)
    {
        for (int i = (n >> 1) - 1; i >= 0; i--)
        {
            buildheap(arr, i);
        }
    }
}