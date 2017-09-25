package com.st.opcserver.dll;

import com.st.opcserver.tags.STTags;

public class STOPCServer {

	static{
        System.loadLibrary("STOPCServer");
	}
	
	//************************�Է������ĸ��ֲ���**************************//
	//��ʾDLL�İ汾
	private native String OPCsvrRevision();    
	//ע�������
	private native boolean RegistryServer(String svrname,String svrdescr);  
	//ж�ط�����
	private native boolean UnregisterServer(String svrname);          
	//��ʼ��������      
	private native boolean InitServer(int serverrate);  
	//ȥ���������ĳ�ʼ��
	private native boolean UninitServer();
	//���ķ������ĸ�������
	private native boolean ResetServerRate(int serverrate);
	//�������ӵ��������ϵĿͻ�������
	private native int NumbrClientConnections();
	//ǿ�ƶϿ����пͻ��˵�����
	private native void RequestDisconnect();
	//ǿ�Ʒ�������ͻ��˷������ݸ���
	private native boolean RefreshAllClients();
	//*********************************��Tag�ĸ��ֲ���**********************//
	//����tag�����ռ�ֲ��ı�־��Ĭ��Ϊ"."
	private native char SetTagNameQualifier(char qualifier);
	//����tag���Ե���ϸ��Ϣ
	private native boolean SetTagProperties(long handle,long propertyid,String property,String property_value);
	//ɾ��Tag
	private native boolean DeleteTag(long handle);                             
	//����Tag
	private native long AddTag(String name,String value,String value_type,boolean iswritable);
	//����Tag
	private native boolean UpdateTag(long handle, String value,String value_type);
	//����Tag by name
	private native boolean UpdateTagByName(String name, String value,String value_type);
	//��ȡTag
	private native String ReadTag(long handle);
	//���崴��Tag
	private native long AllAddTag(String name,String property,String property_value,String value,String value_type,long readaccesslevel,long writeaccesslevel,float[] limits,long[] severity,boolean[] enabled);  
	//�������Tag
	private native boolean AllUpdateTag(long handle,String property,String property_value,String value,String value_type,float[] limits,long[] severity,boolean[] enabled);
	//������������Tag
	private native boolean StartUpdateTags();
	//��������Tag
	private native boolean UpdateTagToList(long handle,String value,String value_type) ;
	//�ر���������Tag
	private native boolean EndUpdateTags();
	//����Tag�ı�����ֵ
	private native boolean SetItemLevelAlarm(long handle,int levelid ,float limits,long severity,boolean enabled);
	//��ȡtag�ı�����ֵ
	private native String GetItemLevelAlarm(long handle,int levelid);
	//������ر�tag�Կͻ��˵ĸ���
	private native boolean SuspendTagUpdates(long handle,boolean onoff);
	
	
	//*****************************************************************************************//
	//******************************�ⲿ���ܵ��õķ���********************************************//`
	//*****************************************************************************************//
	/**
	 * ��ʾDLL�İ汾
	 * 
	 * @return ����"DLL Rev = 932"
	 */
	public String serverRevision(){                                        
		return this.OPCsvrRevision();
	}
	
	/**
	 * ע�������
	 * 
	 * @param svrname ������������
	 * @param svrdescr �Է�����������
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean registryServer(String svrname,String svrdescr){
		return this.RegistryServer(svrname, svrdescr);
	}
	
	/**
	 * ж�ط�����
	 * 
	 * @param svrname ��Ҫж�صķ�������
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean unregisterServer(String svrname){
		return this.UnregisterServer(svrname);
	}

	/**
	 * ��ʼ��������
	 * 
	 * @param serverrate �������ĸ����ٶ�/ms
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean initServer(int serverrate){
		return this.InitServer(serverrate);
	}

	/**
	 * ȥ���������ĳ�ʼ��
	 * 
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean uninitServer(){
		return this.UninitServer();
	}
	
	/**
	 * ���ķ������ĸ�������
	 * 
	 * @param serverrate �������ĸ����ٶ�/ms
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean resetServerRate(int serverrate){
		return this.ResetServerRate(serverrate);
	}
	
	/**
	 * �������ӵ��������ϵĿͻ�������
	 * 
	 * @return ���ӵ��������ϵĿͻ�������
	 */
	public int numbrClientConnections(){
		return this.NumbrClientConnections();
	}
	
