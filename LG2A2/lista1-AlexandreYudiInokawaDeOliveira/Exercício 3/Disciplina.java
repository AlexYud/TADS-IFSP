package lista1item3;

public class Disciplina {
	
	private String matricula;
	private String nome;
	private double p1;
	private double p2;
	private double trab;
	
	public Disciplina(String matricula, String nome, double p1, double p2, double trab) {
		super();
		this.matricula = matricula;
		this.nome = nome;
		this.p1 = p1;
		this.p2 = p2;
		this.trab = trab;
	}
	
	public double calculoMedia(double p1, double p2, double trab) {
		double media = (p1 + p2 + trab)/3;
		return media;
	}
	
	public String situacao(double media) {
		if (media >= 6) {
			String txt = "Aluno aprovado!";
			return txt;
		} else {
			String txt = "Aluno reprovado!";
			return txt;
		}
	}

	public String getMatricula() {
		return matricula;
	}

	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getP1() {
		return p1;
	}

	public void setP1(double p1) {
		this.p1 = p1;
	}

	public double getP2() {
		return p2;
	}

	public void setP2(double p2) {
		this.p2 = p2;
	}

	public double getTrab() {
		return trab;
	}

	public void setTrab(double trab) {
		this.trab = trab;
	}

	@Override
	public String toString() {
		return "Disciplina [matricula=" + matricula + ", nome=" + nome + ", p1=" + p1 + ", p2=" + p2 + ", trab=" + trab
				+ "]";
	}
	
}
