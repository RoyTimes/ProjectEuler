import java.math.*;
import java.util.*;
import java.io.*;

public class Main{

	public static boolean Judge(int y, int x){
		

		double pre = (double)x / (double)y;
			
		//System.out.printf("The ratio of this level is %llf", pre);

		if (pre < 0.1) return true;
		return false;
	}
/*	public static boolean Prime(long long x){
		for (int i = 2; i * i <= x; i ++)
			if (x % i == 0) return false;
		return true;
	}*/
	public static boolean Prime(BigInteger x){
		BigInteger i = new BigInteger("2");
		for (;; i =  i.add(BigInteger.valueOf(1))){
			BigInteger temp = new BigInteger(i.toString());
			temp = temp.pow(2);
			if (temp.compareTo(x) > 0) break;
			temp = new BigInteger(x.toString()); 
			temp = temp.remainder(i);
			BigInteger _temp = new BigInteger("0");
			if (temp.compareTo(_temp) == 0) return false;
		}
		System.out.println("is prime");
		return true;

	}

	public static void main(String argv[]){


		BigInteger get = new BigInteger("9223372036854775817");
		Prime(get);
		//eixt(0);

		//System.out.printf("Prime is %d\n", Prime(BigInteger.valueOf(17)));

		/*int tot = 0, i;
		for (i = 2;; i++){
			int this_layer = i * 2 - 1;
			BigInteger a = new BigInteger(this_layer + "");a = a.pow(2);
			BigInteger b = new BigInteger(a.toString());
			BigInteger c = new BigInteger(a.toString());
			BigInteger d = new BigInteger(a.toString());

			b = b.subtract(BigInteger.valueOf((i - 1) * 2));
			c = c.subtract(BigInteger.valueOf((i - 1) * 6));
			d = d.subtract(BigInteger.valueOf((i - 1) * 4));

			//System.out.printf("the current a = %s\n", a.toString());

			if (Prime(b)) tot ++;
			if (Prime(c)) tot ++;
			if (Prime(d)) tot ++;			

			//System.out.printf("the total is %d, %d",tot, i * 4 - 3);
			

			//double pre = tot / (i * 4 - 3);
			if ((double)tot / (i * 4 - 3) - 0.1 < 0) break;
			//System.out.printf(", %.3f\n", pre);

		}
		System.out.printf("%d\n", i);*/
	}
}
