/*
 * STOPCServerAddTag.java
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
public class STOPCServerAddTag extends javax.swing.JFrame {

	STOPCServer sos = new STOPCServer();
	public static STTags tag = new STTags();//用来储存tag的各种属性
	public static boolean AlarmLimits_select = false;//用来标记AlarmsLimits是否被按下过

	/** Creates new form STOPCServerAddTag */
	public STOPCServerAddTag() {
		initComponents();
		this.setLocationRelativeTo(null);
	}

	//GEN-BEGIN:initComponents
	// <editor-fold defaultstate="collapsed" desc="Generated Code">
	private void initComponents() {

		ValueType = new javax.swing.ButtonGroup();
		Name = new javax.swing.JTextField();
		Property = new javax.swing.JTextField();
		jLabel1 = new javax.swing.JLabel();
		jLabel2 = new javax.swing.JLabel();
		jLabel3 = new javax.swing.JLabel();
		VT_STRING = new javax.swing.JRadioButton();
		VT_DOUBLE = new javax.swing.JRadioButton();
		VT_INT = new javax.swing.JRadioButton();
		VT_BOOLEAN = new javax.swing.JRadioButton();
		jLabel4 = new javax.swing.JLabel();
		jLabel5 = new javax.swing.JLabel();
		jLabel6 = new javax.swing.JLabel();
		jComboBox1 = new javax.swing.JComboBox();
		jLabel7 = new javax.swing.JLabel();
		AlarmLimits = new javax.swing.JButton();
		OK = new javax.swing.JButton();
		Cancel = new javax.swing.JButton();
		Property_Type = new javax.swing.JTextField();
		Value = new javax.swing.JTextField();
		jComboBox2 = new javax.swing.JComboBox();

		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
		setTitle("\u6dfb\u52a0Tag");
		setAlwaysOnTop(true);

		Name.setText("Tag1");
		Name.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				NameActionPerformed(evt);
			}
		});

		Property.setText("null");

		jLabel1.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\name.png")); // NOI18N
		jLabel1.setText("\u540d\u5b57\uff1a");

		jLabel2.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\description.png")); // NOI18N
		jLabel2.setText("\u5c5e\u6027\uff1a");

		jLabel3.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\units.png")); // NOI18N
		jLabel3.setText("\u5c5e\u6027\u503c\uff1a");

		ValueType.add(VT_STRING);
		VT_STRING.setText("STRING");

		ValueType.add(VT_DOUBLE);
		VT_DOUBLE.setText("DOUBLE");

		ValueType.add(VT_INT);
		VT_INT.setText("INT");
		VT_INT.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				VT_INTActionPerformed(evt);
			}
		});

		ValueType.add(VT_BOOLEAN);
		VT_BOOLEAN.setText("BOOL");

		jLabel4.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\value.png")); // NOI18N
		jLabel4.setText("\u6570\u503c\uff1a");

		jLabel5.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\read.png")); // NOI18N
		jLabel5.setText("\u8bfb\u53d6\u7b49\u7ea7\uff1a");

		jLabel6.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\write.png")); // NOI18N
		jLabel6.setText("\u5199\u5165\u7b49\u7ea7\uff1a");

		jComboBox1.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "ACCESSLEVELNONE", "ACCESSLEVEL1",
				"ACCESSLEVEL2", "ACCESSLEVEL3", "ACCESSLEVEL4", "ACCESSLEVEL5", "ACCESSLEVEL6", "ACCESSLEVEL7",
				"ACCESSLEVEL8", "ACCESSLEVEL9", "ACCESSLEVEL10", "ACCESSLEVEL11", "ACCESSLEVEL12", "ACCESSLEVEL13",
				"ACCESSLEVEL14", "ACCESSLEVEL15", "ACCESSLEVEL16" }));

		jLabel7.setIcon(new javax.swing.ImageIcon("D:\\java\\workspace\\stopcserver\\icon\\value type.png")); // NOI18N
		jLabel7.setText("\u6570\u636e\u7c7b\u578b\uff1a");

		AlarmLimits.setText("\u62a5\u8b66\u9650\u503c");
		AlarmLimits.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				AlarmLimitsActionPerformed(evt);
			}
		});

		OK.setText("\u786e\u5b9a");
		OK.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				OKActionPerformed(evt);
			}
		});

		Cancel.setText("\u53d6\u6d88");
		Cancel.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				CancelActionPerformed(evt);
			}
		});

		Property_Type.setText("null");

		Value.setText("0");

		
		jComboBox2.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "ACCESSLEVELNONE", "ACCESSLEVEL1",
				"ACCESSLEVEL2", "ACCESSLEVEL3", "ACCESSLEVEL4", "ACCESSLEVEL5", "ACCESSLEVEL6", "ACCESSLEVEL7",
				"ACCESSLEVEL8", "ACCESSLEVEL9", "ACCESSLEVEL10", "ACCESSLEVEL11", "ACCESSLEVEL12", "ACCESSLEVEL13",
				"ACCESSLEVEL14", "ACCESSLEVEL15", "ACCESSLEVEL16" }));

		VT_INT.setSelected(true);
		
		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(layout.createSequentialGroup().addContainerGap()
						.addGroup(layout.createParallelGroup(
								javax.swing.GroupLayout.Alignment.LEADING)
						.addGroup(layout.createSequentialGroup().addComponent(jLabel2).addContainerGap())
						.addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup().addGroup(
								layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGroup(layout
										.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
										.addGroup(layout.createSequentialGroup().addComponent(jLabel7)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED,
														javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
												.addComponent(VT_INT)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED))
										.addComponent(jLabel1).addComponent(jLabel3).addComponent(jLabel5)
										.addComponent(jLabel6))
										.addGroup(layout.createSequentialGroup().addComponent(jLabel4)
												.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
										.addGroup(layout.createSequentialGroup().addGroup(layout
												.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
												.addComponent(jComboBox1, 0, javax.swing.GroupLayout.DEFAULT_SIZE,
														Short.MAX_VALUE)
												.addComponent(Value, javax.swing.GroupLayout.DEFAULT_SIZE, 180,
														Short.MAX_VALUE)
												.addComponent(Name)
												.addComponent(Property, javax.swing.GroupLayout.DEFAULT_SIZE, 182,
														Short.MAX_VALUE)
												.addComponent(Property_Type).addComponent(jComboBox2, 0,
														javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
												.addContainerGap(113, Short.MAX_VALUE))
										.addGroup(javax.swing.GroupLayout.Alignment.TRAILING,
												layout.createSequentialGroup().addComponent(VT_DOUBLE)
														.addPreferredGap(
																javax.swing.LayoutStyle.ComponentPlacement.RELATED)
														.addComponent(VT_BOOLEAN)
														.addPreferredGap(
																javax.swing.LayoutStyle.ComponentPlacement.RELATED)
														.addComponent(VT_STRING).addGap(90, 90, 90))))))
				.addGroup(layout.createSequentialGroup().addGap(51, 51, 51)
						.addComponent(OK, javax.swing.GroupLayout.PREFERRED_SIZE, 77,
								javax.swing.GroupLayout.PREFERRED_SIZE)
						.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 64, Short.MAX_VALUE)
						.addComponent(AlarmLimits).addGap(54, 54, 54).addComponent(Cancel,
								javax.swing.GroupLayout.PREFERRED_SIZE, 77, javax.swing.GroupLayout.PREFERRED_SIZE)
						.addGap(42, 42, 42)));
		layout.setVerticalGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(layout.createSequentialGroup().addContainerGap()
						.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
								.addComponent(jLabel1).addComponent(Name, javax.swing.GroupLayout.PREFERRED_SIZE,
										javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
				.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
				.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE).addComponent(jLabel2)
						.addComponent(Property, javax.swing.GroupLayout.PREFERRED_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
				.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
				.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE).addComponent(jLabel3)
						.addComponent(Property_Type, javax.swing.GroupLayout.PREFERRED_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
				.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
				.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE).addComponent(VT_INT)
						.addComponent(VT_DOUBLE).addComponent(jLabel7).addComponent(VT_BOOLEAN).addComponent(VT_STRING))
				.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
				.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE).addComponent(jLabel4)
						.addComponent(Value, javax.swing.GroupLayout.PREFERRED_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
				.addGap(14, 14, 14)
				.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE).addComponent(jLabel5)
						.addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
				.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
				.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE).addComponent(jLabel6)
						.addComponent(jComboBox2, javax.swing.GroupLayout.PREFERRED_SIZE,
								javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
				.addGap(51, 51, 51).addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
						.addComponent(OK).addComponent(Cancel).addComponent(AlarmLimits))
				.addContainerGap(19, Short.MAX_VALUE)));

		pack();
	}// </editor-fold>
		//GEN-END:initComponents

	private void CancelActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
		AlarmLimits_select = false;//标记位复位
		this.dispose();
	}

	private void OKActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
		int count = STOPCServerSimulator.TagList_count;//指向一片的新的空间
		
		tag.setName(Name.getText());
		tag.setValue(Value.getText());
		tag.setProperty(Property.getText());
		tag.setProperty_value(Property_Type.getText());
		tag.setReadaccesslevel((long) jComboBox1.getSelectedIndex());
		tag.setWriteaccesslevel((long) jComboBox2.getSelectedIndex());
		
		//AlarmLimit没有被按下过，就需要手动赋值一遍，默认清零
		if (AlarmLimits_select == false) 
		{
			float[] limits_t = new float[4];
			long[] severity_t = new long[4];
			boolean[] enabled_t = new boolean[4];
			for (int i = 0; i < 4; i++) {
				limits_t[i] = 0;
				severity_t[i] = 0;
				enabled_t[i] = false;
			}
			tag.setLimits(limits_t);
			tag.setSeverity(severity_t);
			tag.setEnabled(enabled_t);
		}
		
		//根据选择的数据类型添加tag
		if (VT_INT.isSelected()) {
			//设置数据类型
			tag.setValue_type("VT_INT");
			//调用DLL
			tag.setHandle(sos.allAddTag(tag));
			//将新的tag加入到tags里面
			STOPCServerSimulator.tags.add(tag);
			
		} else if (VT_DOUBLE.isSelected()) {
			//设置数据类型
			tag.setValue_type("VT_DOUBLE");
			//调用DLL
			tag.setHandle(sos.allAddTag(tag));
			//将新的tag加入到tags里面
			STOPCServerSimulator.tags.add(tag);
		} else if (VT_BOOLEAN.isSelected()) {
			//设置数据类型
			tag.setValue_type("VT_BOOLEAN");
			//调用DLL
			tag.setHandle(sos.allAddTag(tag));
			//将新的tag加入到tags里面
			STOPCServerSimulator.tags.add(tag);
		} else if (VT_STRING.isSelected()) {
			//设置数据类型
			tag.setValue_type("VT_STRING");
			//调用DLL
			tag.setHandle(sos.allAddTag(tag));
			//将新的tag加入到tags里面
			STOPCServerSimulator.tags.add(tag);
		}
		
		//每次成功添加tag时都要给taglist_count++，以指向的list的新的一页
		STOPCServerSimulator.TagList_count++;
		//标记位复位
		AlarmLimits_select = false;
		
		this.dispose();
	}

	private void AlarmLimitsActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
		new STOPCServerAlarmLimits().setVisible(true);//调用AlarmLimits窗口
	}

	void VT_FLOATActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
	}

	private void VT_INTActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
	}

	private void NameActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
	}

	/**
	* @param args the command line arguments
	*/
	public static void main(String args[]) {
		java.awt.EventQueue.invokeLater(new Runnable() {
			public void run() {
				new STOPCServerAddTag().setVisible(true);
			}
		});
	}

	//GEN-BEGIN:variables
	// Variables declaration - do not modify
	private javax.swing.JButton AlarmLimits;
	private javax.swing.JButton Cancel;
	private javax.swing.JTextField Name;
	private javax.swing.JButton OK;
	private javax.swing.JTextField Property;
	private javax.swing.JTextField Property_Type;
	private javax.swing.JRadioButton VT_BOOLEAN;
	private javax.swing.JRadioButton VT_DOUBLE;
	private javax.swing.JRadioButton VT_INT;
	private javax.swing.JRadioButton VT_STRING;
	private javax.swing.JTextField Value;
	private javax.swing.ButtonGroup ValueType;
	private javax.swing.JComboBox jComboBox1;
	private javax.swing.JComboBox jComboBox2;
	private javax.swing.JLabel jLabel1;
	private javax.swing.JLabel jLabel2;
	private javax.swing.JLabel jLabel3;
	private javax.swing.JLabel jLabel4;
	private javax.swing.JLabel jLabel5;
	private javax.swing.JLabel jLabel6;
	private javax.swing.JLabel jLabel7;
	// End of variables declaration//GEN-END:variables

}