package gfn;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Tokenizer implements Iterator<Token>
{
	BufferedReader bufferedReader;
	StringTokenizer stringTokenizer;
	Token currentToken;

	HashMap<String, TokenType> tokenTypes;
	ArrayList<TokenType> regexTokenTypes;
	
	public Tokenizer(Reader reader)
	{
		createTokenTypes();
		bufferedReader = new BufferedReader(reader);
		eatLine();
	}

	private void createTokenTypes()
	{
		tokenTypes = new HashMap<String, TokenType>();
		regexTokenTypes = new ArrayList<TokenType>();
		
		for (TokenType tokenType : TokenType.values())
		{
			if (!tokenType.needRegex())
			{
				tokenTypes.put(tokenType.getTokenValue(), tokenType);
			}
			else
			{
				regexTokenTypes.add(tokenType);
			}
		}
	}
	
	private void eatLine()
	{
		try
		{
			String line = bufferedReader.readLine();
			if (line != null)
			{
				stringTokenizer = new StringTokenizer(line, " \t+*-/;=", true);	
				eatToken();
			}
		}
		catch (IOException exception) {}
	}

	private void eatToken()
	{	
		currentToken = null;
		while (currentToken == null && stringTokenizer.hasMoreElements())
		{
			matchToken(stringTokenizer.nextToken());
		}
		
		if (currentToken == null && !stringTokenizer.hasMoreElements())
		{
			eatLine();
		}
	}

	private void matchToken(String tokenValue)
	{
		TokenType tokenType = tokenTypes.get(tokenValue);
		if (tokenType != null)
		{
			currentToken = new Token(tokenValue, tokenType);
		}
		else
		{
			for (TokenType regexTokenType : regexTokenTypes)
			{
				if (tokenValue.matches(regexTokenType.getTokenValue()))
				{
					currentToken = new Token(tokenValue, regexTokenType);
					break;
				}
			}
		}
	}

	@Override
	public boolean hasNext()
	{
		return currentToken != null;
	}

	@Override
	public Token next()
	{
		Token result = currentToken;
		eatToken();
		return result;
	}

	@Override
	public void remove()
	{

	}
}
