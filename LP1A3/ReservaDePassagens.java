package projetolp1a3;

import java.awt.event.*;
import java.util.ArrayList;

import javax.swing.*;

@SuppressWarnings("serial")
public class ReservaDePassagens extends JFrame implements ActionListener {
	
	JButton bFzrReserv = new JButton("Fazer reserva");
	JButton bConsultLug = new JButton("Consultar lugares vazios");
	JButton bConsultReserv = new JButton("Consultar reservas realizadas");
	JButton bVoltar = new JButton("Voltar");
	
	MenuPrincipal menu;
	ArrayList<Aviao> aeronaves;
	ArrayList<Voo> voos;
	FazerReserva reserva;
	
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == bFzrReserv) {
			try {
				if (this.voos != null) {
					if (this.reserva == null) {
						FazerReserva reserva = new FazerReserva(voos, this);
						this.reserva = reserva;
					} else {
						reserva.setVisible(true);
					}
				} else {
					JOptionPane.showMessageDialog(null, "Nenhum voo cadastrado!");
				}
			} catch(Exception err) {
				JOptionPane.showMessageDialog(null, err);
				dispose();
			}
		} else if (e.getSource() == bConsultLug) {
			try {
				new ConsultaLugar(voos);
			} catch(Exception err) {
				JOptionPane.showMessageDialog(null, err);
			}
		} else if (e.getSource() == bConsultReserv) {
			try {
				new ConsultaLugReservado(voos);
			} catch(Exception err) {
				JOptionPane.showMessageDialog(null, err);
			}
		} else {
			try {
				menu.setReservaDePassagens(this);
				menu.setVisible(true);
				setVisible(false);
			} catch (Exception err) {
				JOptionPane.showMessageDialog(null, err);
			}
		}	
	}
	
	public ReservaDePassagens(MenuPrincipal menu, ArrayList<Aviao> aeronaves, ArrayList<Voo> voos) {
		
		setTitle("Parâmetros do sistema");
		setSize(600, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setResizable(false);
		setVisible(true);
		
		setLayout(null);
		bFzrReserv.setBounds(175, 50, 225, 60);
		bConsultLug.setBounds(175, 150, 225, 60);
		bConsultReserv.setBounds(175, 250, 225, 60);
		bVoltar.setBounds(220, 350, 125, 60);
		add(bFzrReserv);
		add(bConsultLug);
		add(bConsultReserv);
		add(bVoltar);
		
		bFzrReserv.addActionListener(this);
		bConsultLug.addActionListener(this);
		bConsultReserv.addActionListener(this);
		bVoltar.addActionListener(this);
		
		this.menu = menu;
		this.aeronaves = aeronaves;
		this.voos = voos;
	}
	
	public void setAeronaves(ArrayList<Aviao> aeronaves) {
		this.aeronaves = aeronaves;
	}
	
	public void setVoos(ArrayList<Voo> voos) {
		this.voos = voos;
	}
}
