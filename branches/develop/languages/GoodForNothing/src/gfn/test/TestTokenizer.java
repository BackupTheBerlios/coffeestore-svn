package gfn.test;

import gfn.Token;
import gfn.TokenType;
import gfn.Tokenizer;

import java.io.Reader;
import java.io.StringReader;
import java.util.Iterator;

import org.junit.Test;
import static org.junit.Assert.*;

public class TestTokenizer
{
	private Iterator<Token> getTokenizer(String text)
	{
		Reader reader = new StringReader(text); // FileReader
		Iterator<Token> tokenizer = new Tokenizer(reader);
		return tokenizer;
	}
	
	@Test
	public void testAddToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x + x");
		
		tokenizer.next();
		assertEquals(new Token("+", TokenType.ADD), tokenizer.next());
	}
	
	@Test
	public void testIdToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x");
		
		assertTrue(tokenizer.hasNext());
		assertEquals(new Token("x", TokenType.IDENTIFIER), tokenizer.next());
	}
	
	@Test
	public void testIterateOverTwoElements()
	{
		Iterator<Token> tokenizer = getTokenizer("x + y + z");
		
		assertTrue(tokenizer.hasNext());
		tokenizer.next();
		assertTrue(tokenizer.hasNext());
		tokenizer.next();
		assertTrue(tokenizer.hasNext());
		tokenizer.next();
		assertTrue(tokenizer.hasNext());
		tokenizer.next();
		assertTrue(tokenizer.hasNext());
		tokenizer.next();
		assertFalse(tokenizer.hasNext());
	}
	
	@Test
	public void testTwoAddTokens()
	{
		Iterator<Token> tokenizer = getTokenizer("x + y + z");
		
		tokenizer.next();
		assertEquals(new Token("+", TokenType.ADD), tokenizer.next());
		tokenizer.next();
		assertEquals(new Token("+", TokenType.ADD), tokenizer.next());
	}

	@Test
	public void testMulToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x * y");
		
		tokenizer.next();
		assertEquals(new Token("*", TokenType.MUL), tokenizer.next());
	}
	
	@Test
	public void testSubToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x - y");
		
		tokenizer.next();
		assertEquals(new Token("-", TokenType.SUB), tokenizer.next());
	}
	
	@Test
	public void testDivToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x / y");
		
		tokenizer.next();
		assertEquals(new Token("/", TokenType.DIV), tokenizer.next());
	}
	
	@Test
	public void testMulAddOnTwoLines()
	{
		Iterator<Token> tokenizer = getTokenizer("x * y\nx + y");
		
		tokenizer.next();
		assertEquals(new Token("*", TokenType.MUL), tokenizer.next());
		tokenizer.next();
		tokenizer.next();
		assertEquals(new Token("+", TokenType.ADD), tokenizer.next());
	}
	
	@Test
	public void testTwoStringsWithSpace()
	{
		Iterator<Token> tokenizer = getTokenizer("str1 str2");
		
		assertEquals(new Token("str1", TokenType.IDENTIFIER), tokenizer.next());
		assertEquals(new Token("str2", TokenType.IDENTIFIER), tokenizer.next());
	}
	
	@Test
	public void testTwoStringsWithTab()
	{
		Iterator<Token> tokenizer = getTokenizer("str1\tstr2");
		
		assertEquals(new Token("str1", TokenType.IDENTIFIER), tokenizer.next());
		assertEquals(new Token("str2", TokenType.IDENTIFIER), tokenizer.next());
	}
	
	@Test
	public void testIntegerToken()
	{
		Iterator<Token> tokenizer = getTokenizer("12");
		
		assertEquals(new Token("12", TokenType.NUMBER), tokenizer.next());
	}

	@Test
	public void testVarToken()
	{
		Iterator<Token> tokenizer = getTokenizer("var");
		
		assertEquals(new Token("var", TokenType.VAR), tokenizer.next());
	}

	@Test
	public void testToToken()
	{
		Iterator<Token> tokenizer = getTokenizer("to");
		
		assertEquals(new Token("to", TokenType.TO), tokenizer.next());
	}
	
	@Test
	public void testDoToken()
	{
		Iterator<Token> tokenizer = getTokenizer("do");
		
		assertEquals(new Token("do", TokenType.DO), tokenizer.next());
	}
	
	@Test
	public void testEndToken()
	{
		Iterator<Token> tokenizer = getTokenizer("end");
		
		assertEquals(new Token("end", TokenType.END), tokenizer.next());
	}
	
	@Test
	public void testPrintToken()
	{
		Iterator<Token> tokenizer = getTokenizer("print");
		
		assertEquals(new Token("print", TokenType.PRINT), tokenizer.next());
	}
	
	
	@Test
	public void testAssignmentToken()
	{
		Iterator<Token> tokenizer = getTokenizer("=");
		
		assertEquals(new Token("=", TokenType.ASSIGNMENT), tokenizer.next());
	}
	
	@Test
	public void testEndOfStatementToken()
	{
		Iterator<Token> tokenizer = getTokenizer(";");
		
		assertEquals(new Token(";", TokenType.ENDSTATEMENT), tokenizer.next());
	}

	@Test
	public void testIfToken()
	{
		Iterator<Token> tokenizer = getTokenizer("if");
		
		assertEquals(new Token("if", TokenType.IF), tokenizer.next());
	}
	
	@Test
	public void testForToken()
	{
		Iterator<Token> tokenizer = getTokenizer("for");
		
		assertEquals(new Token("for", TokenType.FOR), tokenizer.next());
	}
	
}
