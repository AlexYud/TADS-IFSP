package projetolp1a3;

import java.awt.event.*;
import java.util.ArrayList;

import javax.swing.*;

@SuppressWarnings("serial")
public class MenuPrincipal extends JFrame implements ActionListener{
	
	JButton bParametros = new JButton("Parâmetros do Sistema");
	JButton bReserva = new JButton("Reserva de Passagens");
	JButton bSair = new JButton("Sair");
	
	ParametrosDoSistema parametros;
	ReservaDePassagens reserva;
	ArrayList<Aviao> aeronaves;
	ArrayList<Voo> voos;
	
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == bParametros) {
			try {
				if (this.parametros == null) {
					ParametrosDoSistema p = new ParametrosDoSistema(this);
					this.parametros = p;
				} else {
					parametros.setVisible(true);
				}
				setVisible(false);
			} catch (Exception ex) {
				JOptionPane.showMessageDialog(null, ex);
			}
		} else if (e.getSource() == bReserva) {
			try {
				if (this.reserva == null) {
					ReservaDePassagens r = new ReservaDePassagens(this, aeronaves, voos);
					this.reserva = r;
				} else {
					reserva.setAeronaves(aeronaves);
					reserva.setVoos(voos);
					reserva.setVisible(true);
				}
				setVisible(false);
			} catch (Exception ex) {
				JOptionPane.showMessageDialog(null, ex);
			}
		} else {
			if (JOptionPane.showConfirmDialog(bSair, "Deseja mesmo sair?") == 0) {
				System.exit(0);
			}
		}
	}
	
	public MenuPrincipal() {
		
		setTitle("Reserva de Passagens aéreas");
		setSize(500, 400);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setResizable(false);
		setVisible(true);
		
		setLayout(null);
		bParametros.setBounds(150, 50, 200, 60);
		bReserva.setBounds(150, 150, 200, 60);
		bSair.setBounds(200, 250, 100, 60);
		add(bParametros);
		add(bReserva);
		add(bSair);
		
		bParametros.addActionListener(this);
		bReserva.addActionListener(this);
		bSair.addActionListener(this);
	}
	
	public void setParametrosDoSistema(ParametrosDoSistema p) {
		this.parametros = p;
	}
	
	public void setReservaDePassagens(ReservaDePassagens r) {
		this.reserva = r;
	}
	
	public void setAeronaves(ArrayList<Aviao> aeronaves) {
		this.aeronaves = aeronaves;
	}
	
	public void setVoos(ArrayList<Voo> voos) {
		this.voos = voos;
	}
}
