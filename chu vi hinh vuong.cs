using System;

class Program
{
    static void Main()
    {
        // Nhập độ dài cạnh của hình vuông
        Console.Write("Nhập độ dài cạnh của hình vuông: ");
        double canh = Convert.ToDouble(Console.ReadLine());

        // Tính chu vi
        double chuVi = 4 * canh;

        // In kết quả
        Console.WriteLine("Chu vi của hình vuông là: " + chuVi);
    }
}
