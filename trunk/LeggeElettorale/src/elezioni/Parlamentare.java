package elezioni;

public class Parlamentare
{
	private String _nome;
	private String _cognome;
	
	public Parlamentare(String nome, String cognome)
	{
		_nome = nome;
		_cognome = cognome;
	}
	
	public String getNome()
	{
		return _nome;
	}
	public String getCognome()
	{
		return _cognome;
	}
}
