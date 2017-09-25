
/////////////////////////////////////////////////////////////////////////////////////////////
//
//	Callback Definitions 回调定义
//
//	Used by the DLL to pass control back to the Server Application
//  由DLL使用将控制传递回服务器应用程序
//	Each callback must be explicitly enabled by calling one of the following
//  每个回调必须通过调用以下方法之一显式启用
//	exported API functions:
//  导出的API函数:
//					EnableWriteNotification (WRITENOTIFYPROC lpCallback);
//					EnableUnknownItemNotification (UNKNOWNITEMPROC lpCallback);
//					EnableItemRemovalNotification (ITEMREMOVEDPROC lpCallback);
//					EnableDisconnectNotification (DISCONNECTPROC lpCallback);
//					EnableEventMsgs (EVENTMSGPROC lpCallback);
//					EnableRateNotification (RATECHANGEPROC lpCallback);
//					EnableDeviceRead (DEVICEREADPROC lpCallback);
//		
//
//	WRITENOTIFYPROC
		//Signals the Application that an OPC Client has requested a write to a 
		//tag.  HANDLE value represents the tag, VARIANT* defines the new data,
		//and DWORD* allows the application to return either S_OK or an ERROR result
		//	向应用程序发送OPC客户端请求写入的信号
		//	标签。 HANDLE值表示标签，VARIANT *定义新数据，
		//	和DWORD *允许应用程序返回S_OK或ERROR结果
//	UNKNOWNITEMPROC
		//Signals the Application that a Client has requested a tag that has
		//not been previously defined, (or has been suspended).  The two character
		//pointer arguments represent the OPC Path Name and Item Name of the requested 
		//tag.  This callback allows the Server Application to operate with dynamic
		//tags that are created and maintained only when subscribed to by a connected
		//Client.
		//	向应用程序通知客户端请求了具有的标记
		//	以前未定义，（或已暂停）。 两个字符
		//	指针参数表示所请求的OPC路径名称和项目名称
		//	标签。 此回调允许服务器应用程序使用动态操作
		//	标签，只有在由连接订阅时才创建和维护
		//	客户。
//	ITEMREMOVEDPROC
		//Works in conjuction with the above UNKNOWNITEMPROC.  This callback signals the
		//Application that the last client subscription for a given item has ended.  The
		//HANDLE of the tag item is returned as well as the Path and Item Name.  The
		//Server Application may choose to remove or suspend the tag when no clients are
		//subscribing to the data.  
		//	与上述UNKNOWNITEMPROC结合使用。 这个回调信号
		//	给定项目的最后一个客户端订阅已结束的应用程序。 的
		//	返回标签项的HANDLE以及路径和项名称。 的
		//	当没有客户端时，服务器应用程序可以选择删除或挂起标签
		//	订阅数据。
//	DISCONNECTPROC
		//Notifies the Server Application whenever a client disconnects.  The DWORD argument
		//defines the number of client connections remaining.  This callback may be used
		//to shutdown the server when the last client disconnects.
		//	每当客户端断开连接时通知服务器应用程序。 DWORD参数
		//	定义剩余的客户端连接数。 可以使用此回调
		//	以在最后一个客户端断开连接时关闭服务器。
//	EVENTMSGPROC
		//Allows the Application to receive event messages from the WtOPCsvr.dll for
		//tracing OPC Client Interface calls.  Primarily used for debugging purposes.
		//	允许应用程序接收来自WtOPCsvr.dll的事件消息
		//	跟踪OPC客户端接口调用。 主要用于调试目的。
//
//	RATECHANGEPROC
		//Notifies the Application of the fastest update rate requested by a client for an item.
		//May be used to selectively change the server side data refresh rate to optimize
		//operation for different client connections.
		//	通知应用程序客户端为项目请求的最快更新速率。
		//	可用于选择性地更改服务器端的数据刷新率以进行优化
		//	操作为不同的客户端连接。
