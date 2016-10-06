package tokenizer;
import java.util.*;
import java.lang.*;

public class TokenLib {
	//..
	public static void displayTokens(Iterator<String> it) {
		int token_num=0;
		while (it.hasNext()) {
			String token=it.next();
			System.out.println(token_num+":"+token);
			token_num++;
		}
	}
	
	public static Iterator<String> tokenize(String str) {
		return new TokenLibAdaptater(new StringTokenizer(str));
	}
	//..
} 
