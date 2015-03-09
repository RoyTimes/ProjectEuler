import java.io.*;
import java.util.*;
import java.math.*;

public class Problem57{
	public static void main(String argv[]){

		int cut = 0;
		BigInteger up = new BigInteger("3");
		BigInteger down = new BigInteger("2");
		for (int i = 0; i < 1000; i ++){
			up = up.add(down); 
			BigInteger tem;
			tem = up; up = down; down = tem;
			up = up.add(down);

			String get1, get2;
			get1 = up.toString(); get2 = down.toString();
			if (get1.length() > get2.length()){
				//System.out.printf("%d <--> %d\n", up, down);
				cut ++;
			} 
		}

		System.out.printf("%d\n", cut);
	}

}
