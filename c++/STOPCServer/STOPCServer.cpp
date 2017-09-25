// STOPCServer.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "opcda.h"
#include "opc_ae.h"
#include "opcaedef.h"
#include "OPCERROR.h"
#include "WTOPCsvrAPI.h"
#include "WTOPCsvrextAPI.h"
#include "com_st_opcserver_dll_STOPCServer.h"
#include <comutil.h>
#include <string>
#include <math.h>

using namespace std;

static const GUID CLSID_Svr =
{ 0xc192a3a0, 0x21f3, 0x4fe8,{ 0xb9, 0x28, 0x61, 0xd4, 0x24, 0x30, 0x43, 0xf8 } };

WCHAR *WSTRFromCString(const CHAR *buf)
{
	int	length, i;
	WCHAR	*temp;

	length = strlen(buf) + 1;
	temp = new WCHAR[strlen(buf) + 1];

	if (temp)
	{
		for (i = 0; i<length; i++) temp[i] = (WCHAR)buf[i];//使用强制类型转换的形式
	}

	return temp;
}
void WSTRFree(WCHAR * c)
{
	if (c == NULL)
		return;

	delete c;
}
/////////////////////////////////////////////////////////////////////////////
// CWTSvrTestView
//
//Write Notification callback
//pass control to thge CView
//which contains the local tag list
// Write通知回调传递控件到包含本地标签列表的视图
//
void CALLBACK EXPORT WriteNotifyProc2(HANDLE Handle, VARIANT *pNewValue, DWORD *pDevError, CHAR *pUser)
{


}
void CALLBACK EXPORT DeviceReadProc(HANDLE Handle, VARIANT *pNewValue, WORD *pQuality, FILETIME *pTimestamp)
{


}
void CALLBACK EXPORT DisconnectProc(DWORD NumbrActiveClients)
{
	if (NumbrActiveClients == 0)
	{
		// If you want to end the server application
		// when the last client disconnects,
		// be sure to return from the callback
		// to release the client before shutting down.
	}
}

//float StringtoFloat(string s)
//{
//	size_t pos = s.find(".");
//	size_t size = s.size();
//	string zs = s.substr(0, pos);
//	string xs = s.substr(pos + 1, size);
//	int xss = xs.size();
//	int izs = stoi(zs);
//	int ixs = stoi(xs);
//	float fxs = ((float)ixs) / ((float)pow(10, xss));
//	printf("!!!!%f", (float)((float)izs + 0.324));
//	return (float)((float)izs + fxs);
//}


