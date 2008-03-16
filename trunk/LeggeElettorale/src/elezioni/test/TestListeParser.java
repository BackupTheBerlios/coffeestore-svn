package elezioni.test;

import static org.junit.Assert.*;

import java.io.File;
import java.io.IOException;
import java.util.Map;

import org.junit.Test;

import elezioni.Circoscrizione;
import elezioni.Lista;
import elezioni.ListeParser;
import elezioni.Parlamentare;
import elezioni.Partito;
import elezioni.PartitoEnum;
import elezioni.PartitiParser;
import elezioni.Regione;
import elezioni.RegioneEnum;

public class TestListeParser
{
	@Test
	public void testParseAllFiles() throws IOException
	{
		ListeParser parser = new ListeParser();
		
		File directory = new File("varie/listecandidati/src");
		for (File file : directory.listFiles())
		{
			String fileName = file.getName();
			if (!fileName.equals(".svn"))
			{
				parseRegione(parser, file.getAbsolutePath());
			}
		}
	}

	@Test
	public void test() throws IOException
	{
		PartitiParser parser = new PartitiParser();
		parser.parse();
		Partito pd = parser.getPartiti().get(PartitoEnum.PD);
		System.out.println(pd.getName());
		Regione regione = parser.getRegioni().get(RegioneEnum.Lazio);
		int i = 0;
		for (Circoscrizione circoscrizione : regione.getCircscrizioni())
		{
			if (i < 2)
			{
				Lista lista = pd.getListeCamera(circoscrizione);
				assertNotNull(lista);
				
				for (Parlamentare parlamentare : lista.getCandidati())
				{
					System.out.println(parlamentare.getNome() + " " + parlamentare.getCognome());
				}
			}
			else
			{
				Lista lista = pd.getListeSenato(circoscrizione);
				assertNotNull(lista);
				
				for (Parlamentare parlamentare : lista.getCandidati())
				{
					System.out.println(parlamentare.getNome() + " " + parlamentare.getCognome());
				}
			}
			
			i++;
		}
	}
	
	private void parseRegione(ListeParser parser, String regione) throws IOException
	{
		Map<PartitoEnum, Lista> liste = parser.parseListeCircoscrizione(regione);
		for (PartitoEnum partito : liste.keySet())
		{
			Lista lista = liste.get(partito);
		}
	}
}
