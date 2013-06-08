import java.io.*;
import java.util.*;

public class Main {
        public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                String line;

                int iterations = Integer.parseInt(br.readLine());

                for (int i = 0; i < iterations; i++) {
                        String str = br.readLine();
	
			String left = "";
			String right = "";

			if (str.length() % 2 == 0)
			{
				left = str.substring(0, (str.length() / 2));
				right = str.substring(str.length() / 2, str.length());
			}
			else
			{
				left = str.substring(0, (str.length() / 2));
				right = str.substring((str.length() / 2) + 1, str.length());
			}

                        if (compareMaps(getHashMap(left), getHashMap(right)))
                        {
                                System.out.println("YES");
                        }
                        else
                        {
                                System.out.println("NO");
                        }
                }
        }

	public static HashMap<Character, Integer> getHashMap(String str) {
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();

		for (char c : str.toCharArray()) {
			if (map.containsKey(c)) {
				int i = map.get(c);
				map.put(c, i + 1);
			}
			else {
				map.put(c, 1);
			}
		}

		return map;
	}

	public static boolean compareMaps(HashMap<Character, Integer> map1, HashMap<Character, Integer> map2) {
		Iterator it = map1.entrySet().iterator();
    		while (it.hasNext()) {
        		Map.Entry pairs = (Map.Entry)it.next();

			if (!map2.containsKey(pairs.getKey())) { return false; }
			if (map2.get(pairs.getKey()) != pairs.getValue()) { return false; }
        		it.remove();
    		}

		return true;
	}
}