//
//	DEVICEREADPROC
		//Callback into Application whenever a client requests a SyncIO Read
		//with dwSource set to OPC_DS_DEVICE.  Argument list includes the item
		//handle with pointers to the data, quality, and timestamp to be supplied
		//by the application
		//	每当客户端请求SyncIO读取时回调到应用程序
		//	其中dwSource设置为OPC_DS_DEVICE。 参数列表包括项目
		//	句柄，指向要提供的数据，质量和时间戳
		//	由应用程序
/////////////////////////////////////////////////////////////////////////////////////////////
#ifdef STRICT
typedef VOID (CALLBACK* WRITENOTIFYPROC)(HANDLE, VARIANT*, DWORD*);
typedef VOID (CALLBACK* UNKNOWNITEMPROC)(CHAR*,CHAR*);
typedef VOID (CALLBACK* ITEMREMOVEDPROC)(HANDLE,CHAR*,CHAR*);
typedef VOID (CALLBACK* DISCONNECTPROC)(DWORD);
typedef VOID (CALLBACK* EVENTMSGPROC)(CHAR*);
typedef VOID (CALLBACK* RATECHANGEPROC)(HANDLE, DWORD);
typedef VOID (CALLBACK* DEVICEREADPROC)(HANDLE, VARIANT*, WORD*, FILETIME*);
#else /* !STRICT */
typedef FARPROC WRITENOTIFYPROC;
typedef FARPROC UNKNOWNITEMPROC;
typedef FARPROC ITEMREMOVEDPROC;
typedef FARPROC DISCONNECTPROC;
typedef FARPROC EVENTMSGPROC;
typedef FARPROC RATECHANGEPROC;
typedef FARPROC DEVICEREADPROC;

#endif

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */



/////////////////////////////////////////////////////////////////////////////////////////////
//
//	Initialization and Registration functions
//  初始化和注册功能
// 
/////////////////////////////////////////////////////////////////////////////////////////////
//	WTOPCsvrRevision()
		//Simply returns a version identifier for the DLL
		//简单地返回DLL的版本标识符
//	SetThreadingModel()
		//Allows the application to select either the COINIT_MULTITHREADED
		//or COINIT_APARTMENTTHREADED model for the Server, 
		//(the default is COINIT_MULTITHREADED ).
		//	允许应用程序选择COINIT_MULTITHREADED
		//	或COINIT_APARTMENTTHREADED模型为服务器，
		//	（默认值为COINIT_MULTITHREADED）。
//
//	InitWTOPCsvr()
		//Initializes DCOM, Security, and creates the Server ClassFactory
		//pCLSID_Svr points to a c-style GUID structure
		//	初始化DCOM，安全性并创建服务器类工厂
		//	pCLSID_Svr指向c风格的GUID结构
//
//	ResetServerRate()
		//The specified ServerRate is the fastest rate at which the data can
		//be updated to a client.  The minimum server rate that may be selected is
		//10 ms.
		//	指定的ServerRate是数据可以达到的最快速率
		//	更新到客户端。 可以选择的最小服务器速率为
		//	10 ms。
//
//	SetVendorInfo()
		//Allows the application to specify a vendor specifc string to identify
		//the server.  This string will appear as part of the OPCSERVERSTATUS structure
		//returned by the GetStatus Interface.
		//	允许应用程序指定供应商特定的字符串以标识服务器。 
		//	此字符串将作为GetStatus接口返回的OPC SERVER STATUS结构的一部分显示。

//
//	SetCaseSensitivity();
		//Determines how the comparison is made for matcbing Tag Names.
		//	确定如何对匹配的标记名称进行比较。
//
//	UninitWTOPCsvr()
		//Uninitializes COM.
		//	未初始化COM。
//
//	UpdateRegistry()
		//Makes the appropriate entries to the Windows Registry to identify the Server.
		//pCLSID_Svr points to a c-style GUID structure
		//	对Windows注册表进行相应的条目以标识服务器。
		//	pCLSID_Svr指向c风格的GUID结构
