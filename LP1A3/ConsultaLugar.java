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
public class ConsultaLugar extends JFrame implements ActionListener {
	
	JButton bVoltar = new JButton("Voltar");
	JLabel lvoo = new JLabel("Escolha o voo (nº):");
	
	ArrayList<Aviao> aeronaves;
	ArrayList<Voo> voos;
	JComboBox<Integer> cmbVooList;
	
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == cmbVooList) {
			try {
				int vooNumero = (Integer) cmbVooList.getSelectedItem();
				for (Voo voo : voos) {
					if(voo.getNro() == vooNumero) {
						int lugaresDisp = voo.getAeronave().verificaQntdLugares() - voo.getAeronave().verificaQntdLugaresOcup();
						JOptionPane.showMessageDialog(null, "Existem " + lugaresDisp + " lugar(es) disponíveis nesse voo. ");
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

	public ConsultaLugar(ArrayList<Voo> voos) {
		
		Integer[] lista = new Integer[voos.size()];
		int i = 0;
		for (Voo x : voos) {
			lista[i] = x.getNro();
			i++;
		}
		cmbVooList = new JComboBox<Integer>(lista);
		
		setTitle("Consulta lugares disponiveis");
	
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
		pack();
	}	
}