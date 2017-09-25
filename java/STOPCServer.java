package com.st.opcserver.dll;

import com.st.opcserver.tags.STTags;

public class STOPCServer {

	static{
        System.loadLibrary("STOPCServer");
	}
	
	//************************对服务器的各种操作**************************//
	//显示DLL的版本
	private native String OPCsvrRevision();    
	//注册服务器
	private native boolean RegistryServer(String svrname,String svrdescr);  
	//卸载服务器
	private native boolean UnregisterServer(String svrname);          
	//初始化服务器      
	private native boolean InitServer(int serverrate);  
	//去除服务器的初始化
	private native boolean UninitServer();
	//更改服务器的更新速率
	private native boolean ResetServerRate(int serverrate);
	//返回连接到服务器上的客户端数量
	private native int NumbrClientConnections();
	//强制断开所有客户端的连接
	private native void RequestDisconnect();
	//强制服务器向客户端发出数据更新
	private native boolean RefreshAllClients();
	//*********************************对Tag的各种操作**********************//
	//设置tag命名空间分布的标志，默认为"."
	private native char SetTagNameQualifier(char qualifier);
	//设置tag属性的详细信息
	private native boolean SetTagProperties(long handle,long propertyid,String property,String property_value);
	//删除Tag
	private native boolean DeleteTag(long handle);                             
	//创建Tag
	private native long AddTag(String name,String value,String value_type,boolean iswritable);
	//更新Tag
	private native boolean UpdateTag(long handle, String value,String value_type);
	//更新Tag by name
	private native boolean UpdateTagByName(String name, String value,String value_type);
	//读取Tag
	private native String ReadTag(long handle);
	//整体创建Tag
	private native long AllAddTag(String name,String property,String property_value,String value,String value_type,long readaccesslevel,long writeaccesslevel,float[] limits,long[] severity,boolean[] enabled);  
	//整体更新Tag
	private native boolean AllUpdateTag(long handle,String property,String property_value,String value,String value_type,float[] limits,long[] severity,boolean[] enabled);
	//开启批量更新Tag
	private native boolean StartUpdateTags();
	//批量更新Tag
	private native boolean UpdateTagToList(long handle,String value,String value_type) ;
	//关闭批量更新Tag
	private native boolean EndUpdateTags();
	//设置Tag的报警限值
	private native boolean SetItemLevelAlarm(long handle,int levelid ,float limits,long severity,boolean enabled);
	//读取tag的报警限值
	private native String GetItemLevelAlarm(long handle,int levelid);
	//开启或关闭tag对客户端的更新
	private native boolean SuspendTagUpdates(long handle,boolean onoff);
	
	
	//*****************************************************************************************//
	//******************************外部类能调用的方法********************************************//`
	//*****************************************************************************************//
	/**
	 * 显示DLL的版本
	 * 
	 * @return 返回"DLL Rev = 932"
	 */
	public String serverRevision(){                                        
		return this.OPCsvrRevision();
	}
	
	/**
	 * 注册服务器
	 * 
	 * @param svrname 服务器的名字
	 * @param svrdescr 对服务器的描述
	 * @return 成功 = true,失败 = false
	 */
	public boolean registryServer(String svrname,String svrdescr){
		return this.RegistryServer(svrname, svrdescr);
	}
	
	/**
	 * 卸载服务器
	 * 
	 * @param svrname 需要卸载的服务器名
	 * @return 成功 = true,失败 = false
	 */
	public boolean unregisterServer(String svrname){
		return this.UnregisterServer(svrname);
	}

	/**
	 * 初始化服务器
	 * 
	 * @param serverrate 服务器的更新速度/ms
	 * @return 成功 = true,失败 = false
	 */
	public boolean initServer(int serverrate){
		return this.InitServer(serverrate);
	}

	/**
	 * 去除服务器的初始化
	 * 
	 * @return 成功 = true,失败 = false
	 */
	public boolean uninitServer(){
		return this.UninitServer();
	}
	
	/**
	 * 更改服务器的更新速率
	 * 
	 * @param serverrate 服务器的更新速度/ms
	 * @return 成功 = true,失败 = false
	 */
	public boolean resetServerRate(int serverrate){
		return this.ResetServerRate(serverrate);
	}
	
