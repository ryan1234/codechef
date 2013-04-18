using System;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
namespace Sandbox
{
	class Program
	{
		static void Main(string[] args)
		{
			DateTime now = DateTime.Now;
			int testCases = Int32.Parse(Console.ReadLine());
			
			for (int i = 0; i < testCases; i++)
			{	
				int nodeCount = Int32.Parse(Console.ReadLine().ToString());
				int agencyCount = 0;
				int[] array = new int[nodeCount];

				for (int j = 2; j < nodeCount; j++)
				{
					if (array[j] != -1)
					{
						if (nodeCount % j == 0)
						{
							array[j] = -1;
							int k = 2;
	
							while (k * j < nodeCount)
							{
								array[k * j] = -1;
								k++;
							}
						}
						else
						{
							array[j] = 1;
						}
					}
				}
	
				for (int j = 1; j < nodeCount; j++)
				{
					if (array[j] != -1)
					{
						agencyCount++;
					}
				}
	
				Console.WriteLine(agencyCount);
			}

			//Console.WriteLine("Elapsed: {0}", DateTime.Now.Subtract(now).TotalSeconds);
		}
	}
}
