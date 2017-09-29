+ # 显示DLL的版本
  - ## 描述
  调用该接口将获得当前使用的dll版本
  - ## 接口名
  ```
  public String serverRevision()
  ```
  - ## 请求参数说明
    无
  - ## 返回参数说明
    返回"DLL Rev = 932"
---
+ # 注册服务器
  - ## 描述
    输入所需参数并调用后，就可以完成OPC服务器的注册，但后面还需要调用initServer()才可以完成服务器的相关配置。
  - ## 接口名
  ```
  public boolean registryServer(String svrname,String svrdescr)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   svrname|String|无|服务器的名字
   svrdescr|String|无|对服务器的描述

  - ## 返回参数说明
    成功 = true,失败 = false
---
+ # 卸载服务器
  - ## 描述
    输入需要卸载的opc服务器的名字并调用后，就可以完成对该opc服务器的卸载
  - ## 接口名
  ```
  public boolean unregisterServer(String svrname)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   svrname|String|无|需要卸载的服务器名

  - ## 返回参数说明
    成功 = true,失败 = false    
---
+ # 初始化服务器
  - ## 描述
    输入服务器的更新速率并调用后，就可以完成服务器的相关配置
  - ## 接口名
  ```
  public boolean initServer(int serverrate)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   serverrate|int|无|服务器的更新速率/ms

  - ## 返回参数说明
    成功 = true,失败 = false   
---
+ # 去除服务器的初始化
  - ## 描述
    调用就可以移除服务器的相关配置
  - ## 接口名
  ```
  public boolean uninitServer()
  ```
  - ## 请求参数说明
    无
  - ## 返回参数说明
    成功 = true,失败 = false   
---
+ # 更改服务器的更新速率
  - ## 描述
    输入参数并调用就可以随时更改服务器的更新速率，单位是ms
  - ## 接口名
  ```
  public boolean resetServerRate(int serverrate)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   serverrate|int|无|服务器的更新速率/ms

  - ## 返回参数说明
    成功 = true,失败 = false   
---
+ # 返回连接到服务器上的客户端数量
  - ## 描述
    调用就可以返回连接在服务器上的客户端数量
  - ## 接口名
  ```
  public int numbrClientConnections()
  ```
  - ## 请求参数说明
    无
  - ## 返回参数说明
    客户端数量，int类型，单位（个）   
---
+ # 强制断开所有客户端的连接
  - ## 描述
    强制断开所有客户端的连接，但是不确保所有客户端能断开
  - ## 接口名
  ```
   public void requestDisconnect()
  ```
  - ## 请求参数说明
    无
  - ## 返回参数说明
    无
---
+ # 强制服务器向客户端发出数据更新
  - ## 描述
    调用后将立刻强制服务器向所有客户端发送数据
  - ## 接口名
  ```
  public boolean refreshAllClients()
  ```
  - ## 请求参数说明
    无
  - ## 返回参数说明
    成功 = true,失败 = false  
---
+ # 设置tag命名空间分布的标志，默认为"."
  - ## 描述
    输入分隔符号并调用后将替换默认分隔符号，默认分隔符号为','，并且成功后将返回自定义的分隔符号以方便确认
  - ## 接口名
  ```
  public char setTagNameQualifier(char qualifier)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   qualifier|char|无|自定义的分隔符号

  - ## 返回参数说明
    自定义的分隔符号， char类型
---
+ # 设置tag的报警限值
  - ## 描述
    可以更改每一个存在的tag报警参数，包括报警限值，报警严重程度和是否使能报警
  - ## 接口名
  ```
  public boolean setItemLevelAlarm(long handle,int levelid ,float limits,long severity,boolean enabled)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   handle|longint|无|Tag的句柄
   levelid|int|无|分为4个等级 ID_LOLO_LIMIT = 1；ID_LO_LIMIT = 2；ID_HI_LIMIT = 3；ID_HIHI_LIMIT = 4；
   limits|float|无|Tag的报警限值
   severity|long|无|Tag的报警严重程度
   enabled|boolean|无|Tag的该级别的报警是否开启
  - ## 返回参数说明
    成功 = true,失败 = false  
---
+ # 读取tag的报警限值
  - ## 描述
    调用后会将报警限值的各种参数值返回到输入的参数上
  - ## 接口名
  ```
  public boolean getItemLevelAlarm(long handle ,float[] limits,long[] severity,boolean[] enabled)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   handle|long|无|tag的句柄
   limits|float[]|无|Tag的报警限值
   severity|long[]|无|Tag的报警严重程度
   enabled|boolean[]|无|Tag的该级别的报警是否开启

  - ## 返回参数说明
    成功 = true,失败 = false  
---
+ # 删除Tag
  - ## 描述
    输入所创建的Tag的句柄，就可以删除相应的Tag
  - ## 接口名
  ```
  public boolean deleteTag(long handle)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   handle|long|无|Tag的句柄

  - ## 返回参数说明
    成功 = true,失败 = false  
