using System;
using System.Collections.Generic;
using System.Text;
namespace ConsoleApplication1
{
	public class Program
	{
		static void Main(string[] args)
		{
			//long GC_MemoryStart = System.GC.GetTotalMemory(true);
			//DateTime dt = DateTime.Now;
			int testCases = Int32.Parse(Console.ReadLine());
			for (int z = 0; z < testCases; z++)
			{
				string tokens = Console.ReadLine();
				int rows = Int32.Parse(tokens.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)[0]);
				int cols = Int32.Parse(tokens.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)[1]);
				char[,] matrix = PopulateMatrix(rows, cols);
				ScanMatrix(matrix);
			}
			
			//long GC_MemoryEnd = System.GC.GetTotalMemory(true);
			//Console.WriteLine("Memory used: " + (GC_MemoryEnd - GC_MemoryStart).ToString());
			//Console.WriteLine("Time: " + DateTime.Now.Subtract(dt).TotalMilliseconds);
			return;
		}

		private static char[,] PopulateMatrix(int rows, int cols)
		{
			char[,] matrix = new char[rows, cols];
		
			// Populate the matrix.
			for (int i = 0; i < rows; i++)
			{
				string row = Console.ReadLine();
				char[] rowChars = row.ToCharArray();
				for (int j = 0; j < rowChars.Length; j++)
				{
					matrix[i, j] = rowChars[j];
				}
			}
			return matrix;
		}

		private static void ScanMatrix(char[,] matrix)
		{
			// Scan the matrix. Can be combined with populate I'm sure.
			for (int i = 0; i <= matrix.GetUpperBound(0); i++)
			{
				for (int j = 0; j <= matrix.GetUpperBound(1); j++)
				{
					if (matrix[i, j] == 's' || matrix[i, j] == 'S')
					{
						// go through the two possible directions to try and construct the entire word.
						// row first
						if (j + 4 <= matrix.GetUpperBound(1))
						{
							string match = "poon";
							string candidate = matrix[i, j + 1].ToString()
								+ matrix[i, j + 2].ToString()
								+ matrix[i, j + 3].ToString()
								+ matrix[i, j + 4].ToString();

							if (match == candidate.ToLower())
							{
								Console.WriteLine("There is a spoon!");
								return;
							}
						}
						
						// now check column
						if (i + 4 <= matrix.GetUpperBound(0))
						{
							string match = "poon";
							string candidate = matrix[i + 1, j].ToString()
								+ matrix[i + 2, j].ToString()
								+ matrix[i + 3, j].ToString()
								+ matrix[i + 4, j].ToString();
							
							if (match == candidate.ToLower())
							{
								Console.WriteLine("There is a spoon!");
								return;
							}
						}
					}
				}
			}
			
			Console.WriteLine("There is indeed no spoon!");
		}
	}
}
