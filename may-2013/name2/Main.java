import java.io.*;

public class Main {
        public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                String line;

                int iterations = Integer.parseInt(br.readLine());

                for (int i = 0; i < iterations; i++) {
			String[] names = br.readLine().toString().split(" ");
                        System.out.println(areMarried(names[0], names[1]));
                }
        }

	public static String areMarried(String str1, String str2) {
		if (str1.equals(str2)) { return "YES"; }

		if (str1.length() > str2.length()) {
			String temp = str1;
			str1 = str2;
			str2 = temp;
		}

		char[] chars = str1.toCharArray();
		int currentCharIndex = 0;
		char currentChar = chars[currentCharIndex];

		for (char c : str2.toCharArray()) {
			if (c == currentChar) {
				currentCharIndex++;

				if (currentCharIndex == str1.length() - 1) {
					return "YES";
				}

				currentChar = chars[currentCharIndex];
			}
		}

		if (currentCharIndex == str1.length() - 1) { return "YES"; }
	
		return "NO";
	}
}
