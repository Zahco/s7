package Ex4_1;

public class IndexTest {
	public static void main(String[] args) {
		TokenFacade tf = new TokenFacade();
		tf.addNewToken("il", "");
		tf.addNewToken("tu", "");
		tf.addNewToken("je", "");
		tf.addNewToken("il", "");
		for (int i = 0; i < tf.getMaxToken(); ++i) {
			System.out.println(tf.getToken(i)+":"+tf.getTokenId(tf.getToken(i))+" ");
		}
	}
	
}