//
//	AddLocalServiceKeysToRegistry()
		//Makes additional Registry Entries required if the Server is to be installed
		//as an NT Service.
		//	如果要安装服务器，需要额外的注册表项
		//	作为NT服务。
//
//	UnregisterServer()
		//Removes the Registry Entries
		//pCLSID_Svr points to a c-style GUID structure
		//	删除注册表项pCLSID_Svr指向c风格的GUIDE结构
//
/////////////////////////////////////////////////////////////////////////////////////////////

_declspec(dllexport) WORD WINAPI WTOPCsvrRevision();

_declspec(dllexport) BOOL WINAPI SetThreadingModel(DWORD dwCoInit);

_declspec(dllexport) BOOL WINAPI InitWTOPCsvr (BYTE *pCLSID_Svr, UINT ServerRate);

_declspec(dllexport) BOOL WINAPI UninitWTOPCsvr ();

_declspec(dllexport) BOOL WINAPI ResetServerRate (UINT ServerRate);

_declspec(dllexport) BOOL WINAPI UpdateRegistry (BYTE *pCLSID_Svr, LPCSTR Name, LPCSTR Descr, LPCSTR ExePath);

_declspec(dllexport) BOOL WINAPI AddLocalServiceKeysToRegistry (LPCSTR Name);

_declspec(dllexport) BOOL WINAPI UnregisterServer (BYTE *pCLSID_Svr, LPCSTR Name);

_declspec(dllexport) void WINAPI SetVendorInfo (LPCSTR VendorInfo);

_declspec(dllexport) BOOL WINAPI SetCaseSensitivity(BOOL bOn = FALSE);



/////////////////////////////////////////////////////////////////////////////////////////////
//
//	OPC Item Functions
//	OPC项目功能
/////////////////////////////////////////////////////////////////////////////////////////////
//
// SetWtOPCsvrQualifier(...)
		//Allows the application to supply the delimiting character used to
		//seperate tag names in a hiearchial namespace.
		//(The delimiting character by default is '.')
		//	允许应用程序提供用于在分层命名空间
		//	中分隔标记名称的定界字符。（默认情况下，分隔字符为“.”）
//
//	CreateTag()
		//Add an OPC Item to the WtOPCsvr.DLL local tag list.  The dll takes care of
		//all client references to the tag and provides a callback to the application
		//if the tag is updated by a client.  Once a tag gets created, it's name will
		//automatically be presented in the browse list to any interested OPC Client.
		//	将一个OPC项添加到WtOPCsvr.DLL本地标记列表。 dll照顾
		//	所有客户端对标签的引用，并提供对应用程序的回调
		//	如果标签由客户端更新。 一旦标签被创建，它的名字就会
		//	自动在浏览列表中呈现给任何感兴趣的OPC客户端。
//
//	UpdateTag()
//	UpdateTagWithTimeStamp()
//	UpdateTagByName()
		//Allows the Server Application to change the value, quality and timestamp of
		//a tag.  All updates are automatically provided to subscribing clients as defined
		//by the particular connection.  
		//	允许服务器应用程序更改的值，质量和时间戳
		//	标签。 所有更新自动提供给定义的订阅客户端
		//	通过特定连接。
//
//	SetTagProperties()
		//Tag Properties are values associated with an OPC Item other than its Value,
		//Quality and TimeStamp.  Any property value may be assigned by the server
		//for a defined tag.
		//	标记属性是与OPC项目关联的值，而不是其值，
		//	质量和时间戳。 任何属性值都可以由服务器分配
		//	对于定义的标记。
//
//	ReadTag()
//	ReadTagWithTimeStamp()
		//Allows the Application to read each tag value from the WtOPCsvr.dll local Tag List.
		//	允许应用程序从WtOPCsvr.dll本地标记列表中读取每个标记值。
