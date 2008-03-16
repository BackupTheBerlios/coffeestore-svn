package elezioni;

public class Circoscrizione
{
	private String _nome;
	private int _numParlamentari;
	
	public Circoscrizione(String nome, int parlamentari)
	{
		_nome = nome;
		_numParlamentari = parlamentari;
	}

	public String getNome()
	{
		return _nome;
	}
	
	public int getNumParlamentari()
	{
		return _numParlamentari;
	}
}
