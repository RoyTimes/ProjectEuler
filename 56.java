import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String args[]){

		int _max = 0;
		for (int i = 0; i < 100; i ++)
			for (int j = 0; j < 100; j ++){
				String base = i + "";
				BigInteger _base = new BigInteger(base); 
				_base = _base.pow(j); String ans = new String();
				ans = _base.toString(); int tot = 0;
				for (int k = 0; k < ans.length(); k ++)
					tot += ans.charAt(k) - '0';

				if (_max < tot) _max = tot;
				//System.out.println(_base);
				//System.out.printf ("INFO i = %d, j = %d >> %d\n", i,j,tot); 
		}
		System.out.printf("%d\n", _max);
	}
}
