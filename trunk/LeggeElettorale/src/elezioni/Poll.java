package elezioni;

import java.util.GregorianCalendar;
import java.util.HashMap;
import java.lang.Float;

public class Poll
{
	private String _author;
	private GregorianCalendar _dt;
	public HashMap<PartitoEnum,Float> _percentages;
	
	public Poll()
	{
		_author = new String();
		_dt = new GregorianCalendar();
		_percentages = new HashMap<PartitoEnum,Float>();
	}
	
	public String getAuthor()
	{
		return _author;
	}
	
	public void setAuthor(String _author)
	{
		this._author = _author;
	}
	
	public GregorianCalendar getDt()
	{
		return _dt;
	}
	
	public void setDt(GregorianCalendar _dt)
	{
		this._dt = _dt;
	}

	public HashMap<PartitoEnum, Float> getPercentages()
	{
		return _percentages;
	}
	
	public void setPercentages(HashMap<PartitoEnum, Float> _percentages)
	{
		this._percentages = _percentages;
	}
}
