package projetolp1a3;

import java.awt.event.*;
import java.util.ArrayList;

import javax.swing.*;

@SuppressWarnings("serial")
public class ParametrosDoSistema extends JFrame implements ActionListener {
	
	JButton bCadAeronave = new JButton("Cadastrar Aeronave");
	JButton bCadVoo = new JButton("Cadastrar Voo");
	JButton bVoltar = new JButton("Voltar");
	
	MenuPrincipal menu;
	ArrayList<Aviao> aeronaves = new ArrayList<Aviao>();
	CadastroVoo cadVoo;
	
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == bCadAeronave) {
			try {
				String modelo = JOptionPane.showInputDialog("Informe o modelo do Avião");
				int lin = Integer.parseInt(JOptionPane.showInputDialog("Informe a quantidade de fileiras"));
				int col = Integer.parseInt(JOptionPane.showInputDialog("Informe a quantidade de colunas"));
				aeronaves.add(new Aviao(modelo, lin+1, col));
				JOptionPane.showMessageDialog(null, "Avião cadastrado com sucesso!");
			} catch (Exception err) {
				JOptionPane.showMessageDialog(null, err);
			}
		} else if (e.getSource() == bCadVoo) {
			try {
				if (!this.aeronaves.isEmpty()) {
					if (this.cadVoo == null) {
						this.cadVoo = new CadastroVoo(aeronaves);
					} else {
						cadVoo.setAeronaves(aeronaves);
						cadVoo.setVisible(true);
					}
				} else {
					JOptionPane.showMessageDialog(null, "Nenhum avião cadastrado!");
				}
			} catch (Exception err) {
				JOptionPane.showMessageDialog(null, err);
			}
		} else {
			try {
				if (this.cadVoo != null) {
					menu.setAeronaves(aeronaves);
					menu.setVoos(cadVoo.getVoos());
					menu.setParametrosDoSistema(this);
					menu.setVisible(true);
					setVisible(false);
				} else {
					menu.setParametrosDoSistema(this);
					menu.setVisible(true);
					setVisible(false);
				}
			} catch (Exception err) {
				JOptionPane.showMessageDialog(null, err);
			}
		}
	}
	
	public ParametrosDoSistema(MenuPrincipal menu) {
		
		setTitle("Parâmetros do sistema");
		setSize(500, 400);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setResizable(false);
		setVisible(true);
		
		setLayout(null);
		bCadAeronave.setBounds(150, 50, 200, 60);
		bCadVoo.setBounds(150, 150, 200, 60);
		bVoltar.setBounds(200, 250, 100, 60);
		add(bCadAeronave);
		add(bCadVoo);
		add(bVoltar);
		
		bCadAeronave.addActionListener(this);
		bCadVoo.addActionListener(this);
		bVoltar.addActionListener(this);
		
		this.menu = menu;
	}
	
}
