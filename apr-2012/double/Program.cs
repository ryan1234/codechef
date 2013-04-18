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
			//DateTime now = DateTime.Now;
			int testCases = Int32.Parse(Console.ReadLine());

			for (int i = 0; i < testCases; i++)
			{
				int count = Int32.Parse(Console.ReadLine().ToString());

				if (count % 2 == 0)
				{
					Console.WriteLine(count);
				}
				else	
				{
					Console.WriteLine(count - 1);
				}
			}
			
			//Console.WriteLine("Elapsed: {0}", DateTime.Now.Subtract(now).TotalSeconds);
		}
	}
}
