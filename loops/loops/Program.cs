using System;

namespace loops;

class Program
{
    //static void Main(string[] args)
    //{
    //    string input;
    //    int num = 0,sum = 0;
    //    while (num != -1)
    //    {
    //        sum += num;
    //        Console.Write("Enter Number: ");
    //        input = Console.ReadLine();
    //        num = int.Parse(input);
    //    }
    //    Console.WriteLine("Sum is {0}", sum);
    //    Console.ReadKey();
    //}
    static void Main(string[] args)
    {
        int[] numbers = new int[3];
        string input;
        for (int i = 0; i < numbers.Length; i++)
        {
            Console.Write("Enter no {0}{1}", i + 1,": ");
            numbers[i] = int.Parse(Console.ReadLine());
        }
        int largest = numbers[0];
        for (int i = 0; i < numbers.Length; i++)
        {
            if (numbers[i] > largest)
            {
                largest = numbers[i];
            }
        }
        Console.WriteLine("Largest is: {0}", largest);
        Console.ReadKey();
    }
}