	/**
	 * ǿ�ƶϿ����пͻ��˵����ӣ����ǲ�ȷ�����пͻ����ܶϿ�
	 */
	public void requestDisconnect(){
		this.RequestDisconnect();
	}
	
	/**
	 * ǿ�Ʒ�������ͻ��˷������ݸ���
	 * 
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean refreshAllClients(){
		return this.RefreshAllClients();
	}
	
	/**
	 * ����tag�����ռ�ֲ��ı�־��Ĭ��Ϊ"."
	 * 
	 * @param qualifier tag�����ռ�ֲ��ı�־
	 * @return tag�����ռ�ֲ��ı�־
	 */
	public char setTagNameQualifier(char qualifier){
		return this.SetTagNameQualifier(qualifier);
	}
	
	/**
	 * ����tag�ı�����ֵ
	 * 
	 * @param handle Tag�ľ��
	 * @param levelid ��Ϊ4���ȼ� ID_LOLO_LIMIT = 1��ID_LO_LIMIT = 2��ID_HI_LIMIT = 3��ID_HIHI_LIMIT = 4��
	 * @param limits Tag�ı�����ֵ
	 * @param severity Tag�ı������س̶�
	 * @param enabled Tag�ĸü���ı����Ƿ���
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean setItemLevelAlarm(long handle,int levelid ,float limits,long severity,boolean enabled){
		return this.SetItemLevelAlarm(handle, levelid, limits, severity, enabled);
	}
	/**
	 * ��ȡtag�ı�����ֵ
	 * 
	 * @param handle tag�ľ��
	 * @param limits Tag�ı�����ֵ
	 * @param severity Tag�ı������س̶�
	 * @param enabled Tag�ĸü���ı����Ƿ���
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean getItemLevelAlarm(long handle ,float[] limits,long[] severity,boolean[] enabled){
		String[][] snum = new String[4][];
		String[] gila = new String[4];
		
		gila[0] = this.GetItemLevelAlarm(handle, 1);
		gila[1] = this.GetItemLevelAlarm(handle, 2);
		gila[2] = this.GetItemLevelAlarm(handle, 3);
		gila[3] = this.GetItemLevelAlarm(handle, 4);
		//���ַ������
		for(int i=0;i<4;i++){
			if(!(gila[i].equals("null"))){  //������ǿ�
				snum[i] = gila[i].split("*");
				//��������ת��
				limits[i] = Float.parseFloat(snum[i][0]);
				severity[i] = Long.parseLong(snum[i][1]);
				enabled[i] = Boolean.parseBoolean(snum[i][2]);
			}
			else{//����ǿ�
				return false;
			}
		}
		
		return true;
	}
	
	/**
	 * ɾ��Tag
	 * 
	 * @param handle Tag�ľ��
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean deleteTag(long handle){
		return this.DeleteTag(handle);
	}
	
	/**
	 * �����򵥵�Tag
	 * 
	 * @param tags ��Ҫ�Ĳ�����name,value,value_type,iswritable
	 * @return ������tag�ľ��
	 */
	public long addTag(STTags tags){
		return this.AddTag(tags.getName(), tags.getValue(), tags.getValue_type(), tags.getIswritable());
	}
	
