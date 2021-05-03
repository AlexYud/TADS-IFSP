package lista3;

public class Principal {

	public static void main(String[] args) {
		
		Oficina oficina = new Oficina();
		
		Mecanico mecanico1 = new Mecanico("Funileiro", "837.636.160-04", "Lucas");
		Mecanico mecanico2 = new Mecanico("Pintura", "531.316.837-03", "Amanda");
		Mecanico mecanico3 = new Mecanico("Motor", "767.326.420-01", "Regina");
		Mecanico mecanico4 = new Mecanico("Freios", "132.588.580-04", "Roberto");
		
		Servico servico1 = new Servico(2, "Consertar rádio", 150);
		Servico servico2 = new Servico(4, "Trocar peça do motor", 500.75);
		Servico servico3 = new Servico(7, "Lavar carro", 80);
		
		Cliente cliente1 = new Cliente("1111-2222", "235.856.950-00", "Joao");
		Cliente cliente2 = new Cliente("3333-4444", "207.973.050-92", "Pedro");
		Cliente cliente3 = new Cliente("5555-6666", "041.659.750-52", "Paulo");
		
		OrdemDeServico ordem1 = new OrdemDeServico(205, cliente1);
		ordem1.adicionaMecanico(mecanico1);
		ordem1.adicionaServico(servico1);
		ordem1.adicionaServico(servico2);
		ordem1.adicionaServico(servico3);
		
		OrdemDeServico ordem2 = new OrdemDeServico(524, cliente2);
		ordem2.adicionaMecanico(mecanico2);
		ordem2.adicionaServico(servico1);
		ordem2.adicionaServico(servico2);
		
		OrdemDeServico ordem3 = new OrdemDeServico(62, cliente3);
		ordem3.adicionaMecanico(mecanico3);
		ordem3.adicionaServico(servico1);
		ordem3.adicionaServico(servico3);
		
		OrdemDeServico ordem4 = new OrdemDeServico(99, cliente3);
		ordem4.adicionaMecanico(mecanico4);
		ordem4.adicionaServico(servico2);
		ordem4.adicionaServico(servico3);
		
		oficina.adicionaOS(ordem1);
		oficina.adicionaOS(ordem2);
		oficina.adicionaOS(ordem3);
		oficina.adicionaOS(ordem4);
		
		//Tests
		
		System.out.println("\n 1) Busque uma OrdemDeServico por código na Oficina e imprima o cálculo de seu valor total. R$: " + oficina.buscaOSCodigo(62).calculaValorTotal());
		
		System.out.println("\n 2) Busque uma lista de OrdemDeServico por CPF na Oficina e a imprima. " + oficina.buscaOSCliente("041.659.750-52"));
		
		System.out.println("\n 3) Busque uma lista de OrdemDeServico por Serviço na Oficina e a imprima. " + oficina.buscaOSServico(2));
		
		System.out.println("\n 4) Imprima o faturamento total da oficina. R$: " + oficina.calculaFaturamentoTotal());
	}

}
