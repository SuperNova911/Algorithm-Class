using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    public class BubbleSort : ISortingAlgorithm
    {
        public void Sort(int[] array)
        {
            if (array.Length < 1)
            {
                return;
            }

            for (int last = array.Length - 1; last >= 2; last--)
            {
                bool isSorted = true;

                for (int index = 1; index <= last; index++)
                {
                    if (array[index - 1] > array[index])
                    {
                        Swap(array, index - 1, index);
                        isSorted = false;
                    }
                }

                if (isSorted == true)
                {
                    return;
                }
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
