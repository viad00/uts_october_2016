using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ханойские_башни
{
    class Program
    {
        static int count = 0;
        static void Main(string[] args)
        {
            int x;
            char from = 'A', to = 'B', help = 'C';
            
            do
            {
                try
                {
                    Console.WriteLine("Введите кол-во дисков: ");
                    x = int.Parse(Console.ReadLine());
                }
                catch (FormatException e)
                {
					Console.WriteLine(e);
                    x = -10;
                }
            } while (x == -10 || x > 30);
            Console.WriteLine("с - A, на - B, вспомогательная - C");
            count = 0;
            hanoi(x, from, to, help);
            Console.WriteLine("Совершено действий: " + count);
			Console.Write("В бинарном: " + Convert.ToString (count, 2));
			bool fl = true;
			for (int i = 0; i < Convert.ToString(count, 2).Length; i++)
			{
				fl &= Convert.ToString(count, 2)[i] != '0';
			}
			if (fl) { Console.Write(" OK\n"); } else { Console.Write(" ERROR\n"); }
            Console.Read();
        }

        static void hanoi(int x, char from, char to, char help)
        {
            if (x > 0)
            {
                hanoi(x - 1, from, help, to);
                move(x, from, to);
                hanoi(x - 1, help, to, from);
            }

        }

        static void move(int x, char from, char to)
        {
			count++;
            Console.WriteLine(count + ": Двигаем диск " + x + " с " + from + " на " + to);
        }
    }
}
