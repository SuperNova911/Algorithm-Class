import java.util.ArrayList;

public class SelectionSort
{
    public static int CompareCount = 0;

    public static void Sort(ArrayList<Integer> list)
    {
        CompareCount = 0;

        int maxIndex, temp;

        for (int k = list.size() - 1; k > 0; k--)
        {
            maxIndex = 0;
            for (int index = 0; index <= k; index++)
            {
                if (list.get(maxIndex) < list.get(index))
                {
                    maxIndex = index;
                    CompareCount++;
                }
            }

            temp = list.get(k);
            list.set(k, list.get(maxIndex));
            list.set(maxIndex, temp);
        }
    }
}