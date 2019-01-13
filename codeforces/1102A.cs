using System;

namespace progcomp1102A
{
    class Program
    {
        static void Main(string[] args)
        {
            // Read
            string[] str = Console.ReadLine().Split();
            int n = int.Parse(str[0]);
            int solution = ((n+1)/2)%2;
            Console.WriteLine(solution);
        }
    }
}