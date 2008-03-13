package elezioni;

import java.util.HashMap;
import java.util.Map;

public class Partito
{
	private String _name;
	private Premier _premier;
	private Map<Circoscrizione, Lista> _listeCamera;
	private Map<Circoscrizione, Lista> _listeSenato;
	
	public Partito(String name, Premier premier)
	{
		_name = name;
		_premier = premier;
		_listeCamera = new HashMap<Circoscrizione, Lista>();
		_listeSenato = new HashMap<Circoscrizione, Lista>();
	}

	public String getName()
	{
		return _name;
	}

	public Premier getPremier()
	{
		return _premier;
	}

	public Lista getListeSenato(Circoscrizione circoscrizione)
	{
		return _listeSenato.get(circoscrizione);
	}
	
	public Lista getListeCamera(Circoscrizione circoscrizione)
	{
		return _listeCamera.get(circoscrizione);
	}

	public void addToCamera(Circoscrizione circoscrizione, Lista lista)
	{
		_listeCamera.put(circoscrizione, lista);
	}
	
	public void addToSenato(Circoscrizione circoscrizione, Lista lista)
	{
		_listeSenato.put(circoscrizione, lista);
	}
}
