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
            using (var md5 = MD5.Create())
            {
                using (var stream = File.OpenRead(fileName))
                {
                    byte[] hash = md5.ComputeHash(stream);
                    string hashString = BitConverter.ToString(hash).Replace("-", "").ToLower();

                    Console.WriteLine($"MD5 хеш файла {fileName}: {hashString}");
                }
            }
        }
        else
        {
            Console.WriteLine("Файл не найден.");
        }
    }
}