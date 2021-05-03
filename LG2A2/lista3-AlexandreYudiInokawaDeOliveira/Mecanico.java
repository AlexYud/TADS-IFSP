package lista3;

public class Mecanico extends Pessoa {
	
	private String especialidade;
	
	public Mecanico(String especialidade, String cpf, String nome) {
		super(cpf, nome);
		this.especialidade = especialidade;
	}

	public String getEspecialidade() {
		return especialidade;
	}

	public void setEspecialidade(String especialidade) {
		this.especialidade = especialidade;
	}

	@Override
	public String toString() {
		return "Mecanico [especialidade=" + especialidade + "]";
	}
	
}
