using System;
using System.Text;
using System.Collections.Generic;
using System.Collections;
using System.IO;
namespace ConsoleApplication1
{
	public class Program
	{
		static void Main(string[] args)
		{
			TextReader reader = Console.In;
			int testCases = Int32.Parse(reader.ReadLine());

			for (int i = 0; i < testCases; i++)
			{
				int numCount = Int32.Parse(reader.ReadLine());
				string[] tokens = reader.ReadLine().Split(' ');
				int min = int.MaxValue;
				int max = 0;
				ArrayList candidates = new ArrayList();

				foreach (string token in tokens)
				{
					int num = int.Parse(token);
					
					if (num > max) { max = num; }
		
					if (num < min)
					{
						if (max - min > 0) { candidates.Add(max - min); }
						min = num;
						max = 0;
					}

					//Console.WriteLine(string.Format("max: {0}, min: {1}", max, min));
				}

				if (max - min > 0) { candidates.Add(max - min); }

				int candidateMax = 0;

				foreach (int candidate in candidates)
				{
					if (candidate > candidateMax)
					{
						candidateMax = candidate;
					}
				}

				if (candidateMax <= 0)
				{
					Console.WriteLine("UNFIT");
				}
				else
				{
					Console.WriteLine(candidateMax);
				}
			}
			
			return;
		}
	}
}
