using System.IO;

string filePath = "./Data/4.txt";

try
{
    string fileContent = File.ReadAllText(filePath);
    var stringArray = fileContent.Split("\n");

    var result = Four.Solution1(stringArray);

    Console.WriteLine(result);
}
catch (IOException e)
{
    Console.WriteLine($"Error reading file: {e.Message}");
}