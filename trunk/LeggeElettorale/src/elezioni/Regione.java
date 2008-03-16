package elezioni;

import java.util.ArrayList;
import java.util.Collection;

public class Regione
{
	private String _nome;
	private Collection<Circoscrizione> _circoscrizioni;
	
	public Regione(String nome)
	{
		_nome = nome;
		_circoscrizioni = new ArrayList<Circoscrizione>();
	}
	
	public String getNome()
	{
		return _nome;
	}
	
	public Collection<Circoscrizione> getCircscrizioni()
	{
		return _circoscrizioni;
	}
	
	public void addCircoscrizione(Circoscrizione circoscrizione)
	{
		_circoscrizioni.add(circoscrizione);
	}
}
