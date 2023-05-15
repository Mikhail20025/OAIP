using System;
using System.IO;
using System.Diagnostics;

class Program
{
    
    static void Swap(ref int e1, ref int e2) //метод обмена элементов
    {
        int temp = e1;
        e1 = e2;
        e2 = temp;
    }

    
    static int[] DirectShakerSort(int[] array) //прямая сортировка
    {
        int[] Darray = new int[array.Length];
        for (var i = 0; i < array.Length; i++)
        {
            Darray[i] = array[i];
        }
        var len = Darray.Length;
        int left = 0,
            right = len - 1,
            sravnenie = 0,
            swap = 0;

        Stopwatch clock = new Stopwatch();
        clock.Start();
        while (left < right)
        {
            for (int i = left; i < right; i++)
            {
                sravnenie++;
                if (Darray[i] > Darray[i + 1])
                {
                    Swap(ref Darray[i], ref Darray[i + 1]);
                    swap++;
                }
            }
            right--;

            for (int i = right; i > left; i--)
            {
                sravnenie++;
                if (Darray[i - 1] > Darray[i])
                {
                    Swap(ref Darray[i-1], ref Darray[i]);
                    swap++;
                }
            }
            left++;
        }
        clock.Stop();
       
        Console.WriteLine("Прямая сортировка: ");
        Console.WriteLine("Количество сравнений: {0}. Количество замен: {1} ", sravnenie, swap);
        Console.WriteLine("Время работы: {0} ", clock.Elapsed);
        return Darray;
    }

    static int[] ReverseShakerSort(int[] array)//обратная сортировка
    {
        
        
        int[] Rarray = new int[array.Length];
        for (var i = 0; i < array.Length; i++)
        {
            Rarray[i] = array[i];
        }
        var len = Rarray.Length;
        int left = 0,
            right = len - 1,
            sravnenie = 0,
            swap = 0;

        Stopwatch clock = new Stopwatch();
        clock.Start();
        while (left < right)
        {
            for (int i = left; i < right; i++)
            {
                sravnenie++;
                if (Rarray[i] < Rarray[i + 1])
                {
                    Swap(ref Rarray[i], ref Rarray[i + 1]);
                    swap++;
                }
            }
            right--;

            for (int i = right; i > left; i--)
            {
                sravnenie++;
                if (Rarray[i - 1] < Rarray[i])
                {
                    Swap(ref Rarray[i - 1], ref Rarray[i]);
                    swap++;
                }
            }
            left++;
        }
        clock.Stop();

        Console.WriteLine("Обратная сортировка: ");
        Console.WriteLine("Количество сравнений: {0}. Количество замен: {1} ", sravnenie, swap);
        Console.WriteLine("Время работы: {0} ", clock.Elapsed);
        return Rarray;
    }

    static int[] Reader(string[] arr)//извлечение массива
    {
        char pattern = ' ';
        String[] nums = arr[0].Split(pattern); //извлечение размерности массива
        String[] AS = arr[1].Split(pattern); //извлечение самого массива
        int n = int.Parse(nums[0]);

        int[] array = new int[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = int.Parse(AS[i]);
        }
        return array;
    }
    static void Main(string[] args)
    {
        try
        {
            Console.WriteLine("Шейкерная сортировка");
            // Чтение данных из файла
            Stopwatch clock = new Stopwatch();
            clock.Start();

            clock.Stop();
            Console.WriteLine("Время работы: {0} ", clock.ElapsedTicks);
            string[] Strarr = System.IO.File.ReadAllLines(@"Array.txt");
            Console.WriteLine("Случайный массив: {0}", string.Join(", ", Reader(Strarr)));
            Console.WriteLine("Отсортированный массив прямой сортировкой: {0}", string.Join(", ", DirectShakerSort(Reader(Strarr))));
            Console.WriteLine("Отсортированный массив обратной сортировкой: {0}", string.Join(", ", ReverseShakerSort(Reader(Strarr))));
        }
        catch(Exception ex)
        {
            Console.WriteLine(ex.ToString());
        }

        Console.ReadLine();
    }
}
