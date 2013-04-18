import java.io.*;
import java.util.*;
 
public class Main {
	public static HashMap map = new HashMap();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] firstLineTokens = br.readLine().toString().split("\\s+");
 
		int iterations = Integer.parseInt(firstLineTokens[0]);
		String alphabet = firstLineTokens[1];
 
		setHashMap(alphabet);
 
		for (int i = 0; i < iterations; i++) {
			String phrase = br.readLine();
			System.out.println(translate(phrase));
		}
	}
	
	public static void setHashMap(String alphabet) {
		int letter = 97;
 
		for (char c : alphabet.toCharArray()) {
			map.put((char)letter, c);
			letter++;
		}
 
		letter = 65;
 
		for (char c : alphabet.toUpperCase().toCharArray()) {
			map.put((char)letter, c);
			letter++;
		}
 
		map.put('_', ' ');
		map.put('?', '?');
		map.put('.', '.');
		map.put('!', '!');
		map.put(',', ',');
	}
 
	public static String translate(String bytelandian) {
		StringBuilder sb = new StringBuilder();
 
		for (char c : bytelandian.toCharArray()) {
			boolean isUpper = false;
 
			sb.append(map.get(c));
		}
 
		return sb.toString();
	}
}
