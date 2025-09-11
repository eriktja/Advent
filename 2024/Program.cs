using System.IO;

string filePath = "./Data/2.txt";

try
{
    string fileContent = File.ReadAllText(filePath);
    var stringArray = fileContent.Split("\n");

    var result = Two.Solution(stringArray);

    Console.WriteLine(result);
}
catch (IOException e)
{
    Console.WriteLine($"Error reading file: {e.Message}");
}