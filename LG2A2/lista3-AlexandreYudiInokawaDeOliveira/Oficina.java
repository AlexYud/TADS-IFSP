package lista3;

import java.util.ArrayList;
import java.util.List;

public class Oficina {
	
	//private List<OrdemDeServico> ordensServico;
	private ArrayList<OrdemDeServico> ordensServico = new ArrayList<OrdemDeServico>();

	public Oficina() {
		super();
	}

	public void adicionaOS(OrdemDeServico os) {
		ordensServico.add(os);
	}
	
	public OrdemDeServico buscaOSCodigo(int codigo) {
		for (OrdemDeServico Ordem : ordensServico) {
			if (Ordem.getCodigo() == codigo) {
				return Ordem;
			}
		}
		return null;
	}
	
	public OrdemDeServico buscaOSServico(int codigo) {
		for (OrdemDeServico ordemDeServico : ordensServico) {
			for (Servico Servico : ordemDeServico.getServicos()) {
				if (Servico.getCodigo() == codigo) {
					return ordemDeServico;
				}
			}
		}
		return null;
	}
	
	public List<Servico> buscaOSCliente(String cpf) {
		for (OrdemDeServico ordemDeServico : ordensServico) {
			if (ordemDeServico.getCliente().getCpf().equals(cpf)) {
				return ordemDeServico.getServicos();
			}
		}
		return null;
	}
	
	public double calculaFaturamentoTotal() {
		double total = 0;
		for (OrdemDeServico ordemDeServico : ordensServico) {
			for (Servico Servico : ordemDeServico.getServicos()) {
				total += Servico.getValor();
			}
		}
		return total;
	}

	public ArrayList<OrdemDeServico> getOrdensServico() {
		return ordensServico;
	}

	public void setOrdensServico(ArrayList<OrdemDeServico> ordensServico) {
		this.ordensServico = ordensServico;
	}

	@Override
	public String toString() {
		return "Oficina []";
	}
	
}
