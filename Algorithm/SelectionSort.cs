using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    public class SelectionSort : ISortingAlgorithm
    {
        public void Sort(int[] array)
        {
            for (int last = array.Length - 1; last > 0; last--)
            {
                int largestIndex = FindLargestIndex(array, last);

                if (largestIndex != last)
                {
                    Swap(array, largestIndex, last);
                }
            }
        }

        private int FindLargestIndex(int[] array, int range)
        {
            int largestIndex = 0;

            for (int index = 1; index <= range; index++)
            {
                if (array[index] > array[largestIndex])
                {
                    largestIndex = index;
                }
            }

            return largestIndex;
        }

        private void Swap(int[] array, int x, int y)
        {
            int temp = array[x];
            array[x] = array[y];
            array[y] = temp;
        }
    }
}
