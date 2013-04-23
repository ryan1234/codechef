// Learned that mod stuff should be applied to the sum of two numbers, not individually and then sum
// (a + b) % mod == correct
// (a % mod) + (b % mod) == incorrect
import java.io.*;

class Main {
	private static final int mod = 1000000007;
	private static final int[] fibs = new int[1000000];

	public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                String line;

                int iterations = Integer.parseInt(br.readLine());

		populateFibs(1000000);

                for (int i = 0; i < iterations; i++) {
			String[] tokens = br.readLine().toString().split(" ");	
			int n = Integer.parseInt(tokens[0]);
			int g = Integer.parseInt(tokens[1]);

			if (countOfOnes(fibs[n + 1]) == g) {
				System.out.println("CORRECT");
			} else {
				System.out.println("INCORRECT");
			}
                }
	}

	private static void populateFibs(int n) {
		int a = 0;
		int b = 1;

		fibs[0] = 0;
		fibs[1] = 1;

		for (int i = 0; i < n - 2; i++) {
			int temp = a;
			a = b;
			b = (temp + b) % mod;
			fibs[i + 2] = b;
		}
	}

	private static int countOfOnes(int i)
	{
		i = i - ((i >> 1) & 0x55555555);
		i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
		return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
	}
}
