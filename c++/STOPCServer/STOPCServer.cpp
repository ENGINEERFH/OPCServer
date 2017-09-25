// STOPCServer.cpp : ���� DLL Ӧ�ó���ĵ���������
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
		for (i = 0; i<length; i++) temp[i] = (WCHAR)buf[i];//ʹ��ǿ������ת������ʽ
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
// Write֪ͨ�ص����ݿؼ����������ر�ǩ�б����ͼ
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


//***********************��ʾDLL�ļ��汾��Ϣ*****************************//
JNIEXPORT jstring JNICALL Java_com_st_opcserver_dll_STOPCServer_OPCsvrRevision(JNIEnv *env, jobject obj)
{
	WORD	rev;
	char buf[100];
	rev = WTOPCsvrRevision();
	sprintf_s(buf, "DLL Rev = %x", rev);
	jstring jsrev = env->NewStringUTF(buf);//char*תjstring
	return jsrev;
}
//**************************ע�������***********************************//
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
//**************************ж�ط�����***********************************//
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
//*************************��ʼ��������**********************************//
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
//*************************ȥ���������ĳ�ʼ��****************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UninitServer(JNIEnv *env, jobject obj)
{
	//����DLL
	BOOL bj = UninitWTOPCsvr();

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//***********************���ķ������ĸ�������****************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_ResetServerRate(JNIEnv *env, jobject obj, jint serverrate)
{
	//��ֵServerrate
	UINT Serverrate = (UINT)serverrate;
	//����DLL
	BOOL bj = ResetServerRate(Serverrate);

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//****************�������ӵ��������ϵĿͻ�������*************************//
JNIEXPORT jint JNICALL Java_com_st_opcserver_dll_STOPCServer_NumbrClientConnections(JNIEnv *env, jobject obj)
{
	int nb = NumbrClientConnections();
	return (jint)nb;
}
//*****************ǿ�ƶϿ����пͻ��˵�����******************************//
JNIEXPORT void JNICALL Java_com_st_opcserver_dll_STOPCServer_RequestDisconnect(JNIEnv *env, jobject obj)
{
	RequestDisconnect();
}
//*****************ǿ�Ʒ�������ͻ��˷������ݸ���************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_RefreshAllClients(JNIEnv *env, jobject obj)
{
	BOOL bj = RefreshAllClients();

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//**********************����tag�����ռ�ֲ��ı�־��Ĭ��Ϊ"."*************//
JNIEXPORT jchar JNICALL Java_com_st_opcserver_dll_STOPCServer_SetTagNameQualifier(JNIEnv *env, jobject obj, jchar qualifier)
{
	//��ֵQualifier
	char Qualifier = (char)qualifier;
	char c = SetWtOPCsvrQualifier(Qualifier);
	return (jchar)c;
}
//*************************����tag���Ե���ϸ��Ϣ*************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_SetTagProperties(JNIEnv *env, jobject obj, jlong handle, jlong propertyid, jstring property, jstring property_value)
{
	//��ֵHandle
	HANDLE Handle = (HANDLE)handle;
	//��ֵPropertyid
	DWORD Propertyid = (DWORD)Propertyid;
	//��ֵDescription
	const char * Ccproperty = env->GetStringUTFChars(property, NULL);
	LPCSTR Property = Ccproperty;
	//��ֵProperty_Value
	const char *Property_Value = env->GetStringUTFChars(property_value, NULL);
	CString CProperty_Value = Property_Value;
	BSTR BSCProperty_Value = CProperty_Value.AllocSysString();
	VARIANT	PropertyValue;
	VariantInit(&PropertyValue);//���ڻ�ΪVT_EMPTY
	PropertyValue.vt = VT_BSTR;
	PropertyValue.bstrVal = BSCProperty_Value;
	//����DLL
	BOOL bj = SetTagProperties(Handle, Propertyid, Property, PropertyValue);
	
	//�����ڴ�
	VariantClear(&PropertyValue);//���Vvlaue
	SysFreeString(BSCProperty_Value);//����
	env->ReleaseStringUTFChars(property, Ccproperty);
	env->ReleaseStringUTFChars(property_value, Property_Value);

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//***************************ɾ��Tag*************************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_DeleteTag(JNIEnv *env, jobject obj, jlong handle)
{
	HANDLE Handle = (HANDLE)handle;
	if (RemoveTag(Handle))
		return (jboolean)1;
	else return (jboolean)0;
}
//***************************�����򵥵�Tag*************************************//
JNIEXPORT jlong JNICALL Java_com_st_opcserver_dll_STOPCServer_AddTag(JNIEnv *env, jobject obj, jstring name, jstring value, jstring value_type, jboolean iswritable)
{
	//��ֵName
	const char *Name = env->GetStringUTFChars(name, NULL);
	//��ֵiswritable
	BOOL IsWritable = iswritable;
	//��ʼ��һ��HANDLE
	HANDLE Handle = NULL;
	//��ֵValue����ת��ΪVARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//���ڻ�ΪVT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value����ΪINT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value����ΪDOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value����ΪBOOLEAN
	{
		if (strcmp("true", Value) == 0)//��Ϊjava��ʹ�õ���true/false���˴���Ϊ�˼���
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
		else//�������Ĳ���true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value����ΪSTRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		Handle = CreateTag(Name, Vvalue, OPC_QUALITY_GOOD, IsWritable);
		VariantClear(&Vvalue);//���Vvlaue
		SysFreeString(BSValue);//����
	}
	else
	{
		printf("C++��ʾ�����������������AddTagʧ��");
		VariantClear(&Vvalue);//���Vvlaue
		env->ReleaseStringUTFChars(name, Name);
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return -2;
	}
	//����DLL�ļ�
	if (strcmp("VT_STRING", Value_type) != 0)//Value���Ͳ�ΪSTRING
	{
		Handle = CreateTag(Name, Vvalue, OPC_QUALITY_GOOD, IsWritable);
		VariantClear(&Vvalue);//���Vvlaue
	}

	env->ReleaseStringUTFChars(name, Name);
	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);
	printf("C++��ʾ��AddTag,HANDLE=%u\n", (UINT32)Handle);
	return (UINT32)Handle;
}
//*************************���¼򵥵�Tag***************************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UpdateTag(JNIEnv *env, jobject obj, jlong handle, jstring value, jstring value_type)
{
	//��ֵHANDLE
	HANDLE Handle = (HANDLE)handle;
	//�����жϸ����Ƿ�ɹ�
	BOOL bj = 0;
	//��ֵValue����ת��ΪVARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//���ڻ�ΪVT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value����ΪINT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value����ΪDOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value����ΪBOOLEAN
	{
		if (strcmp("true", Value) == 0)//��Ϊjava��ʹ�õ���true/false���˴���Ϊ�˼���
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
		else//�������Ĳ���true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value����ΪSTRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		bj = UpdateTag(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//���Vvlaue
		SysFreeString(BSValue);//����
	}
	else
	{
		printf("C++��ʾ�����������������UpdateTagʧ��");
		VariantClear(&Vvalue);//���Vvlaue
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return (jboolean)0;
	}
	//����DLL�ļ�
	if (strcmp("VT_STRING", Value_type) != 0)//Value���Ͳ�ΪSTRING��Ϊ�˽��SysFreeString(BSValue);������
	{
		bj = UpdateTag(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//���Vvlaue
	}

	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	if (bj == 1) return (jboolean)1;

	return  (jboolean)0;
}
//************************����Tag by name********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UpdateTagByName(JNIEnv *env, jobject obj, jstring name, jstring value, jstring value_type)
{
	//��ֵName
	const char *Name = env->GetStringUTFChars(name, NULL);
	//�����жϸ����Ƿ�ɹ�
	BOOL bj = 0;
	//��ֵValue����ת��ΪVARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//���ڻ�ΪVT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value����ΪINT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value����ΪDOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value����ΪBOOLEAN
	{
		if (strcmp("true", Value) == 0)//��Ϊjava��ʹ�õ���true/false���˴���Ϊ�˼���
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
		else//�������Ĳ���true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value����ΪSTRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		bj = UpdateTagByName(Name, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//���Vvlaue
		SysFreeString(BSValue);//����
	}
	else
	{
		printf("C++��ʾ�����������������UpdateTagʧ��");
		VariantClear(&Vvalue);//���Vvlaue
		env->ReleaseStringUTFChars(name, Name);
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return (jboolean)0;
	}
	//����DLL�ļ�
	if (strcmp("VT_STRING", Value_type) != 0)//Value���Ͳ�ΪSTRING��Ϊ�˽��SysFreeString(BSValue);������
	{
		bj = UpdateTagByName(Name, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//���Vvlaue
	}

	env->ReleaseStringUTFChars(name, Name);
	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	if (bj == 1) return (jboolean)1;
	return  (jboolean)0;

}
//************************��ȡTag****************************************//
JNIEXPORT jstring JNICALL Java_com_st_opcserver_dll_STOPCServer_ReadTag(JNIEnv *env, jobject obj, jlong handle)
{
	//��ֵHANDLE
	HANDLE Handle = (HANDLE)handle;
	//��ȡValue
	VARIANT Value;
	VariantInit(&Value);//���ڻ�ΪVT_EMPTY
	ReadTag(Handle, &Value);
	if (Value.vt == VT_INT)//��������ΪINT
	{
		int Ivalue = Value.intVal;
		string Svalue = to_string(Ivalue);
		string Value_type = "VT_INT";
		string Stvalue = Value_type + Svalue;
		const char *Ccvalue = Stvalue.data();
		jstring Vvalue = env->NewStringUTF(Ccvalue);
		printf("C++��ʾ��HANDLE = %u", handle);
		printf("��Tagֵ = %s\n", Ccvalue);
		VariantClear(&Value);//���Value
		return Vvalue;
	}
	else if (Value.vt == VT_R8)//��������ΪDOUBLE
	{
		double Dvalue = Value.dblVal;
		string Svalue = to_string(Dvalue);
		string Value_type = "VT_DOUBLE";
		string Stvalue = Value_type + Svalue;
		const char *Ccvalue = Stvalue.data();
		jstring Vvalue = env->NewStringUTF(Ccvalue);
		printf("C++��ʾ��HANDLE = %u", handle);
		printf("��Tagֵ = %s\n", Ccvalue);
		VariantClear(&Value);//���Value
		return Vvalue;
	}
	else if (Value.vt == VT_BOOL)//��������ΪBOOLEAN
	{
		BOOL Bvalue = Value.boolVal;
		string Svalue = to_string(Bvalue);
		string Value_type = "VT_BOOLEAN";
		string Stvalue = Value_type + Svalue;
		const char *Ccvalue = Stvalue.data();
		jstring Vvalue = env->NewStringUTF(Ccvalue);
		printf("C++��ʾ��HANDLE = %u", handle);
		printf("��Tagֵ = %s\n", Ccvalue);
		VariantClear(&Value);//���Value
		return Vvalue;
	}
	else if (Value.vt == VT_BSTR)
	{
		BSTR Bvalue = Value.bstrVal;
		const char* TCcvalue = _com_util::ConvertBSTRToString(Bvalue);//BSTR--��const char *
		string Svalue = TCcvalue;
		string Value_type = "VT_STRING";
		string Stvalue = Value_type + Svalue;
		const char *Ccvalue = Stvalue.data();
		jstring Vvalue = env->NewStringUTF(Ccvalue);
		printf("C++��ʾ��HANDLE = %u", handle);
		printf("��Tagֵ = %s\n", Ccvalue);
		SysFreeString(Bvalue);//�ͷ�Bvalue
		VariantClear(&Value);//���Value
		return Vvalue;
	}
	//�������ʹ���
	const char *Ccvalue = "VT_ERROR";
	jstring Vvalue = env->NewStringUTF(Ccvalue);
	printf("C++��ʾ��HANDLE = %u", handle);
	printf("��Tagֵ = %s\n", Ccvalue);
	VariantClear(&Value);//���Value
	return Vvalue;
}
//************************���崴��Tag***********************************//
JNIEXPORT jlong JNICALL Java_com_st_opcserver_dll_STOPCServer_AllAddTag(JNIEnv *env, jobject obj, jstring name, jstring property, jstring property_value, jstring value, jstring value_type, jlong readAccesslevel, jlong writeAccessLevel, jfloatArray limits, jlongArray severity, jbooleanArray enabled)
{
	//��ֵName
	const char *Name = env->GetStringUTFChars(name, NULL);
	//��ֵProperty
	const char *Property = env->GetStringUTFChars(property, NULL);
	//��ֵProperty_value
	const char *Property_value = env->GetStringUTFChars(property_value, NULL);
	//��ֵReadAccessLevel
	DWORD ReadAccessLevel = (DWORD)readAccesslevel;
	//��ֵWriteAccessLevel
	DWORD WriteAccessLevel = (DWORD)writeAccessLevel;
	//��ֵLimits
	jfloat jlimits[4];
	env->GetFloatArrayRegion(limits, 0, 4, jlimits);
	float Limits[4];
	for (int i = 0; i < 4; i++)
	{
		Limits[i] = (float)jlimits[i];
	}
	//��ֵSeverity
	jlong jseverity[4];
	env->GetLongArrayRegion(severity, 0, 4, jseverity);
	DWORD Severity[4];
	for (int i = 0; i < 4; i++)
	{
		Severity[i] = (DWORD)jseverity[i];
	}
	//��ֵEnabled
	jboolean jenabled[4];
	env->SetBooleanArrayRegion(enabled, 0, 4, jenabled);
	BOOL Enabled[4];
	for (int i = 0; i < 4; i++)
	{
		Enabled[i] = (BOOL)jenabled[i];
	}
	//��ʼ��һ��HANDLE
	HANDLE Handle = NULL;
	//��ֵValue����ת��ΪVARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//���ڻ�ΪVT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value����ΪINT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value����ΪDOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value����ΪBOOLEAN
	{
		if (strcmp("true", Value) == 0)//��Ϊjava��ʹ�õ���true/false���˴���Ϊ�˼���
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
		else//�������Ĳ���true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value����ΪSTRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		Handle = CreateSecureTag(Name, Vvalue, OPC_QUALITY_GOOD, ReadAccessLevel, WriteAccessLevel);
		VariantClear(&Vvalue);//���Vvlaue
		SysFreeString(BSValue);//����
	}
	else
	{
		printf("C++��ʾ�����������������AllAddTagʧ��");
		VariantClear(&Vvalue);//���Vvlaue
		env->ReleaseStringUTFChars(name, Name);
		env->ReleaseStringUTFChars(property, Property);
		env->ReleaseStringUTFChars(property_value, Property_value);
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return -2;
	}
	//����DLL�ļ�
	if (strcmp("VT_STRING", Value_type) != 0)//Value���Ͳ�ΪSTRING��Ϊ�˽��SysFreeString(BSValue);������
	{
		Handle = CreateSecureTag(Name, Vvalue, OPC_QUALITY_GOOD, ReadAccessLevel, WriteAccessLevel);
		VariantClear(&Vvalue);//���Vvlaue
	}

	//�������Ժ�����ֵ
	VARIANT	PropertyValue;
	VariantInit(&PropertyValue);//���ڻ�ΪVT_EMPTY
	PropertyValue.vt = VT_BSTR;//unsigned short����ʾ��������
	CString CProperty_value = Property_value;//const char*--��CString
	WCHAR *pWCHAR = WSTRFromCString(CProperty_value);//CString������WCHAR
	PropertyValue.bstrVal = SysAllocString(pWCHAR);
	WSTRFree(pWCHAR);//�ͷ�WCHAR���͵�����Դ
					 //����DLL�����������������OPC��Ŀ������ֵ
	SetTagProperties(Handle, 100, Property, PropertyValue);
	VariantClear(&PropertyValue);//���PropertyValue


	//����DLL
	SetItemLevelAlarm(Handle, ID_LOLO_LIMIT, Limits[0], Severity[0], Enabled[0]);
	SetItemLevelAlarm(Handle, ID_LO_LIMIT, Limits[1], Severity[1], Enabled[1]);
	SetItemLevelAlarm(Handle, ID_HI_LIMIT, Limits[2], Severity[2], Enabled[2]);
	SetItemLevelAlarm(Handle, ID_HIHI_LIMIT, Limits[3], Severity[3], Enabled[3]);

	//������Դ
	env->ReleaseStringUTFChars(name, Name);
	env->ReleaseStringUTFChars(property, Property);
	env->ReleaseStringUTFChars(property_value, Property_value);
	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	printf("C++��ʾ��AllAddTag,HANDLE=%u\n", (UINT32)Handle);
	return (UINT32)Handle;//��������������ʽ����HANDLEָ��
}
//**********************�������Tag*************************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_AllUpdateTag(JNIEnv *env, jobject obj, jlong handle, jstring property, jstring property_value, jstring value, jstring value_type, jfloatArray limits, jlongArray severity, jbooleanArray enabled)
{
	//��ֵProperty
	const char *Property = env->GetStringUTFChars(property, NULL);
	//�����жϸ����Ƿ�ɹ�
	BOOL jb1 = 0;
	//��ֵProperty_value
	const char *Property_value = env->GetStringUTFChars(property_value, NULL);
	//��ֵLimits
	jfloat jlimits[4];
	env->GetFloatArrayRegion(limits, 0, 4, jlimits);
	float Limits[4];
	for (int i = 0; i < 4; i++)
	{
		Limits[i] =(float)jlimits[i];
	}
	//��ֵSeverity
	jlong jseverity[4];
	env->GetLongArrayRegion(severity, 0, 4, jseverity);
	DWORD Severity[4];
	for (int i = 0; i < 4; i++)
	{
		Severity[i] = (DWORD)jseverity[i];
	}
	//��ֵEnabled
	jboolean jenabled[4];
	env->SetBooleanArrayRegion(enabled, 0, 4, jenabled);
	BOOL Enabled[4];
	for (int i = 0; i < 4; i++)
	{
		Enabled[i] = (BOOL)jenabled[i];
	}
	//��ֵHandle
	HANDLE Handle = (HANDLE)handle;
	//��ֵValue����ת��ΪVARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//���ڻ�ΪVT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value����ΪINT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value����ΪDOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value����ΪBOOLEAN
	{
		if (strcmp("true", Value) == 0)//��Ϊjava��ʹ�õ���true/false���˴���Ϊ�˼���
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
		else//�������Ĳ���true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value����ΪSTRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		jb1 = UpdateTag(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//���Vvlaue
		SysFreeString(BSValue);//����
	}
	else
	{
		printf("C++��ʾ�����������������AllAddTagʧ��");
		VariantClear(&Vvalue);//���Vvlaue
		env->ReleaseStringUTFChars(property, Property);
		env->ReleaseStringUTFChars(property_value, Property_value);
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return (jboolean)0;
	}
	//����DLL�ļ�
	if (strcmp("VT_STRING", Value_type) != 0)//Value���Ͳ�ΪSTRING��Ϊ�˽��SysFreeString(BSValue);������
	{
		jb1 = UpdateTag(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//���Vvlaue
	}

	//�������Ժ�����ֵ
	VARIANT	PropertyValue;
	VariantInit(&PropertyValue);//���ڻ�ΪVT_EMPTY
	PropertyValue.vt = VT_BSTR;//unsigned short����ʾ��������
	CString CProperty_value = Property_value;//const char*--��CString
	WCHAR *pWCHAR = WSTRFromCString(CProperty_value);//CString������WCHAR
	PropertyValue.bstrVal = SysAllocString(pWCHAR);
	WSTRFree(pWCHAR);//�ͷ�WCHAR���͵�����Դ
					 //����DLL�����������������OPC��Ŀ������ֵ
	BOOL jb2 = SetTagProperties(Handle, 100, Property, PropertyValue);
	VariantClear(&PropertyValue);//���PropertyValue


	//����DLL
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
//**********************������������Tag**********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_StartUpdateTags(JNIEnv *env, jobject obj)
{
	//����DLL
	BOOL bj = StartUpdateTags();

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//***********************��������Tag*************************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_UpdateTagToList(JNIEnv *env, jobject obj, jlong handle, jstring value, jstring value_type)
{
	//��ֵHandle
	HANDLE Handle = (HANDLE)handle;
	//�����жϸ����Ƿ�ɹ�
	BOOL bj = 0;
	//��ֵValue����ת��ΪVARIANT
	const char *Value = env->GetStringUTFChars(value, NULL);
	const char *Value_type = env->GetStringUTFChars(value_type, NULL);
	VARIANT Vvalue;
	VariantInit(&Vvalue);//���ڻ�ΪVT_EMPTY
	if (strcmp("VT_INT", Value_type) == 0)//Value����ΪINT
	{
		string Svalue = Value;
		int Ivalue = stoi(Svalue);
		Vvalue.vt = VT_INT;
		Vvalue.intVal = Ivalue;
	}
	else if (strcmp("VT_DOUBLE", Value_type) == 0)//Value����ΪDOUBLE
	{
		string Svalue = Value;
		double Dvalue = stod(Svalue);
		Vvalue.vt = VT_R8;
		Vvalue.dblVal = Dvalue;
	}
	else if (strcmp("VT_BOOLEAN", Value_type) == 0)//Value����ΪBOOLEAN
	{
		if (strcmp("true", Value) == 0)//��Ϊjava��ʹ�õ���true/false���˴���Ϊ�˼���
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
		else//�������Ĳ���true/falae
		{
			string Svalue = Value;
			BOOL Bvalue = stoi(Svalue);
			Vvalue.vt = VT_BOOL;
			Vvalue.boolVal = Bvalue;
		}
	}
	else if (strcmp("VT_STRING", Value_type) == 0)//Value����ΪSTRING
	{
		CString Cvalue = Value;
		BSTR BSValue = Cvalue.AllocSysString();
		Vvalue.vt = VT_BSTR;
		Vvalue.bstrVal = BSValue;
		bj = UpdateTagToList(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//���Vvlaue
		SysFreeString(BSValue);//����
	}
	else
	{
		printf("C++��ʾ�����������������UpdateTagʧ��");
		VariantClear(&Vvalue);//���Vvlaue
		env->ReleaseStringUTFChars(value, Value);
		env->ReleaseStringUTFChars(value_type, Value_type);
		return (jboolean)0;
	}
	//����DLL�ļ�
	if (strcmp("VT_STRING", Value_type) != 0)//Value���Ͳ�ΪSTRING��Ϊ�˽��SysFreeString(BSValue);������
	{
		bj = UpdateTagToList(Handle, Vvalue, OPC_QUALITY_GOOD);
		VariantClear(&Vvalue);//���Vvlaue
	}

	env->ReleaseStringUTFChars(value, Value);
	env->ReleaseStringUTFChars(value_type, Value_type);

	if (bj == 1) return (jboolean)1;

	return  (jboolean)0;

}
//***********************�ر���������Tag*********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_EndUpdateTags(JNIEnv *env, jobject obj)
{
	//����DLL
	BOOL bj = EndUpdateTags();

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//**********************����Tag�ı�����ֵ********************************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_SetItemLevelAlarm(JNIEnv *env, jobject obj, jlong handle, jint levelid, jfloat limits, jlong severity, jboolean enabled)
{
	//��ֵHandle
	HANDLE Handle = (HANDLE)handle;
	//��ֵLevelID
	int LevelID = (int)levelid;
	//��ֵLimits
	float Limits = (float)limits;
	//��ֵSeverity 
	DWORD Severity = (DWORD)severity;
	//��ֵEnabled
	BOOL Enabled = (BOOL)enabled;
	//����DLL
	BOOL bj = SetItemLevelAlarm(Handle, LevelID, Limits, Severity, Enabled);

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}
//*********************��ȡtag�ı�����ֵ*********************************//
JNIEXPORT jstring JNICALL Java_com_st_opcserver_dll_STOPCServer_GetItemLevelAlarm(JNIEnv *env, jobject obj, jlong handle, jint levelid)
{
	//��ֵHandle
	HANDLE Handle = (HANDLE)handle;
	//��ֵLevelID
	int LevelID = (int)levelid;

	float Limits = 0;
	DWORD Severity = 0;
	BOOL Enabled = 0;
	BOOL bj = GetItemLevelAlarm(Handle, LevelID, &Limits, &Severity, &Enabled);
	if (bj)
	{
		string point = "*";//��������ÿ�����ݣ�������java�зֿ�
		string SLimits = to_string(Limits);
		string SSeverity = to_string(Severity);
		string SEnabled = to_string(Enabled);
		string Send = SLimits + point + SSeverity + point + SEnabled;
		const char *Csend = Send.data();
		jstring jsend = env->NewStringUTF(Csend);
		return jsend;
	}
	else//�����ȡʧ�ܣ�����null
	{
		const char *Csend = "null";
		jstring jsend = env->NewStringUTF(Csend);
		return jsend;
	}
}
//*********************������ر�tag�Կͻ��˵ĸ���********************//
JNIEXPORT jboolean JNICALL Java_com_st_opcserver_dll_STOPCServer_SuspendTagUpdates(JNIEnv *env, jobject obj, jlong handle, jboolean onoff)
{
	//��ֵHandle
	HANDLE Handle = (HANDLE)handle;
	//��ֵOnOff
	BOOL OnOff = (BOOL)onoff;
	//����DLL
	BOOL bj = SuspendTagUpdates(Handle, OnOff);

	if (bj) return (jboolean)1;
	else return (jboolean)0;
}