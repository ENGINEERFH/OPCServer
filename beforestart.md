# 开发环境与工具
 + # 开发环境
   1. 由于所使用的动态链接库是32位的，所以选用的JDK(Java软件开发工具包)也是需要32位的，本文采用的版本为：JDK 1.8.0_121。
   2. 下载OPC基金会的OPC Proxy DLL然后按照说明进行安装（见DLL文件夹）。这些动态库是opc程序运行所必须的。
   将下列文件拷贝至要运行OPC服务器和OPC客户端的机器上的SYSTEM32目录下
      - copy opcproxy.dll C:\WINDOWS\system32
      - copy opccomn_ps.dll C:\WINDOWS\system32
      - copy opc_aeps.dll C:\WINDOWS\system32
      - copy opchda_ps.dll C:\WINDOWS\system32
      - copy aprxdist.exe C:\WINDOWS\system32
      - copy opcenum.exe C:\WINDOWS\system32
   3. 注册这些 dll 文件
      - REGSVR32 opcproxy.dll
      - REGSVR32 opccomn_ps.dll
      - REGSVR32 opc_aeps.dll
      - REGSVR32 opchda_ps.dll
   4. 如果在windows 系统(\WINDOWS \system32)目录下不存在actxprxy.dll，运行aprxdist.exe
   5. 安装 opcenum.exe
      - opcenum /regserver
   6. 将OPC动态链接库WtOPCSvr.dll和上面生成的STOPCServer.dll也一起拷贝到SYSTEM32目录下
+ # 开发工具
  1. 在Java端所使用的开发工具为MyEclipse
  2. 在本地C++端所使用的开发工具为Visual Studio 2015
