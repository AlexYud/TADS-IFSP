package lista2item5;

public class Principal {

	public static void main(String[] args) {
		
		Data data = new Data(18, 4, 2021);
		
		System.out.println(data.imprimeData(data));
		System.out.println(data.qntDeDias(data.getMes()));
	}

}
