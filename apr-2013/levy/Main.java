import java.util.*;
import java.io.*;

class Main {
	static final int[] primes;
	static final int max = 10000;
	static HashMap<Integer, Integer> map;

	static {
		primes = getPrimes();
		map = new HashMap<Integer, Integer>();

		for (int i = 0; i <= 50000; i++) {
			map.put(i, 0);
		} 
	}

	public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

                int iterations = Integer.parseInt(br.readLine());
		int n = 0;	
	
		populateMap();

                for (int i = 0; i < iterations; i++) {
                        n = Integer.parseInt(br.readLine());
        	        System.out.println(map.get(n));
		}

		return;
	}

	public static void populateMap() {
		int candidate = 0;

        	for (int j = 0; j < primes.length; j++) {
                	for (int k = 0; k < primes.length; k++) {
                        	candidate = primes[j] + (2 * primes[k]);
				map.put(candidate, map.get(candidate) + 1);
                        }
		}
	}

	public static int[] getPrimes() {
		boolean[] isComposite = new boolean[max + 1];
		
		for (int i = 2; i * i <= max; i++) {
			if (!isComposite [i]) {
				for (int j = i; i * j <= max; j++) {
					isComposite [i*j] = true;
				}
			}
		}
 
		int numPrimes = 0;
 
		for (int i = 2; i <= max; i++) {
			if (!isComposite [i]) numPrimes++;
		}
 
		int[] primeNumbers = new int [numPrimes];
		int index = 0;
 
		for (int i = 2; i <= max; i++) {
			if (!isComposite[i]) { 
				primeNumbers[index++] = i;
			}
		}
 
		return primeNumbers;
	}
}
