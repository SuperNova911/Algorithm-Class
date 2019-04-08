import java.util.ArrayList;

public class MergeSort
{
    public static int CompareCount;

    public static void Sort(ArrayList<Integer> list, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            Sort(list, start, mid);
            Sort(list, mid + 1, end);
            Merge(list, start, mid, end);

        }
    }

    private static void Merge(ArrayList<Integer> list, int start, int mid, int end)
    {
        int i = start;
        int j = mid + 1;
        int t = 0;

        ArrayList<Integer> tempList = new ArrayList<Integer>();
        tempList.addAll(list);

        while (i <= mid && j <= end)
        {
            if (list.get(i) >= list.get(j))
            {
                tempList.set(t++, list.get(j++));
                CompareCount++;
            }
            else
            {
                tempList.set(t++, list.get(i++));
                CompareCount++;
            }
        }

        while (i <= mid)
        {
            tempList.set(t++, list.get(i++));
        }

        while (j <= end)
        {
            tempList.set(t++, list.get(j++));
        }

        i = start;
        t = 0;

        while (i <= end)
        {
            list.set(i++, tempList.get(t++));
        }
    }
}