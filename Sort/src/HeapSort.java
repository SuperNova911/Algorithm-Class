import java.util.ArrayList;

public class HeapSort
{
    private static boolean BuildingHeap = false;
    public static int SwapCount;

    public static void Sort(ArrayList<Integer> list)
    {
        BuildingHeap = true;
        BuildHeap(list, list.size());
        BuildingHeap = false;

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
            if (list.get(left) <= list.get(right))
            {
                p = right;
            }
            else
            {
                p = left;
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

        if (list.get(p) > list.get(i))
        {
            Swap(list, p, i);
            if (BuildingHeap == false)
            {
                SwapCount++;
            }

            Heapify(list, p, n);
        }
    }

    private static void Swap(ArrayList<Integer> list, int indexX, int indexY)
    {
        int temp = list.get(indexX);
        list.set(indexX, list.get(indexY));
        list.set(indexY, temp);
    }
}