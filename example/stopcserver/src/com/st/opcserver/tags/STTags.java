package com.st.opcserver.tags;


public class STTags {

	private String name;      						//Tag的名字
	private Long handle;							//Tag在服务器中的句柄
	private String property;						//Tag的属性
	private String property_value;					//Tag的属性值
	private String value;							//Tag的数值，用String表示，在DLL中已经做了数据类型转换
	private String value_type;						//Tag的数据类型，VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING
	private Boolean iswritable;					//Tag是否可写
	private Long readaccesslevel;					//Tag的访问等级
	private Long writeaccesslevel;					//Tag的写入等级
	private float[] limits = new float[4];		//Tag的报警限值
	private long[] severity = new long[4];		//Tag的报警严重程度
	private boolean[] enabled = new boolean[4];	//Tag的该级别的报警是否开启
	
	/**
	 * 无参数构造函数，默认设置所有数据为null和0
	 */
	public STTags(){
		this.name = "null";
		this.handle = (long) 0;
		this.property = "null";
		this.property_value = "null";
		this.value = "null";
		this.value_type = "null";
		this.readaccesslevel = (long) 0;
		this.writeaccesslevel = (long) 0;
		this.iswritable = true;
	}

	/**
	 * 有参数构造函数，将所有的参数根据输入的参数初始化一编
	 * 
	 * @param name Tag的名字
	 * @param handle Tag在服务器中的句柄
	 * @param property Tag的属性
	 * @param property_value Tag的属性值
	 * @param value Tag的数据，用String表示，在DLL中已经做了数据类型转换
	 * @param value_type  Tag的数据类型，VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING
	 * @param iswritable Tag是否可写
	 * @param readaccesslevel Tag的访问等级
	 * @param writeaccesslevel Tag的写入等级
	 * @param limits Tag的报警限值
	 * @param severity Tag的报警严重程度
	 * @param enabled Tag的该级别的报警是否开启
	 */
	public STTags(String name, Long handle, String property, String property_value, String value, String value_type,boolean iswritable,
			Long readaccesslevel, Long writeaccesslevel, float[] limits, long[] severity, boolean[] enabled) {
		super();
		this.name = name;
		this.handle = handle;
		this.property = property;
		this.property_value = property_value;
		this.value = value;
		this.value_type = value_type;
		this.iswritable = iswritable;
		this.readaccesslevel = readaccesslevel;
		this.writeaccesslevel = writeaccesslevel;
		this.limits = limits;
		this.severity = severity;
		this.enabled = enabled;
	}

	/**
	 * 获取Tag的名字
	 * 
	 * @return Tag的名字
	 */
	public String getName() {
		return name;
	}

	/**
	 * 设置Tag的名字
	 * 
	 * @param name Tag的名字
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * 获取Tag在服务器中的句柄
	 *  
	 * @return Tag在服务器中的句柄
	 */
	public Long getHandle() {
		return handle;
	}

	/**
	 * 设置Tag在服务器中的句柄
	 * 
	 * @param handle Tag在服务器中的句柄
	 */
	public void setHandle(Long handle) {
		this.handle = handle;
	}

	/**
	 * 获取Tag的属性
	 * 
	 * @return Tag的属性
	 */
	public String getProperty() {
		return property;
	}

	/**
	 * 设置Tag的属性
	 * 
	 * @param property Tag的属性
	 */
	public void setProperty(String property) {
		this.property = property;
	}

	/**
	 * 获取Tag的属性值
	 * 
	 * @return Tag的属性值
	 */
	public String getProperty_value() {
		return property_value;
	}

	/**
	 * 设置Tag的属性值
	 * 
	 * @param property_value Tag的属性值
	 */
	public void setProperty_value(String property_value) {
		this.property_value = property_value;
	}

	/**
	 * 获取Tag的数值
	 * 
	 * @return Tag的数值，用String表示，在DLL中已经做了数据类型转换
	 */
	public String getValue() {
		return value;
	}

	/**
	 * 设置Tag的数值
	 * 
	 * @param value Tag的数值，用String表示，在DLL中已经做了数据类型转换
	 */
	public void setValue(String value) {
		this.value = value;
	}

	/**
	 * 获取Tag的数据类型
	 * 
	 * @return Tag的数据类型，包括VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING
	 */
	public String getValue_type() {
		return value_type;
	}

	/**
	 * 设置Tag的数据类型
	 * 
	 * @param value_type Tag的数据类型，包括VT_INT，VT_DOUBLE，VT_BOOLEAN，VT_STRING
	 */
	public void setValue_type(String value_type) {
		this.value_type = value_type;
	}

	/**
	 * 获取Tag是否可写
	 * 
	 * @return Tag是否可写
	 */
	public Boolean getIswritable() {
		return iswritable;
	}

	/**
	 * 设置Tag是否可写
	 * 
	 * @param iswritable Tag是否可写
	 */
	public void setIswritable(Boolean iswritable) {
		this.iswritable = iswritable;
	}

	/**
	 * 获取Tag的访问等级
	 * 
	 * @return Tag的访问等级
	 */
	public Long getReadaccesslevel() {
		return readaccesslevel;
	}

	/**
	 * 设置Tag的访问等级
	 * 
	 * @param readaccesslevel Tag的访问等级
	 */
	public void setReadaccesslevel(Long readaccesslevel) {
		this.readaccesslevel = readaccesslevel;
	}

	/**
	 * 获取Tag的写入等级
	 * 
	 * @return Tag的写入等级
	 */
	public Long getWriteaccesslevel() {
		return writeaccesslevel;
	}

	/**
	 * 设置Tag的写入等级
	 * 
	 * @param writeaccesslevel Tag的写入等级
	 */
	public void setWriteaccesslevel(Long writeaccesslevel) {
		this.writeaccesslevel = writeaccesslevel;
	}

	/**
	 * 获取Tag的报警限值
	 * 
	 * @return Tag的报警限值
	 */
	public float[] getLimits() {
		return limits;
	}

	/**
	 * 设置Tag的报警限值
	 * 
	 * @param limits Tag的报警限值
	 */
	public void setLimits(float[] limits) {
		this.limits = limits;
	}

	/**
	 * 获取Tag的报警严重程度
	 * 
	 * @return Tag的报警严重程度
	 */
	public long[] getSeverity() {
		return severity;
	}

	/**
	 * 设置Tag的报警严重程度
	 * 
	 * @param severity Tag的报警严重程度
	 */
	public void setSeverity(long[] severity) {
		this.severity = severity;
	}

	/**
	 * 获取Tag的该级别的报警是否开启
	 * 
	 * @return Tag的该级别的报警是否开启
	 */
	public boolean[] getEnabled() {
		return enabled;
	}

	/**
	 * 设置Tag的该级别的报警是否开启
	 * 
	 * @param enabled Tag的该级别的报警是否开启
	 */
	public void setEnabled(boolean[] enabled) {
		this.enabled = enabled;
	}

}
