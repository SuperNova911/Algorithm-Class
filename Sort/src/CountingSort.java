import java.util.ArrayList;

public class CountingSort
{
    public static ArrayList<Integer> Sort(ArrayList<Integer> list)
    {
        int min = list.get(0);
        int max = list.get(0);

        for (int index = 0; index < list.size(); index++)
        {
            if (min > list.get(index))
            {
                min = list.get(index);
            }
            if (max < list.get(index))
            {
                max = list.get(index);
            }
        }

        int k = max - min + 1;
        ArrayList<Integer> counter = new ArrayList<Integer>();
        for (int index = 0; index < k; index++)
        {
            counter.add(0);
        }

        int targetIndex;
        for (int value : list)
        {
            targetIndex = value - min;
            counter.set(targetIndex, counter.get(targetIndex) + 1);
        }

        for (int index = 1; index < k; index++)
        {
            counter.set(index, counter.get(index) + counter.get(index - 1));
        }

        for (int value : counter)
        {
            System.out.print(value + " ");
        }

        ArrayList<Integer> result = new ArrayList<Integer>();
        for (int index = 0; index < list.size(); index++)
        {
            result.add(0);
        }

        for (int index = list.size() - 1; index >=0; index--)
        {
            result.set(counter.get(list.get(index) - min) - 1, list.get(index));
            counter.set(list.get(index) - min, counter.get(list.get(index) - min) - 1);
        }

        return result;
    }
}