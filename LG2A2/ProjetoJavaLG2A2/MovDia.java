package ProjetoLG2A2;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;

public class MovDia {

	private int id;
	private int dia;
	private int mes;
	private ArrayList<Transacao> transacoes = new ArrayList<Transacao>();
	
	public MovDia(int id, int dia, int mes) {
		super();
		this.id = id;
		this.dia = dia;
		this.mes = mes;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
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

	public ArrayList<Transacao> getTransacoes() {
		return transacoes;
	}

	public void setTransacoes(ArrayList<Transacao> transacoes) {
		this.transacoes = transacoes;
	}

	@Override
	public String toString() {
		return "MovDia [id=" + id + ", dia=" + dia + ", mes=" + mes + ", transacoes=" + transacoes + "]";
	}
	
	public void addTrans(Transacao trans) {
		transacoes.add(trans);
	}
	
	public void removeTrans(int id) {
		transacoes.remove(id);
	}
	
	public Transacao buscaTrans(int id) {
		for (Transacao Transacao : transacoes) {
			if (Transacao.getId() == id) {
				return Transacao;
			}
		}
		return null;
	}
	
	public String relatorioCategoriaDia() {
		BigDecimal zero = new BigDecimal("0");
		BigDecimal total = zero;
		BigDecimal tAlimentacao = zero;
		BigDecimal tTransporte = zero;
		BigDecimal tResidencia = zero;
		BigDecimal tInvestimento = zero;
		BigDecimal tPessoal = zero;
		
		BigDecimal cem = new BigDecimal("100");
		
		for (Transacao Transacao : transacoes) {
			if (Transacao.getTipo().equals(Tipo.DESPESA)) {
				total = total.add(Transacao.getValor());
				
				if (Transacao.getCategoria().equals(Categoria.ALIMENTAÇÃO)) {
					tAlimentacao = tAlimentacao.add(Transacao.getValor());
				}
				if (Transacao.getCategoria().equals(Categoria.TRANSPORTE)) {
					tTransporte = tTransporte.add(Transacao.getValor());
				}
				if (Transacao.getCategoria().equals(Categoria.RESIDÊNCIA)) {
					tResidencia = tResidencia.add(Transacao.getValor());
				}
				if (Transacao.getCategoria().equals(Categoria.INVESTIMENTO)) {
					tInvestimento = tInvestimento.add(Transacao.getValor());
				}
				if (Transacao.getCategoria().equals(Categoria.PESSOAL)) {
					tPessoal = tPessoal.add(Transacao.getValor());
				}
			}
			
		}
		
		BigDecimal porcentAlimentacao = tAlimentacao.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentTransporte = tTransporte.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentResidencia = tResidencia.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentInvestimento = tInvestimento.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentPessoal = tPessoal.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		
		return ("\n -- Relatório Categoria --" 
				+ "\n Despesa total do dia " + dia + "/" + mes + ": R$ " + total 
				+ "\n Total gasto Alimentação: R$ " + tAlimentacao + " (" + porcentAlimentacao + "%)"
				+ "\n Total gasto Transporte: R$ " + tTransporte + " (" + porcentTransporte + "%)"
				+ "\n Total gasto Residência: R$ " + tResidencia + " (" + porcentResidencia + "%)"
				+ "\n Total gasto Investimento: R$ " + tInvestimento + " (" + porcentInvestimento + "%)"
				+ "\n Total gasto Pessoal: R$ " + tPessoal + " (" + porcentPessoal + "%)"
				);
	}
	
	public String relatorioModalidadeDia() {
		BigDecimal zero = new BigDecimal("0");
		BigDecimal total = zero;
		BigDecimal tFix = zero;
		BigDecimal tInd = zero;
		BigDecimal cem = new BigDecimal("100");
		
		for (Transacao Transacao : transacoes) {
			total = total.add(Transacao.getValor());
			if (Transacao.getModalidade().equals(Modalidade.FIXA)) {
				tFix = tFix.add(Transacao.getValor());
			} else {
				tInd = tInd.add(Transacao.getValor());
			}
		}
		
		BigDecimal porcentFix = tFix.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentInd = tInd.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		
		return ("\n -- Relatório Modalidade --" 
				+ "\n Despesa total do dia " + dia + "/" + mes + ": R$ " + total 
				+ "\n Total gasto FIXA: R$ " + tFix + " (" + porcentFix + "%)"
				+ "\n Total gasto INDIVIDUAL: R$ " + tInd + " (" + porcentInd + "%)"
				);
	}
	
	public String relatorioContaDia() {
		BigDecimal zero = new BigDecimal("0");
		BigDecimal total = zero;
		BigDecimal tItau = zero;
		BigDecimal tBradesco = zero;
		BigDecimal tSantander = zero;
		BigDecimal tCarteira = zero;
		BigDecimal tCaixa = zero;
		BigDecimal tCartCred = zero;
		BigDecimal tCartDeb = zero;
		BigDecimal tDinheiro = zero;
		
		BigDecimal cem = new BigDecimal("100");
		
		for (Transacao Transacao : transacoes) {
			if (Transacao.getTipo().equals(Tipo.DESPESA)) {
				total = total.add(Transacao.getValor());
				
				if (Transacao.getConta().equals(Conta.ITAU)) {
					tItau = tItau.add(Transacao.getValor());
				}
				if (Transacao.getConta().equals(Conta.BRADESCO)) {
					tBradesco = tBradesco.add(Transacao.getValor());
				}
				if (Transacao.getConta().equals(Conta.SANTANDER)) {
					tSantander = tSantander.add(Transacao.getValor());
				}
				if (Transacao.getConta().equals(Conta.CARTEIRA)) {
					tCarteira = tCarteira.add(Transacao.getValor());
				}
				if (Transacao.getConta().equals(Conta.CAIXA)) {
					tCaixa = tCaixa.add(Transacao.getValor());
				}
				if (Transacao.getConta().equals(Conta.CARTÃO_DE_CRÉDITO)) {
					tCartCred = tCartCred.add(Transacao.getValor());
				}
				if (Transacao.getConta().equals(Conta.CARTÃO_DE_DÉBITO)) {
					tCartDeb = tCartDeb.add(Transacao.getValor());
				}
				if (Transacao.getConta().equals(Conta.DINHEIRO)) {
					tDinheiro = tDinheiro.add(Transacao.getValor());
				}
			}
		}
		
		BigDecimal porcentItau = tItau.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentBradesco = tBradesco.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentSantander = tSantander.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentCarteira = tCarteira.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentCaixa = tCaixa.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentCartCred = tCartCred.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentCartDeb = tCartDeb.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentDinheiro = tDinheiro.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		
		return ("\n -- Relatório Conta --" 
				+ "\n Despesa total do dia " + dia + "/" + mes + ": R$ " + total 
				+ "\n Total gasto Itaú: R$ " + tItau + " (" + porcentItau + "%)"
				+ "\n Total gasto Bradesco: R$ " + tBradesco + " (" + porcentBradesco + "%)"
				+ "\n Total gasto Santander: R$ " + tSantander + " (" + porcentSantander + "%)"
				+ "\n Total gasto Carteira: R$ " + tCarteira + " (" + porcentCarteira + "%)"
				+ "\n Total gasto Caixa: R$ " + tCaixa + " (" + porcentCaixa + "%)"
				+ "\n Total gasto Cartão de crédito: R$ " + tCartCred + " (" + porcentCartCred + "%)"
				+ "\n Total gasto Cartão de débito: R$ " + tCartDeb + " (" + porcentCartDeb + "%)"
				+ "\n Total gasto Dinheiro: R$ " + tDinheiro + " (" + porcentDinheiro + "%)"
				);
	}
	
	public String projecaoDia() {
		
		BigDecimal zero = new BigDecimal("0");
		BigDecimal total = zero;
		BigDecimal totalInd = zero;
		BigDecimal totalFix = zero;
		BigDecimal totalDiasRestantes = zero;
		int dias = 0;
		int diasRestantes = 0;
		
		for (Transacao Transacao : transacoes) {
			if (Transacao.getTipo().equals(Tipo.DESPESA)) {
				total = total.add(Transacao.getValor());
				if (Transacao.getModalidade().equals(Modalidade.FIXA)) {
					totalFix = totalFix.add(Transacao.getValor());
				}
			}
		}
		
		totalInd = total.subtract(totalFix);
		
		if (mes <= 7) {
			if (mes % 2 != 0) {
				dias = dias + 31;
			} else {
				if (mes == 2) {
					dias = dias + 28;
				} else {
					dias = dias + 30;
				}
			}
		} else {
			if (mes % 2 == 0) {
				dias = dias + 31;
			} else {
				dias = dias + 30;
			}
		}
		
		diasRestantes = dias - dia;
		totalDiasRestantes = (new BigDecimal(diasRestantes)).multiply(totalFix);
		
		return ("\n -- Projeção Dia -- " +
				"\n Despesa do dia " + dia + "/" + mes +
				"\n Total : R$ " + total +
				"\n Transações INDIVIDUAIS : R$ " + totalInd +
				"\n Transações FIXAS : R$ " + totalFix +
				"\n Dias restantes até o fim do mês: " + diasRestantes +
				"\n Projeção do restante do mês com apenas FIXAS: R$ " + totalDiasRestantes			
				);
	}
}
