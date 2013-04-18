using System;
using System.Collections.Generic;
namespace ConsoleApplication1
{
	public class Program
	{
		static void Main(string[] args)
		{
			int testCases = Int32.Parse(Console.ReadLine());
			for (int z = 0; z < testCases; z++)
			{
				int numLength = Int32.Parse(Console.ReadLine());
				string numString = Console.ReadLine();
				int[] nums = new int[numLength];
				string[] tokens = numString.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
				for (int i = 0; i < numLength; i++)
				{
					nums[i] = Int32.Parse(tokens[i]);
				}

				SortedDictionary d = new SortedDictionary();
				
				for (int i = 0; i < nums.Length; i++)
				{
					if (!d.ContainsKey(nums[i]))
					{
						d.Add(nums[i], 1);
					}
					else
					{
						d[nums[i]] = d[nums[i]] + 1;
					}
				}

				List counts = new List(d.Values);
				counts.Sort();

				int val = 0;
				
				foreach (KeyValuePair kvp in d)
				{
					if (kvp.Value == counts[counts.Count - 1])
					{
						val = kvp.Key;
						break;
					}
				}

				Console.WriteLine(string.Format("{0} {1}", val, counts[counts.Count - 1]));
			}
			return;
		}
	}
}
