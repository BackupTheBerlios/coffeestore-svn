package elezioni;

import java.util.ArrayList;
import java.util.Collection;

public class Lista
{
	Collection<Parlamentare> _parlamentari; 
	
	public Lista()
	{
		_parlamentari = new ArrayList<Parlamentare>();
	}
	
	public void add(Parlamentare parlamentare)
	{
		_parlamentari.add(parlamentare);
	}

	public boolean isEmpty()
	{
		return _parlamentari.isEmpty();
	}
	
	public Collection<Parlamentare> getCandidati()
	{
		return _parlamentari;
	}
}
