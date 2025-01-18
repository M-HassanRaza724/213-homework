using System;
using System.IO;

namespace function_and_file
{


    class Program
    {

        //static void Main(string[] args)
        //{
        //    string path = "F:\\CS\\2nd semester\\OOPL\\week1\\Functions\\file.txt";
        //    if (File.Exists(path))
        //    {
        //        StreamReader FileVariable = new StreamReader(path);
        //        string record;
        //        while ((record = FileVariable.ReadLine()) != null)
        //        {
        //            Console.WriteLine(record);
        //        }
        //        FileVariable.Close();
        //    }
        //    else
        //    {
        //        Console.WriteLine("NOt Exist");
        //    }
        //}
        static void Main(string[] args)
        {
            string path = "F:\\CS\\2nd semester\\OOPL\\week1\\Functions\\file.txt";
            StreamWriter File = new StreamWriter(path,true);
            File.WriteLine("Hello this is written by program");
            File.Flush();
            File.Close();
            Console.WriteLine("Done writing...!");
            Console.ReadKey;
        }
        
    }
}