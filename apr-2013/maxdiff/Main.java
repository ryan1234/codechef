import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
                int iterations = Integer.parseInt(br.readLine());
 
                for (int i = 0; i < iterations; i++) {
                        String line = br.readLine();
			int weightSize = Integer.parseInt(line.split(" ")[0]);
			int k = Integer.parseInt(line.split(" ")[1]);

			line = br.readLine();
			String[] weightTokens = line.split(" ");
			
			int[] weights = new int[weightSize];

			for (int j = 0; j < weightTokens.length; j++) {
				weights[j] = Integer.parseInt(weightTokens[j]);
			}

			quicksort(weights, 0, weights.length - 1);
			k = getNewK(k, weights.length);			
			System.out.println(getSum(weights, k) - getFirstSum(weights, k));
                } 
	}

	private static int getNewK(int k, int length) {
		int mid = length / 2;
		if (k <= mid) {
			return k;
		}
		else {
			return length - k;
		}
	}

	private static void quicksort(int[] numbers, int low, int high) {
		int i = low, j = high;

		// Get the pivot element from the middle of the list
		int pivot = numbers[low + (high-low)/2];

		// Divide into two lists
		while (i <= j) {
			// If the current value from the left list is smaller then the pivot
			// element then get the next element from the left list
			while (numbers[i] < pivot) {
				i++;
			}

			// If the current value from the right list is larger then the pivot
			// element then get the next element from the right list
			while (numbers[j] > pivot) {
				j--;
			}

			if (i <= j) {
				exchange(numbers, i, j);
				i++;
				j--;
			}
		}

		// Recursion
		if (low < j)
			quicksort(numbers, low, j);

		if (i < high)
			quicksort(numbers, i, high);
	}

	private static void exchange(int[] numbers, int i, int j) {
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}

	private static int getFirstSum(int[] weights, int k) {
		int sum = 0;

		for (int i = 0; i < k; i++) {
			sum += weights[i];
		}

		return sum;
	}

	private static int getSum(int[] weights, int k) {
		int sum = 0;

		for (int i = k; i < weights.length; i++) {
			sum += weights[i];
		}
		
		return sum;
	}
}
