package unidade1;

public class Pessoa {

	private String nome;
	private int dataNascimento;
	private float altura;
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public int getDataNascimento() {
		return this.dataNascimento;
	}
	
	public void setDataNascimento(int dataNascimento) {
		this.dataNascimento = dataNascimento;
	}
	
	public float getAltura() {
		return this.altura;
	}
	
	public void setAltura(float altura) {
		this.altura = altura;
	}
	
	public static void exibirDados(Pessoa pessoa1) {
		System.out.println(pessoa1.getNome() + " " + pessoa1.getDataNascimento() + " " + pessoa1.getAltura());
	}
	
	public static void calcularIdade(Pessoa pessoa1) {
		int Idade = 2020 - pessoa1.dataNascimento; 
		System.out.println("Idade da pessoa: " + Idade);
	}

	
	public static void main(String[] args) {
		
		Pessoa pessoa1 = new Pessoa();
		
		pessoa1.setNome("Pedro");
		pessoa1.setDataNascimento(1998);
		pessoa1.setAltura((float) 1.80);
		
		exibirDados(pessoa1);
		calcularIdade(pessoa1);
	}
	
}
