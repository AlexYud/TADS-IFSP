package revisao;

public class Aluno extends Pessoa implements Autenticacao{
	
	public static int qtdAluno = 0;
	
	private String rne;
	private int matricula;
	private Turma turma;
	private Situacao situacaoAcademica;
	
	// Aluno estrangeiro
	public Aluno(String nome, String rne, Turma turma) {
		super(nome);
		this.rne = rne;
		this.matricula = ++qtdAluno;
		this.turma = turma;
		this.situacaoAcademica = Situacao.MATRICULADO;
	}
	
	public Aluno(String nome, Turma turma) {
		super(nome);
		this.matricula = ++qtdAluno;
		this.turma = turma;
		this.situacaoAcademica = Situacao.MATRICULADO;
	}

	public static int getQtdAluno() {
		return qtdAluno;
	}

	public static void setQtdAluno(int qtdAluno) {
		Aluno.qtdAluno = qtdAluno;
	}

	public String getRne() {
		return rne;
	}

	public void setRne(String rne) {
		this.rne = rne;
	}

	public int getMatricula() {
		return matricula;
	}

	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}

	public Turma getTurma() {
		return turma;
	}

	public void setTurma(Turma turma) {
		this.turma = turma;
	}

	@Override
	public double calcRefeicao() {
		// TODO Auto-generated method stub
		return 5;
	}
	
	@Override
	public String toString() {
		return "Aluno [nome=" + super.getNome() + ", rne=" + rne + ", matricula=" + matricula +", situa??o="+ situacaoAcademica + ", turma=" + turma + "]";
	}
	
	@Override
	public void login(String user, String senha) {
	System.out.println("Bem-vindo aluno "+user);
	}

}
