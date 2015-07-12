// Just a quicksort test.
// RS11062015

#include <iostream>
#include <random>

using namespace std;

int pivot(int *, int, int);
int partition(int *, int, int);
void quicksort(int *, int, int);
void print_array(int *, int);
void swap(int *, int, int);

const int MAX_NUM = 10;

int main()
{
        int array [MAX_NUM];

        // Initialize array.
        for(int i = MAX_NUM - 1; i > -1; i--)
        {
                array[MAX_NUM - 1 - i] = i;
        }

        print_array(array, MAX_NUM);

        quicksort(array, 0, MAX_NUM - 1);

        //swap(array, 0, 9);
        //
        // print_array(array, MAX_NUM);
        //
        // swap(array, 1, 1);
        //
        // print_array(array, MAX_NUM);
        //
        // swap(array, 2, 3);
        //
        // print_array(array, MAX_NUM);
}

void quicksort(int *a, int lo, int hi)
{
        cout << "Sorting from index " << lo << " to " << hi << endl << endl;
        if(lo < hi)
        {
                int p = partition(a, lo, hi);
                quicksort(a, lo, p - 1);
                quicksort(a, p + 1, hi);
        }
}

int partition(int *a, int lo, int hi)
{
        int pivot_index = pivot(a, lo, hi);
        int pivot_val = a[pivot_index];

        cout << "Pivot value is: " << pivot_val << ", index: " << pivot_index;

        swap(a, pivot_index, hi);
        print_array(a, MAX_NUM);

        int store_index = lo;

        for(int i = lo; i < hi - 1; ++i)
        {
            cout << "i: " << i;

            if (a[i] < pivot_val)
            {
                swap(a, i, store_index);
                print_array(a, MAX_NUM);
                store_index++;
            }

            cout << endl;
        }

        swap(a, store_index, hi);

        print_array(a, MAX_NUM);

        return store_index;
}

int pivot(int *a, int lo, int hi)
{
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(lo, hi);

        return distr(eng);
}

void print_array(int *a, int len)
{
        cout << endl;

        for(int i = 0; i < len; ++i)
        {
                cout << a[i] << " ";
        }

        cout << endl;
}

void swap(int *a, int from_index, int to_index)
{
        int temp = a[to_index];
        cout << endl << "   swapping " << a[from_index] << " with " << a[to_index] << endl;
        a[to_index] = a[from_index];
        a[from_index] = temp;
}
