package lista2;

import java.math.BigDecimal;
import java.time.LocalDateTime;

public class Principal {

	public static void main(String[] args) {
		
		LocalDateTime ldt = LocalDateTime.now();
		BigDecimal valor = new BigDecimal("7.50");
		String desc = "Café-da-manhã";
		Transacao trans = Transacao.DESPESA;
		Categoria cat = Categoria.ALIMENTAÇÃO;
		Tipo tipo = Tipo.FIXA;
		
		LocalDateTime ldt2 = LocalDateTime.now();
		BigDecimal valor2 = new BigDecimal("150");
		String desc2 = "Abastecimento de gasolina semanal";
		Transacao trans2 = Transacao.DESPESA;
		Categoria cat2 = Categoria.CARRO;
		Tipo tipo2 = Tipo.FIXA;
		
		LocalDateTime ldt3 = LocalDateTime.now();
		BigDecimal valor3 = new BigDecimal("400");
		String desc3 = "Vendi minha bicicleta para um amigo";
		Transacao trans3 = Transacao.RECEITA;
		Categoria cat3 = Categoria.REVENDA;
		Tipo tipo3 = Tipo.INDIVIDUAL;
		
		LocalDateTime ldt4 = LocalDateTime.now();
		BigDecimal valor4 = new BigDecimal("2.500");
		String desc4 = "Comprei um notebook para trabalhos da faculdade";
		Transacao trans4 = Transacao.DESPESA;
		Categoria cat4 = Categoria.PESSOAL;
		Tipo tipo4 = Tipo.INDIVIDUAL;
		
		Orcamento cafe = new Orcamento(ldt, valor, desc, trans, cat, tipo);
		Orcamento gasolina = new Orcamento(ldt2, valor2, desc2, trans2, cat2, tipo2);
		Orcamento bicicleta = new Orcamento(ldt3, valor3, desc3, trans3, cat3, tipo3);
		Orcamento notebook = new Orcamento(ldt4, valor4, desc4, trans4, cat4, tipo4);
		
		System.out.println(cafe.toString());
		System.out.println(gasolina.toString());
		System.out.println(bicicleta.toString());
		System.out.println(notebook.toString());
		
	}

}
