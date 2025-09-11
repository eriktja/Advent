using System.IO;

string filePath = "./Data/3.txt";

try
{
    string fileContent = File.ReadAllText(filePath);
    // var stringArray = fileContent.Split("\n");

    var result = Three.Solution(fileContent);

    Console.WriteLine(result);
}
catch (IOException e)
{
    Console.WriteLine($"Error reading file: {e.Message}");
}