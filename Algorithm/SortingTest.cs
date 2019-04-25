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
        public enum SortingOrder { NotSorted, Ascending, Descending }

        public static void Main(string[] args)
        {
            List<ISortingAlgorithm> Algorithms = new List<ISortingAlgorithm>()
            {
                //new SelectionSort(),
                //new BubbleSort(),
                //new InsertionSort(),
                //new MergeSort(),
                //new QuickSort(),
                //new HeapSort(),
                //new RadixSort(),
                new CountingSort(),
            };

            const int TEST_SIZE = 10000;
            foreach (var algorithm in Algorithms)
            {
                TestSortingAlgorithm(algorithm, TEST_SIZE, 10);
            }

            Console.ReadKey();
        }

        private static void TestSortingAlgorithm(ISortingAlgorithm algorithm, int maxArraySize, int numberOfTest)
        {
            Stopwatch stopwatch = new Stopwatch();

            for (int arraySize = 10; arraySize <= maxArraySize; arraySize *= 10)
            {
                for (int n = 0; n <= numberOfTest; n++)
                {
                    int[] array = GenerateRandomArray(arraySize);

                    stopwatch.Start();
                    algorithm.Sort(array);
                    stopwatch.Stop();

                    Console.WriteLine(string.Format("'{0}', SortingBy: '{1}', ElapsedTime: '{2}', N: '{3}'", algorithm.GetType().Name, SortingBy(array), stopwatch.Elapsed, array.Length));
                    stopwatch.Reset();
                }
            }
        }

        private static int[] GenerateRandomArray(int arraySize)
        {
            int[] newArray = new int[arraySize];

            Random random = new Random();

            for (int index = 0; index < newArray.Length; index++)
            {
                newArray[index] = random.Next(10);
            }

            return newArray;
        }

        private static SortingOrder SortingBy(int[] array)
        {
            bool ascending = true;
            bool descending = true;

            if (array.Length <= 1)
            {
                return SortingOrder.NotSorted;
            }

            for (int index = 1; index < array.Length; index++)
            {
                if (array[index - 1] > array[index])
                {
                    ascending = false;
                    break;
                }
            }

            if (ascending == true)
            {
                return SortingOrder.Ascending;
            }

            for (int index = 1; index < array.Length; index++)
            {
                if (array[index - 1] < array[index])
                {
                    descending = false;
                    break;
                }
            }

            if (descending == true)
            {
                return SortingOrder.Descending;
            }

            return SortingOrder.NotSorted;
        }
    }
}
