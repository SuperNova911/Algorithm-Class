using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    public class QuickSort : ISortingAlgorithm
    {
        public void Sort(int[] array)
        {
            if (array.Length < 1)
            {
                return;
            }

            Sort(array, 0, array.Length - 1);
        }

        private void Sort(int[] array, int first, int last)
        {
            if (first >= last)
            {
                return;
            }

            int pivot = Partition(array, first, last);
            Sort(array, first, pivot - 1);
            Sort(array, pivot + 1, last);
        }

        private int Partition(int[] array, int first, int last)
        {
            int i = first - 1;

            for (int j = first; j < last; j++)
            {
                if (array[j] <= array[last])
                {
                    Swap(array, ++i, j);
                }
            }

            Swap(array, i + 1, last);
            return i + 1;
        }

        private void Swap(int[] array, int x, int y)
        {
            int temp = array[x];
            array[x] = array[y];
            array[y] = temp;
        }
    }
}
