package ProjetoLG2A2;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;

public class MovMes {
	
	private int id;
	private int mes;
	private ArrayList<MovDia> movimentacoes = new ArrayList<MovDia>();
	
	public MovMes(int id, int mes) {
		super();
		this.id = id;
		this.mes = mes;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public int getMes() {
		return mes;
	}

	public void setMes(int mes) {
		this.mes = mes;
	}

	public ArrayList<MovDia> getMovimentacoes() {
		return movimentacoes;
	}

	public void setMovimentacoes(ArrayList<MovDia> movimentacoes) {
		this.movimentacoes = movimentacoes;
	}

	@Override
	public String toString() {
		return "MovMes [id=" + id + ", mes=" + mes + ", movimentacoes=" + movimentacoes + "]";
	}
	
	public void addMovDia(MovDia mov) {
		movimentacoes.add(mov);
	}
	
	public void removeMovDia(int id) {
		movimentacoes.remove(id);
	}
	
	public MovDia buscaMovDia(int id) {
		for (MovDia mov : movimentacoes) {
			if (mov.getId() == id) {
				return mov;
			}
		}
		return null;
	}
	
	public String relatorioCategoriaMes() {
		String mesString = null;
		BigDecimal zero = new BigDecimal("0");
		BigDecimal total = zero;
		BigDecimal tAlimentacao = zero;
		BigDecimal tTransporte = zero;
		BigDecimal tResidencia = zero;
		BigDecimal tInvestimento = zero;
		BigDecimal tPessoal = zero;
		
		BigDecimal cem = new BigDecimal("100");
		
		for (MovDia MovDia : movimentacoes) {
			for (Transacao Transacao : MovDia.getTransacoes()) {
				if (Transacao.getTipo().equals(Tipo.DESPESA)) {
					total = total.add(Transacao.getValor());
					
					if (Transacao.getCategoria().equals(Categoria.ALIMENTA��O)) {
						tAlimentacao = tAlimentacao.add(Transacao.getValor());
					}
					if (Transacao.getCategoria().equals(Categoria.TRANSPORTE)) {
						tTransporte = tTransporte.add(Transacao.getValor());
					}
					if (Transacao.getCategoria().equals(Categoria.RESID�NCIA)) {
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
		}
		
		BigDecimal porcentAlimentacao = tAlimentacao.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentTransporte = tTransporte.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentResidencia = tResidencia.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentInvestimento = tInvestimento.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentPessoal = tPessoal.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		
		switch (mes) {
			case 1:
				mesString = "Janeiro";
				break;
			case 2:
				mesString = "Fevereiro";
				break;
			case 3:
				mesString = "Mar�o";
				break;
			case 4:
				mesString = "Abril";
				break;
			case 5:
				mesString = "Maio";
				break;
			case 6:
				mesString = "Junho";
				break;
			case 7:
				mesString = "Julho";
				break;
			case 8:
				mesString = "Agosto";
				break;
			case 9:
				mesString = "Setembro";
				break;
			case 10:
				mesString = "Outubro";
				break;
			case 11:
				mesString = "Novembro";
				break;
			case 12:
				mesString = "Dezembro";
				break;
		}
		
		return ("\n -- Relat�rio Categoria --" 
				+ "\n Despesa total do m�s de " + mesString + ": R$ " + total 
				+ "\n Total gasto Alimenta��o: R$ " + tAlimentacao + " (" + porcentAlimentacao + "%)"
				+ "\n Total gasto Transporte: R$ " + tTransporte + " (" + porcentTransporte + "%)"
				+ "\n Total gasto Resid�ncia: R$ " + tResidencia + " (" + porcentResidencia + "%)"
				+ "\n Total gasto Investimento: R$ " + tInvestimento + " (" + porcentInvestimento + "%)"
				+ "\n Total gasto Pessoal: R$ " + tPessoal + " (" + porcentPessoal + "%)"
				);
	}
	
	public String relatorioModalidadeMes() {
		String mesString = null;
		BigDecimal zero = new BigDecimal("0");
		BigDecimal total = zero;
		BigDecimal tFix = zero;
		BigDecimal tInd = zero;
		BigDecimal cem = new BigDecimal("100");
		
		for (MovDia MovDia : movimentacoes) {
			for (Transacao Transacao : MovDia.getTransacoes()) {
				total = total.add(Transacao.getValor());
				if (Transacao.getModalidade().equals(Modalidade.FIXA)) {
					tFix = tFix.add(Transacao.getValor());
				} else {
					tInd = tInd.add(Transacao.getValor());
				}
			}
		}
		
		BigDecimal porcentFix = tFix.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		BigDecimal porcentInd = tInd.divide(total, 2, RoundingMode.HALF_UP).multiply(cem);
		
		switch (mes) {
		case 1:
			mesString = "Janeiro";
			break;
		case 2:
			mesString = "Fevereiro";
			break;
		case 3:
			mesString = "Mar�o";
			break;
		case 4:
			mesString = "Abril";
			break;
		case 5:
			mesString = "Maio";
			break;
		case 6:
			mesString = "Junho";
			break;
		case 7:
			mesString = "Julho";
			break;
		case 8:
			mesString = "Agosto";
			break;
		case 9:
			mesString = "Setembro";
			break;
		case 10:
			mesString = "Outubro";
			break;
		case 11:
			mesString = "Novembro";
			break;
		case 12:
			mesString = "Dezembro";
			break;
		}
		
		return ("\n -- Relat�rio Modalidade --" 
				+ "\n Despesa total do m�s de " + mesString + ": R$ " + total  
				+ "\n Total gasto FIXA: R$ " + tFix + " (" + porcentFix + "%)"
				+ "\n Total gasto INDIVIDUAL: R$ " + tInd + " (" + porcentInd + "%)"
				);
	}
	
	public String relatorioContaMes() {
		String mesString = null;
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
		
		for (MovDia MovDia : movimentacoes) {
			for (Transacao Transacao : MovDia.getTransacoes()) {
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
					if (Transacao.getConta().equals(Conta.CART�O_DE_CR�DITO)) {
						tCartCred = tCartCred.add(Transacao.getValor());
					}
					if (Transacao.getConta().equals(Conta.CART�O_DE_D�BITO)) {
						tCartDeb = tCartDeb.add(Transacao.getValor());
					}
					if (Transacao.getConta().equals(Conta.DINHEIRO)) {
						tDinheiro = tDinheiro.add(Transacao.getValor());
					}
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
		
		switch (mes) {
		case 1:
			mesString = "Janeiro";
			break;
		case 2:
			mesString = "Fevereiro";
			break;
		case 3:
			mesString = "Mar�o";
			break;
		case 4:
			mesString = "Abril";
			break;
		case 5:
			mesString = "Maio";
			break;
		case 6:
			mesString = "Junho";
			break;
		case 7:
			mesString = "Julho";
			break;
		case 8:
			mesString = "Agosto";
			break;
		case 9:
			mesString = "Setembro";
			break;
		case 10:
			mesString = "Outubro";
			break;
		case 11:
			mesString = "Novembro";
			break;
		case 12:
			mesString = "Dezembro";
			break;
		}
		
		return ("\n -- Relat�rio Conta --" 
				+ "\n Despesa total do m�s de " + mesString + ": R$ " + total 
				+ "\n Total gasto Ita�: R$ " + tItau + " (" + porcentItau + "%)"
				+ "\n Total gasto Bradesco: R$ " + tBradesco + " (" + porcentBradesco + "%)"
				+ "\n Total gasto Santander: R$ " + tSantander + " (" + porcentSantander + "%)"
				+ "\n Total gasto Carteira: R$ " + tCarteira + " (" + porcentCarteira + "%)"
				+ "\n Total gasto Caixa: R$ " + tCaixa + " (" + porcentCaixa + "%)"
				+ "\n Total gasto Cart�o de cr�dito: R$ " + tCartCred + " (" + porcentCartCred + "%)"
				+ "\n Total gasto Cart�o de d�bito: R$ " + tCartDeb + " (" + porcentCartDeb + "%)"
				+ "\n Total gasto Dinheiro: R$ " + tDinheiro + " (" + porcentDinheiro + "%)"
				);
	}
	
	public String projecaoMes() {
		String mesString = null;
		BigDecimal zero = new BigDecimal("0");
		BigDecimal totalDesp = zero;
		BigDecimal totalReceita = zero;
		BigDecimal totalInd = zero;
		BigDecimal totalFix = zero;
		BigDecimal totalMesesRestantes = zero;
		int mesesRestantes = 0;
		
		for (MovDia MovDia : movimentacoes) {
			for (Transacao Transacao : MovDia.getTransacoes()) {
				if (Transacao.getTipo().equals(Tipo.DESPESA)) {
					totalDesp = totalDesp.add(Transacao.getValor());
					if (Transacao.getModalidade().equals(Modalidade.INDIVIDUAL)) {
						totalInd = totalInd.add(Transacao.getValor());
					} else {
						totalFix = totalFix.add(Transacao.getValor());
					}
				} else {
					totalReceita = totalReceita.add(Transacao.getValor());
				}
			}
		}
		
		mesesRestantes = 12 - mes;
		totalMesesRestantes = new BigDecimal(mesesRestantes).multiply(totalFix);
		
		switch (mes) {
		case 1:
			mesString = "Janeiro";
			break;
		case 2:
			mesString = "Fevereiro";
			break;
		case 3:
			mesString = "Mar�o";
			break;
		case 4:
			mesString = "Abril";
			break;
		case 5:
			mesString = "Maio";
			break;
		case 6:
			mesString = "Junho";
			break;
		case 7:
			mesString = "Julho";
			break;
		case 8:
			mesString = "Agosto";
			break;
		case 9:
			mesString = "Setembro";
			break;
		case 10:
			mesString = "Outubro";
			break;
		case 11:
			mesString = "Novembro";
			break;
		case 12:
			mesString = "Dezembro";
			break;
		}
		
		return ("\n -- Proje��o M�s -- " +
				"\n Relat�rio do m�s de " + mesString +
				"\n Total Despesa : R$ " + totalDesp +
				"\n Total Receita : R$ " + totalReceita +
				"\n Transa��es INDIVIDUAIS : R$ " + totalInd +
				"\n Transa��es FIXAS : R$ " + totalFix +
				"\n Meses restantes at� o fim do ano: " + mesesRestantes +
				"\n Proje��o do restante do ano com apenas FIXAS: R$ " + totalMesesRestantes			
				);
	}
}
