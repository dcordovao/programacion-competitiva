using System;

namespace progcomp50A
{
    class Program
    {
        static void Main(string[] args)
        {
            // Read
            string[] str = Console.ReadLine().Split();
            int m = int.Parse(str[0]);
            int n = int.Parse(str[1]);

            int ans = m*n/2;

            Console.WriteLine(ans);
        }
    }
}