//
//	SuspendTagUpdates()
		//When a Tag is created by the Server Application, it is automatically enabled for
		//client subscription.  The tag name will automatically be included in the server
		//browse list and any client may connect and read it's current value.  In certain 
		//applications, it is desirable to only create the tag whenever a client requests it.
		//The UNKNOWNITEMPROC callback may be used for dynamic tag allocation, but until the
		//tag is created, the tag name will not show up in the browse list.  Creation of the
		//tag followed by a call to SuspendTagUpdates() will allow the tag name to be browsed
		//by a client, but not subscribed to.  In this scenario, the WtOPCsvr.dll will issue
		//the UNKNOWNITEMPROC callback to allow the Application to enable the tag and begin
		//updating it's value only when being actively subscribed by an OPC Client.
		//	当标记由服务器应用程序创建时，会自动启用
		//	客户端订阅。 标签名称将自动包含在p服务器中
		//	浏览列表，任何客户端可以连接并读取其当前值。 在某些
		//	应用程序，每当客户端请求它时，只需创建标记。
		//	UNKNOWNITEMPROC回调可以用于动态标签分配，但直到
		//	标签，则标签名称不会显示在浏览列表中。 创建
		//	标签，然后调用SuspendTagUpdates（）将允许浏览标签名称
		//	由客户端，但没有订阅。 在这种情况下，WtOPCsvr.dll将发出
		//	UNKNOWNITEMPROC回调允许应用程序启用标记并开始
		//	只有在被OPC客户端主动订阅时才更新它的值。
//
//	RemoveTag()
		//Deletes a tag from the WtOPCsvr Tag List.
		//	从WtOPCsvr标记列表中删除标记。
//
/////////////////////////////////////////////////////////////////////////////////////////////

_declspec(dllexport) char  WINAPI SetWtOPCsvrQualifier (char qualifier);

_declspec(dllexport) HANDLE WINAPI CreateTag (LPCSTR Name, VARIANT Value, WORD InitialQuality, BOOL IsWritable);

_declspec(dllexport) BOOL WINAPI UpdateTag (HANDLE TagHandle, VARIANT Value, WORD Quality);

_declspec(dllexport) BOOL WINAPI UpdateTagWithTimeStamp (HANDLE TagHandle, VARIANT Value, WORD Quality, FILETIME timestamp);

_declspec(dllexport) BOOL WINAPI UpdateTagByName (LPCSTR Name, VARIANT Value, WORD Quality);

_declspec(dllexport) BOOL WINAPI SetTagProperties (HANDLE TagHandle, DWORD PropertyID, LPCSTR Description, VARIANT Value);

_declspec(dllexport) BOOL WINAPI ReadTag (HANDLE TagHandle, VARIANT *pValue);

_declspec(dllexport) BOOL WINAPI ReadTagWithTimeStamp (HANDLE TagHandle, VARIANT *pValue, WORD *pQuality, FILETIME *pTimestamp);

_declspec(dllexport) BOOL WINAPI SuspendTagUpdates (HANDLE TagHandle, BOOL OnOff);

_declspec(dllexport) BOOL WINAPI RemoveTag (HANDLE TagHandle);

//RWD	2-Aug-2000	ARtI - Associates for Real-time Information
//-------------------------------------------------------------------------------------
// SetServerState	allows user to show problems 允许用户显示问题
// SetHashing		enables hashing, sets suggested hashtable size 启用散列，设置建议的散列表大小
// UpdateTagToList	replaces UpdateTag call, requires prior StartUpdateTags else fails
//					and EndUpdateTags after all tags updated...替换UpdateTag调用，在所有标签更新后需要先前的StartUpdateTags否则失败和EndUpdateTags ...
// variations UpdateTagWithTimeStampTo List and UpdateTagByNameToList could also be done...变量UpdateTagWithTimeStampTo List和UpdateTagByNameToList也可以做...

_declspec(dllexport) void WINAPI SetServerState( OPCSERVERSTATE ServerState );

