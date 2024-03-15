using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace s03_07_VAR
{
    internal static class Program
    {
        /*
              1. Приложение-калькулятор для сложения и вычитания целых однозначных
              десятичных чисел.В главной форме имеются кнопки «0», «1», ..., «9», «+», «-»,
              «=» и текстовое поле для вывода результата. Результаты действий пользователя
              (ввод чисел и действий, результат) отражаются в текстовом поле.
              2. Программа, вычисляющая, сколько дней/недель осталось до Нового года.
              Единицы измерения (дни или недели) выбираются с помощью элементов

              TODO1:
                  - Кнопки (13)
                  - Текстовые поля (3)
                  - 
        */
        RadioButton
                /// <summary>
                /// The main entry point for the application.
                /// </summary>
                [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
