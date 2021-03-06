package revisao;

public abstract class Pessoa {
	
	private String nome;
	
	public abstract double calcRefeicao();

	public Pessoa(String nome) {
		super();
		this.nome = nome;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}
	
	@Override
	public String toString() {
		return "Pessoa [nome=" + nome + "]";
	}
	
	
}
