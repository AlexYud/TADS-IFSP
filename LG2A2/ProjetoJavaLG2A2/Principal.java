package ProjetoLG2A2;

import java.math.BigDecimal;

public class Principal {

	public static void main(String[] args) {
		
		MovMes mes2 = new MovMes(1, 2);
		
		MovDia dia21 = new MovDia(1, 21, 2);
		// Transa��es dia 21/2
		Transacao trans1 = new Transacao(1212, (new BigDecimal("7.50")), 21, 2, "Caf�-da-manh�", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.DINHEIRO);
		Transacao trans2 = new Transacao(2212, (new BigDecimal("29.90")), 21, 2, "Almo�o", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.CART�O_DE_D�BITO);
		Transacao trans3 = new Transacao(3212, (new BigDecimal("4.40")), 21, 2, "Metr�", Tipo.DESPESA, Categoria.TRANSPORTE, Modalidade.FIXA, Conta.DINHEIRO);
		Transacao trans4 = new Transacao(4212, (new BigDecimal("289.99")), 21, 2, "Viol�o", Tipo.DESPESA, Categoria.PESSOAL, Modalidade.INDIVIDUAL, Conta.CART�O_DE_CR�DITO);
		Transacao trans5 = new Transacao(5212, (new BigDecimal("250")), 21, 2, "Prateleiras", Tipo.DESPESA, Categoria.RESID�NCIA, Modalidade.INDIVIDUAL, Conta.CART�O_DE_CR�DITO);
		Transacao trans6 = new Transacao(6212, (new BigDecimal("4.40")), 21, 2, "Metr�", Tipo.DESPESA, Categoria.TRANSPORTE, Modalidade.FIXA, Conta.DINHEIRO);
		Transacao trans7 = new Transacao(7212, (new BigDecimal("19.90")), 21, 2, "Janta", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.CART�O_DE_D�BITO);
		// Adicionando transa��es ao dia
		dia21.addTrans(trans1);
		dia21.addTrans(trans2);
		dia21.addTrans(trans3);
		dia21.addTrans(trans4);
		dia21.addTrans(trans5);
		dia21.addTrans(trans6);
		dia21.addTrans(trans7);
		// Alguns m�todos do dia 
		System.out.println(dia21.relatorioCategoriaDia());
		System.out.println(dia21.relatorioModalidadeDia());
		System.out.println(dia21.relatorioContaDia());
		System.out.println(dia21.projecaoDia());
		// Adicionando dia ao m�s
		mes2.addMovDia(dia21);
		
		MovDia dia22 = new MovDia(2, 22, 2);
		// Transa��es dia 22/2
		Transacao trans8 = new Transacao(1222, (new BigDecimal("7.50")), 22, 2, "Caf�-da-manh�", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.DINHEIRO);
		Transacao trans9 = new Transacao(2222, (new BigDecimal("29.90")), 22, 2, "Almo�o", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.CART�O_DE_D�BITO);
		Transacao trans10 = new Transacao(3222, (new BigDecimal("4.40")), 22, 2, "Metr�", Tipo.DESPESA, Categoria.TRANSPORTE, Modalidade.FIXA, Conta.DINHEIRO);
		Transacao trans11 = new Transacao(4222, (new BigDecimal("73.50")), 22, 2, "Farm�cia", Tipo.DESPESA, Categoria.PESSOAL, Modalidade.INDIVIDUAL, Conta.CART�O_DE_D�BITO);
		Transacao trans12 = new Transacao(5222, (new BigDecimal("10.90")), 22, 2, "Misto quente", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.INDIVIDUAL, Conta.CART�O_DE_D�BITO);
		Transacao trans13 = new Transacao(6222, (new BigDecimal("4.40")), 22, 2, "Metr�", Tipo.DESPESA, Categoria.TRANSPORTE, Modalidade.FIXA, Conta.DINHEIRO);
		Transacao trans14 = new Transacao(7222, (new BigDecimal("39.90")), 22, 2, "Janta", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.CART�O_DE_D�BITO);
		// Adicionando transa��es ao dia
		dia22.addTrans(trans8);
		dia22.addTrans(trans9);
		dia22.addTrans(trans10);
		dia22.addTrans(trans11);
		dia22.addTrans(trans12);
		dia22.addTrans(trans13);
		dia22.addTrans(trans14);
		// Alguns m�todos do dia 
		System.out.println(dia22.relatorioCategoriaDia());
		System.out.println(dia22.relatorioModalidadeDia());
		System.out.println(dia22.relatorioContaDia());
		System.out.println(dia22.projecaoDia());
		// Adicionando dia ao m�s
		mes2.addMovDia(dia22);
		
		MovDia dia23 = new MovDia(2, 23, 2);
		// Transa��es dia 23/2
		Transacao trans15 = new Transacao(1232, (new BigDecimal("9.50")), 23, 2, "Caf�-da-manh�", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.DINHEIRO);
		Transacao trans16 = new Transacao(2232, (new BigDecimal("29.90")), 23, 2, "Almo�o", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.CART�O_DE_D�BITO);
		Transacao trans17 = new Transacao(3232, (new BigDecimal("4.40")), 23, 2, "Metr�", Tipo.DESPESA, Categoria.TRANSPORTE, Modalidade.FIXA, Conta.DINHEIRO);
		Transacao trans18 = new Transacao(4232, (new BigDecimal("300.00")), 23, 2, "Receita investimento", Tipo.RECEITA, Categoria.PESSOAL, Modalidade.INDIVIDUAL, Conta.ITAU);
		Transacao trans19 = new Transacao(5232, (new BigDecimal("300.00")), 23, 2, "Curso de programa��o", Tipo.DESPESA, Categoria.PESSOAL, Modalidade.INDIVIDUAL, Conta.ITAU);
		Transacao trans20 = new Transacao(6232, (new BigDecimal("24.40")), 23, 2, "Uber", Tipo.DESPESA, Categoria.TRANSPORTE, Modalidade.INDIVIDUAL, Conta.DINHEIRO);
		Transacao trans21 = new Transacao(7232, (new BigDecimal("29.90")), 23, 2, "Janta", Tipo.DESPESA, Categoria.ALIMENTA��O, Modalidade.FIXA, Conta.DINHEIRO);
		// Adicionando transa��es ao dia
		dia23.addTrans(trans15);
		dia23.addTrans(trans16);
		dia23.addTrans(trans17);
		dia23.addTrans(trans18);
		dia23.addTrans(trans19);
		dia23.addTrans(trans20);
		dia23.addTrans(trans21);
		// Alguns m�todos do dia 
		System.out.println(dia23.relatorioCategoriaDia());
		System.out.println(dia23.relatorioModalidadeDia());
		System.out.println(dia23.relatorioContaDia());
		System.out.println(dia23.projecaoDia());
		// Adicionando dia ao m�s
		mes2.addMovDia(dia23);
		
		// Alguns m�todos do m�s
		System.out.println(mes2.relatorioCategoriaMes());
		System.out.println(mes2.relatorioModalidadeMes());
		System.out.println(mes2.relatorioContaMes());
		System.out.println(mes2.projecaoMes());
	}

}
