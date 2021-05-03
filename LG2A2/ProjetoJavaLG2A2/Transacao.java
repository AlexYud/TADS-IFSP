package ProjetoLG2A2;

import java.math.BigDecimal;

public class Transacao {

	private int id;
	private BigDecimal valor;
	private int dia;
	private int mes;
	private String descricao;
	private Tipo tipo;
	private Categoria categoria;
	private Modalidade modalidade;
	private Conta conta;
	
	public Transacao(int id, BigDecimal valor, int dia, int mes, String descricao, Tipo tipo, Categoria categoria,
			Modalidade modalidade, Conta conta) {
		super();
		this.id = id;
		this.valor = valor;
		this.dia = dia;
		this.mes = mes;
		this.descricao = descricao;
		this.tipo = tipo;
		this.categoria = categoria;
		this.modalidade = modalidade;
		this.conta = conta;
	}
	
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public BigDecimal getValor() {
		return valor;
	}
	
	public void setValor(BigDecimal valor) {
		this.valor = valor;
	}
	
	public int getDia() {
		return dia;
	}
	
	public void setDia(int dia) {
		this.dia = dia;
	}
	
	public int getMes() {
		return mes;
	}
	
	public void setMes(int mes) {
		this.mes = mes;
	}
	
	public String getDescricao() {
		return descricao;
	}
	
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	
	public Tipo getTipo() {
		return tipo;
	}
	
	public void setTipo(Tipo tipo) {
		this.tipo = tipo;
	}
	
	public Categoria getCategoria() {
		return categoria;
	}
	
	public void setCategoria(Categoria categoria) {
		this.categoria = categoria;
	}
	
	public Modalidade getModalidade() {
		return modalidade;
	}
	
	public void setModalidade(Modalidade modalidade) {
		this.modalidade = modalidade;
	}
	
	public Conta getConta() {
		return conta;
	}
	
	public void setConta(Conta conta) {
		this.conta = conta;
	}

	@Override
	public String toString() {
		return "Transacao [id=" + id + ", valor=" + valor + ", dia=" + dia + ", mes=" + mes + ", descricao=" + descricao
				+ ", tipo=" + tipo + ", categoria=" + categoria + ", modalidade=" + modalidade + "]";
	}
	
}
