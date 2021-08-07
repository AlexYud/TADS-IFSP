package projetolp1a3;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

@SuppressWarnings("serial")
public class Matriz extends JFrame implements ActionListener {
	
	JButton bVoltar = new JButton("Voltar");
	JLabel label = new JLabel("matriz");
	
	ArrayList<Voo> voos;
	
	@Override
	public void actionPerformed(ActionEvent e) {
		dispose();
	}

	public Matriz(Voo voo) {
		
		setTitle("Consulta lugares reservados");
	
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setLayout(new FlowLayout(1, 50, 50));
		
		setResizable(true);
		setVisible(true);
		
		String x = " -----";
		for(int linha = 0 ; linha < voo.getAeronave().lin ; linha++){
            for(int coluna = 0; coluna < voo.getAeronave().col ; coluna++){
            	if (coluna < voo.getAeronave().col && linha == 0) {
            		int col = coluna;
                    	x += "---" + col;
            	} else {
            		if (voo.getAeronave().lugares[linha][coluna] == null) {
                		x += " [--]";
                	} else {
                		x += " [X]";
                	}
            	}
            }
            int lin = linha;
            if (lin < voo.getAeronave().lin - 1) {
            	x += "<br> | " + lin + " -- ";
            }
            
        }
		String td = "<html>" + x + "</html>";
		label.setText(td);
		
		bVoltar.setBounds(75, 200, 150, 75);
		
		add(label);
		add(bVoltar);

		bVoltar.addActionListener(this);
		
		pack();
	}	
}
