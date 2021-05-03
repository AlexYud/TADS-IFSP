package lista1item4;

public class Pessoa {
	
	private String nome;
	private int idade;
	private String pai;
	private String mae;
	
	public Pessoa(String nome, int idade, String pai, String mae) {
		super();
		this.nome = nome;
		this.idade = idade;
		this.pai = pai;
		this.mae = mae;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public int getIdade() {
		return idade;
	}
	
	public void setIdade(int idade) {
		this.idade = idade;
	}
	
	public String getPai() {
		return pai;
	}
	
	public void setPai(String pai) {
		this.pai = pai;
	}
	
	public String getMae() {
		return mae;
	}
	
	public void setMae(String mae) {
		this.mae = mae;
	}
	
	@Override
	public String toString() {
		return "Pessoa [nome=" + nome + ", idade=" + idade + ", pai=" + pai + ", mae=" + mae + "]";
	}
	
}
