package lista1item6;

public class Principal {

	public static void main(String[] args) {
		
		Tempo tempo0 = new Tempo(0);
		Tempo tempo1 = new Tempo(15, 50, 9);
		Tempo tempo2 = new Tempo(2, 5, 10);
		Tempo tempo3 = new Tempo(8, 12, 10);
		
		// 00:00:00
		System.out.println(tempo0.imprimeHoras(tempo0));
		// imprime horas
		System.out.println(tempo1.imprimeHoras(tempo1));
		// somar tempo2 e tempo3
		tempo1 = tempo1.somarObj(tempo2, tempo3);
		System.out.println(tempo1.imprimeHoras(tempo1));
		// subtrair tempo3 e tempo2
		tempo1 = tempo1.subtrairObj(tempo3, tempo2);
		System.out.println(tempo1.imprimeHoras(tempo1));
	}

}
