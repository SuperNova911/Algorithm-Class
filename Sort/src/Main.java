import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main
{
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
    }
}