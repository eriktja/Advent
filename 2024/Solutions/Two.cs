public class Two
{
    public static int Solution(string[] data)
    {
        int result = 0;

        foreach (var row in data)
        {
            var numbers = new List<int>();

            var strings = row.Split(" ");
            foreach (var num in strings)
            {
                numbers.Add(int.Parse(num));
            }

            if (IsSafe1(numbers)) result++;
            else
            {
                for (int i = 0; i < numbers.Count; i++)
                {
                    var copy = numbers.ToList();
                    copy.RemoveAt(i);
                    if (IsSafe1(copy))
                    {
                        result++;
                        break;
                    }
                }
            }
        }
        return result;
    }

    public static int MinRange = 1;
    public static int MaxRange = 3;
    private static bool IsSafe1(List<int> numbers)
    {
        bool increasing = false;
        bool decreasing = false;

        for (int i = 0; i < numbers.Count - 1; i++)
        {
            var diff = numbers[i] - numbers[i + 1];

            if (diff == 0) return false;

            if (diff > 0) increasing = true;
            else decreasing = true;

            if (increasing && decreasing) return false;

            var absDiff = Math.Abs(diff);
            if (absDiff < MinRange || absDiff > MaxRange)
            {
                return false;
            }
        }

        return true;
    }
}