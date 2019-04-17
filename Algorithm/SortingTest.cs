using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    public class SortingTest
    {
        public static void Main(string[] args)
        {
            List<ISortingAlgorithm> Algorithms = new List<ISortingAlgorithm>()
            {
                new SelectionSort(),
            };

            const int TEST_SIZE = 10000;
            foreach (var algorithm in Algorithms)
            {
                TestSortingAlgorithm(algorithm, TEST_SIZE);
            }
        }

        private static void TestSortingAlgorithm(ISortingAlgorithm algorithm, int maxArraySize)
        {
            Stopwatch stopwatch = new Stopwatch();

            for (int n = 10; n <= maxArraySize; n *= 10)
            {
                int[] array = GenerateRandomArray(n);

                stopwatch.Start();
                algorithm.Sort(array);
                stopwatch.Stop();

                Console.WriteLine(string.Format("'{0}', IsSorted: '{1}', ElapsedTime: '{2}', N: '{3}'", algorithm.GetType().Name, IsSorted(array), stopwatch.Elapsed, array.Length));
                stopwatch.Reset();
            }
        }

        private static int[] GenerateRandomArray(int arraySize)
        {
            int[] newArray = new int[arraySize];

            Random random = new Random();

            for (int index = 0; index < newArray.Length; index++)
            {
                newArray[index] = random.Next();
            }

            return newArray;
        }

        private static bool IsSorted(int[] array)
        {
            if (array.Length <= 1)
            {
                return true;
            }

            for (int index = 1; index < array.Length; index++)
            {
                if (array[index - 1] > array[index])
                {
                    return false;
                }
            }

            return true;
        }
    }
}
