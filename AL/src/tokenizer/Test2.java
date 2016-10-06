package tokenizer;
import java.util.*;

import javax.swing.table.TableModel;

import java.lang.*;

public class Test2 {
	public static void main(String[] args) {
		Iterator<String> it=TokenLib.tokenize("Ceci est une liste de tokens");
		TokenLib.displayTokens(it);
		new TableViewer(null);
	}
} 
