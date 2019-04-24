using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    public class CountingSort : ISortingAlgorithm
    {
        public void Sort(int[] array)
        {
            if (array.Length < 1)
            {
                return;
            }

            int min = array[0];
            int max = array[0];

            foreach (int value in array)
            {
                if (value < min)
                {
                    min = value;
                    continue;
                }

                if (value > max)
                {
                    max = value;
                }
            }

            int tableSize = max - min + 1;

            int[] table = new int[tableSize];

            foreach (int value in array)
            {
                table[value - min]++;
            }

            for (int index = 1; index < tableSize; index++)
            {
                table[index] += table[index - 1];
            }

            int[] sortedArray = new int[array.Length];
            for (int index = array.Length - 1; index >= 0; index--)
            {
                sortedArray[table[array[index] - min] - 1] = array[index];
                table[array[index] - min]--;
            }

            sortedArray.CopyTo(array, 0);
        }
    }
}
