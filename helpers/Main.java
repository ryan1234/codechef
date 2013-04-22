class Main {
	public static void main(String[] args) {
		// We want to calculate the answer to 500! / 20! mod 1000000007 
		int mod = 1000000007;
		long result = 1;

		for (int i = 21; i <= 500; i++) {
			long j = (i * result) % mod;
			result = j;
		}

		System.out.println(result);
	}
}