_declspec(dllexport) unsigned long WINAPI SetHashing( unsigned long sizeHash );

_declspec(dllexport) BOOL WINAPI StartUpdateTags ();

_declspec(dllexport) BOOL WINAPI UpdateTagToList (HANDLE TagHandle, VARIANT Value, WORD Quality);

_declspec(dllexport) BOOL WINAPI EndUpdateTags ();
//endRWD

/////////////////////////////////////////////////////////////////////////////////////////////
//
//	Auxilary Functions
//	辅助功能
/////////////////////////////////////////////////////////////////////////////////////////////
//
//	NumbrClientConnections()
		//Allows the Server Application to determine the number of OPC Clients
		//currently connected.
		//	允许服务器应用程序确定OPC客户端的数量
		//	当前连接。
//
//	RequestDisconnect()
		//Provides the ability for the Server Application to request that all
		//Clients gracefully disconnect.  There is no guarantee that any client
		//will honor the request.
		//	提供服务器应用程序请求所有的能力
		//	客户端正常断开连接。 不能保证任何客户
		//	将尊重该请求。
//
//	RefreshAllClients()
	//	Forces the WtOPCsvr.DLL to issue data updates to all connected Clients.
	//	(Primarily used for debugging.  Normal client updates are issued automatically
	//	by the WtOPCsvr.DLL based on an iternal clock tick.)
	//	RefreshAllClients（）
	//	强制WtOPCsvr.DLL向所有连接的客户端发出数据更新。
	//	（主要用于调试。正常客户端更新自动发出
	//	由基于一个时钟周期的WtOPCsvr.DLL）。
//
// ConvertVBDateToFileTime()
// ConvertFileTimeToVBDate()
		//To be used with Visual Basic to convert between the OPC timestamp
		//iand a Date variable
		//	要与Visual Basic一起使用以在OPC时间戳之间进行转换
		//	iand一个Date变量
//
////////////////////////////////////////////////////////////////////////////////////////////

_declspec(dllexport) int WINAPI NumbrClientConnections ();

_declspec(dllexport) void WINAPI RequestDisconnect ();

_declspec(dllexport) BOOL WINAPI RefreshAllClients();

_declspec(dllexport) BOOL WINAPI ConvertVBDateToFileTime1 (double *pVBDate, FILETIME *pFileTime);

_declspec(dllexport) BOOL WINAPI ConvertFileTimeToVBDate1 (FILETIME *pFileTime, double *pVBDate);

/////////////////////////////////////////////////////////////////////////////////////////////
//
//	Callback Enabling Functions
//	回调启用功能
/////////////////////////////////////////////////////////////////////////////////////////////
_declspec(dllexport) BOOL WINAPI EnableWriteNotification (WRITENOTIFYPROC lpCallback, BOOL ConvertToNativeType);

_declspec(dllexport) BOOL WINAPI EnableUnknownItemNotification (UNKNOWNITEMPROC lpCallback);

_declspec(dllexport) BOOL WINAPI EnableItemRemovalNotification (ITEMREMOVEDPROC lpCallback);

_declspec(dllexport) BOOL WINAPI EnableDisconnectNotification (DISCONNECTPROC lpCallback);

_declspec(dllexport) BOOL WINAPI EnableEventMsgs (EVENTMSGPROC lpCallback);

_declspec(dllexport) BOOL WINAPI EnableRateNotification (RATECHANGEPROC lpCallback);

_declspec(dllexport) BOOL WINAPI EnableDeviceRead (DEVICEREADPROC lpCallback);

/////////////////////////////////////////////////////////////////////////////////////////////
//
// Support for Alarms & Events
// (March 2000)
//	支持报警和事件
/////////////////////////////////////////////////////////////////////////////////////////////
_declspec(dllexport) BOOL WINAPI UserAEMessage (LPCSTR Msg, DWORD Severity);

