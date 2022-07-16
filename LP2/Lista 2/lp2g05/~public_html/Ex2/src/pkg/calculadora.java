package pkg;

import javax.swing.ButtonGroup;
import javax.swing.JApplet;
import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JRadioButton;
import javax.swing.JScrollBar;

import javax.swing.JTextPane;

import java.awt.Color;
import java.awt.Component;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JSlider;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;
import javax.swing.JPanel;
import java.awt.FlowLayout;
import javax.swing.JOptionPane;
import javax.swing.event.AncestorListener;
import javax.swing.event.AncestorEvent;

public class calculadora extends JApplet {
	private JTextField text_altura;
	double peso, altura, imc;
    String sexo,valor;
    JLabel ResulLabel = new JLabel("Resultado:");
    JSlider slPeso = new JSlider();
    JLabel lbPeso = new JLabel("New label");
    
   
	/**
	 * Create the applet.
	 */
	public calculadora() 
	{
	
		JButton btcalcular = new JButton("calcular");
		btcalcular.setBounds(24, 226, 114, 25);
		btcalcular.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				try
				{
					altura = Double.parseDouble(text_altura.getText());
				}
				catch(Exception f)
				{
					JOptionPane.showConfirmDialog(null, "Insira um valor valido para a altura","Erro",JOptionPane.ERROR_MESSAGE);
					altura = -1;
				}
				if(peso ==0 || altura == 0)
				{
					JOptionPane.showConfirmDialog(null, "O peso e a altura devem ser diferentes de 0","Erro",JOptionPane.ERROR_MESSAGE);
				}
				
				else 
				{
					imc = peso/(altura*altura);
					if("h".equals(sexo));
					{
						if(imc < 20.7)
						{
							
							ResulLabel.setForeground(Color.green);
							ResulLabel.setText("abaixo do peso ideal");
						}
						
						else if((imc >20.7) && (imc <26.4))
						{
							ResulLabel.setForeground(Color.red);
							ResulLabel.setText("Peso ideal");
						}
						
						else if(imc >26.4)
						{
							ResulLabel.setForeground(Color.green);
							ResulLabel.setText("Acima do peso ideal");
						}
					}
					 if("m".equals(sexo));
						{
							if(imc<19)
							{
								ResulLabel.setForeground(Color.green);
								ResulLabel.setText("abaixo do peso ideal");
							}
							else if((imc>19) && (imc <25.8))
							{
								ResulLabel.setForeground(Color.red);
								ResulLabel.setText("Peso ideal");
							}
						
							else if(imc > 25.8)
							{
								ResulLabel.setForeground(Color.green);
								ResulLabel.setText("Acima do peso ideal");
							}
						}
						if(sexo!="h" && sexo!="m")
						{
							JOptionPane.showConfirmDialog(null, "O sexo deve ser selecionado para o calculo do IMC","Erro",JOptionPane.ERROR_MESSAGE);
						}
				}
				
				
				
			}
		});
		getContentPane().setLayout(null);
		getContentPane().add(btcalcular);
		
		JRadioButton radiohomem = new JRadioButton("Homem");
		radiohomem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				sexo = "h";
			}
		});
		radiohomem.setBounds(14, 103, 77, 25);
		getContentPane().add(radiohomem);
		
		JRadioButton radiomulher = new JRadioButton("Mulher");
		radiomulher.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				sexo = "m";
			}
		});
		radiomulher.setBounds(101, 104, 98, 23);
		getContentPane().add(radiomulher);
		ButtonGroup bg = new ButtonGroup();
		bg.add(radiomulher);
		bg.add(radiohomem);
		
		
		JTextPane txtpnPeso = new JTextPane();
		txtpnPeso.setFont(new Font("Dialog", Font.BOLD, 15));
		txtpnPeso.setText("Peso");
		txtpnPeso.setBounds(381, 12, 57, 21);
		getContentPane().add(txtpnPeso);
		
		text_altura = new JTextField();
		text_altura.setBounds(22, 171, 114, 19);
		getContentPane().add(text_altura);
		text_altura.setColumns(10);
		
		JTextPane txtpnAltura = new JTextPane();
		txtpnAltura.setFont(new Font("Dialog", Font.BOLD, 15));
		txtpnAltura.setText("Altura");
		txtpnAltura.setBounds(24, 140, 68, 21);
		getContentPane().add(txtpnAltura);
		
		JLabel lb_IMC = new JLabel("IMC");
		lb_IMC.setFont(new Font("Dialog", Font.BOLD, 15));
		lb_IMC.setBounds(179, 216, 124, 15);
		getContentPane().add(lb_IMC);
		JTextPane text = new JTextPane();
		text.setFont(new Font("Dialog", Font.BOLD, 15));
		text.setText("Sexo");
		text.setBounds(14, 74, 77, 21);
		getContentPane().add(text);
		slPeso.addChangeListener(new ChangeListener() 
		{
			public void stateChanged(ChangeEvent e) 
			{
				peso = (double) slPeso.getValue()/10;
				String valor_peso = Double.toString(peso);
				lbPeso.setText(valor_peso);
			}
		});
		slPeso.setBounds(399, 36, 39, 158);
		getContentPane().add(slPeso);
		slPeso.setMaximum(2000);
		slPeso.setOrientation(javax.swing.JSlider.VERTICAL);
		slPeso.setToolTipText("Peso (KG)");
		slPeso.setValue(600);
		slPeso.setAlignmentX(1.0F);
		slPeso.setAlignmentY(1.0F);
		slPeso.setBorder(new javax.swing.border.MatteBorder(null));
		
		
		lbPeso.setBounds(368, 206, 70, 15);
		getContentPane().add(lbPeso);
		
		JButton btnNewButton = new JButton("Limpar");
		btnNewButton.setBounds(22, 263, 117, 25);
		getContentPane().add(btnNewButton);
		
		
		ResulLabel.addAncestorListener(new AncestorListener() {
			public void ancestorAdded(AncestorEvent event) {
			}
			public void ancestorMoved(AncestorEvent event) {
			}
			public void ancestorRemoved(AncestorEvent event) {
			}
		});
		ResulLabel.setFont(new Font("Dialog", Font.BOLD, 15));
		ResulLabel.setBounds(179, 243, 148, 15);
		getContentPane().add(ResulLabel);
		
		JLabel lblNewLabel_1 = new JLabel("New label");
		lblNewLabel_1.setBounds(201, 12, 70, 15);
		getContentPane().add(lblNewLabel_1);

	}
}