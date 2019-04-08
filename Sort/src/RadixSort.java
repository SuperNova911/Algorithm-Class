import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class RadixSort
{
    public static void Sort(ArrayList<Integer> list, int k)
    {
        Queue<Integer>[] queue = new Queue[10];
        for (int index = 0; index < 10; index++)
        {
            queue[index] = new LinkedList<Integer>();
        }

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < list.size(); j++)
            {
                int d = Digit(list.get(j), i);
                queue[d].offer(list.get(j));
            }
            int p = 0;
            for (int j = 0; j <= 9; j++)
            {
                while (queue[j].isEmpty() == false)
                {
                    list.set(p++, queue[j].poll());
                }
            }

            if (i == k)
            {
                for (int val : list)
                {
                    System.out.print(val + " ");
                }
            }
        }
    }

    private static int Digit(int value, int i)
    {
        return (int)(value / Math.pow(10, i - 1) % 10);
    }
}