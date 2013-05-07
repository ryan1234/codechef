import java.io.*;
import java.util.*;

public class Main {
	private static HashMap<Character, Integer> parentMap;
	private static HashMap<Character, Integer> childrenMap;

        public static void main(String[] args) throws IOException {
		parentMap = new HashMap<Character, Integer>();
		childrenMap = new HashMap<Character, Integer>();

                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                String line;

                int iterations = Integer.parseInt(br.readLine());

                for (int i = 0; i < iterations; i++) {
			parentMap.clear();
			childrenMap.clear();

			String[] parentNames = br.readLine().split(" ");
			String parentName = parentNames[0] + parentNames[1];

			populateMap(parentMap, parentName);

                        int childrenCount = Integer.parseInt(br.readLine());
			StringBuilder sb = new StringBuilder();

			for (int j = 0; j < childrenCount; j++) {
				sb.append(br.readLine());
			}

			populateMap(childrenMap, sb.toString());

			boolean passes = true;

			for (char c : childrenMap.keySet()) {
				if (!parentMap.containsKey(c)) {
					passes = false;
					break;
				} else {
					if (parentMap.get(c) < childrenMap.get(c)) {
						passes = false;
					}
				}
			}

			if (passes) { 
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
                }
        }

	private static void populateMap(HashMap<Character, Integer> map, String str) {
		for (char c : str.toCharArray()) {
			if (map.containsKey(c)) {
				int i = map.get(c) + 1;		
				map.put(c, i);
			} else {
				map.put(c, 1);
			}
		}
	}
}
