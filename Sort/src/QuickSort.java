import java.util.ArrayList;

public class QuickSort
{
    public static int SwapCount;

    public static void Sort(ArrayList<Integer> list, int p, int r)
    {
        if (p < r)
        {
            int q = Partition(list, p, r);
            Sort(list, p, q - 1);
            Sort(list, q + 1, r);
        }
    }

    private static int Partition(ArrayList<Integer> list, int p, int r)
    {
        int x = list.get(r);
        int i = p - 1;
        for (int j = p; j < r; j++)
        {
            if (list.get(j) <= x)
            {
                Swap(list, ++i, j);
            }
        }
        Swap(list, i + 1, r);
        return i + 1;
    }

    private static void Swap(ArrayList<Integer> list, int indexX, int indexY)
    {
        int temp = list.get(indexX);
        list.set(indexX, list.get(indexY));
        list.set(indexY, temp);
        SwapCount++;
    }
}