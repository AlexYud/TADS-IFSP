package lista1item4;

public class Principal {

	public static void main(String[] args) {
		
		Pessoa pessoa1 = new Pessoa("Anakin Skywalker", 78, "Desconhecido", "Shmi Skywalker");
		Pessoa pessoa2 = new Pessoa("Luke Skywalker", 40, "Anakin Skywalker", "Padmé Amidala");
		Pessoa pessoa3 = new Pessoa("Leia Organa", 40, "Anakin Skywalker", "Padmé Amidala");
		Pessoa pessoa4 = new Pessoa("Ben Solo", 10, "Han Solo", "Leia Skywalker");
		
		System.out.println(pessoa1.toString());
		System.out.println(pessoa2.toString());
		System.out.println(pessoa3.toString());
		System.out.println(pessoa4.toString());
	}

}
