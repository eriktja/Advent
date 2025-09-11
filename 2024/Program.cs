using System.IO;

string filePath = "./Data/1.txt";

try
{
    string fileContent = File.ReadAllText(filePath);
    var stringArray = fileContent.Split("\n");
    var answer1 = One.Solution1(stringArray);
    var answer2 = One.Solution2(stringArray);

    Console.WriteLine(answer1);
    Console.WriteLine(answer2);
}
catch (IOException e)
{
    Console.WriteLine($"Error reading file: {e.Message}");
}