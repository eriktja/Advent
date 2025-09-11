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

            if (IsSafe2(numbers)) result++;
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
    private static bool IsSafe2(List<int> numbers, bool retry = true)
    {
        bool increasing = false;
        bool decreasing = false;
        for (int i = 0; i < numbers.Count - 1; i++)
        {
            var diff = numbers[i] - numbers[i + 1];

            if (diff == 0) return HandleFalse(numbers, i, retry);

            if (diff > 0) increasing = true;
            else decreasing = true;

            if (increasing && decreasing) return HandleFalse(numbers, i, retry);

            var absDiff = Math.Abs(diff);
            if (absDiff < MinRange || absDiff > MaxRange)
            {
                return HandleFalse(numbers, i, retry);
            }
        }

        return true;
    }

    private static bool HandleFalse(List<int> numbers, int index, bool retry)
    {
        if (!retry) return false;

        var copy = numbers.ToList();

        Console.WriteLine($"Retry 1 on {string.Join(" ", numbers)} by removing {numbers[index+1]} at {index+1}");
        numbers.RemoveAt(index + 1);
        if (IsSafe2(numbers, false)) return true;

        Console.WriteLine($"Retry 2 on {string.Join(" ", copy)} by removing {copy[index]} at {index}");
        copy.RemoveAt(index);
        var result = IsSafe2(copy, false);
        Console.WriteLine(result);
        return result;
    }
}