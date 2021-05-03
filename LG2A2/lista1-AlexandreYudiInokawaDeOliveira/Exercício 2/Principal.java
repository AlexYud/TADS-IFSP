package lista1;

public class Principal {

	public static void main(String[] args) {
		
		Agenda agenda = new Agenda();
		
		Contato contato1 = new Contato("Amanda", "1111-1111", "Rua 1, numero 1");
		Contato contato2 = new Contato("Beatriz", "2222-2222", "Rua 2, numero 2");
		Contato contato3 = new Contato("Carlos", "3333-3333", "Rua 3, numero 3");
		Contato contato4 = new Contato("Daniel", "4444-4444", "Rua 4, numero 4");
		Contato contato5 = new Contato("Elaine", "5555-5555", "Rua 5, numero 5");
		Contato contato6 = new Contato("Fernanda", "6666-6666", "Rua 6, numero 6");
		Contato contato7 = new Contato("Gabriel", "7777-7777", "Rua 7, numero 7");
		
		agenda.adicionaContato(contato1);
		agenda.adicionaContato(contato2);
		agenda.adicionaContato(contato3);
		agenda.adicionaContato(contato4);
		agenda.adicionaContato(contato5);
		agenda.adicionaContato(contato6);
		agenda.adicionaContato(contato7);
		
		System.out.println(agenda.mostrarContatos());

	}

}
