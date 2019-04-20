using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    public class MergeSort : ISortingAlgorithm
    {
        public void Sort(int[] array)
        {
            Sort(array, 0, array.Length - 1);
        }

        private void Sort(int[] array, int first, int last)
        {
            if (first >= last)
            {
                return;
            }

            int mid = (first + last) / 2;

            Sort(array, first, mid);
            Sort(array, mid + 1, last);
            Merge(array, first, mid, last);
        }

        private void Merge(int[] array, int first, int mid, int last)
        {
            int[] sortedArray = new int[last - first + 1];
            int sortedArrayIndex = 0;

            int i = first;
            int j = mid + 1;

            while (i <= mid && j <= last)
            {
                if (array[i] <= array[j])
                {
                    sortedArray[sortedArrayIndex++] = array[i++];
                }
                else
                {
                    sortedArray[sortedArrayIndex++] = array[j++];
                }
            }

            while (i <= mid)
            {
                sortedArray[sortedArrayIndex++] = array[i++];
            }

            while (j <= last)
            {
                sortedArray[sortedArrayIndex++] = array[j++];
            }

            sortedArrayIndex = 0;
            i = first;
            while (i <= last)
            {
                array[i++] = sortedArray[sortedArrayIndex++];
            }
        }
    }
}
