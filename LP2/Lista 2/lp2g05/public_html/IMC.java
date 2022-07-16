import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import java.awt.event.*;
import java.awt.*;
public class IMC extends JApplet {
	private static final long serialVersionUID = 1L;
	private JTextField text_altura;
	double peso, altura , imc;
    String sexo,valor;
    JLabel Result = new JLabel("Resposta: ");
    JSlider slPeso = new JSlider();
    JLabel lbPeso = new JLabel("IMC");
	public IMC() 
	{
		JButton botaoCalcular = new JButton("Calcular");
		botaoCalcular.setBounds(24, 226, 114, 25);
		botaoCalcular.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent e) 
			{
				try
				{
					altura = Double.parseDouble(text_altura.getText());
				}
				catch(Exception e1)
				{
					JOptionPane.showConfirmDialog(null, "Insira um valor valido para a altura","Erro",JOptionPane.ERROR_MESSAGE);
					altura = -1;
				}
				if (peso > 0 || altura > 0)
				{
					imc = peso/(altura*altura);
					if("h".equals(sexo));
					{
						Homem ser = new Homem(null,null,peso,altura);
						if(imc < 20.7)
						{
							Result.setForeground(Color.blue);
							Result.setText(ser.resultIMC());
							Result.setText("abaixo do peso ideal");
						}
						else if((imc >20.7) && (imc <26.4))
						{
							Result.setForeground(Color.red);
							Result.setText(ser.resultIMC());
							Result.setText("Peso ideal");
						}
						else if(imc >26.4)
						{
							Result.setForeground(Color.green);
							Result.setText(ser.resultIMC());
							Result.setText("Acima do peso ideal");
						}
					}
				if("m".equals(sexo));
				{
					Mulher ser = new Mulher(null,null,peso,altura);
					if(imc<19)
					{
						Result.setForeground(Color.blue);
						Result.setText(ser.resultIMC());
						Result.setText("abaixo do peso ideal");
					}
					else if((imc>19) && (imc <25.8))
					{
						Result.setForeground(Color.red);
						Result.setText(ser.resultIMC());
						Result.setText("Peso ideal");
					}	
					else if(imc > 25.8)
					{
						Result.setForeground(Color.green);
						Result.setText(ser.resultIMC());
						Result.setText("Acima do peso ideal");
					}
				}
				if(sexo!="h" && sexo!="m")
				{
					JOptionPane.showConfirmDialog(null, "O sexo deve ser selecionado para o calculo do IMC","Erro",JOptionPane.ERROR_MESSAGE);
				}
				else
				{
					JOptionPane.showConfirmDialog(null, "O peso e a altura devem ser diferentes de 0","Erro",JOptionPane.ERROR_MESSAGE);
				}
			}
		}
	});
	getContentPane().setLayout(null);
	getContentPane().add(botaoCalcular);
	JRadioButton radiohomem = new JRadioButton("Homem");
	radiohomem.addActionListener(new ActionListener() 
	{
		public void actionPerformed(ActionEvent e) 
		{
			sexo = "h";
		}
	});
	radiohomem.setBounds(14, 103, 77, 25);
	getContentPane().add(radiohomem);
		
	JRadioButton radiomulher = new JRadioButton("Mulher");
	radiomulher.addActionListener(new ActionListener() 
	{
		public void actionPerformed(ActionEvent e) 
		{
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
	slPeso.addChangeListener(new ChangeListener() {
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
	lbPeso.setBounds(368, 306, 70, 15);
	getContentPane().add(lbPeso);
	lbPeso.setBounds(368, 206, 70, 15);
	getContentPane().add(lbPeso);
	JButton btnNewButton = new JButton("Limpar");
	btnNewButton.setBounds(22, 263, 117, 25);
	getContentPane().add(btnNewButton);
	Result.setFont(new Font("Dialog", Font.BOLD, 15));
	Result.setBounds(179, 243, 148, 15);
	getContentPane().add(Result);
	JLabel lblNewLabel_1 = new JLabel("IMC");
	lblNewLabel_1.setBounds(201, 12, 70, 15);
	getContentPane().add(lblNewLabel_1);
	}
}