package Ex4_1;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TokenFacade {
	private int nextToken; 
	
	private List <Token> idToToken;
	
	private Map<String, Token> tokenToId;
	
	public TokenFacade() {
		nextToken = 0;
		idToToken = new ArrayList<Token>();
		tokenToId = new HashMap<String, Token>();
	}
	
	public Token getTokenMapping(int tokenId){
		return idToToken.get(tokenId);
	}
	public String getToken(int tokenId) {
		return getTokenMapping(tokenId).getTokenStr();
	}
	public String getAnnotation(int tokenId) {
		return getTokenMapping(tokenId).getAnnotation();
	}
	
	public int getTokenId(String token) {
		if (tokenToId.get(token) == null) {
			return -1;
		}
		return tokenToId.get(token).getTokenId();
	}
	
	public int getMaxToken() {
		return nextToken;
	}
	
	public int addNewToken (String str, String annotation) {
		if (getTokenId(str) != -1) {
			return -1;
		}
		Token token = new Token(str, nextToken, annotation);
		idToToken.add(token);
		++nextToken;
		tokenToId.put(str, token);
		return nextToken;
	}
} 
