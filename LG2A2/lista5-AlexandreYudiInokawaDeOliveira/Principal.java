package revisao;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		
		Scanner entrada = new Scanner(System.in);
		System.out.println("Digite a Sigla:");
		String sigla = entrada.next();
		Turma t1 = new Turma(sigla, "ADS");
		System.out.println(t1.toString());
		
		Professor p = new Professor("Johnata", "Mestre", 111);
		System.out.println(p.toString());

		System.out.println("Alunos: "+Aluno.qtdAluno);
		Aluno a = new Aluno("John", t1);
		Aluno b = new Aluno("Fulano", t1);
		System.out.println(b.toString());
		System.out.println("Alunos: "+Aluno.qtdAluno);
		
		Disciplina d = new Disciplina("LG2A2", p);
		System.out.println(d.toString());
		
		Avaliacao av = new Avaliacao(10, d, b);
		System.out.println(av.toString());
	}

}
