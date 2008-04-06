package elezioni;

import java.util.GregorianCalendar;
import java.util.ArrayList;
import elezioni.RisultatoElettorale;

public class Elezione
{
	private GregorianCalendar _date;
	private ArrayList<RisultatoElettorale> _res;
	
	public Elezione(GregorianCalendar date)
	{
		_date = date;
		_res = new ArrayList<RisultatoElettorale>();
	}

	public GregorianCalendar get_date()
	{
		return _date;
	}

	public void set_date(GregorianCalendar _date)
	{
		this._date = _date;
	}

	public ArrayList<RisultatoElettorale> get_res()
	{
		return _res;
	}

	public void set_res(ArrayList<RisultatoElettorale> _res)
	{
		this._res = _res;
	}
	
}