_declspec(dllexport) BOOL WINAPI UserAEMessageEx (ONEVENTSTRUCT Msg);

_declspec(dllexport) BOOL WINAPI UserAEMessageEx2 (DWORD hEventSubscription, ONEVENTSTRUCT Msg, BOOL bRefresh, BOOL bLastRefresh);

//
// Literal Definitions for LevelID LevelID的字面定义
//
#define	ID_LOLO_LIMIT	1
#define ID_LO_LIMIT		2
#define ID_HI_LIMIT		3
#define ID_HIHI_LIMIT	4

_declspec(dllexport) BOOL WINAPI SetItemLevelAlarm (HANDLE TagHandle, int LevelID, float Limit, DWORD Severity, BOOL Enabled);

_declspec(dllexport) BOOL WINAPI GetItemLevelAlarm (HANDLE TagHandle, int LevelID, float *pLimit, DWORD *pSeverity, BOOL *pEnabled);




/////////////				Undocumented Functions						  ////////////////
//																						//
//				Undocumented function to Disable Demo Timer								//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////


_declspec(dllexport) BOOL WINAPI Deactivate30MinTimer (LPCSTR Authorization);


/////////////////////////////////////////////////////////////////////////////////////////////
//
// Expanded Support for A&E callbacks 扩展支持A＆E回调
// (March 2001)
//
 //The application can use the CWtAExCallback object definition below
 //to generate overloaded functions to change the default behavior of the 
 //WtOPCsvr.dll with regard to Alarms & Events.
//应用程序可以使用下面的CWtAExCallback对象定义来生成重载函数，
//以更改WtOPCsvr.dll关于警报和事件的默认行为。
//
 //Basic support for Alarms & Events is supplied by the dll in the form of
 //High & Low level alarms surrounding each defined OPC Item.  As the data values
 //change, these level limits are compared and event messages generated as appropriate.
 //The default behavior of the WtOPCsvr.dll does not provide for acknowledgements
 //from an OPC Client or any filtering to be applied to the event subscription.
	// 对报警和事件的基本支持由dll的形式提供
	// 围绕每个定义的OPC项目的高 / 低电平报警。 作为数据值
	// 更改，则会对这些级别限制进行比较，并根据需要生成事件消息。
	// WtOPCsvr.dll的默认行为不提供确认
	// 从OPC客户端或要应用于事件订阅的任何过滤。
//
 //by basing a c++ object on the cwtaexcallback object and overloading any of
 //the virtual functions the application can expand upon or replace the basic
 //a&e functionality of the dll as required.
	// 通过在cwtaexcallback对象上建立一个c ++对象并重载任何
	// 应用程序可以扩展或替换基本的虚拟功能
	// dll的e＆e功能。
/////////////////////////////////////////////////////////////////////////////////////////////