//***********************显示DLL文件版本信息*****************************//
JNIEXPORT jstring JNICALL Java_com_st_opcserver_dll_STOPCServer_OPCsvrRevision(JNIEnv *env, jobject obj)
{
	WORD	rev;
	char buf[100];
	rev = WTOPCsvrRevision();
	sprintf_s(buf, "DLL Rev = %x", rev);
	jstring jsrev = env->NewStringUTF(buf);//char*转jstring
	return jsrev;
}
//**************************注册服务器***********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_RegistryServer(JNIEnv *env, jobject obj, jstring svrname, jstring svrdescr)
{
	const char *SvrName = env->GetStringUTFChars(svrname, NULL);//
	const char *SvrDescr = env->GetStringUTFChars(svrdescr, NULL);
	char exeFullPath[MAX_PATH]; // Full path   
	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	if (UpdateRegistry((BYTE *)&CLSID_Svr, SvrName, SvrDescr, exeFullPath))
	{
		env->ReleaseStringUTFChars(svrname, SvrName);
		env->ReleaseStringUTFChars(svrdescr, SvrDescr);
		return (jboolean)1;
	}
	else
	{
		env->ReleaseStringUTFChars(svrname, SvrName);
		env->ReleaseStringUTFChars(svrdescr, SvrDescr);
		return (jboolean)0;
	}
}
//**************************卸载服务器***********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UnregisterServer(JNIEnv *env, jobject obj, jstring svrname)
{
	const char *SvrName = env->GetStringUTFChars(svrname, NULL);
	if (UnregisterServer((BYTE *)&CLSID_Svr, SvrName))
	{
		env->ReleaseStringUTFChars(svrname, SvrName);
		return (jboolean)1;
	}
	else
	{
		env->ReleaseStringUTFChars(svrname, SvrName);
		return (jboolean)0;
	}
}
//*************************初始化服务器**********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_InitServer(JNIEnv *env, jobject obj, jint serverrate)
{
	UINT Serverrate = (UINT)serverrate;
	if (InitWTOPCsvr((BYTE *)&CLSID_Svr, Serverrate))
	{
		return (jboolean)1;
	}
	else
	{
		return (jboolean)0;
	}

	//EnableWriteNotification2(&WriteNotifyProc2, TRUE);
	//EnableDisconnectNotification(&DisconnectProc);
	//EnableDeviceRead(&DeviceReadProc);
}
//*************************去除服务器的初始化****************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UninitServer(JNIEnv *env, jobject obj)
{
	//调用DLL
	BOOL bj = UninitWTOPCsvr();

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//***********************更改服务器的更新速率****************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_ResetServerRate(JNIEnv *env, jobject obj, jint serverrate)
{
	//赋值Serverrate
	UINT Serverrate = (UINT)serverrate;
	//调用DLL
	BOOL bj = ResetServerRate(Serverrate);

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//****************返回连接到服务器上的客户端数量*************************//
JNIEXPORT jint JNICALL Java_com_st_opcserver_dll_STOPCServer_NumbrClientConnections(JNIEnv *env, jobject obj)
{
	int nb = NumbrClientConnections();
	return (jint)nb;
}
//*****************强制断开所有客户端的连接******************************//
JNIEXPORT void JNICALL Java_com_st_opcserver_dll_STOPCServer_RequestDisconnect(JNIEnv *env, jobject obj)
{
	RequestDisconnect();
}
//*****************强制服务器向客户端发出数据更新************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_RefreshAllClients(JNIEnv *env, jobject obj)
{
	BOOL bj = RefreshAllClients();

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//**********************设置tag命名空间分布的标志，默认为"."*************//
JNIEXPORT jchar JNICALL Java_com_st_opcserver_dll_STOPCServer_SetTagNameQualifier(JNIEnv *env, jobject obj, jchar qualifier)
{
	//赋值Qualifier
	char Qualifier = (char)qualifier;
	char c = SetWtOPCsvrQualifier(Qualifier);
	return (jchar)c;
}
//*************************设置tag属性的详细信息*************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_SetTagProperties(JNIEnv *env, jobject obj, jlong handle, jlong propertyid, jstring property, jstring property_value)
{
	//赋值Handle
	HANDLE Handle = (HANDLE)handle;
	//赋值Propertyid
	DWORD Propertyid = (DWORD)Propertyid;
	//赋值Description
	const char * Ccproperty = env->GetStringUTFChars(property, NULL);
	LPCSTR Property = Ccproperty;
	//赋值Property_Value
	const char *Property_Value = env->GetStringUTFChars(property_value, NULL);
	CString CProperty_Value = Property_Value;
	BSTR BSCProperty_Value = CProperty_Value.AllocSysString();
	VARIANT	PropertyValue;
	VariantInit(&PropertyValue);//初期化为VT_EMPTY
	PropertyValue.vt = VT_BSTR;
	PropertyValue.bstrVal = BSCProperty_Value;
	//调用DLL
	BOOL bj = SetTagProperties(Handle, Propertyid, Property, PropertyValue);
	
	//回收内存
	VariantClear(&PropertyValue);//清除Vvlaue
	SysFreeString(BSCProperty_Value);//回收
	env->ReleaseStringUTFChars(property, Ccproperty);
	env->ReleaseStringUTFChars(property_value, Property_Value);

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//***************************删除Tag*************************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_DeleteTag(JNIEnv *env, jobject obj, jlong handle)
{
	HANDLE Handle = (HANDLE)handle;
	if (RemoveTag(Handle))
		return (jboolean)1;
	else return (jboolean)0;
}
//***************************创建简单的Tag*************************************//
JNIEXPORT jlong JNICALL Java_com_st_opcserver_dll_STOPCServer_AddTag(JNIEnv *env, jobject obj, jstring name, jstring value, jstring value_type, jboolean iswritable)
{
	//赋值Name
	const char *Name = env->GetStringUTFChars(name, NULL);
	//赋值iswritable
	BOOL IsWritable = iswritable;
	//初始化一个HANDLE
	HANDLE Handle = NULL;
	//赋值Value，并转化为VARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//初期化为VT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value类型为INT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value类型为DOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value类型为BOOLEAN
	{
		if (strcmp("true", Value) == 0)//因为java中使用的是true/false，此处是为了兼容
		{
			BOOL Bvalue = 1;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else if (strcmp("false", Value) == 0)
		{
			BOOL Bvalue = 0;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else//如果输入的不是true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value类型为STRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		Handle = CreateTag(Name, Vvalue, OPC_QUALITY_GOOD, IsWritable);
		VariantClear(&Vvalue);//清除Vvlaue
		SysFreeString(BSValue);//回收
	}
	else
	{
		printf("C++提示：数据类型输入错误，AddTag失败");
		VariantClear(&Vvalue);//清除Vvlaue
		env->ReleaseStringUTFChars(name, Name);
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return -2;
	}
	//调用DLL文件
	if (strcmp("VT_STRING", Value_type) != 0)//Value类型不为STRING
	{
		Handle = CreateTag(Name, Vvalue, OPC_QUALITY_GOOD, IsWritable);
		VariantClear(&Vvalue);//清除Vvlaue
	}

	env->ReleaseStringUTFChars(name, Name);
	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);
	printf("C++提示：AddTag,HANDLE=%u\n", (UINT32)Handle);
	return (UINT32)Handle;
}
//*************************更新简单的Tag***************************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UpdateTag(JNIEnv *env, jobject obj, jlong handle, jstring value, jstring value_type)
{
	//赋值HANDLE
	HANDLE Handle = (HANDLE)handle;
	//用于判断更新是否成功
	BOOL bj = 0;
	//赋值Value，并转化为VARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//初期化为VT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value类型为INT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value类型为DOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value类型为BOOLEAN
	{
		if (strcmp("true", Value) == 0)//因为java中使用的是true/false，此处是为了兼容
		{
			BOOL Bvalue = 1;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else if (strcmp("false", Value) == 0)
		{
			BOOL Bvalue = 0;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else//如果输入的不是true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value类型为STRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		bj = UpdateTag(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//清除Vvlaue
		SysFreeString(BSValue);//回收
	}
	else
	{
		printf("C++提示：数据类型输入错误，UpdateTag失败");
		VariantClear(&Vvalue);//清除Vvlaue
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return (jboolean)0;
	}
	//调用DLL文件
	if (strcmp("VT_STRING", Value_type) != 0)//Value类型不为STRING，为了解决SysFreeString(BSValue);的问题
	{
		bj = UpdateTag(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//清除Vvlaue
	}

	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	if (bj == 1) return (jboolean)1;

	return  (jboolean)0;
}
//************************更新Tag by name********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UpdateTagByName(JNIEnv *env, jobject obj, jstring name, jstring value, jstring value_type)
{
	//赋值Name
	const char *Name = env->GetStringUTFChars(name, NULL);
	//用于判断更新是否成功
	BOOL bj = 0;
	//赋值Value，并转化为VARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//初期化为VT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value类型为INT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value类型为DOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value类型为BOOLEAN
	{
		if (strcmp("true", Value) == 0)//因为java中使用的是true/false，此处是为了兼容
		{
			BOOL Bvalue = 1;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else if (strcmp("false", Value) == 0)
		{
			BOOL Bvalue = 0;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else//如果输入的不是true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value类型为STRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		bj = UpdateTagByName(Name, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//清除Vvlaue
		SysFreeString(BSValue);//回收
	}
	else
	{
		printf("C++提示：数据类型输入错误，UpdateTag失败");
		VariantClear(&Vvalue);//清除Vvlaue
		env->ReleaseStringUTFChars(name, Name);
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return (jboolean)0;
	}
	//调用DLL文件
	if (strcmp("VT_STRING", Value_type) != 0)//Value类型不为STRING，为了解决SysFreeString(BSValue);的问题
	{
		bj = UpdateTagByName(Name, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//清除Vvlaue
	}

	env->ReleaseStringUTFChars(name, Name);
	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	if (bj == 1) return (jboolean)1;
	return  (jboolean)0;

}
//************************读取Tag****************************************//
JNIEXPORT jstring JNICALL Java_com_st_opcserver_dll_STOPCServer_ReadTag(JNIEnv *env, jobject obj, jlong handle)
{
	//赋值HANDLE
	HANDLE Handle = (HANDLE)handle;
	//获取Value
	VARIANT Value;
	VariantInit(&Value);//初期化为VT_EMPTY
	ReadTag(Handle, &Value);
	if (Value.vt == VT_INT)//数据类型为INT
	{
		int Ivalue = Value.intVal;
		string Svalue = to_string(Ivalue);
		string Value_type = "VT_INT";
		string Stvalue = Value_type + Svalue;
		const char *Ccvalue = Stvalue.data();
		jstring Vvalue = env->NewStringUTF(Ccvalue);
		printf("C++提示：HANDLE = %u", handle);
		printf("的Tag值 = %s\n", Ccvalue);
		VariantClear(&Value);//清除Value
		return Vvalue;
	}
	else if (Value.vt == VT_R8)//数据类型为DOUBLE
	{
		double Dvalue = Value.dblVal;
		string Svalue = to_string(Dvalue);
		string Value_type = "VT_DOUBLE";
		string Stvalue = Value_type + Svalue;
		const char *Ccvalue = Stvalue.data();
		jstring Vvalue = env->NewStringUTF(Ccvalue);
		printf("C++提示：HANDLE = %u", handle);
		printf("的Tag值 = %s\n", Ccvalue);
		VariantClear(&Value);//清除Value
		return Vvalue;
	}
	else if (Value.vt == VT_BOOL)//数据类型为BOOLEAN
	{
		BOOL Bvalue = Value.boolVal;
		string Svalue = to_string(Bvalue);
		string Value_type = "VT_BOOLEAN";
		string Stvalue = Value_type + Svalue;
		const char *Ccvalue = Stvalue.data();
		jstring Vvalue = env->NewStringUTF(Ccvalue);
		printf("C++提示：HANDLE = %u", handle);
		printf("的Tag值 = %s\n", Ccvalue);
		VariantClear(&Value);//清除Value
		return Vvalue;
	}
	else if (Value.vt == VT_BSTR)
	{
		BSTR Bvalue = Value.bstrVal;
		const char* TCcvalue = _com_util::ConvertBSTRToString(Bvalue);//BSTR--》const char *
		string Svalue = TCcvalue;
		string Value_type = "VT_STRING";
		string Stvalue = Value_type + Svalue;
		const char *Ccvalue = Stvalue.data();
		jstring Vvalue = env->NewStringUTF(Ccvalue);
		printf("C++提示：HANDLE = %u", handle);
		printf("的Tag值 = %s\n", Ccvalue);
		SysFreeString(Bvalue);//释放Bvalue
		VariantClear(&Value);//清除Value
		return Vvalue;
	}
	//数据类型错误
	const char *Ccvalue = "VT_ERROR";
	jstring Vvalue = env->NewStringUTF(Ccvalue);
	printf("C++提示：HANDLE = %u", handle);
	printf("的Tag值 = %s\n", Ccvalue);
	VariantClear(&Value);//清除Value
	return Vvalue;
}
//************************整体创建Tag***********************************//
JNIEXPORT jlong JNICALL Java_com_st_opcserver_dll_STOPCServer_AllAddTag(JNIEnv *env, jobject obj, jstring name, jstring property, jstring property_value, jstring value, jstring value_type, jlong readAccesslevel, jlong writeAccessLevel, jfloatArray limits, jlongArray severity, jbooleanArray enabled)
{
	//赋值Name
	const char *Name = env->GetStringUTFChars(name, NULL);
	//赋值Property
	const char *Property = env->GetStringUTFChars(property, NULL);
	//赋值Property_value
	const char *Property_value = env->GetStringUTFChars(property_value, NULL);
	//赋值ReadAccessLevel
	DWORD ReadAccessLevel = (DWORD)readAccesslevel;
	//赋值WriteAccessLevel
	DWORD WriteAccessLevel = (DWORD)writeAccessLevel;
	//赋值Limits
	jfloat jlimits[4];
	env->GetFloatArrayRegion(limits, 0, 4, jlimits);
	float Limits[4];
	for (int i = 0; i < 4; i++)
	{
		Limits[i] = (float)jlimits[i];
	}
	//赋值Severity
	jlong jseverity[4];
	env->GetLongArrayRegion(severity, 0, 4, jseverity);
	DWORD Severity[4];
	for (int i = 0; i < 4; i++)
	{
		Severity[i] = (DWORD)jseverity[i];
	}
	//赋值Enabled
	jboolean jenabled[4];
	env->SetBooleanArrayRegion(enabled, 0, 4, jenabled);
	BOOL Enabled[4];
	for (int i = 0; i < 4; i++)
	{
		Enabled[i] = (BOOL)jenabled[i];
	}
	//初始化一个HANDLE
	HANDLE Handle = NULL;
	//赋值Value，并转化为VARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//初期化为VT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value类型为INT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value类型为DOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value类型为BOOLEAN
	{
		if (strcmp("true", Value) == 0)//因为java中使用的是true/false，此处是为了兼容
		{
			BOOL Bvalue = 1;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else if (strcmp("false", Value) == 0)
		{
			BOOL Bvalue = 0;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else//如果输入的不是true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value类型为STRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		Handle = CreateSecureTag(Name, Vvalue, OPC_QUALITY_GOOD, ReadAccessLevel, WriteAccessLevel);
		VariantClear(&Vvalue);//清除Vvlaue
		SysFreeString(BSValue);//回收
	}
	else
	{
		printf("C++提示：数据类型输入错误，AllAddTag失败");
		VariantClear(&Vvalue);//清除Vvlaue
		env->ReleaseStringUTFChars(name, Name);
		env->ReleaseStringUTFChars(property, Property);
		env->ReleaseStringUTFChars(property_value, Property_value);
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return -2;
	}
	//调用DLL文件
	if (strcmp("VT_STRING", Value_type) != 0)//Value类型不为STRING，为了解决SysFreeString(BSValue);的问题
	{
		Handle = CreateSecureTag(Name, Vvalue, OPC_QUALITY_GOOD, ReadAccessLevel, WriteAccessLevel);
		VariantClear(&Vvalue);//清除Vvlaue
	}

	//设置属性和属性值
	VARIANT	PropertyValue;
	VariantInit(&PropertyValue);//初期化为VT_EMPTY
	PropertyValue.vt = VT_BSTR;//unsigned short，表示数据类型
	CString CProperty_value = Property_value;//const char*--》CString
	WCHAR *pWCHAR = WSTRFromCString(CProperty_value);//CString——》WCHAR
	PropertyValue.bstrVal = SysAllocString(pWCHAR);
	WSTRFree(pWCHAR);//释放WCHAR类型的数据源
					 //调用DLL函数，标记属性是与OPC项目关联的值
	SetTagProperties(Handle, 100, Property, PropertyValue);
	VariantClear(&PropertyValue);//清除PropertyValue


	//调用DLL
	SetItemLevelAlarm(Handle, ID_LOLO_LIMIT, Limits[0], Severity[0], Enabled[0]);
	SetItemLevelAlarm(Handle, ID_LO_LIMIT, Limits[1], Severity[1], Enabled[1]);
	SetItemLevelAlarm(Handle, ID_HI_LIMIT, Limits[2], Severity[2], Enabled[2]);
	SetItemLevelAlarm(Handle, ID_HIHI_LIMIT, Limits[3], Severity[3], Enabled[3]);

	//回收资源
	env->ReleaseStringUTFChars(name, Name);
	env->ReleaseStringUTFChars(property, Property);
	env->ReleaseStringUTFChars(property_value, Property_value);
	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	printf("C++提示：AllAddTag,HANDLE=%u\n", (UINT32)Handle);
	return (UINT32)Handle;//返回以整数的形式传递HANDLE指针
}
//**********************整体更新Tag*************************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_AllUpdateTag(JNIEnv *env, jobject obj, jlong handle, jstring property, jstring property_value, jstring value, jstring value_type, jfloatArray limits, jlongArray severity, jbooleanArray enabled)
{
	//赋值Property
	const char *Property = env->GetStringUTFChars(property, NULL);
	//用于判断更新是否成功
	BOOL jb1 = 0;
	//赋值Property_value
	const char *Property_value = env->GetStringUTFChars(property_value, NULL);
	//赋值Limits
	jfloat jlimits[4];
	env->GetFloatArrayRegion(limits, 0, 4, jlimits);
	float Limits[4];
	for (int i = 0; i < 4; i++)
	{
		Limits[i] =(float)jlimits[i];
	}
	//赋值Severity
	jlong jseverity[4];
	env->GetLongArrayRegion(severity, 0, 4, jseverity);
	DWORD Severity[4];
	for (int i = 0; i < 4; i++)
	{
		Severity[i] = (DWORD)jseverity[i];
	}
	//赋值Enabled
	jboolean jenabled[4];
	env->SetBooleanArrayRegion(enabled, 0, 4, jenabled);
	BOOL Enabled[4];
	for (int i = 0; i < 4; i++)
	{
		Enabled[i] = (BOOL)jenabled[i];
	}
	//赋值Handle
	HANDLE Handle = (HANDLE)handle;
	//赋值Value，并转化为VARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//初期化为VT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value类型为INT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value类型为DOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value类型为BOOLEAN
	{
		if (strcmp("true", Value) == 0)//因为java中使用的是true/false，此处是为了兼容
		{
			BOOL Bvalue = 1;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else if (strcmp("false", Value) == 0)
		{
			BOOL Bvalue = 0;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else//如果输入的不是true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value类型为STRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		jb1 = UpdateTag(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//清除Vvlaue
		SysFreeString(BSValue);//回收
	}
	else
	{
		printf("C++提示：数据类型输入错误，AllAddTag失败");
		VariantClear(&Vvalue);//清除Vvlaue
		env->ReleaseStringUTFChars(property, Property);
		env->ReleaseStringUTFChars(property_value, Property_value);
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return (jboolean)0;
	}
	//调用DLL文件
	if (strcmp("VT_STRING", Value_type) != 0)//Value类型不为STRING，为了解决SysFreeString(BSValue);的问题
	{
		jb1 = UpdateTag(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//清除Vvlaue
	}

	//设置属性和属性值
	VARIANT	PropertyValue;
	VariantInit(&PropertyValue);//初期化为VT_EMPTY
	PropertyValue.vt = VT_BSTR;//unsigned short，表示数据类型
	CString CProperty_value = Property_value;//const char*--》CString
	WCHAR *pWCHAR = WSTRFromCString(CProperty_value);//CString——》WCHAR
	PropertyValue.bstrVal = SysAllocString(pWCHAR);
	WSTRFree(pWCHAR);//释放WCHAR类型的数据源
					 //调用DLL函数，标记属性是与OPC项目关联的值
	BOOL jb2 = SetTagProperties(Handle, 100, Property, PropertyValue);
	VariantClear(&PropertyValue);//清除PropertyValue


	//调用DLL
	BOOL jb3 = SetItemLevelAlarm(Handle, ID_LOLO_LIMIT, Limits[0], Severity[0], Enabled[0]);
	BOOL jb4 = SetItemLevelAlarm(Handle, ID_LO_LIMIT, Limits[1], Severity[1], Enabled[1]);
	BOOL jb5 = SetItemLevelAlarm(Handle, ID_HI_LIMIT, Limits[2], Severity[2], Enabled[2]);
	BOOL jb6 = SetItemLevelAlarm(Handle, ID_HIHI_LIMIT, Limits[3], Severity[3], Enabled[3]);

	env->ReleaseStringUTFChars(property, Property);
	env->ReleaseStringUTFChars(property_value, Property_value);
	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	if (jb1 + jb2 + jb3 + jb4 + jb5 + jb6 == 6) return (jboolean)1;
	else return (jboolean)0;
}
//**********************开启批量更新Tag**********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_StartUpdateTags(JNIEnv *env, jobject obj)
{
	//调用DLL
	BOOL bj = StartUpdateTags();

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//***********************批量更新Tag*************************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UpdateTagToList(JNIEnv *env, jobject obj, jlong handle, jstring value, jstring value_type)
{
	//赋值Handle
	HANDLE Handle = (HANDLE)handle;
	//用于判断更新是否成功
	BOOL bj = 0;
	//赋值Value，并转化为VARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//初期化为VT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value类型为INT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value类型为DOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value类型为BOOLEAN
	{
		if (strcmp("true", Value) == 0)//因为java中使用的是true/false，此处是为了兼容
		{
			BOOL Bvalue = 1;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else if (strcmp("false", Value) == 0)
		{
			BOOL Bvalue = 0;
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
		else//如果输入的不是true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value类型为STRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		bj = UpdateTagToList(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//清除Vvlaue
		SysFreeString(BSValue);//回收
	}
	else
	{
		printf("C++提示：数据类型输入错误，UpdateTag失败");
		VariantClear(&Vvalue);//清除Vvlaue
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return (jboolean)0;
	}
	//调用DLL文件
	if (strcmp("VT_STRING", Value_type) != 0)//Value类型不为STRING，为了解决SysFreeString(BSValue);的问题
	{
		bj = UpdateTagToList(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//清除Vvlaue
	}

	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	if (bj == 1) return (jboolean)1;

	return  (jboolean)0;

}
//***********************关闭批量更新Tag*********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_EndUpdateTags(JNIEnv *env, jobject obj)
{
	//调用DLL
	BOOL bj = EndUpdateTags();

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//**********************设置Tag的报警限值********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_SetItemLevelAlarm(JNIEnv *env, jobject obj, jlong handle, jint levelid, jfloat limits, jlong severity, jboolean enabled)
{
	//赋值Handle
	HANDLE Handle = (HANDLE)handle;
	//赋值LevelID
	int LevelID = (int)levelid;
	//赋值Limits
	float Limits = (float)limits;
	//赋值Severity 
	DWORD Severity = (DWORD)severity;
	//赋值Enabled
	BOOL Enabled = (BOOL)enabled;
	//调用DLL
	BOOL bj = SetItemLevelAlarm(Handle, LevelID, Limits, Severity, Enabled);

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//*********************读取tag的报警限值*********************************//
JNIEXPORT jstring JNICALL Java_com_st_opcserver_dll_STOPCServer_GetItemLevelAlarm(JNIEnv *env, jobject obj, jlong handle, jint levelid)
{
	//赋值Handle
	HANDLE Handle = (HANDLE)handle;
	//赋值LevelID
	int LevelID = (int)levelid;

	float Limits = 0;
	DWORD Severity = 0;
	BOOL Enabled = 0;
	BOOL bj = GetItemLevelAlarm(Handle, LevelID, &Limits, &Severity, &Enabled);
	if (bj)
	{
		string point = "*";//用来隔开每个数据，方便在java中分开
		string SLimits = to_string(Limits);
		string SSeverity = to_string(Severity);
		string SEnabled = to_string(Enabled);
		string Send = SLimits + point + SSeverity + point + SEnabled;
		const char *Csend = Send.data();
		jstring jsend = env->NewStringUTF(Csend);
		return jsend;
	}
	else//如果读取失败，返回null
	{
		const char *Csend = "null";
		jstring jsend = env->NewStringUTF(Csend);
		return jsend;
	}
}
//*********************开启或关闭tag对客户端的更新********************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_SuspendTagUpdates(JNIEnv *env, jobject obj, jlong handle, jboolean onoff)
{
	//赋值Handle
	HANDLE Handle = (HANDLE)handle;
	//赋值OnOff
	BOOL OnOff = (BOOL)onoff;
	//调用DLL
	BOOL bj = SuspendTagUpdates(Handle, OnOff);

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}