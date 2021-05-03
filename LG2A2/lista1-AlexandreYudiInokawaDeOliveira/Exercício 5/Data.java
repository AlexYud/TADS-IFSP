package lista2item5;

public class Data {
	
	private int dia;
	private int mes;
	private int ano;
	
	public Data(int dia, int mes, int ano) {
		super();
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
	
	public int getDia() {
		return dia;
	}
	public void setDia(int dia) {
		this.dia = dia;
	}
	public int getMes() {
		return mes;
	}
	public void setMes(int mes) {
		this.mes = mes;
	}
	public int getAno() {
		return ano;
	}
	public void setAno(int ano) {
		this.ano = ano;
	}
	
	public String imprimeData(Data data) {
		int d = data.getDia();
		int m = data.getMes();
		int a = data.getAno();
		return(d + " / " + m + " / " + a);
	}
	
	public int qntDeDias(int mes) {
		int total = 0;
		for (int i=1; i<mes ;i++) {
			if (i <= 7) {
				if (i % 2 != 0) {
					total = total + 31;
				} else {
					if (i == 2) {
						total = total + 28;
					} else {
						total = total + 30;
					}
				}
			} else {
				if (i % 2 == 0) {
					total = total + 31;
				} else {
					total = total + 30;
				}
			}
		}
		return total;
	}
	
	@Override
	public String toString() {
		return "Data [dia=" + dia + ", mes=" + mes + ", ano=" + ano + "]";
	}
	
}
