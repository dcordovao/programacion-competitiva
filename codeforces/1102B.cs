using System;
using System.Collections.Generic;
using System.Linq;

/*
    Solution by DiegoCO
    We will sort the array of numbers saving the initial position of every 
    element. Then we will start painting the elements sorted with the color 1, 
    then the color 2, etc. When i get to color K, we start painting with color
    1 again. The cariable "counter" is used to count how many equal elements i
    have seen. In case is greater than K, the solution is "NO".

 */

namespace progcomp1102B
{
    class Program
    {
        static void Main(string[] args)
        {
            // Reading input
            string[] str = Console.ReadLine().Split();
            int n = int.Parse(str[0]);
            int k = int.Parse(str[1]);
            str = Console.ReadLine().Split();
            int[] numbers = Array.ConvertAll(str, int.Parse);

            // variables
            int[] initial_pos = Enumerable.Range(0,n).ToArray();
            int[] solution = new int[n];
            bool flag = true;
            int counter = 0;
            int last_number = 0;

            Array.Sort(numbers, initial_pos);

            for (int i = 0; i < n; i++) {
                if(numbers[i] != last_number) {
                    counter = 0;
                    last_number = numbers[i];
                }
                counter += 1;
                if (counter > k) {
                    flag = false;
                    break;
                }
                solution[initial_pos[i]] = (i%k)+1;
            }

            // Print solution
            if (flag) {
                Console.WriteLine("YES");
                for (int i = 0; i < n; i++)
                {
                    Console.Write(solution[i].ToString()+" ");
                }
            } else {
                Console.WriteLine("NO");
            }
        }
    }
}