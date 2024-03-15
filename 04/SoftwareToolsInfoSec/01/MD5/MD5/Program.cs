using System.Security;
using System.Security.Cryptography;

// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, World!");

static string CalculateMD5(string filename)
{
    using (var md5 = MD5.Create())
    {
        using (var stream = File.OpenRead(filename))
        {
            var hash = md5.ComputeHash(stream);
            return BitConverter.ToString(hash).Replace("-", "").ToLowerInvariant();
        }
    }
}

namespace s04_01
{
    public static Main()
    {
        
    }
}

