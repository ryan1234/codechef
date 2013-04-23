import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                String[] tokens = br.readLine().toString().split(" ");

                int iterations = Integer.parseInt(tokens[0]);
		int divisor = Integer.parseInt(tokens[1]);

		int count = 0;

                for (int i = 0; i < iterations; i++) {
			int num = Integer.parseInt(br.readLine().toString());	
			if ((num % divisor) == 0) { count++; }
                }

		System.out.println(count);
	}
}
