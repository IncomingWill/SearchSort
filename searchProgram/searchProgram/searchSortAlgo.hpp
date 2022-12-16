/*
Title: Chapter Eighteen Search Program -- Function Header File
Created by William Schaeffer
CPS 362
P. 1356, Challenge 4, Search Program, Week 11
04.07.2022
*/

#include <iostream>

using namespace std;

//Search Function Templates

template <class elemType>
int seqSearch(const elemType list[], int length, const elemType& item)
{
    int loc;
    bool found = false;

    loc = 0;

    while (loc < length && !found)
        if (list[loc] == item)
            found = true;
        else
            loc++;

    if (found)
        return loc;
    else
        return -1;
}


template <class elemType>
int binarySearch(elemType list[], int length, const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid;
    int comp = 0;                                           //for comparison, initialize at 1 for while comparison

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
        {
            comp++;                                         //1 comparison made
            found = true;

        }
        else if (list[mid] > item)
        {
            comp+=2;                                        //2 comparisons made
            last = mid - 1;
            int size = *(&list + 1) - list;                 //calculate size of array
            if (size < 15)
                mid = seqSearch(list, size, item);
        }
        else
        {
            first = mid + 1;
        }
    }

    cout << "Number of comparisons: " << comp 
         << endl << endl;

    if (found)
        return mid;
    else
        return -1;
}

//Sort Function Templates

template <class elemType>
void bubbleSort(elemType list[], int length)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
        {
            if (list[index] > list[index + 1])
            {
                elemType temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
}

template <class elemType>
void selectionSort(elemType list[], int length)
{
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
}

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last; loc++)
        if (list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
}

template <class elemType>
void insertionSort(elemType list[], int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length;
        firstOutOfOrder++)
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            elemType temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
}
/*
template <class elemType>
void quickSort(elemType list[], int length)
{
    int start = 0;
    recQuickSort(list, start, length - 1);
}

template <class elemType> void recQuickSort(elemType list[], int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        //cout << endl << "After first call to partition: ";
        //for (int i = length - 1; i >= 0; i--)
        //    cout << list[i] << ", ";
        //cout << endl;
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }
}

template <class elemType>
int partition(elemType list[], int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }

    swap(list, first, smallIndex);

    return smallIndex;
}
*/
template <class elemType>
void heapSort(elemType list[], int length)
{
    buildHeap(list, length);

    for (int lastOutOfOrder = length - 1; lastOutOfOrder >= 0;
        lastOutOfOrder--)
    {
        elemType temp = list[lastOutOfOrder];
        list[lastOutOfOrder] = list[0];
        list[0] = temp;
        heapify(list, 0, lastOutOfOrder - 1);
    }
}

template <class elemType>
void heapify(elemType list[], int low, int high)
{
    int largeIndex;

    elemType temp = list[low];                              //copy the root node of the subtree

    largeIndex = 2 * low + 1;                               //index of the left child

    while (largeIndex <= high)
    {
        if (largeIndex < high)
            if (list[largeIndex] < list[largeIndex + 1])
                largeIndex = largeIndex + 1;                //index of the largest child

        if (temp > list[largeIndex])                        //subtree is already in a heap
            break;
        else
        {
            list[low] = list[largeIndex];                   //move the larger child to the root
            low = largeIndex;                               //go to the subtree to restore the heap
            largeIndex = 2 * low + 1;
        }
    }

    list[low] = temp;                                       //insert temp into the tree, that is, list
}

template <class elemType>
void buildHeap(elemType list[], int length)
{
    for (int index = length / 2 - 1; index >= 0; index--)
        heapify(list, index, length - 1);
}