using System.Text.RegularExpressions;

public class Three
{
    public static int Solution(string fileContent)
    {
        var matchCollection = Regex.Matches(fileContent, @"mul\([1-9]\d{0,2},[1-9]\d{0,2}\)");
        var result = matchCollection
        .Cast<Match>()
        .Select(x => x.Value)
        .Select(x => x[4..^1])
        .Select(x => x.Split(","))
        .Select(x => int.Parse(x[0]) * int.Parse(x[1]))
        .Aggregate((sum, x) => sum + x);// .Select(x => int.Parse(x[0]) * int.Parse(x[1]));

        return result;
    }

    public static int Solution2(string fileContent)
    {
        var matchCollection = Regex.Matches(fileContent, @"mul\([1-9]\d{0,2},[1-9]\d{0,2}\)|don't\(\)|do\(\)");

        var matches = matchCollection
        .Cast<Match>()
        .Select(x => x.Value).ToList();
        // .Select(x => x[4..^1])
        // .Select(x => x.Split(","))
        // .Select(x => int.Parse(x[0]) * int.Parse(x[1]))
        // .Aggregate((sum, x) => sum + x);// .Select(x => int.Parse(x[0]) * int.Parse(x[1]));

        int sum = 0;
        bool enabled = true;
        foreach (var a in matches)
        {
            if (a == "do()")
            {
                enabled = true;
            }
            else if (a == "don't()")
            {
                enabled = false;
            }
            else if (enabled)
            {
                var b = a[4..^1];
                var n = b.Split(",");
                sum += int.Parse(n[0]) * int.Parse(n[1]);
            }
        }

        return sum;
    }
}