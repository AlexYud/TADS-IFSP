package lista1item6;

public class Tempo {
	
	private int s;
	private int m;
	private int h;
	
	public Tempo(int s, int m, int h) {
		super();
		this.s = s;
		this.m = m;
		this.h = h;
	}
	
	public Tempo(int t) {
		super();
		this.s = t;
		this.m = t;
		this.h = t;
	}

	public int getS() {
		return s;
	}

	public void setS(int s) {
		this.s = s;
	}

	public int getM() {
		return m;
	}

	public void setM(int m) {
		this.m = m;
	}

	public int getH() {
		return h;
	}

	public void setH(int h) {
		this.h = h;
	}
	
	public String imprimeHoras(Tempo tempo) {
		String hor, min, seg;
		
		if (tempo.getH() < 10) {
			hor = 0 + "" + tempo.getH();
		} else {
			hor = "" + tempo.getH();
		}
		
		if (tempo.getM() < 10) {
			min = 0 + "" + tempo.getM();
		} else {
			min = "" + tempo.getM();
		}
		
		if (tempo.getS() < 10) {
			seg = 0 + "" + tempo.getS();
		} else {
			seg = "" + tempo.getS();
		}
		
		return hor + ":" + min + ":" + seg;
	}
	
	public Tempo subtrairObj(Tempo tempo1, Tempo tempo2) {
		int hn, mn, sn;
		hn = tempo1.getH() - tempo2.getH();
		mn = tempo1.getM() - tempo2.getM();
		sn = tempo1.getS() - tempo2.getS();
		Tempo temponovo = new Tempo(sn, mn, hn);
		return temponovo;
	}
	
	public Tempo somarObj(Tempo tempo1, Tempo tempo2) {
		int hn, mn, sn;
		hn = tempo1.getH() + tempo2.getH();
		mn = tempo1.getM() + tempo2.getM();
		sn = tempo1.getS() + tempo2.getS();
		Tempo temponovo = new Tempo(sn, mn, hn);
		return temponovo;
	}

	@Override
	public String toString() {
		return "Tempo [s=" + s + ", m=" + m + ", h=" + h + "]";
	}
	
	
}
