using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    public class InsertionSort : ISortingAlgorithm
    {
        public void Sort(int[] array)
        {
            if (array.Length < 1)
            {
                return;
            }

            for (int i = 1; i < array.Length; i++)
            {
                int newItem = array[i];
                int targetIndex = i - 1;

                while (targetIndex >= 1 && newItem < array[targetIndex])
                {
                    array[targetIndex + 1] = array[targetIndex];
                    targetIndex--;
                }

                array[targetIndex] = newItem;
            }
        }
    }
}
