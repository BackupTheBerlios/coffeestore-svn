package elezioni.test;

import static org.junit.Assert.*;
import org.junit.Test;

import elezioni.Circoscrizione;
import elezioni.Lista;
import elezioni.Parlamentare;
import elezioni.Partito;
import elezioni.PartitoEnum;
import elezioni.Premier;

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
		
		String pdl = "PDL";
		
		PartitoEnum d = PartitoEnum.valueOf(pdl);
		assertEquals(PartitoEnum.PDL, d);
	}
}
