public class Four
{
    public static int Solution1(string[] stringArray)
    {
        var result = 0;
        var maxX = stringArray[0].Length - 2;   //One extra because of \n ?
        var maxY = stringArray.Length - 1;

        for (var x = 0; x <= maxX; x++)
        {
            for (var y = 0; y <= maxY; y++)
            {
                if (stringArray[y][x] == 'X')
                {
                    if (CheckNorth(stringArray, x, y))
                        result++;
                    if (CheckNorthEast(stringArray, x, y, maxX))
                        result++;
                    if (CheckEast(stringArray, x, y, maxX))
                        result++;
                    if (CheckSouthEast(stringArray, x, y, maxX, maxY))
                        result++;
                    if (CheckSouth(stringArray, x, y, maxY))
                        result++;
                    if (CheckSouthWest(stringArray, x, y, maxY))
                        result++;
                    if (CheckWest(stringArray, x, y))
                        result++;
                    if (CheckNorthWest(stringArray, x, y))
                        result++;
                }
            }
        }

        return result;
    }

    public static int Solution2(string[] stringArray)
    {
        var result = 0;
        var maxX = stringArray[0].Length - 2;   //One extra because of \n ?
        var maxY = stringArray.Length - 1;

        for (var x = 1; x < maxX; x++)
        {
            for (var y = 1; y < maxY; y++)
            {
                if (stringArray[y][x] == 'A' &&
                    ((stringArray[y - 1][x - 1] == 'M' && stringArray[y + 1][x + 1] == 'S') ||
                     (stringArray[y - 1][x - 1] == 'S' && stringArray[y + 1][x + 1] == 'M')) &&
                    ((stringArray[y - 1][x + 1] == 'M' && stringArray[y + 1][x - 1] == 'S') ||
                     (stringArray[y - 1][x + 1] == 'S' && stringArray[y + 1][x - 1] == 'M')))
                {
                    result++;
                }
            }
        }

        return result;
    }

    private static bool CheckNorth(string[] stringArray, int x, int y)
    {
        return y >= 3 &&
               stringArray[y - 1][x] == 'M' && stringArray[y - 2][x] == 'A' && stringArray[y - 3][x] == 'S';
    }

    private static bool CheckNorthEast(string[] stringArray, int x, int y, int maxX)
    {
        return x + 3 <= maxX && y >= 3 &&
               stringArray[y - 1][x + 1] == 'M' && stringArray[y - 2][x + 2] == 'A' && stringArray[y - 3][x + 3] == 'S';
    }

    private static bool CheckEast(string[] stringArray, int x, int y, int maxX)
    {
        return x + 3 <= maxX &&
               stringArray[y][x + 1] == 'M' && stringArray[y][x + 2] == 'A' && stringArray[y][x + 3] == 'S';
    }

    private static bool CheckSouthEast(string[] stringArray, int x, int y, int maxX, int maxY)
    {
        return x + 3 <= maxX && y + 3 <= maxY &&
               stringArray[y + 1][x + 1] == 'M' && stringArray[y + 2][x + 2] == 'A' && stringArray[y + 3][x + 3] == 'S';
    }

    private static bool CheckSouth(string[] stringArray, int x, int y, int maxY)
    {
        return y + 3 <= maxY &&
               stringArray[y + 1][x] == 'M' && stringArray[y + 2][x] == 'A' && stringArray[y + 3][x] == 'S';
    }

    private static bool CheckSouthWest(string[] stringArray, int x, int y, int maxY)
    {
        return x >= 3 && y + 3 <= maxY &&
               stringArray[y + 1][x - 1] == 'M' && stringArray[y + 2][x - 2] == 'A' && stringArray[y + 3][x - 3] == 'S';
    }

    private static bool CheckWest(string[] stringArray, int x, int y)
    {
        return x >= 3 &&
               stringArray[y][x - 1] == 'M' && stringArray[y][x - 2] == 'A' && stringArray[y][x - 3] == 'S';
    }

    private static bool CheckNorthWest(string[] stringArray, int x, int y)
    {
        return x >= 3 && y >= 3 &&
               stringArray[y - 1][x - 1] == 'M' && stringArray[y - 2][x - 2] == 'A' && stringArray[y - 3][x - 3] == 'S';
    }
}