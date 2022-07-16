

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.TrayIcon.MessageType;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.BoxLayout;

import java.awt.GridLayout;

import javax.swing.ButtonGroup;
import javax.swing.JApplet;
import javax.swing.JOptionPane;
import javax.swing.JTextPane;
import javax.swing.JSplitPane;
import javax.swing.JInternalFrame;
import javax.swing.JTextField;
import javax.swing.JRadioButton;
import javax.swing.JScrollBar;
import javax.swing.JProgressBar;
import javax.swing.JSlider;

import java.awt.Font;

import javax.swing.JLabel;

import java.awt.Color;

public class apllet extends JApplet {

	/**
	 * 
	 */
	private static final long serialVersionUID = 6536216594665342769L;
	private JPanel contentPane;
	private JPanel panel_1;
	private JRadioButton rbtSexoM;
	private JSlider slbPeso;
	private JPanel panel_2;
	private JTextField textoAltura;
	private JTextField textoNome;
	private JTextField textoData;
	private JRadioButton rbtSexoF;
	private JButton btnStart;
	private JLabel lblNome;
	private JLabel lblData;
	private JLabel lblAltura;
	private JLabel lblPeso;
	private JLabel lblRes;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					apllet frame = new apllet();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	public void calcula()
	{
		String nome = textoNome.getText();
		String data = textoData.getText();
		String altura = textoAltura.getText();
		float altura2;
		double peso;
		peso = (double)slbPeso.getValue();
		try{
			altura2 = Float.parseFloat(altura);
			PessoaIMC pess = null;
			if(rbtSexoF.isSelected()){
				pess = new Mulher(nome, data, peso, altura2);
			}
			else if(rbtSexoM.isSelected()){
				pess = new Homem(nome, data, peso, altura2);
			}
			Resultado res =pess.resultIMC();

			float r = 0;
			float g = 0;
			float b = 0;
			
			if(res.dist>0)
			{
				r=0.21f*res.dist;
				g=1-0.3f*res.dist;
				b=0;
			}
			else
			{
				r=-0.17f*res.dist;
				g=1+0.2f*res.dist;
				b=0;
			}
			if(res.dist == 0)
			{r=0;g=0.8f;b=0;}
			if(r>1)
				{r=1;}
			if(g>1)
				{g=1;}
			if(g<0)
				{g=0;}
			lblRes.setForeground(new Color(r,g,b));
			lblRes.setText(res.resultado);
		}
		catch(Exception e){
			JOptionPane.showMessageDialog(null,e.getMessage(),"Erro",MessageType.ERROR.ordinal());
		}
		
	}

	/**
	 * Create the frame.
	 */
	public apllet() {
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new BoxLayout(contentPane, BoxLayout.X_AXIS));
		
		JPanel panel = new JPanel();
		contentPane.add(panel);
		panel.setLayout(new GridLayout(0, 2, 0, 0));
		
		panel_1 = new JPanel();
		panel.add(panel_1);
		panel_1.setLayout(new GridLayout(6, 2, 0, 0));
		
		lblNome = new JLabel("Nome");
		lblNome.setFont(new Font("Tahoma", Font.PLAIN, 16));
		panel_1.add(lblNome);
		
		lblData = new JLabel("Data de Nascimento");
		lblData.setFont(new Font("Tahoma", Font.PLAIN, 16));
		panel_1.add(lblData);
		
		lblAltura = new JLabel("Altura");
		lblAltura.setFont(new Font("Tahoma", Font.PLAIN, 16));
		panel_1.add(lblAltura);
		
		rbtSexoM = new JRadioButton("masculino");
		rbtSexoM.setFont(new Font("Tahoma", Font.PLAIN, 16));
		panel_1.add(rbtSexoM);
		
		rbtSexoF = new JRadioButton("feminino");
		panel_1.add(rbtSexoF);
		rbtSexoF.setFont(new Font("Tahoma", Font.PLAIN, 16));
		
		lblRes = new JLabel("");
		panel_1.add(lblRes);
		
		panel_2 = new JPanel();
		panel.add(panel_2);
		panel_2.setLayout(new GridLayout(6, 0, 0, 0));
		
		textoNome = new JTextField();
		panel_2.add(textoNome);
		textoNome.setColumns(10);
		
		textoData = new JTextField();
		panel_2.add(textoData);
		textoData.setColumns(10);
		
		textoAltura = new JTextField();
		panel_2.add(textoAltura);
		textoAltura.setColumns(10);
		
		lblPeso = new JLabel("Peso");
		panel_2.add(lblPeso);
		lblPeso.setForeground(Color.BLACK);
		lblPeso.setFont(new Font("Tahoma", Font.PLAIN, 16));
		
		btnStart = new JButton("Start");
		btnStart.setFont(new Font("Tahoma", Font.PLAIN, 16));
		btnStart.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				calcula();
			}
		});
		
		slbPeso = new JSlider();
		slbPeso.setMaximum(200);
		slbPeso.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				lblPeso.setText(Integer.toString(slbPeso.getValue())+"kg");
			}
		});
		ButtonGroup bg = new ButtonGroup();
		bg.add(rbtSexoM);
		bg.add(rbtSexoF);
		
		panel_2.add(slbPeso);
		panel_2.add(btnStart);
	}

}