#ifdef _WTOPCSVRDLL
class __declspec(dllexport) CWtAExCallback
#else
class __declspec(dllimport) CWtAExCallback
#endif
{
public:
	// This is the object definition for the A&E callback object
   CWtAExCallback();
   virtual ~CWtAExCallback();

   // CIOPCEventServer::GetStatus(...)
   // The dll supplies the Last Update Time parameter to match the requesting subscriber.
   // The default implementation of this function returns valid parameters to the client.
   // Only overload this function if you have specific infprmation to add to the status structure
   virtual HRESULT GetStatus(OPCEVENTSERVERSTATUS** ppEventServerStatus, FILETIME LastUpdateTime);

   // CIOPCEventServer::QueryAvailableFilters(...)
   // The default implementation of this function returns zero for the FilterMask
   // ans S_OK, (i.e. Filters not supported!)
   virtual HRESULT QueryAvailableFilters (DWORD *pdwFilterMask);

   // CIOPCEventServer::QueryEventCategories (...)
   // The default implementation of this function supports two categories
   //		OPC_SIMPLE_EVENT	--  OPC_MSG_CAT:System Message
   //		OPC_CONDITION_EVENT	--	OPC_LEVEL_CAT:Level
   //							--	OPC_DISCRETE_CAT:Discrete
   virtual HRESULT QueryEventCategories( 
								DWORD		dwEventType,
								DWORD		*pdwCount,
								DWORD		**ppdwEventCategories,
								LPWSTR		**ppszEventCategoryDescs);

   // CIOPCEventServer::QueryConditionNames (...)
   // The default implementation of this function returns the following condition names
   //	OPC_MSG_CAT			--	"Informational Text"
   //	OPC_LEVEL_CAT		--	"Level Alarm"
   //	OPC_DISCRETE_CAT	--	"Discrete Alarm"
   virtual HRESULT QueryConditionNames( 
								DWORD		dwEventCategory,
								DWORD		*pdwCount,
								LPWSTR		**ppszConditionNames);

   // CIOPCEventServer::QuerySubConditionNames(...)
   // The default implementation of this function returns 
   // four subCondition Names for the "Level Alarm" condition:
   //		"Lo"
   //		"Lo Lo"
   //		"Hi"
   //		"Hi Hi"
   virtual HRESULT QuerySubConditionNames( 
								LPWSTR		szConditionName,
								DWORD		*pdwCount,
								LPWSTR		**ppszSubConditionNames);

   // CIOPCEventServer::QuerySourceConditions(...)
   // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT QuerySourceConditions( 
								LPWSTR		szSource,
								DWORD		*pdwCount,
								LPWSTR		**ppszConditionNames);

  // CIOPCEventServer::QueryEventAttributes(...)
  // The default implementation of this function returns E_NOTIMPL
  virtual HRESULT QueryEventAttributes( 
								DWORD		dwEventCategory,
								DWORD		*pdwCount,
								DWORD		**ppdwAttrIDs,
								LPWSTR		**ppszAttrDescs,
								VARTYPE		**ppvtAttrTypes);

  // CIOPCEventServer::TranslateToItemIDs(...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT TranslateToItemIDs( 
								LPWSTR		szSource,
								DWORD		dwEventCategory,
								LPWSTR		szConditionName,
								LPWSTR		szSubconditionName,
								DWORD		dwCount,
								DWORD		*pdwAssocAttrIDs,
								LPWSTR		**ppszAttrItemIDs,
								LPWSTR		**ppszNodeNames,
								CLSID		**ppCLSIDs);

  // CIOPCEventServer::GetConditionState(...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT GetConditionState( 
								LPWSTR		szSource,
								LPWSTR		szConditionName,
								DWORD		dwNumEventAttrs,
								DWORD		*pdwAttributeIDs,
								OPCCONDITIONSTATE	**ppConditionState);

  // CIOPCEventServer::EnableConditionByArea(...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT EnableConditionByArea( 
								DWORD			dwNumAreas,
								LPWSTR			*pszAreas);

  // CIOPCEventServer::EnableConditionBySource(...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT EnableConditionBySource( 
								DWORD		dwNumSources,
								LPWSTR		*pszSources);

  // CIOPCEventServer::DisableConditionByArea(...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT DisableConditionByArea( 
								DWORD		dwNumAreas,
								LPWSTR		*pszAreas);

  // CIOPCEventServer::DisableConditionBySource(...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT DisableConditionBySource( 
								DWORD		dwNumSources,
								LPWSTR		*pszSources);

  // CIOPCEventServer::AckCondition(...)
  // The default implementation of this function returns S_FALSE
   virtual HRESULT AckCondition( 
								DWORD		dwCount,
								LPWSTR		szAcknowledgerID,
								LPWSTR		szComment,
								LPWSTR		*pszSource,
								LPWSTR		*pszConditionName,
								FILETIME	*pftActiveTime,
								DWORD		*pdwCookie,
								HRESULT		**ppErrors);

  // CIOPCEventServer::CreateAreaBrowser(...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT CreateAreaBrowser( 
								REFIID		riid,
								LPUNKNOWN	*ppUnk);


  // CreateEventSubscription (DWORD hEventSubscription)
  // RemoveEventSubscription (DWORD hEventSubscription)
  // WtOPCsvr.dll will execute these funtions in the application callback
  // object whenevr a client subcribes and unsubscribes to the event server.
  // This allows the application to implement filters on an individual
  // subscription basis by calling UserAEMessageEx2.
   virtual HRESULT CreateEventSubscription (DWORD hEventSubscription, DWORD dwBufferTime, DWORD dwMaxSize, OPCHANDLE hClientSubscription); 
   virtual HRESULT RemoveEventSubscription (DWORD hEventSubscription); 

  // CIOPCEventSubscriptionMgt::SetFilter (...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT SetEventSubscriptionFilter( 
							DWORD		hEventSubscription,
							DWORD		dwEventType,
							DWORD		dwNumCategories,
							DWORD		*pdwEventCategories,
							DWORD		dwLowSeverity,
							DWORD		dwHighSeverity,
							DWORD		dwNumAreas,
							LPWSTR		*pszAreaList,
							DWORD		dwNumSources,
							LPWSTR		*pszSourceList);

  // CIOPCEventSubscriptionMgt::GetFilter (...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT GetEventSubscriptionFilter( 
							DWORD			hEventSubscription,
							DWORD			*pdwEventType,
							DWORD			*pdwNumCategories,
							DWORD			**ppdwEventCategories,
							DWORD			*pdwLowSeverity,
							DWORD			*pdwHighSeverity,
							DWORD			*pdwNumAreas,
							LPWSTR			**ppszAreaList,
							DWORD			*pdwNumSources,
							LPWSTR			**ppszSourceList);

  // CIOPCEventSubscriptionMgt::SelectReturnedAttributes (...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT SelectEventSubscriptionReturnedAttributes( 
										DWORD		hEventSubscription,
										DWORD		dwEventCategory,
										DWORD		dwCount,
										DWORD		*dwAttributeIDs);
        
  // CIOPCEventSubscriptionMgt::GetReturnedAttributes (...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT GetEventSubscriptionReturnedAttributes( 
										DWORD		hEventSubscription,
										DWORD		dwEventCategory,
										DWORD		*pdwCount,
										DWORD		**ppdwAttributeIDs);

  // CIOPCEventSubscriptionMgt::Refresh (...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT RefreshEventSubscription(
							DWORD		hEventSubscription,
							DWORD		dwConnection);
        
  // CIOPCEventSubscriptionMgt::CancelRefresh (...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT CancelEventSubscriptionRefresh(
							DWORD		hEventSubscription,
							DWORD		dwConnection);
        
  // CIOPCEventSubscriptionMgt::GetState (...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT GetEventSubscriptionState( 
							DWORD			hEventSubscription,
							BOOL			*pbActive,
							DWORD			*pdwBufferTime,
							DWORD			*pdwMaxSize,
							OPCHANDLE		*phClientSubscription);
        
  // CIOPCEventSubscriptionMgt::SetState (...)
  // The default implementation of this function returns E_NOTIMPL
   virtual HRESULT SetEventSubscriptionState( 
							DWORD			hEventSubscription,
							BOOL			*pbActive,
							DWORD			*pdwBufferTime,
							DWORD			*pdwMaxSize,
							OPCHANDLE		hClientSubscription,
							DWORD			*pdwRevisedBufferTime,
							DWORD			*pdwRevisedMaxSize);


};

//
// Exported function to override the default CWtAExCallback object with one
// specific to the application.  Overload the functions you wish to process
// within your app.  If the application chooses to implement its own set
// of Alarms & Event categories, it should disable the internal limit checking
// for item values.
//
_declspec(dllexport) BOOL WINAPI SetAEServerCallback (BOOL DisableInternalItemLimits, CWtAExCallback *pCallback); 


#ifdef __cplusplus
}
#endif
