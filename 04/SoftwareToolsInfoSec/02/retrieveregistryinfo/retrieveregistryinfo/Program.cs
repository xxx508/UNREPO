using System;
using Microsoft.Win32;
using System.IO;

class Program
{
    static void Main()
    {
        string serialNumber = "";
        string motherboardName = "";

        using (RegistryKey key = Registry.LocalMachine.OpenSubKey(@"HARDWARE\DESCRIPTION\System\BIOS"))
        {
            if (key != null)
            {
                serialNumber = key.GetValue("SystemSKU").ToString();
            }
        }

        using (RegistryKey key = Registry.LocalMachine.OpenSubKey(@"HARDWARE\DESCRIPTION\System\BIOS"))
        {
            if (key != null)
            {
                motherboardName = key.GetValue("BaseBoardProduct").ToString();
            }
        }

        string filePath = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + "\\Desktop\\system_info.txt";

        using (StreamWriter writer = new StreamWriter(filePath))
        {
            writer.WriteLine("Серийный номер: " + serialNumber);
            writer.WriteLine("Название мат. платы: " + motherboardName);
        }

        Console.WriteLine("Информация была сохранена в " + filePath);
    }
}