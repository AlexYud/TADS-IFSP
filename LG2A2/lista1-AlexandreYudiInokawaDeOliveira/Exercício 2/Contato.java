package lista1;

public class Contato {
	
	private String nome;
	private String numero;
	private String endereco;

	public Contato(String nome, String numero, String endereco) {
		super();
		this.nome = nome;
		this.numero = numero;
		this.endereco = endereco;
	}

	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getEndereco() {
		return endereco;
	}
	
	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}
	
	public String getNumero() {
		return numero;
	}

	public void setNumero(String numero) {
		this.numero = numero;
	}

	@Override
	public String toString() {
		return "Contato [nome=" + nome + ", numero=" + numero + ", endereco=" + endereco + "]";
	}

}