	/**
	 * 返回连接到服务器上的客户端数量
	 * 
	 * @return 连接到服务器上的客户端数量
	 */
	public int numbrClientConnections(){
		return this.NumbrClientConnections();
	}
	
	/**
	 * 强制断开所有客户端的连接，但是不确保所有客户端能断开
	 */
	public void requestDisconnect(){
		this.RequestDisconnect();
	}
	
	/**
	 * 强制服务器向客户端发出数据更新
	 * 
	 * @return 成功 = true,失败 = false
	 */
	public boolean refreshAllClients(){
		return this.RefreshAllClients();
	}
	
	/**
	 * 设置tag命名空间分布的标志，默认为"."
	 * 
	 * @param qualifier tag命名空间分布的标志
	 * @return tag命名空间分布的标志
	 */
	public char setTagNameQualifier(char qualifier){
		return this.SetTagNameQualifier(qualifier);
	}
	
	/**
	 * 设置tag的报警限值
	 * 
	 * @param handle Tag的句柄
	 * @param levelid 分为4个等级 ID_LOLO_LIMIT = 1；ID_LO_LIMIT = 2；ID_HI_LIMIT = 3；ID_HIHI_LIMIT = 4；
	 * @param limits Tag的报警限值
	 * @param severity Tag的报警严重程度
	 * @param enabled Tag的该级别的报警是否开启
	 * @return 成功 = true,失败 = false
	 */
	public boolean setItemLevelAlarm(long handle,int levelid ,float limits,long severity,boolean enabled){
		return this.SetItemLevelAlarm(handle, levelid, limits, severity, enabled);
	}
	/**
	 * 读取tag的报警限值
	 * 
	 * @param handle tag的句柄
	 * @param limits Tag的报警限值
	 * @param severity Tag的报警严重程度
	 * @param enabled Tag的该级别的报警是否开启
	 * @return 成功 = true,失败 = false
	 */
	public boolean getItemLevelAlarm(long handle ,float[] limits,long[] severity,boolean[] enabled){
		String[][] snum = new String[4][];
		String[] gila = new String[4];
		
		gila[0] = this.GetItemLevelAlarm(handle, 1);
		gila[1] = this.GetItemLevelAlarm(handle, 2);
		gila[2] = this.GetItemLevelAlarm(handle, 3);
		gila[3] = this.GetItemLevelAlarm(handle, 4);
		//将字符串拆解
		for(int i=0;i<4;i++){
			if(!(gila[i].equals("null"))){  //如果不是空
				snum[i] = gila[i].split("*");
				//进行数据转换
				limits[i] = Float.parseFloat(snum[i][0]);
				severity[i] = Long.parseLong(snum[i][1]);
				enabled[i] = Boolean.parseBoolean(snum[i][2]);
			}
			else{//如果是空
				return false;
			}
		}
		
		return true;
	}
	
	/**
	 * 删除Tag
	 * 
	 * @param handle Tag的句柄
	 * @return 成功 = true,失败 = false
	 */
	public boolean deleteTag(long handle){
		return this.DeleteTag(handle);
	}
	
	/**
	 * 创建简单的Tag
	 * 
	 * @param tags 需要的参数：name,value,value_type,iswritable
	 * @return 创建的tag的句柄
	 */
	public long addTag(STTags tags){
		return this.AddTag(tags.getName(), tags.getValue(), tags.getValue_type(), tags.getIswritable());
	}
	
	/**
	 * 通过句柄来更新简单的Tag
	 * 
	 * @param tags 需要的参数：handle，value，value_type
	 * @return 成功 = true,失败 = false
	 */
	public boolean updateTag(STTags tags){
		return this.UpdateTag(tags.getHandle(), tags.getValue(), tags.getValue_type());
	}
	
	/**
	 * 通过Tag的名字来更新简单的Tag
	 * 
	 * @param tags 需要的参数：name，value，value_type
	 * @return 成功 = true,失败 = false
	 */
	public boolean updateTagByName(STTags tags){         
		return this.UpdateTagByName(tags.getName(), tags.getValue(), tags.getValue_type());
	}
	
