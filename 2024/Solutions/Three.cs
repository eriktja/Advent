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
        .Aggregate((sum, x) => x);// .Select(x => int.Parse(x[0]) * int.Parse(x[1]));

        return result;
    }
}