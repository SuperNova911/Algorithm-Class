import java.util.ArrayList;

public class InsertionSort
{
    public static int MoveCount;

    public static void Sort(ArrayList<Integer> list)
    {
        MoveCount = 0;

        for (int k = 1; k < list.size(); k++)
        {
            int temp = list.get(k);
            int index = k - 1;

            while (index >= 0 && list.get(index) > temp)
            {
                list.set(index + 1, list.get(index));
                index--;
                MoveCount++;
            }

            list.set(index + 1, temp);
            MoveCount++;
        }
    }
}