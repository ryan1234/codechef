import java.io.*;

public class Main {
        public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                String line;

                int iterations = Integer.parseInt(br.readLine());

                for (int i = 0; i < iterations; i++) {
                        int num = Integer.parseInt(br.readLine());
                        System.out.println(printPi(num));
                }
        }
}
