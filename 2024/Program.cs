using System.IO;

string filePath = "./Data/4.txt";

try
{
    string fileContent = File.ReadAllText(filePath);
    var stringArray = fileContent.Split("\n");

    Console.WriteLine(Four.Solution1(stringArray));
    Console.WriteLine(Four.Solution2(stringArray));
}
catch (IOException e)
{
    Console.WriteLine($"Error reading file: {e.Message}");
}