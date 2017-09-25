# 开发环境与工具
 + # 开发环境
   1. 由于所使用的动态链接库是32位的，所以选用的JDK(Java软件开发工具包)也是需要32位的，本文采用的版本为：JDK 1.8.0_121。
   2. 下载OPC基金会的OPC Proxy DLL然后按照说明进行安装。这些动态库是opc程序运行所必须的。
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
MyEclipse 是一个非常出色的用于开发Java, J2EE的 Eclipse 插件集合，MyEclipse的功能十分丰富，支持也非常广泛，特别是对各种开源产品的支持非常出色。MyEclipse可以支持Java Servlet，AJAX，JSP，JSF，Struts，Spring，Hibernate，EJB3，JDBC数据库链接工具等多项功能。可以说MyEclipse是收纳了目前所有主要开源产品的eclipse开发工具。
  2. 在本地C++端所使用的开发工具为Visual Studio 2015
Visual Studio 是一套基于组件的软件开发工具和其他技术，可用于构建功能强大、性能出众的应用程序。作为一个功能强大的开发工具，其具有很多优点，例如更优的代码编辑器、能够调试Lambdas表达式、更优的代码智能提示、强大的诊断工具和完全支持C++11标准等等。
