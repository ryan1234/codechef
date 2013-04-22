import java.io.*;
import java.util.*;

class Main {
        public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                String line;

                int iterations = Integer.parseInt(br.readLine());

                for (int i = 0; i < iterations; i++) {
			String jewels = br.readLine().toString();	
			System.out.println(countMin(jewels));
                }
        }

	private static int countMin(String jewels) {
		int total = 0;
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();

		for (char c : jewels.toCharArray()) {
			int count;

			if (map.get(c) == null) {
				count = 0;
			} else {
				count = map.get(c);
			}

			map.put(c, count + 1);
		}

		for (Map.Entry<Character, Integer> entry : map.entrySet()) {
			int counted = entry.getValue();
			total += counted / 2;
			total += counted % 2;
		}

		return total;
	}
}
