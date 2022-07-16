import javax.swing.*;

import java.lang.Exception;
import java.math.BigDecimal;
import java.awt.*;
import java.awt.event.*;

public class IMC extends JApplet implements ActionListener
{
	private static final long serialVersionUID = 1L;
	private JTextField peso, altura;
	String[] sexoString={"selecione","Masculino","Feminino"};
	private JComboBox sexSelection;
	private JTextArea resposta;
	private Container c;
	private JPanel botaoPanel, botaoPanel2, p, p2;
	private JPanel textPanel1, textPanel2;
	private JButton calc, corrig;
	private JLabel t1, t2, t3, t4, result;
	private Font fonte, fonte2;
	
	public void init() {
		//Nome do Applet.
		fonte = new Font("Arial", Font.BOLD, 30);
		JLabel rotulo = new JLabel("Calculadora IMC");
		rotulo.setFont(fonte);
		
		//Opcao de sexo: Feminino ou masculino.
		botaoPanel = new JPanel();
		sexSelection = new JComboBox(sexoString);
		sexSelection.addActionListener(this);
		botaoPanel.add(new JLabel("Sexo:    "));
		botaoPanel.add(sexSelection);
		
		//Botoes "Calcular" e "Corrigir".
		botaoPanel2 = new JPanel();
		calc = new JButton("Calcular");
		corrig = new JButton("Corrigir");
		botaoPanel2.add(calc);
		botaoPanel2.add(corrig);
		calc.addActionListener(this);
		corrig.addActionListener(this);
		
		t3 = new JLabel("Peso:    ");
		peso = new JTextField(20);
		textPanel1 = new JPanel();
		peso.setText("Digite seu peso(em gramas).");
		textPanel1.add(t3);
		textPanel1.add(peso);
		peso.addActionListener(this);
		
		t4 = new JLabel("Altura:   ");
		altura = new JTextField(20);
		altura.setText("Digite sua altura(em metros).");
		textPanel2 = new JPanel();
		textPanel2.add(t4);
		textPanel2.add(altura);
		altura.addActionListener(this);
		
		//Rotulo do resultado do IMC.
		result = new JLabel("Conclusao do IMC aqui.");
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
		p.add(botaoPanel2);
		p2.add(p);
		p2.add(scrollPane);
		p2.add(result);
		c.add(p2);
	}

	public void actionPerformed(ActionEvent e) {
		boolean teste = false;
		double high = 0, weight = 0;
		double resultado;
		PessoaIMC obj;
		
		if((e.getSource() == calc)||(e.getSource() instanceof JTextField)){
			String w, h;
			w = peso.getText();
			h = altura.getText();
			teste = true;
			
			try{
				weight = Double.parseDouble(w);
			}catch (NumberFormatException x){
				JOptionPane.showMessageDialog(null, "O peso deve ser um numero\n"
						+ " decimal ou inteiro.");
				teste = false;
			}
			
			try{
				high = Double.parseDouble(h);
			}catch (NumberFormatException x){
				JOptionPane.showMessageDialog(null, "A altura deve ser um numero\n"
						+ " decimal ou inteiro.");
				teste = false;
			}
			
			if(teste == false){
				result.setText("Digite as informacoes novamente.");
				fonte2 = new Font("arial", Font.BOLD, 16);
				result.setFont(fonte2);
				result.setForeground(Color.BLACK);
			}
			
			if(teste == true)
			{
				if(sexSelection.getSelectedItem() == "Masculino")
				{
					obj = new Homem(null, null, weight, high);
					resultado = Double.parseDouble(obj.resultIMC());
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
					obj = new Mulher(null, null, weight, high);
					
					resultado = Double.parseDouble(obj.resultIMC());
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
				
				else{
					result.setText("Qual e o sexo do individuo?");
					fonte2 = new Font("arial", Font.BOLD, 16);
					result.setFont(fonte2);
					result.setForeground(Color.BLACK);
				}
			}
		}
		
		else if(e.getSource() == corrig){
			peso.setText("");
			altura.setText("");
			resposta.setText("");
			result.setText("Corrigindo informacoes...");
			fonte2 = new Font("arial", Font.BOLD, 16);
			result.setFont(fonte2);
			result.setForeground(Color.BLACK);
		}
	}
}