    using System;
    using System.Collections.Generic;
    using System.Linq;

    /* Simple solution. The number of turns doesn't matter, because the max
        value is too large. If x > y, we can destroy all the doors. In other
        case we can destroy only the doors with durability lower or equal
        to x. We break one door on each turn but the other player save one
        door by turn to */

    namespace progcomp1102C
    {
        class Program
        {
            static void Main(string[] args)
            {
                // Reading input
                string[] str = Console.ReadLine().Split();
                int n = int.Parse(str[0]);
                int x = int.Parse(str[1]);
                int y = int.Parse(str[2]);
                str = Console.ReadLine().Split();
                int[] numbers = Array.ConvertAll(str, int.Parse);

                if (x > y) {
                    Console.WriteLine(n);
                } else {
                    int counter = 0;
                    for (int i = 0; i < n; i++) {
                        if (numbers[i] <= x) {
                            counter += 1;
                        }
                    }
                    Console.WriteLine((counter + 1) / 2);
                }
            }
        }
    }