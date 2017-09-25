/*
 * STOPCServerUpdateAlarmLimits.java
 *
 * Created on __DATE__, __TIME__
 */

package stopcserver;


import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;
import com.st.opcserver.dll.STOPCServer;
import com.st.opcserver.tags.STTags;
/**
 *
 * @author  __USER__
 */
public class STOPCServerUpdateAlarmLimits extends javax.swing.JFrame {

	private float[] Limits_init = STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getLimits();
	private long[] severity_init = STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getSeverity();
	private boolean[] enabled_init = STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getEnabled();
	/** Creates new form STOPCServerUpdateAlarmLimits */
	public STOPCServerUpdateAlarmLimits() {
		initComponents();
		this.setLocationRelativeTo(null);
	}
	
	//GEN-BEGIN:initComponents
	// <editor-fold defaultstate="collapsed" desc="Generated Code">
	private void initComponents() {

		jLabel5 = new javax.swing.JLabel();
		OK = new javax.swing.JButton();
		jLabel2 = new javax.swing.JLabel();
		jLabel1 = new javax.swing.JLabel();
		jLabel3 = new javax.swing.JLabel();
		jLabel4 = new javax.swing.JLabel();
		Enabled3 = new javax.swing.JCheckBox();
		Enabled2 = new javax.swing.JCheckBox();
		Enabled1 = new javax.swing.JCheckBox();
		Enabled4 = new javax.swing.JCheckBox();
		Limits4 = new javax.swing.JTextField();
		Limits1 = new javax.swing.JTextField();
		Limits3 = new javax.swing.JTextField();
		Limits2 = new javax.swing.JTextField();
		Severity2 = new javax.swing.JTextField();
		Severity3 = new javax.swing.JTextField();
		Severity4 = new javax.swing.JTextField();
		jLabel6 = new javax.swing.JLabel();
		Severity1 = new javax.swing.JTextField();
		Cancel = new javax.swing.JButton();

		setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
		setTitle("\u66f4\u65b0\u62a5\u8b66\u9650\u503c");
		
		jLabel5.setText("Level");

		OK.setText("OK");
		OK.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				OKActionPerformed(evt);
			}
		});

		jLabel2.setText("High:");

		jLabel1.setText("High High:");

		jLabel3.setText("Low:");

		jLabel4.setText("Low Low:");
		
		if(enabled_init[0] == true){
			Enabled1.setSelected(true);
		}
		
		if(enabled_init[1] == true){
			Enabled2.setSelected(true);
		}
		
		if(enabled_init[2] == true){
			Enabled3.setSelected(true);
		}
		
		if(enabled_init[3] == true){
			Enabled4.setSelected(true);
		}
		
		Limits1.setText( String.valueOf(Limits_init[0]));
		
		Limits2.setText( String.valueOf(Limits_init[1]));

		Limits3.setText( String.valueOf(Limits_init[2]));
		
		Limits4.setText( String.valueOf(Limits_init[3]));
		
		Severity1.setText(String.valueOf(severity_init[0]));
		
		Severity2.setText(String.valueOf(severity_init[1]));
		
		Severity3.setText(String.valueOf(severity_init[2]));
		
		Severity4.setText(String.valueOf(severity_init[3]));

		jLabel6.setText("Severity");

		Cancel.setText("Cancel");
		Cancel.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				CancelActionPerformed(evt);
			}
		});

		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(
				layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGap(0, 402, Short.MAX_VALUE)
						.addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
										.addGroup(javax.swing.GroupLayout.Alignment.TRAILING,
												layout.createSequentialGroup().addContainerGap().addComponent(jLabel5)
														.addGap(33, 33, 33))
								.addGroup(layout.createSequentialGroup()
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
												.addGroup(layout.createSequentialGroup().addContainerGap().addComponent(
														OK, javax.swing.GroupLayout.PREFERRED_SIZE, 64,
														javax.swing.GroupLayout.PREFERRED_SIZE))
										.addGroup(javax.swing.GroupLayout.Alignment.LEADING,
												layout.createSequentialGroup().addGap(44, 44, 44)
														.addGroup(layout
																.createParallelGroup(
																		javax.swing.GroupLayout.Alignment.TRAILING)
																.addComponent(jLabel2).addComponent(jLabel1)
																.addComponent(jLabel3).addComponent(jLabel4))
														.addGap(32, 32, 32)
														.addGroup(layout
																.createParallelGroup(
																		javax.swing.GroupLayout.Alignment.LEADING)
																.addComponent(Enabled3).addComponent(Enabled2)
																.addComponent(Enabled1).addComponent(Enabled4))))
										.addGap(35, 35, 35)
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addComponent(Limits4, javax.swing.GroupLayout.DEFAULT_SIZE, 65,
														Short.MAX_VALUE)
												.addComponent(Limits1, javax.swing.GroupLayout.Alignment.TRAILING,
														javax.swing.GroupLayout.DEFAULT_SIZE, 65, Short.MAX_VALUE)
												.addComponent(Limits3, javax.swing.GroupLayout.Alignment.TRAILING,
														javax.swing.GroupLayout.DEFAULT_SIZE, 65, Short.MAX_VALUE)
												.addComponent(Limits2, javax.swing.GroupLayout.Alignment.TRAILING,
														javax.swing.GroupLayout.DEFAULT_SIZE, 65, Short.MAX_VALUE))
										.addGap(18, 18, 18)))
								.addGroup(
										layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addGroup(layout
														.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING,
																false)
														.addComponent(Severity2).addComponent(Severity3)
														.addComponent(Severity4)
														.addGroup(layout.createSequentialGroup().addGap(13, 13, 13)
																.addComponent(jLabel6))
														.addComponent(Severity1))
												.addGroup(layout.createSequentialGroup().addGap(19, 19, 19)
														.addComponent(Cancel)))
								.addGap(36, 36, 36)));
		layout.setVerticalGroup(
				layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGap(0, 324, Short.MAX_VALUE)
						.addGroup(layout.createSequentialGroup().addGap(19, 19, 19)
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
										.addComponent(jLabel5).addComponent(jLabel6))
						.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
								.addGroup(layout.createSequentialGroup()
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addComponent(Enabled1).addComponent(jLabel1))
										.addGap(29, 29, 29)
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addComponent(jLabel2).addComponent(Enabled2)))
								.addGroup(layout.createSequentialGroup()
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
												.addComponent(Severity1, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE)
										.addComponent(Limits1, javax.swing.GroupLayout.PREFERRED_SIZE,
												javax.swing.GroupLayout.DEFAULT_SIZE,
												javax.swing.GroupLayout.PREFERRED_SIZE))
										.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED,
												javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
												.addComponent(Severity2, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addComponent(Limits2, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE))))
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
								.addGroup(layout.createSequentialGroup().addGap(30, 30, 30)
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addComponent(jLabel3).addComponent(Enabled3))
								.addGap(27, 27, 27)
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
										.addComponent(jLabel4).addComponent(Enabled4)))
								.addGroup(layout.createSequentialGroup().addGap(27, 27, 27)
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
												.addComponent(Limits3, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addComponent(Severity3, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE))
										.addGap(28, 28, 28)
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
												.addComponent(Severity4, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addComponent(Limits4, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE))))
						.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 54, Short.MAX_VALUE)
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(Cancel).addComponent(OK)).addGap(29, 29, 29)));

		pack();
	}// </editor-fold>
		//GEN-END:initComponents

	private void CancelActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
		this.dispose();
	}

	private void Enabled1ActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
	}

	private void OKActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
		float[] limit_t = new float[4];
		long[] severity_t = new long[4];
		int[] enabled_t = new int[4];
		limit_t[0] = Float.parseFloat(Limits1.getText());
		severity_t[0] = Long.parseLong(Severity1.getText());
		if (Enabled1.isSelected())
			enabled_t[0] = 1;
		else
			enabled_t[0] = 0;
		limit_t[1] = Float.parseFloat(Limits2.getText());
		severity_t[1] = Long.parseLong(Severity2.getText());
		if (Enabled2.isSelected())
			enabled_t[1] = 1;
		else
			enabled_t[1] = 0;
		limit_t[2] = Float.parseFloat(Limits3.getText());
		severity_t[2] = Long.parseLong(Severity3.getText());
		if (Enabled3.isSelected())
			enabled_t[2] = 1;
		else
			enabled_t[2] = 0;
		limit_t[3] = Float.parseFloat(Limits4.getText());
		severity_t[3] = Long.parseLong(Severity4.getText());
		if (Enabled4.isSelected())
			enabled_t[3] = 1;
		else
			enabled_t[3] = 0;
		
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setLimits(limit_t);
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setSeverity(severity_t);
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setEnabled(enabled_init);
		
		this.dispose();
	}

	/**
	* @param args the command line arguments
	*/
	public static void main(String args[]) {
		java.awt.EventQueue.invokeLater(new Runnable() {
			public void run() {
				new STOPCServerUpdateAlarmLimits().setVisible(true);
			}
		});
	}

	//GEN-BEGIN:variables
	// Variables declaration - do not modify
	private javax.swing.JTextField Limits1;
	private javax.swing.JTextField Limits2;
	private javax.swing.JTextField Limits3;
	private javax.swing.JTextField Limits4;
	private javax.swing.JButton Cancel;
	private javax.swing.JCheckBox Enabled1;
	private javax.swing.JCheckBox Enabled2;
	private javax.swing.JCheckBox Enabled3;
	private javax.swing.JCheckBox Enabled4;
	private javax.swing.JButton OK;
	private javax.swing.JTextField Severity1;
	private javax.swing.JTextField Severity2;
	private javax.swing.JTextField Severity3;
	private javax.swing.JTextField Severity4;
	private javax.swing.JLabel jLabel1;
	private javax.swing.JLabel jLabel2;
	private javax.swing.JLabel jLabel3;
	private javax.swing.JLabel jLabel4;
	private javax.swing.JLabel jLabel5;
	private javax.swing.JLabel jLabel6;
	// End of variables declaration//GEN-END:variables

}