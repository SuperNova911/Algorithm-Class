import java.util.ArrayList;

public class BubbleSort
{
    public static int CompareCount;

    public static void Sort(ArrayList<Integer> list)
    {
        CompareCount = 0;

        for (int k = list.size() - 1; k >= 1; k--)
        {
            for (int i = 0; i < k; i++)
            {
                if (list.get(i) > list.get(i + 1))
                {
                    Swap(list, i, i + 1);
                    CompareCount++;
                }
            }
        }
    }

    private static void Swap(ArrayList<Integer> list, int indexX, int indexY)
    {
        int temp = list.get(indexX);
        list.set(indexX, list.get(indexY));
        list.set(indexY, temp);
    }
}