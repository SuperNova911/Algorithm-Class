using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    public class HeapSort : ISortingAlgorithm
    {
        public void Sort(int[] array)
        {
            BuildHeap(array);

            for (int last = array.Length - 1; last >= 1; last--)
            {
                Swap(array, 0, last);
                Heapify(array, 0, last - 1);
            }
        }

        private void BuildHeap(int[] array)
        {
            for (int rootIndex = array.Length / 2 + 1; rootIndex >= 0; rootIndex--)
            {
                Heapify(array, rootIndex, array.Length - 1);
            }
        }

        private void Heapify(int[] array, int rootIndex, int lastIndex)
        {
            int leftChild = rootIndex * 2 + 1;
            int rightChild = rootIndex * 2 + 2;

            int small = rootIndex;
            
            if (rightChild <= lastIndex)
            {
                if (array[leftChild] <= array[rightChild])
                {
                    small = leftChild;
                }
                else
                {
                    small = rightChild;
                }
            }
            else if (leftChild <= lastIndex)
            {
                small = leftChild;
            }
            else
            {
                return;
            }

            if (array[small] < array[rootIndex])
            {
                Swap(array, small, rootIndex);
                Heapify(array, small, lastIndex);
            }
        }

        private void Swap(int[] array, int x, int y)
        {
            int temp = array[x];
            array[x] = array[y];
            array[y] = temp;
        }
    }
}
