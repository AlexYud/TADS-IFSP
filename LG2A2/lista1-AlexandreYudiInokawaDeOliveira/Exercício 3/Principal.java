package lista1item3;

public class Principal {

	public static void main(String[] args) {
		
		Disciplina aluno1 = new Disciplina("SP3032492", "Julia", 7.5, 5, 8.5);
		Disciplina aluno2 = new Disciplina("SP3421492", "Lucas", 9, 7, 9.5);
		Disciplina aluno3 = new Disciplina("SP3642492", "Roberto", 3, 1, 6.5);
		
		System.out.println("\n Aluno1: " + aluno1.toString());
		System.out.println(" Média: " + aluno1.calculoMedia(aluno1.getP1(), aluno1.getP2(), aluno1.getTrab()));
		System.out.println(" Situação: " + aluno1.situacao(aluno1.calculoMedia(aluno1.getP1(), aluno1.getP2(), aluno1.getTrab())));
		
		System.out.println("\n Aluno2: " + aluno2.toString());
		System.out.println(" Média: " + aluno2.calculoMedia(aluno2.getP1(), aluno2.getP2(), aluno2.getTrab()));
		System.out.println(" Situação: " + aluno2.situacao(aluno2.calculoMedia(aluno2.getP1(), aluno2.getP2(), aluno2.getTrab())));
		
		System.out.println("\n Aluno3: " + aluno3.toString());
		System.out.println(" Média: " + aluno3.calculoMedia(aluno3.getP1(), aluno3.getP2(), aluno3.getTrab()));
		System.out.println(" Situação: " + aluno3.situacao(aluno3.calculoMedia(aluno3.getP1(), aluno3.getP2(), aluno3.getTrab())));
		}

}
