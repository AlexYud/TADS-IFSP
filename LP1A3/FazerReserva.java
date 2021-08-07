package projetolp1a3;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

@SuppressWarnings("serial")
public class FazerReserva extends JFrame implements ActionListener {
	
	JButton bVoltar = new JButton("Voltar");
	JLabel lvoo = new JLabel("Escolha o voo (nº):");
	
	ArrayList<Aviao> aeronaves;
	ArrayList<Voo> voos;
	JComboBox<Integer> cmbVooList;
	ReservaDePassagens reservaP;
	
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == cmbVooList) {
			try {
				int vooNumero = (Integer) cmbVooList.getSelectedItem();
				for (Voo voo : voos) {
					if(voo.getNro() == vooNumero) {
						if(voo.getAeronave().verificaQntdLugares() == voo.getAeronave().verificaQntdLugaresOcup()) {
							JOptionPane.showMessageDialog(null, "Todos os lugares estão ocupados!");
							dispose();
						} else {
							String nome = JOptionPane.showInputDialog("Informe o nome do passageio");
							String cpf = JOptionPane.showInputDialog("Informe o CPF do passageiro");
							int lin = Integer.parseInt(JOptionPane.showInputDialog("Informe a fileira do assento"));
							int col = Integer.parseInt(JOptionPane.showInputDialog("Informe a coluna do assento"));
							
							if (voo.getAeronave().verificaLugarOcupado(lin+1, col)) {
								JOptionPane.showMessageDialog(null, "Lugar Ocupado!");
								int lin2 = Integer.parseInt(JOptionPane.showInputDialog("Informe novamente a fileira do assento"));
								int col2 = Integer.parseInt(JOptionPane.showInputDialog("Informe novamente a coluna do assento"));
								voo.getAeronave().setPassageiro(lin2+1, col2, new Passageiro(nome, cpf));
								reservaP.setAeronaves(aeronaves);
								reservaP.setVoos(voos);
								JOptionPane.showMessageDialog(null, "Reserva concluída!");
								setVisible(false);
							} else {
								voo.getAeronave().setPassageiro(lin+1, col, new Passageiro(nome, cpf));
								reservaP.setAeronaves(aeronaves);
								reservaP.setVoos(voos);
								JOptionPane.showMessageDialog(null, "Reserva concluída!");
								setVisible(false);
							}
						}
					} 
				}
			} catch (Exception err) {
				JOptionPane.showMessageDialog(null, err);
				dispose();
			}
		} else {
			dispose();
		}
	}

	public FazerReserva(ArrayList<Voo> voos, ReservaDePassagens reservaP) {
		
		Integer[] lista = new Integer[voos.size()];
		int i = 0;
		for (Voo x : voos) {
			lista[i] = x.getNro();
			i++;
		}
		cmbVooList = new JComboBox<Integer>(lista);
		
		setTitle("Cadastro do Voo");
	
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout(1, 50, 50));
		
		setResizable(true);
		setVisible(true);
		
		bVoltar.setBounds(75, 200, 150, 75);
		
		add(lvoo);
		add(cmbVooList);
		add(bVoltar);

		cmbVooList.addActionListener(this);
		bVoltar.addActionListener(this);
		
		this.voos = voos;
		this.reservaP = reservaP;
		pack();
	}	
}
