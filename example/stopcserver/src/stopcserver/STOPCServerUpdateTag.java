/*
 * STOPCServerUpdateTag.java
 *
 * Created on __DATE__, __TIME__
 */

package stopcserver;

import java.awt.event.ItemEvent;

import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;
import com.st.opcserver.dll.STOPCServer;
import com.st.opcserver.tags.STTags;

/**
 *
 * @author  __USER__
 */
public class STOPCServerUpdateTag extends javax.swing.JFrame {

	STOPCServer sos = new STOPCServer();
	private String[] name_init = new String[STOPCServerSimulator.TagList_count];
	//用来暂存AlarmLimits中的数据，用来防止修改了AlarmLimits中的数据，却取消数据更新时造成的原始数据丢失
	private float[] limits_temp = new float[4];
	private long[] severity_temp = new long[4];
	private boolean[] enabled_temp = new boolean[4];

	/** Creates new form STOPCServerUpdateTag */
	public STOPCServerUpdateTag() {
		for (int i = 0; i < STOPCServerSimulator.TagList_count; i++) {
			name_init[i] = STOPCServerSimulator.tags.get(i).getName();
		}
		initComponents();
		this.setLocationRelativeTo(null);
	}

	//GEN-BEGIN:initComponents
	// <editor-fold defaultstate="collapsed" desc="Generated Code">
	private void initComponents() {

		buttonGroup1 = new javax.swing.ButtonGroup();
		jComboBox1 = new javax.swing.JComboBox();
		jLabel1 = new javax.swing.JLabel();
		jLabel2 = new javax.swing.JLabel();
		jLabel3 = new javax.swing.JLabel();
		jLabel7 = new javax.swing.JLabel();
		jLabel4 = new javax.swing.JLabel();
		jLabel5 = new javax.swing.JLabel();
		jLabel6 = new javax.swing.JLabel();
		Property_Value = new javax.swing.JTextField();
		VT_STRING = new javax.swing.JRadioButton();
		VT_BOOLEAN = new javax.swing.JRadioButton();
		VT_DOUBLE = new javax.swing.JRadioButton();
		VT_INT = new javax.swing.JRadioButton();
		Value = new javax.swing.JTextField();
		jComboBox2 = new javax.swing.JComboBox();
		jComboBox3 = new javax.swing.JComboBox();
		Property = new javax.swing.JTextField();
		OK = new javax.swing.JButton();
		AlarmLimits = new javax.swing.JButton();
		Cancel = new javax.swing.JButton();

		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
		setTitle("\u66f4\u65b0Tag");

		jComboBox1.setModel(new javax.swing.DefaultComboBoxModel(name_init));
		jComboBox1.addItemListener(new java.awt.event.ItemListener() {
			public void itemStateChanged(java.awt.event.ItemEvent evt) {
				jComboBox1ItemStateChanged(evt);
			}
		});

		jLabel1.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\name.png")); // NOI18N
		jLabel1.setText("\u540d\u5b57\uff1a");

		jLabel2.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\description.png")); // NOI18N
		jLabel2.setText("\u5c5e\u6027\uff1a");

		jLabel3.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\units.png")); // NOI18N
		jLabel3.setText("\u5c5e\u6027\u503c\uff1a");

		jLabel7.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\value type.png")); // NOI18N
		jLabel7.setText("\u6570\u636e\u7c7b\u578b\uff1a");

		jLabel4.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\value.png")); // NOI18N
		jLabel4.setText("\u6570\u503c\uff1a");

		jLabel5.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\read.png")); // NOI18N
		jLabel5.setText("\u8bfb\u53d6\u7b49\u7ea7\uff1a");

		jLabel6.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\write.png")); // NOI18N
		jLabel6.setText("\u5199\u5165\u7b49\u7ea7\uff1a");

		buttonGroup1.add(VT_STRING);
		VT_STRING.setText("STRING");

		buttonGroup1.add(VT_BOOLEAN);
		VT_BOOLEAN.setText("BOOL");

		buttonGroup1.add(VT_DOUBLE);
		VT_DOUBLE.setText("DOUBLE");

		buttonGroup1.add(VT_INT);
		VT_INT.setText("INT");
		VT_INT.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				VT_INTActionPerformed(evt);
			}
		});

		jComboBox2.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "ACCESSLEVELNONE", "ACCESSLEVEL1",
				"ACCESSLEVEL2", "ACCESSLEVEL3", "ACCESSLEVEL4", "ACCESSLEVEL5", "ACCESSLEVEL6", "ACCESSLEVEL7",
				"ACCESSLEVEL8", "ACCESSLEVEL9", "ACCESSLEVEL10", "ACCESSLEVEL11", "ACCESSLEVEL12", "ACCESSLEVEL13",
				"ACCESSLEVEL14", "ACCESSLEVEL15", "ACCESSLEVEL16" }));

		jComboBox3.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "ACCESSLEVELNONE", "ACCESSLEVEL1",
				"ACCESSLEVEL2", "ACCESSLEVEL3", "ACCESSLEVEL4", "ACCESSLEVEL5", "ACCESSLEVEL6", "ACCESSLEVEL7",
				"ACCESSLEVEL8", "ACCESSLEVEL9", "ACCESSLEVEL10", "ACCESSLEVEL11", "ACCESSLEVEL12", "ACCESSLEVEL13",
				"ACCESSLEVEL14", "ACCESSLEVEL15", "ACCESSLEVEL16" }));

		OK.setText("\u786e\u5b9a");
		OK.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				OKActionPerformed(evt);
			}
		});

		AlarmLimits.setText("\u62a5\u8b66\u9650\u503c");
		AlarmLimits.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				AlarmLimitsActionPerformed(evt);
			}
		});

		Cancel.setText("\u53d6\u6d88");
		Cancel.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				CancelActionPerformed(evt);
			}
		});
		
		ReflashWind();

		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGroup(
				javax.swing.GroupLayout.Alignment.TRAILING,
				layout.createSequentialGroup()
						.addGroup(layout
								.createParallelGroup(
										javax.swing.GroupLayout.Alignment.TRAILING)
								.addGroup(layout.createSequentialGroup().addContainerGap()
										.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addComponent(jLabel4).addComponent(jLabel7).addComponent(jLabel3)
												.addComponent(jLabel2).addComponent(jLabel1).addComponent(jLabel5)
												.addComponent(jLabel6))
								.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 49,
										Short.MAX_VALUE)
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
										.addGroup(layout.createSequentialGroup().addGroup(layout
												.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
												.addGroup(layout.createSequentialGroup().addGap(18, 18, 18)
														.addGroup(layout
																.createParallelGroup(
																		javax.swing.GroupLayout.Alignment.LEADING,
																		false)
																.addComponent(jComboBox3,
																		javax.swing.GroupLayout.Alignment.TRAILING, 0,
																		javax.swing.GroupLayout.DEFAULT_SIZE,
																		Short.MAX_VALUE)
																.addComponent(jComboBox2,
																		javax.swing.GroupLayout.Alignment.TRAILING, 0,
																		javax.swing.GroupLayout.DEFAULT_SIZE,
																		Short.MAX_VALUE)
																.addComponent(Value,
																		javax.swing.GroupLayout.DEFAULT_SIZE, 175,
																		Short.MAX_VALUE)))
												.addGroup(layout.createSequentialGroup().addGap(17, 17, 17)
														.addGroup(layout
																.createParallelGroup(
																		javax.swing.GroupLayout.Alignment.LEADING,
																		false)
																.addComponent(Property)
																.addComponent(jComboBox1, 0, 172, Short.MAX_VALUE)
																.addComponent(Property_Value,
																		javax.swing.GroupLayout.PREFERRED_SIZE, 173,
																		javax.swing.GroupLayout.PREFERRED_SIZE))))
												.addGap(23, 23, 23))
										.addGroup(
												layout.createSequentialGroup().addComponent(VT_INT)
														.addPreferredGap(
																javax.swing.LayoutStyle.ComponentPlacement.RELATED)
														.addComponent(VT_DOUBLE)
														.addPreferredGap(
																javax.swing.LayoutStyle.ComponentPlacement.RELATED)
														.addComponent(VT_BOOLEAN)
														.addPreferredGap(
																javax.swing.LayoutStyle.ComponentPlacement.RELATED)
														.addComponent(VT_STRING))))
						.addGroup(javax.swing.GroupLayout.Alignment.LEADING,
								layout.createSequentialGroup().addGap(30, 30, 30).addComponent(OK).addGap(77, 77, 77)
										.addComponent(AlarmLimits)
										.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 87,
												Short.MAX_VALUE)
										.addComponent(Cancel)))
						.addGap(32, 32, 32)));
		layout.setVerticalGroup(
				layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
						.addGroup(layout.createSequentialGroup().addContainerGap()
								.addGroup(layout
										.createParallelGroup(
												javax.swing.GroupLayout.Alignment.LEADING)
										.addGroup(
												layout.createSequentialGroup().addComponent(jLabel1)
														.addPreferredGap(
																javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addComponent(jLabel2)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addComponent(jLabel3)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addComponent(jLabel7)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addComponent(jLabel4))
						.addGroup(layout.createSequentialGroup()
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
										.addGroup(layout.createSequentialGroup()
												.addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addComponent(Property, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
												.addComponent(Property_Value, javax.swing.GroupLayout.PREFERRED_SIZE,
														javax.swing.GroupLayout.DEFAULT_SIZE,
														javax.swing.GroupLayout.PREFERRED_SIZE)
												.addGap(46, 46, 46))
										.addGroup(
												layout.createSequentialGroup().addGap(96, 96, 96)
														.addGroup(layout
																.createParallelGroup(
																		javax.swing.GroupLayout.Alignment.BASELINE)
																.addComponent(VT_INT).addComponent(VT_DOUBLE)
																.addComponent(VT_BOOLEAN).addComponent(VT_STRING))
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)))
								.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
								.addComponent(Value, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
				.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
				.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE).addComponent(jLabel5)
						.addComponent(jComboBox2, javax.swing.GroupLayout.PREFERRED_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
				.addGap(9, 9, 9)
				.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE).addComponent(jLabel6)
						.addComponent(jComboBox3, javax.swing.GroupLayout.PREFERRED_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
				.addGap(18, 18, 18).addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
						.addComponent(OK).addComponent(AlarmLimits).addComponent(Cancel)).addContainerGap()));

		pack();
	}// </editor-fold>
		//GEN-END:initComponents

	private void CancelActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
		//取消更新的话恢复AlarmLimits中的原始数据
		
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setLimits(limits_temp);
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setSeverity(severity_temp);
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setEnabled(enabled_temp);
		
		this.dispose();
	}

	private void AlarmLimitsActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
		new STOPCServerUpdateAlarmLimits().setVisible(true);
	}

	private void OKActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:

		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setValue(Value.getText());
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setProperty(Property.getText());
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setProperty_value(Property_Value.getText());
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setReadaccesslevel((long)jComboBox2.getSelectedIndex());
		STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setWriteaccesslevel((long)jComboBox3.getSelectedIndex());
		
		
		if (VT_INT.isSelected()) {
			STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setValue_type("VT_INT");
			sos.allUpdateTag(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select));
		} 
		else if (VT_DOUBLE.isSelected()) {
			STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setValue_type("VT_DOUBLE");
			sos.allUpdateTag(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select));
		}
		else if (VT_BOOLEAN.isSelected()) {
			STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setValue_type("VT_BOOLEAN");
			sos.allUpdateTag(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select));
		} 
		else if (VT_STRING.isSelected()) {
			STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).setValue_type("VT_STRING");
			sos.allUpdateTag(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select));
		}

		this.dispose();

	}

	private void jComboBox1ItemStateChanged(java.awt.event.ItemEvent evt) {
		// TODO add your handling code here:
		if (evt.getStateChange() == ItemEvent.SELECTED) {
			//读取TagList并刷新一遍窗口中的值
			STOPCServerSimulator.tagList_select = jComboBox1.getSelectedIndex();
			ReflashWind();
		}

	}

	private void VT_INTActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
	}

	private void VT_DOUBLEActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
	}

	private void ReflashWind() {

		Property.setText(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getProperty());
		Property_Value.setText(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getProperty_value());
		//对radio按钮的刷新
		if(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getValue_type().equals("VT_INT")){
			VT_INT.setSelected(true);
		}
		else if(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getValue_type().equals("VT_DOUBLE")){
			VT_DOUBLE.setSelected(true);
		}
		else if(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getValue_type().equals("VT_BOOLEAN")){
			VT_BOOLEAN.setSelected(true);
		}
		else if(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getValue_type().equals("VT_STRING")){
			VT_STRING.setSelected(true);
		}
		//对radio按钮的刷新结束
		Value.setText(STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getValue());
		jComboBox2.setSelectedIndex(
				((Number) STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getReadaccesslevel()).intValue());//此处number解决long转换到int
		jComboBox3.setSelectedIndex(
				((Number)STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getWriteaccesslevel()).intValue());

		limits_temp = STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getLimits();
		severity_temp = STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getSeverity();
		enabled_temp = STOPCServerSimulator.tags.get(STOPCServerSimulator.tagList_select).getEnabled();
	}

	/**
	* @param args the command line arguments
	*/
	public static void main(String args[]) {
		java.awt.EventQueue.invokeLater(new Runnable() {
			public void run() {
				new STOPCServerUpdateTag().setVisible(true);
			}
		});
	}

	//GEN-BEGIN:variables
	// Variables declaration - do not modify
	private javax.swing.JButton AlarmLimits;
	private javax.swing.JButton Cancel;
	private javax.swing.JButton OK;
	private javax.swing.JTextField Property;
	private javax.swing.JTextField Property_Value;
	private javax.swing.JRadioButton VT_BOOLEAN;
	private javax.swing.JRadioButton VT_DOUBLE;
	private javax.swing.JRadioButton VT_INT;
	private javax.swing.JRadioButton VT_STRING;
	private javax.swing.JTextField Value;
	private javax.swing.ButtonGroup buttonGroup1;
	private javax.swing.JComboBox jComboBox1;
	private javax.swing.JComboBox jComboBox2;
	private javax.swing.JComboBox jComboBox3;
	private javax.swing.JLabel jLabel1;
	private javax.swing.JLabel jLabel2;
	private javax.swing.JLabel jLabel3;
	private javax.swing.JLabel jLabel4;
	private javax.swing.JLabel jLabel5;
	private javax.swing.JLabel jLabel6;
	private javax.swing.JLabel jLabel7;
	// End of variables declaration//GEN-END:variables

}