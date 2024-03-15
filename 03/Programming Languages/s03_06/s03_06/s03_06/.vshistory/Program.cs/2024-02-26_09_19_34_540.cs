using System;
using System.Collections.Generic;
using System.Linq;
namespace s03_06
{
    class Program
    {
        static void Func1()
        {
            Console.WriteLine("Введите элементы массива через пробел:");
            string input = Console.ReadLine();
            string[] inputArray = input.Split(' ');
            int n = inputArray.Length;
            double[] array = new double[n];
            for (int i = 0; i < n; i++) array[i] = Convert.ToDouble(inputArray[i]);
            for (int i = 0; i < n; i++) if (array[i] < 0) array[i] = 3;
            Console.WriteLine("Измененный массив:");
            for (int i = 0; i < n; i++) Console.Write(array[i] + " ");
            Console.WriteLine();
        }
        static void Func2()
        {
            double[,] matrix; double mid = 0;
            Console.WriteLine("Введите квадратную матрицу:");
            string inp = Console.ReadLine();
            List<string> strings = new List<string>(inp.Split(' '));
            int n = strings.Count;
            matrix = new double[n, n];
            double[] sum = new double[n];
            for (int i = 0; i < n; i++) { sum[i] = 0; }
            for (int i = 0; i < n; i++) { matrix[0, i] = Convert.ToDouble(strings[i]); mid += matrix[0, i]; }
            for (int j = 1; j < n; j++)
            {
                inp = Console.ReadLine();
                strings.Clear();
                strings = new List<string>(inp.Split(' '));
                while (strings.Count < n)
                {
                    string stradd = Console.ReadLine();
                    string[] addar = stradd.Split(' ');
                    foreach (string s in addar) strings.Add(s);
                }
                for (int i = 0; i < n; i++) { matrix[j, i] = Convert.ToDouble(strings[i]); mid += matrix[j, i]; }
                for (int i = 0; i < n; i++)
                    for (int k = 0; k < n; k++)
                    {
                        sum[j] += matrix[i, j];
                    }
            }
            mid = mid / n / n;
            Console.WriteLine("Среднее значение всех элементов: " + mid);
            Console.WriteLine("Суммы столбцов:");
            for (int i = 0; i < n; i++) Console.Write(sum[i] + " ");
            Console.WriteLine();
            double minimal = -int.MaxValue
            for ()
        }
        static void Main()
        {
            Func1();
            Func2();
            Console.WriteLine("Awaiting key input...");
            Console.ReadKey();
        }
    }
}