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
   serverrate|int|>= 10|服务器的更新速率/ms

  - ## 返回参数说明
    成功 = true,失败 = false   



