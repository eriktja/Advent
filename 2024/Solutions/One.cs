public class One
{
    public static int Solution1(string[] data)
    {
        var list1 = new List<int>();
        var list2 = new List<int>();

        foreach (var row in data)
        {
            var numbers = row.Split("   ");
            list1.Add(int.Parse(numbers[0]));
            list2.Add(int.Parse(numbers[1]));
        }

        var sortedList1 = list1.Order().ToList();
        var sortedList2 = list2.Order().ToList();

        int diffSum = 0;

        for (int i = 0; i < list1.Count; i++)
        {
            diffSum += Math.Abs(sortedList1[i] - sortedList2[i]);
        }

        return diffSum;
    }

     public static int Solution2(string[] data)
    {
        var list1 = new List<int>();
        var list2 = new List<int>();

        foreach (var row in data)
        {
            var numbers = row.Split("   ");
            list1.Add(int.Parse(numbers[0]));
            list2.Add(int.Parse(numbers[1]));
        }

        var dict = new Dictionary<int, int>();

        int diffSum = 0;

        foreach (var num in list2)
        {
            if (!dict.ContainsKey(num))
            {
                dict.Add(num, 1);
            }
            else
            {
                dict[num]++;
            }
        }

        foreach (var num in list1)
        {
            if (dict.ContainsKey(num))
            {
                diffSum += num * dict[num];
            }
        }

        return diffSum;
    }

}