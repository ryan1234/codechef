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
 
        public static String printPi(int num) {
                int a = 103993;
                int b = 33102;
                int remainder = 0;
 
                StringBuilder sb = new StringBuilder();
 
                for (int i = 0; i <= num; i++) {
                        sb.append(a / b); 
 
                        if (i == 0 && num > 0) {
                                sb.append(".");
                        }   
 
                        remainder = (a % b) * 10; 
                        a = remainder;
                }   
 
                return sb.toString();
        }   
}
