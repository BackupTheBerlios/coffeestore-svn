package elezioni;

import java.util.Collection;

public class Regione
{
	private String _nome;
	private int _numParlamentari;
	private Collection<Circoscrizione> _circoscrizione;
	
	public Regione(String nome, int parlamentari, Collection<Circoscrizione> circscrizioni)
	{
		_nome = nome;
		_numParlamentari = parlamentari;
		_circoscrizione = circscrizioni;
	}
	
	public String getNome()
	{
		return _nome;
	}
	
	public int getNumParlamentari()
	{
		return _numParlamentari;
	}
	
	public Collection<Circoscrizione> getCircscrizione()
	{
		return _circoscrizione;
	}
}
