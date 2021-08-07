package projetolp1a3;

public class Aviao extends Aeronave {

		public Passageiro[][] lugares;
		public int lin;
		public int col;

		public Aviao(String modelo, int lin, int col) {
			super(modelo);
			this.lugares = new Passageiro[lin][col];
			this.lin = lin;
			this.col = col;
		}

		public Passageiro getPassageiro(int lin, int col) {
			if (this.lugares[lin][col] != null) {
				Passageiro passageiro = this.lugares[lin][col];
				return passageiro;
			} else {
				return null;
			}
		}
		
		public void setPassageiro(int lin, int col, Passageiro passageiro) {
			this.lugares[lin][col] = passageiro;
		}
		
		public boolean verificaLugarOcupado(int lin, int col) {
			if (this.lugares[lin][col] != null) {
				return true;
			} else {
				return false;
			}
		}
		
		public int verificaQntdLugares() {
			int qntdLugares = 0;
			for(int linha = 0 ; linha < this.lin ; linha++){
                for(int coluna = 0; coluna < this.col ; coluna++){
                    qntdLugares++;
                }
            }
			return qntdLugares;
		}
		
		public int verificaQntdLugaresOcup() {
			int qntdLugaresOcup = 0;
			for(int linha = 0 ; linha < this.lin ; linha++){
                for(int coluna = 0; coluna < this.col ; coluna++){
                    if(lugares[linha][coluna] != null) {
                    	qntdLugaresOcup++;
                    }
                }
            }
			return qntdLugaresOcup;
		}
}