	/**
	 * 从服务器中读取Tag的数值
	 * 
	 * @param handle Tag的句柄
	 * @return String[0] = value;String[1] = value_type
	 */
	//读取Tag的值
	//读取Tag
	public String[] readTag(long handle){
		
		String Svalue = this.ReadTag(handle);
		String[] Value = new String[2];
		if(Svalue.indexOf("VT_INT") !=-1){//数据类型为INT       
			Value[0] = Svalue.replaceAll("VT_INT", "");	//存入数据
			Value[1] = "VT_INT";							//存入数据类型
			return Value;
		}
		else if(Svalue.indexOf("VT_FLOAT") !=-1){//数据类型为FLOAT
			Value[0] = Svalue.replaceAll("VT_FLOAT", "");	//存入数据
			Value[1] = "VT_FLOAT";							//存入数据类型
			return Value;
		}
		else if(Svalue.indexOf("VT_BOOLEAN") !=-1){//数据类型为BOOLEAN
			Svalue = Svalue.replaceAll("VT_BOOLEAN", "");	//删去数据类型
			if(Svalue.indexOf("1") !=-1){                  //由于java中的BOOLEAN为TRUE和FALSE
				Value[0] = Svalue.replaceAll("1", "true");	//存入数据
			}
			else if(Svalue.indexOf("0") !=-1){                  
				Value[0] = Svalue.replaceAll("0", "false");	//存入数据
			}
			else 
			{
				Value[0] = "";
				System.out.println("Boolean错误"+Svalue);
			}
			Value[1] = "VT_BOOLEAN";							//存入数据类型
			return Value;
		}
		else if(Svalue.indexOf("VT_STRING") !=-1){//数据类型为STRING
			Value[0] = Svalue.replaceAll("VT_STRING", "");	//存入数据
			Value[1] = "VT_STRING";							//存入数据类型
			return Value;
		}
		else if(Svalue.indexOf("VT_ERROR") !=-1){//数据类型错误
			Value[0] = "";
			Value[1] = "VT_ERROR";
			return Value;
		}
		Value[0] = "";
		Value[1] = "VT_NULL";
		return Value;
	}
	
	/**
	 * 完整创建Tag
	 * 
	 * @param tags 需要的参数：name，property，property_value,value,value_type,readaccesslevel,writeaccesslevel,limits,Severity,Enabled
	 * @return 创建的tag的句柄
	 */
	public long allAddTag(STTags tags){
		return this.AllAddTag(tags.getName(), tags.getProperty(), tags.getProperty_value(), tags.getValue(), tags.getValue_type(), tags.getReadaccesslevel(), tags.getWriteaccesslevel(), tags.getLimits(), tags.getSeverity(), tags.getEnabled());
	}
	
	/**
	 * 整体更新Tag
	 * 
	 * @param tags 需要的参数：handle，property，property_value,value,value_type,readaccesslevel,writeaccesslevel,limits,Severity,Enabled
	 * @return 成功 = true,失败 = false
	 */
	public boolean allUpdateTag(STTags tags){
		return this.AllUpdateTag(tags.getHandle(), tags.getProperty(), tags.getProperty_value(), tags.getValue(), tags.getValue_type(), tags.getLimits(), tags.getSeverity(), tags.getEnabled());
	}
	
	/**
	 * 开启或关闭tag对客户端的更新
	 * 
	 * @param handle Tag的句柄
	 * @param onoff 关闭或开启tag对客户端的更新
	 * @return 成功 = true,失败 = false
	 */
	public boolean suspendTagUpdates(long handle,boolean onoff){
		return this.SuspendTagUpdates(handle, onoff);
	}
	
	/**
	 * 开启批量更新Tag
	 * 
	 * @return 成功 = true,失败 = false
	 */
	public boolean startUpdateTags(){
		return this.StartUpdateTags();
	}
	
	/**
	 * 批量更新Tag
	 * 
	 * @param tags 需要的参数：handle，value，value_type
	 * @return 成功 = true,失败 = false
	 */
	public boolean updateTagsToList(STTags tags){
		return this.UpdateTagToList(tags.getHandle(), tags.getValue(), tags.getValue_type());
	}
	
	/**
	 * 关闭批量更新Tag
	 * 
	 * @return 成功 = true,失败 = false
	 */
	public boolean endUpdateTags(){
		return this.EndUpdateTags();
	}
	
}