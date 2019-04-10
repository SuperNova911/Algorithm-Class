import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main
{
    public static class HeapSort
    {
        public static int SwapCount;

        public static void Sort(ArrayList<Integer> list)
        {
            BuildHeap(list, list.size());
            for (int index = list.size() - 1; index >= 1; index--)
            {
                Swap(list, 0, index);
                Heapify(list, 0, index);
            }
        }

        private static void BuildHeap(ArrayList<Integer> list, int n)
        {
            for (int index = n / 2; index >= 0; index--)
            {
                Heapify(list, index, n);
            }
        }

        private static void Heapify(ArrayList<Integer> list, int i, int n)
        {
            int p = i;
            int left = i * 2 + 1;
            int right = i * 2 + 2;

            if (right < n)
            {
                if (list.get(left) < list.get(right))
                {
                    p = left;
                }
                else
                {
                    p = right;
                }
            }
            else if (left < n)
            {
                p = left;
            }
            else
            {
                return;
            }

            if (list.get(p) < list.get(i))
            {
                Swap(list, p, i);
                SwapCount++;
                Heapify(list, p, n);
            }
//
//            if (left < n)
//            {
//                if (list.get(left) > list.get(i))
//                {
//                    p = left;
//                }
//                else
//                {
//                    p = i;
//                }
//            }
//            else
//            {
//                return;
//            }
//
//            if (right < n)
//            {
//                if (list.get(right) > list.get(p))
//                {
//                    p = right;
//                }
//            }
//
//            if (p != i)
//            {
//                Swap(list, p, i);
//                SwapCount++;
//                Heapify(list, p, n);
//            }
        }

        private static void Swap(ArrayList<Integer> list, int indexX, int indexY)
        {
            int temp = list.get(indexX);
            list.set(indexX, list.get(indexY));
            list.set(indexY, temp);
        }
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int index = 0; index < n; index++)
        {
            list.add(index, scanner.nextInt());
        }
        scanner.close();

        HeapSort.SwapCount = 0;
        HeapSort.Sort(list);
        System.out.println(HeapSort.SwapCount);

        for (int val : list)
        {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}