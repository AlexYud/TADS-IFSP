package lista2;

import java.math.BigDecimal;
import java.time.LocalDateTime;

public class Orcamento {
	
	private LocalDateTime data;
	private BigDecimal valor;
	private String descricao;
	private Transacao transacao;
	private Categoria categoria;
	private Tipo tipo;
	
	public LocalDateTime getData() {
		return data;
	}

	public void setData(LocalDateTime data) {
		this.data = data;
	}

	public BigDecimal getValor() {
		return valor;
	}

	public void setValor(BigDecimal valor) {
		this.valor = valor;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public Transacao getTransacao() {
		return transacao;
	}

	public void setTransacao(Transacao transacao) {
		this.transacao = transacao;
	}

	public Categoria getCategoria() {
		return categoria;
	}

	public void setCategoria(Categoria categoria) {
		this.categoria = categoria;
	}

	public Tipo getTipo() {
		return tipo;
	}

	public void setTipo(Tipo tipo) {
		this.tipo = tipo;
	}
	
	public Orcamento(LocalDateTime data, BigDecimal valor, String descricao, Transacao transacao, Categoria categoria, Tipo tipo ) {
		this.setData(data);
		this.setValor(valor);
		this.setDescricao(descricao);
		this.setTransacao(transacao);
		this.setCategoria(categoria);
		this.setTipo(tipo);
	}
	
	@Override
	public String toString() {
		return " Data/Hora = " + data + " || VALOR: R$ " + valor + "\n Descricao = " + descricao + "\n Transacao = " + transacao + " || Categoria = " + categoria + " || Tipo = " + tipo + "\n";
	}
}
