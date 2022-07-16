package CalculoIMC;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import java.lang.Exception;
import java.awt.*;
import java.awt.event.*;

public class IMC extends JApplet implements ActionListener
{
	private static final long serialVersionUID = 1L;
	private double pesoP;
	private JTextField altura,nome,dataNasc,peso;
	String[] sexoString={"selecione","Masculino","Feminino"};
	private JComboBox sexSelection;
	private JLabel lbPeso = new JLabel("New label");
	private JTextArea resposta;
	private JSlider slPeso = new JSlider(JSlider.HORIZONTAL,
            PES_MIN, PES_MAX, PES_INIT);
	private Container c;
	private JPanel botaoPanel, botaoPanel2, p, p2;
	private JPanel textPanel1, textPanel2, textPanel3,textPanel4;
	private JButton calc, corrig;
	private JLabel t1, t2, t3, t4,result;
	private Font fonte, fonte2,fonte3;
	static final int PES_MIN = 0;
	static final int PES_MAX = 200;
	static final int PES_INIT = 100;
	
	public void init() 
	{
		fonte = new Font("Arial", Font.BOLD, 30);
		JLabel rotulo = new JLabel("Calculadora IMC");
		rotulo.setFont(fonte);
		botaoPanel = new JPanel();
		sexSelection = new JComboBox(sexoString);
		sexSelection.addActionListener(this);
		botaoPanel.add(new JLabel("Sexo:    "));
		botaoPanel.add(sexSelection);
		botaoPanel2 = new JPanel();
		calc = new JButton("Calcular");
		corrig = new JButton("Corrigir");
		botaoPanel2.add(calc);
		botaoPanel2.add(corrig);
		calc.addActionListener(this);
		corrig.addActionListener(this);
		t1 = new JLabel("Nome");
		nome = new JTextField(20);
		textPanel1 = new JPanel();
		textPanel1.add(t1);
		textPanel1.add(nome);
		nome.addActionListener(this);
		t2 = new JLabel("Data de nascimento");
		dataNasc = new JTextField(20);
		textPanel2 = new JPanel();
		textPanel2.add(t2);
		textPanel2.add(dataNasc);
		dataNasc.addActionListener(this);
		slPeso.setBounds(300, 236, 339, 358);
		getContentPane().add(slPeso);
		slPeso.setMaximum(200);
		slPeso.setMajorTickSpacing(50);
		slPeso.setMinorTickSpacing(10);
		slPeso.setPaintTicks(true);
		slPeso.setPaintLabels(true);
		slPeso.setValue(600);
		slPeso.setAlignmentX(1.0F);
		slPeso.setAlignmentY(1.0F);
		slPeso.setBorder(new javax.swing.border.MatteBorder(null));
		t4 = new JLabel ("Peso");
		peso = new JTextField(20);
		textPanel4 = new JPanel();
		t4.setForeground(Color.BLACK);
		textPanel4.setBounds(281, 412, 57, 21);
		textPanel4.add(t4);
		textPanel4.add(peso);
		t4.setFont(new Font("Dialog", Font.BOLD, 15));
		slPeso.setToolTipText("Peso (KG)");
		t4.setBounds(700, 316, 324, 315);
		peso.addActionListener(this);
		slPeso.addChangeListener(new ChangeListener() 
		{
			public void stateChanged(ChangeEvent e) 
			{
				pesoP = (double) slPeso.getValue();
				String valorpeso = Double.toString(pesoP);
				lbPeso.setText(valorpeso);
				t4.setBounds(100, 116, 124, 115);
			}
		});
		getContentPane().add(peso);
	
		t3 = new JLabel("Altura (em metros)");
		altura = new JTextField(20);
		textPanel3 = new JPanel();
		textPanel3.add(t3);
		textPanel3.add(altura);
		altura.addActionListener(this);
		
		//Rotulo do resultado do IMC.
		result = new JLabel("IMC");
		fonte2 = new Font("arial", Font.BOLD, 16);
		result.setFont(fonte2);
		result.setForeground(Color.BLACK);
				
		c = getContentPane();
		p = new JPanel();
		p2 = new JPanel();
		Font f = new Font("arial", Font.PLAIN, 14);
		resposta = new JTextArea();
		resposta.setEditable(false);
		resposta.setFont(f);
		JScrollPane scrollPane = new JScrollPane(resposta, 
                JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
                JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		scrollPane.setPreferredSize(new Dimension(280, 120));
		p2.add(rotulo);
		p.setLayout(new GridLayout(6,1));
		p.add(botaoPanel);
		p.add(textPanel1);
		p.add(textPanel2);
		p.add(textPanel3);
		p.add(botaoPanel2);
		p2.add(p);
		p2.add(scrollPane);
		p2.add(result);
		c.add(p2);
	}

	public void actionPerformed(ActionEvent e) {
		String nomePessoa = nome.getText();
		String DataNascPessoa = dataNasc.getText();
		boolean teste = false;
		double high = 0, weight = 0;
		double resultado;
		PessoaIMC obj = null;
		if((e.getSource() == calc)||(e.getSource() instanceof JTextField)){
			String  h;
			//w = peso.getText();
			h = altura.getText();
			teste = true;
			try
			{
				weight = pesoP;
			}
			catch (NumberFormatException e1)
			{
				JOptionPane.showMessageDialog(null, "O peso deve ser um numero\n"
						+ " decimal ou inteiro.");
				teste = false;
			}
			
			try
			{
				high = Double.parseDouble(h);
			}
			catch (NumberFormatException x){
				JOptionPane.showMessageDialog(null, "A altura deve ser um numero\n"
						+ " decimal ou inteiro.");
				teste = false;
			}
			
			if(teste == false)
			{
				result.setText("Digite as informacoes novamente.");
				fonte2 = new Font("arial", Font.BOLD, 16);
				result.setFont(fonte2);
				result.setForeground(Color.BLACK);
			}
			
			if(teste == true)
			{
				if(sexSelection.getSelectedItem() == "Masculino")
				{
					obj = new Homem(nomePessoa, DataNascPessoa, weight, high);
					resultado = weight/(high*high);
					resposta.append("\n"+obj.toString()+"\nIMC: "+resultado+"\n");
					if(resultado < 20.7){
						result.setText("IMC abaixo do peso ideal.");
						fonte2 = new Font("serif", Font.BOLD|Font.ITALIC, 16);
						result.setFont(fonte2);
						result.setForeground(Color.RED);
					}

					else if((resultado >= 20.7)&&(resultado < 26.4)){
						result.setText("IMC no Peso ideal.");
						fonte2 = new Font("serif", Font.BOLD|Font.ITALIC, 16);
						result.setFont(fonte2);
						result.setForeground(Color.GREEN);
					}
					
					else if(resultado > 26.4){ 
						result.setText("IMC acima do peso ideal.");
						fonte2 = new Font("serif", Font.BOLD|Font.ITALIC, 16);
						result.setFont(fonte2);
						result.setForeground(Color.RED);
					}
				}
				
				else if(sexSelection.getSelectedItem() == "Feminino"){
					obj = new Mulher(nomePessoa, DataNascPessoa, weight, high);
					resultado = weight/(high*high);
					resposta.append("\n"+obj.toString()+"\nIMC: "+resultado+"\n");
					if(resultado < 19){
						result.setText("IMC abaixo do peso ideal.");
						fonte2 = new Font("serif", Font.BOLD|Font.ITALIC, 16);
						result.setFont(fonte2);
						result.setForeground(Color.RED);
					}

					else if((resultado >= 19)&&(resultado < 25.8)){
						result.setText("IMC no Peso ideal.");
						fonte2 = new Font("serif", Font.BOLD|Font.ITALIC, 16);
						result.setFont(fonte2);
						result.setForeground(Color.GREEN);
					}

					else if (resultado > 25.8){
						result.setText("IMC acima do peso ideal.");
						fonte2 = new Font("serif", Font.BOLD|Font.ITALIC, 16);
						result.setFont(fonte2);
						result.setForeground(Color.RED);
					}
				}
				
				else
				{
					result.setText("Qual e o sexo do individuo?");
					fonte2 = new Font("arial", Font.BOLD, 16);
					result.setFont(fonte2);
					result.setForeground(Color.BLACK);
				}
			}
		}
		
		else if(e.getSource() == corrig)
		{
			altura.setText("");
			resposta.setText("");
			fonte2 = new Font("arial", Font.BOLD, 16);
			result.setFont(fonte2);
			result.setForeground(Color.BLACK);
		}
	}
}