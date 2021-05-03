package lista1;

import java.util.ArrayList;

public class Agenda {
	
	private ArrayList<Contato> contatos = new ArrayList<Contato>();
	
	public void adicionaContato(Contato contato) {
		contatos.add(contato);
	}
	
	public ArrayList<Contato> mostrarContatos() {
		return contatos;
	}

	public ArrayList<Contato> getContatos() {
		return contatos;
	}

	public void setContatos(ArrayList<Contato> contatos) {
		this.contatos = contatos;
	}

	@Override
	public String toString() {
		return "Agenda [contatos=" + contatos + "]";
	}
}
