import java.math.*;
import java.util.*;

public class Main{

	static List<Integer> primes = new ArrayList<Integer>();
	static int[] result = new int[11];
	public static void main(String[] args){
		find();
	}
	public static void find(){
		primes.add(2);
		int sum = 0, cut = 0;
		for (int i = 3 ;; i += 2){
			boolean isPrime = true;
			for (int p : primes){
				if(p > (int)Math.sqrt(i)) break;
				if(i % p == 0){
					isPrime = false;
					break;
				}
			}
			if (isPrime){
				primes.add(i);
				if(i > 10 && isTruncatable(i)){
					sum += i;
					System.out.printf("The %d number of the answer is %d\n", cut + 1,  i);
					if (++ cut >= 11) break;
				}
			}
		}

		System.out.printf("The final answer %d\n", sum);
	}
	public static boolean isTruncatable(int num){
		int step = 10;
		while(num > step){
			int temp0 = num % step;
			int temp1 = num / step;
			if(Collections.binarySearch(primes, temp0) < 0
				|| Collections.binarySearch(primes, temp1) < 0)
				return false;
			step *= 10;
		}
		return true;
	}
}
