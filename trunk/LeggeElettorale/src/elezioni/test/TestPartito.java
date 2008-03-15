package elezioni.test;

import static org.junit.Assert.*;
import org.junit.Test;

import elezioni.Circoscrizione;
import elezioni.Lista;
import elezioni.Parlamentare;
import elezioni.Partito;
import elezioni.Premier;


import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;

public class TestPartito 
{
	@Test
	public void test()
	{
		Premier veltroni = new Premier("Walter", "Veltroni");
		Partito pd = new Partito("Partito Democratico", veltroni);
		Circoscrizione umbria1 = new Circoscrizione("Umbria1");
		Circoscrizione marche1 = new Circoscrizione("Marche1");
		Circoscrizione toscana1 = new Circoscrizione("Toscana1");
		Circoscrizione toscana2 = new Circoscrizione("Toscana2");
		Lista listaUmbria1Pd = new Lista();
		listaUmbria1Pd.add(new Parlamentare("Fabio", "Lombardelli"));
		Lista listaMarche1Pd = new Lista();
		listaUmbria1Pd.add(new Parlamentare("Guido", "Ranzuglia"));
		Lista listaToscana1Pd = new Lista();
		listaUmbria1Pd.add(new Parlamentare("Massimo", "Ceccherini"));
		Lista listaToscana2Pd = new Lista();
		listaUmbria1Pd.add(new Parlamentare("Alessandro", "Paci"));
		
		pd.addToCamera(umbria1, listaUmbria1Pd);
		pd.addToCamera(marche1, listaMarche1Pd);
		pd.addToCamera(toscana1, listaToscana1Pd);
		pd.addToCamera(toscana2, listaToscana2Pd);
		
		assertEquals(pd.getListeCamera(umbria1), listaUmbria1Pd);
	}

	
	public static ArrayList<String> scanSingleLine(String line)
	{
//		String line = "GIPIEFFE_SPA;14-03-2008;PD:33.3;IDV:2.3;SA:6.8;PDL:40.6;LEGA:5.3;MPA:0.1;UDC:7.4;DX:1.9;SOC:0.9;";
		Pattern patternInfo = Pattern.compile("(\\w+);(\\d+)-(\\d+)-(\\d+);(.*)");
		Pattern patternVoti = Pattern.compile("(\\w+):(.*?);");
		Matcher matcher = patternInfo.matcher(line);
		ArrayList<String> list = new ArrayList<String>();
		if (matcher.matches())
		{
			
			list.add(matcher.group(1));
			list.add(matcher.group(2));
			list.add(matcher.group(3));
			list.add(matcher.group(4));
			Matcher matchVoti = patternVoti.matcher(matcher.group(5));
			while (matchVoti.find())
			{
				list.add(matchVoti.group(1));
				list.add(matchVoti.group(2));
			}
		}
		return list;
	}
	
//	public static 
}
