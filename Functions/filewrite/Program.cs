using System;
using System.IO;

namespace filewrite
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = "F:\\CS\\2nd semester\\OOPL\\week1\\Functions\\file.txt";
            StreamWriter File = new StreamWriter(path, true);
            File.WriteLine("Hello this is written by program");
            File.Flush();
            File.Close();
            Console.WriteLine("Done writing...!");
            Console.ReadKey();
        }
    }
}
