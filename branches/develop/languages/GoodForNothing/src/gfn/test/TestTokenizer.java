package gfn.test;

import gfn.ArithOpToken;
import gfn.Token;
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
		
		assertEquals(ArithOpToken.add, tokenizer.next());
	}
	
	@Test
	public void testWithNoToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x");
		
		assertFalse(tokenizer.hasNext());
	}
	
	@Test
	public void testIterateOverTwoElements()
	{
		Iterator<Token> tokenizer = getTokenizer("x + y + z");
		
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
		
		assertEquals(ArithOpToken.add, tokenizer.next());
		assertEquals(ArithOpToken.add, tokenizer.next());
	}

	@Test
	public void testMulToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x * y");
		
		assertEquals(ArithOpToken.mul, tokenizer.next());
	}
	
	@Test
	public void testSubToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x - y");
		
		assertEquals(ArithOpToken.sub, tokenizer.next());
	}
	
	@Test
	public void testDivToken()
	{
		Iterator<Token> tokenizer = getTokenizer("x / y");
		
		assertEquals(ArithOpToken.div, tokenizer.next());
	}
	
	@Test
	public void testMulAddOnTwoLines()
	{
		Iterator<Token> tokenizer = getTokenizer("x * y\nx + y");
		
		assertEquals(ArithOpToken.mul, tokenizer.next());
		assertEquals(ArithOpToken.add, tokenizer.next());
	}
}