---
+ # 创建简单的Tag
  - ## 描述
    该接口只是加单的Tag创建，但是已经基本满足简单的需求了，传入的参数是一个对象，该对象的创建，可参考exampl的com.st.opcserver.tags中的形式或者根据下面的参数介绍自行创建（下同）
  - ## 接口名
  ```
  public long addTag(STTags tags)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   name|String|无|Tag的名字
   value|String|无|Tag的数值，用String表示，在DLL中已经做了数据类型转换
   value_type|String|VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING|Tag的数据类型
   iswritable|Boolean|无|Tag是否可写

  - ## 返回参数说明
    成功 = true,失败 = false  
---
+ # 通过句柄来更新简单的Tag
  - ## 描述
    只用来更新简单的Tag，匹配的参数是句柄
  - ## 接口名
  ```
  public boolean updateTag(STTags tags)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   handle|Long|无|Tag在服务器中的句柄
   value|String|无|Tag的数值，用String表示，在DLL中已经做了数据类型转换
   value_type|String|VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING|Tag的数据类型

  - ## 返回参数说明
    成功 = true,失败 = false  
---
+ # 通过Tag的名字来更新简单的Tag
  - ## 描述
    只用来更新简单的Tag，匹配的参数是Tag的名字
  - ## 接口名
  ```
  public boolean updateTagByName(STTags tags)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   name|String|无|Tag的名字
   value|String|无|Tag的数值，用String表示，在DLL中已经做了数据类型转换
   value_type|String|VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING|Tag的数据类型

  - ## 返回参数说明
    成功 = true,失败 = false  
---
+ # 从服务器中读取Tag的数值
  - ## 描述
    输入参数并调用就可以读取Tag的当前数值大小和类型
  - ## 接口名
  ```
  public String[] readTag(long handle)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   handle|long|无|Tag的句柄

  - ## 返回参数说明
    - String[0] = value --- 数值大小
    - String[1] = value_type --- 数值类型
---
+ # 完整创建Tag
  - ## 描述
    完整的创建一个Tag，包含了所有的可以设置的参数
  - ## 接口名
  ```
  public long allAddTag(STTags tags)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   name|String|无|Tag的名字
   property|String|无|Tag的属性
   property_value|String|无|Tag的属性值
   value|String|无|Tag的数值，用String表示，在DLL中已经做了数据类型转换
   value_type|String|VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING|Tag的数据类型
   iswritable|Boolean|无|Tag是否可写
   readaccesslevel|Long|无|Tag的访问等级
   writeaccesslevel|Long|无|Tag的写入等级
   limits|float[]|无|Tag的报警限值
   severity|long[]|无|Tag的报警严重程度
   enabled|boolean[]|无|Tag的该级别的报警是否开启

  - ## 返回参数说明
    成功 = true,失败 = false  
---
+ # 整体更新Tag
  - ## 描述
    只用来更新完整的Tag，同过Tag的句柄来匹配
  - ## 接口名
  ```
  public boolean allUpdateTag(STTags tags)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   handle|Long|无|Tag在服务器中的句柄
   property|String|无|Tag的属性
   property_value|String|无|Tag的属性值
   value|String|无|Tag的数值，用String表示，在DLL中已经做了数据类型转换
   value_type|String|VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING|Tag的数据类型
   iswritable|Boolean|无|Tag是否可写
   readaccesslevel|Long|无|Tag的访问等级
   writeaccesslevel|Long|无|Tag的写入等级
   limits|float[]|无|Tag的报警限值
   severity|long[]|无|Tag的报警严重程度
   enabled|boolean[]|无|Tag的该级别的报警是否开启

  - ## 返回参数说明
    成功 = true,失败 = false 
---
+ # 开启或关闭tag对客户端的更新
  - ## 描述
    通过改变输入的布尔型参数来对某一个根据句柄匹配到Tag的更新与否进行修改
  - ## 接口名
  ```
  public boolean suspendTagUpdates(long handle,boolean onoff)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   handle|long|无|Tag的句柄
   onoff|boolean|无|关闭或开启tag对客户端的更新

  - ## 返回参数说明
    成功 = true,失败 = false 
---
+ # 开启批量更新Tag
  - ## 描述
    调用将开启批量更新（用于需要大量同时更新Tag的场景），需配合updateTagsToList()和endUpdateTags()使用（见下面两个介绍）
  - ## 接口名
  ```
  public boolean startUpdateTags()
  ```
  - ## 请求参数说明
    无
  - ## 返回参数说明
    成功 = true,失败 = false 
---
+ # 批量更新Tag
  - ## 描述
    将一个需要更新的Tag和修改参数一起加入到更新队列中
  - ## 接口名
  ```
  public boolean updateTagsToList(STTags tags)
  ```
  - ## 请求参数说明

   参数字段|类型|限制|说明
   :----|:-----:|-----:|-----:
   handle|Long|无|Tag在服务器中的句柄
   value|String|无|Tag的数值，用String表示，在DLL中已经做了数据类型转换
   value_type|String|VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING|Tag的数据类型

  - ## 返回参数说明
    成功 = true,失败 = false 
---
+ # 关闭批量更新Tag
  - ## 描述
    调用后将在最短时间内完成对更新列表中的Tag的更新
  - ## 接口名
  ```
  public boolean endUpdateTags()
  ```
  - ## 请求参数说明
    无
  - ## 返回参数说明
    成功 = true,失败 = false 