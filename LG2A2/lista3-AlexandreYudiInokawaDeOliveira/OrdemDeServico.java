package lista3;

import java.util.ArrayList;

public class OrdemDeServico {
	
	private int codigo;
	private Cliente cliente;
	//private List<Servico> servicos;
	//private List<Mecanico> mecanicos;
	private ArrayList<Mecanico> mecanicos = new ArrayList<Mecanico>();
	private ArrayList<Servico> servicos = new ArrayList<Servico>();
	
	
	public OrdemDeServico(int codigo, Cliente cliente) {
		super();
		this.codigo = codigo;
		this.cliente = cliente;
	}
	
	public void adicionaServico(Servico servico) {
		servicos.add(servico);
	}
	
	public void adicionaMecanico(Mecanico mecanico) {
		mecanicos.add(mecanico);
	}
	
	public double calculaValorTotal() {
		double total = 0;
		for (Servico Servico : servicos) {
			total += Servico.getValor();
		}
		return total;
	}
	
	public boolean possuiServico(int codigo) {
		for (Servico Servico : servicos) {
			if (Servico.getCodigo() == codigo) {
				return true;
			}
		}
		return false;
	}
	
	public boolean possuiMecanico(String cpf) {
		for (Mecanico Mecanico : mecanicos) {
			if (Mecanico.getCpf().equals(cpf)) {
				return true;
			}
		}
		return false;
	}

	public int getCodigo() {
		return codigo;
	}

	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}

	public Cliente getCliente() {
		return cliente;
	}

	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}

	public ArrayList<Mecanico> getMecanicos() {
		return mecanicos;
	}

	public void setMecanicos(ArrayList<Mecanico> mecanicos) {
		this.mecanicos = mecanicos;
	}

	public ArrayList<Servico> getServicos() {
		return servicos;
	}

	public void setServicos(ArrayList<Servico> servicos) {
		this.servicos = servicos;
	}

	@Override
	public String toString() {
		return "OrdemDeServico [codigo=" + codigo + ", cliente=" + cliente + "]";
	}
	
}
