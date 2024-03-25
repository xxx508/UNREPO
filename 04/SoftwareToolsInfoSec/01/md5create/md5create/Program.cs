using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

class Program
{
    static void Main()
    {
        Console.WriteLine("Введите имя файла:");
        string fileName = Console.ReadLine();

        if (File.Exists(fileName))
        {

            byte[] hash = MD5.Create().ComputeHash(File.OpenRead(fileName));
            string hashString = BitConverter.ToString(hash).Replace("-", "").ToLower();
            Console.WriteLine($"MD5 хеш файла {fileName}: \n{hashString}");
        }
        else
        {
            Console.WriteLine("Файл не найден.");
        }
    }
}