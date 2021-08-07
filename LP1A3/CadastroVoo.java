package projetolp1a3;

import java.awt.FlowLayout;
import java.awt.event.*;
import java.util.ArrayList;

import javax.swing.*;

@SuppressWarnings("serial")
public class CadastroVoo extends JFrame implements ActionListener {
	
	JButton bVoltar = new JButton("Voltar");
	JLabel lavioes = new JLabel("Aviões Cadastrados:");
	
	ArrayList<Aviao> aeronaves;
	JComboBox<String> cmbAeronaveList;
	ArrayList<Voo> voos = new ArrayList<Voo>();

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == cmbAeronaveList) {
			try {
				int numero = Integer.parseInt(JOptionPane.showInputDialog("Informe o número do voo"));
				String data = JOptionPane.showInputDialog("Informe a data do voo");
				String hora = JOptionPane.showInputDialog("Informe a hora do voo");
				String modelo = (String) cmbAeronaveList.getSelectedItem();
				for (Aviao aviao : aeronaves) {
					if(aviao.modelo == modelo) {
						voos.add(new Voo(aviao, numero, data, hora));
					} 
				}
				JOptionPane.showMessageDialog(null, "Voo cadastrado com sucesso!");
				setVisible(false);
			} catch (Exception err) {
				JOptionPane.showMessageDialog(null, err);
				setVisible(false);
			}
		} else {
			setVisible(false);
		}
	}
	
	public CadastroVoo(ArrayList<Aviao> aeronaves) {
		
		String[] lista = new String[aeronaves.size()];
		int i = 0;
		for (Aviao x : aeronaves) {
			lista[i] = x.modelo;
			i++;
		}
		cmbAeronaveList = new JComboBox<String>(lista);
		
		setTitle("Cadastro do Voo");
	
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout(1, 50, 50));
		
		setResizable(true);
		setVisible(true);
		
		bVoltar.setBounds(75, 200, 150, 75);
		
		add(lavioes);
		add(cmbAeronaveList);
		add(bVoltar);

		cmbAeronaveList.addActionListener(this);
		bVoltar.addActionListener(this);
		
		this.aeronaves = aeronaves;
		pack();
	}
	
	
	public ArrayList<Aviao> getAeronaves() {
		return aeronaves;
	}

	public void setAeronaves(ArrayList<Aviao> aeronaves) {
		this.aeronaves = aeronaves;
	}

	public ArrayList<Voo> getVoos() {
		return voos;
	}

	public void setVoos(ArrayList<Voo> voos) {
		this.voos = voos;
	}
	
}