	/**
	 * ͨ����������¼򵥵�Tag
	 * 
	 * @param tags ��Ҫ�Ĳ�����handle��value��value_type
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean updateTag(STTags tags){
		return this.UpdateTag(tags.getHandle(), tags.getValue(), tags.getValue_type());
	}
	
	/**
	 * ͨ��Tag�����������¼򵥵�Tag
	 * 
	 * @param tags ��Ҫ�Ĳ�����name��value��value_type
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean updateTagByName(STTags tags){         
		return this.UpdateTagByName(tags.getName(), tags.getValue(), tags.getValue_type());
	}
	
	/**
	 * �ӷ������ж�ȡTag����ֵ
	 * 
	 * @param handle Tag�ľ��
	 * @return String[0] = value;String[1] = value_type
	 */
	//��ȡTag��ֵ
	//��ȡTag
	public String[] readTag(long handle){
		
		String Svalue = this.ReadTag(handle);
		String[] Value = new String[2];
		if(Svalue.indexOf("VT_INT") !=-1){//��������ΪINT       
			Value[0] = Svalue.replaceAll("VT_INT", "");	//��������
			Value[1] = "VT_INT";							//������������
			return Value;
		}
		else if(Svalue.indexOf("VT_FLOAT") !=-1){//��������ΪFLOAT
			Value[0] = Svalue.replaceAll("VT_FLOAT", "");	//��������
			Value[1] = "VT_FLOAT";							//������������
			return Value;
		}
		else if(Svalue.indexOf("VT_BOOLEAN") !=-1){//��������ΪBOOLEAN
			Svalue = Svalue.replaceAll("VT_BOOLEAN", "");	//ɾȥ��������
			if(Svalue.indexOf("1") !=-1){                  //����java�е�BOOLEANΪTRUE��FALSE
				Value[0] = Svalue.replaceAll("1", "true");	//��������
			}
			else if(Svalue.indexOf("0") !=-1){                  
				Value[0] = Svalue.replaceAll("0", "false");	//��������
			}
			else 
			{
				Value[0] = "";
				System.out.println("Boolean����"+Svalue);
			}
			Value[1] = "VT_BOOLEAN";							//������������
			return Value;
		}
		else if(Svalue.indexOf("VT_STRING") !=-1){//��������ΪSTRING
			Value[0] = Svalue.replaceAll("VT_STRING", "");	//��������
			Value[1] = "VT_STRING";							//������������
			return Value;
		}
		else if(Svalue.indexOf("VT_ERROR") !=-1){//�������ʹ���
			Value[0] = "";
			Value[1] = "VT_ERROR";
			return Value;
		}
		Value[0] = "";
		Value[1] = "VT_NULL";
		return Value;
	}
	
	/**
	 * ��������Tag
	 * 
	 * @param tags ��Ҫ�Ĳ�����name��property��property_value,value,value_type,readaccesslevel,writeaccesslevel,limits,Severity,Enabled
	 * @return ������tag�ľ��
	 */
	public long allAddTag(STTags tags){
		return this.AllAddTag(tags.getName(), tags.getProperty(), tags.getProperty_value(), tags.getValue(), tags.getValue_type(), tags.getReadaccesslevel(), tags.getWriteaccesslevel(), tags.getLimits(), tags.getSeverity(), tags.getEnabled());
	}
	
	/**
	 * �������Tag
	 * 
	 * @param tags ��Ҫ�Ĳ�����handle��property��property_value,value,value_type,readaccesslevel,writeaccesslevel,limits,Severity,Enabled
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean allUpdateTag(STTags tags){
		return this.AllUpdateTag(tags.getHandle(), tags.getProperty(), tags.getProperty_value(), tags.getValue(), tags.getValue_type(), tags.getLimits(), tags.getSeverity(), tags.getEnabled());
	}
	
	/**
	 * ������ر�tag�Կͻ��˵ĸ���
	 * 
	 * @param handle Tag�ľ��
	 * @param onoff �رջ���tag�Կͻ��˵ĸ���
	 * @return �ɹ� = true,ʧ�� = false
	 */
	public boolean suspendTagUpdates(long handle,boolean onoff){
		return this.SuspendTagUpdates(handle, onoff);
	}
	
	
}