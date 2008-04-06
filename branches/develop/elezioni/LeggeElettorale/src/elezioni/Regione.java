package elezioni;

import java.util.ArrayList;
import java.util.Collection;

public class Regione
{
	private String _nome;
	private Collection<Circoscrizione> _circoscrizioniCamera;
	private Collection<Circoscrizione> _circoscrizioniSenato;
	
	public Regione(String nome)
	{
		_nome = nome;
		_circoscrizioniCamera = new ArrayList<Circoscrizione>();
		_circoscrizioniSenato = new ArrayList<Circoscrizione>();
	}
	
	public String getNome()
	{
		return _nome;
	}
	
	public Collection<Circoscrizione> getCircscrizioniCamera()
	{
		return _circoscrizioniCamera;
	}
	
	public void addCircoscrizioneCamera(Circoscrizione circoscrizione)
	{
		_circoscrizioniCamera.add(circoscrizione);
	}
	
	public Collection<Circoscrizione> getCircscrizioniSenato()
	{
		return _circoscrizioniSenato;
	}
	
	public void addCircoscrizioneSenato(Circoscrizione circoscrizione)
	{
		_circoscrizioniSenato.add(circoscrizione);
	}
}
