package com.st.opcserver.tags;


public class STTags {

	private String name;      						//Tag������
	private Long handle;							//Tag�ڷ������еľ��
	private String property;						//Tag������
	private String property_value;					//Tag������ֵ
	private String value;							//Tag����ֵ����String��ʾ����DLL���Ѿ�������������ת��
	private String value_type;						//Tag���������ͣ�VT_INT��VT_DOUBLE��VT_BOOLEAN��VT_STRING
	private Boolean iswritable;					//Tag�Ƿ��д
	private Long readaccesslevel;					//Tag�ķ��ʵȼ�
	private Long writeaccesslevel;					//Tag��д��ȼ�
	private float[] limits = new float[4];		//Tag�ı�����ֵ
	private long[] severity = new long[4];		//Tag�ı������س̶�
	private boolean[] enabled = new boolean[4];	//Tag�ĸü���ı����Ƿ���
	
	/**
	 * �޲������캯����Ĭ��������������Ϊnull��0
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
	 * �в������캯���������еĲ�����������Ĳ�����ʼ��һ��
	 * 
	 * @param name Tag������
	 * @param handle Tag�ڷ������еľ��
	 * @param property Tag������
	 * @param property_value Tag������ֵ
	 * @param value Tag�����ݣ���String��ʾ����DLL���Ѿ�������������ת��
	 * @param value_type  Tag���������ͣ�VT_INT��VT_DOUBLE��VT_BOOLEAN��VT_STRING
	 * @param iswritable Tag�Ƿ��д
	 * @param readaccesslevel Tag�ķ��ʵȼ�
	 * @param writeaccesslevel Tag��д��ȼ�
	 * @param limits Tag�ı�����ֵ
	 * @param severity Tag�ı������س̶�
	 * @param enabled Tag�ĸü���ı����Ƿ���
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
	 * ��ȡTag������
	 * 
	 * @return Tag������
	 */
	public String getName() {
		return name;
	}

	/**
	 * ����Tag������
	 * 
	 * @param name Tag������
	 */
	public void setName(String name) {
		this.name = name;
	}

	/**
	 * ��ȡTag�ڷ������еľ��
	 *  
	 * @return Tag�ڷ������еľ��
	 */
	public Long getHandle() {
		return handle;
	}

	/**
	 * ����Tag�ڷ������еľ��
	 * 
	 * @param handle Tag�ڷ������еľ��
	 */
	public void setHandle(Long handle) {
		this.handle = handle;
	}

	/**
	 * ��ȡTag������
	 * 
	 * @return Tag������
	 */
	public String getProperty() {
		return property;
	}

	/**
	 * ����Tag������
	 * 
	 * @param property Tag������
	 */
	public void setProperty(String property) {
		this.property = property;
	}

	/**
	 * ��ȡTag������ֵ
	 * 
	 * @return Tag������ֵ
	 */
	public String getProperty_value() {
		return property_value;
	}

	/**
	 * ����Tag������ֵ
	 * 
	 * @param property_value Tag������ֵ
	 */
	public void setProperty_value(String property_value) {
		this.property_value = property_value;
	}

	/**
	 * ��ȡTag����ֵ
	 * 
	 * @return Tag����ֵ����String��ʾ����DLL���Ѿ�������������ת��
	 */
	public String getValue() {
		return value;
	}

	/**
	 * ����Tag����ֵ
	 * 
	 * @param value Tag����ֵ����String��ʾ����DLL���Ѿ�������������ת��
	 */
	public void setValue(String value) {
		this.value = value;
	}

	/**
	 * ��ȡTag����������
	 * 
	 * @return Tag���������ͣ�����VT_INT��VT_DOUBLE��VT_BOOLEAN��VT_STRING
	 */
	public String getValue_type() {
		return value_type;
	}

	/**
	 * ����Tag����������
	 * 
	 * @param value_type Tag���������ͣ�����VT_INT��VT_DOUBLE��VT_BOOLEAN��VT_STRING
	 */
	public void setValue_type(String value_type) {
		this.value_type = value_type;
	}

	/**
	 * ��ȡTag�Ƿ��д
	 * 
	 * @return Tag�Ƿ��д
	 */
	public Boolean getIswritable() {
		return iswritable;
	}

	/**
	 * ����Tag�Ƿ��д
	 * 
	 * @param iswritable Tag�Ƿ��д
	 */
	public void setIswritable(Boolean iswritable) {
		this.iswritable = iswritable;
	}

	/**
	 * ��ȡTag�ķ��ʵȼ�
	 * 
	 * @return Tag�ķ��ʵȼ�
	 */
	public Long getReadaccesslevel() {
		return readaccesslevel;
	}

	/**
	 * ����Tag�ķ��ʵȼ�
	 * 
	 * @param readaccesslevel Tag�ķ��ʵȼ�
	 */
	public void setReadaccesslevel(Long readaccesslevel) {
		this.readaccesslevel = readaccesslevel;
	}

	/**
	 * ��ȡTag��д��ȼ�
	 * 
	 * @return Tag��д��ȼ�
	 */
	public Long getWriteaccesslevel() {
		return writeaccesslevel;
	}

	/**
	 * ����Tag��д��ȼ�
	 * 
	 * @param writeaccesslevel Tag��д��ȼ�
	 */
	public void setWriteaccesslevel(Long writeaccesslevel) {
		this.writeaccesslevel = writeaccesslevel;
	}

	/**
	 * ��ȡTag�ı�����ֵ
	 * 
	 * @return Tag�ı�����ֵ
	 */
	public float[] getLimits() {
		return limits;
	}

	/**
	 * ����Tag�ı�����ֵ
	 * 
	 * @param limits Tag�ı�����ֵ
	 */
	public void setLimits(float[] limits) {
		this.limits = limits;
	}

	/**
	 * ��ȡTag�ı������س̶�
	 * 
	 * @return Tag�ı������س̶�
	 */
	public long[] getSeverity() {
		return severity;
	}

	/**
	 * ����Tag�ı������س̶�
	 * 
	 * @param severity Tag�ı������س̶�
	 */
	public void setSeverity(long[] severity) {
		this.severity = severity;
	}

	/**
	 * ��ȡTag�ĸü���ı����Ƿ���
	 * 
	 * @return Tag�ĸü���ı����Ƿ���
	 */
	public boolean[] getEnabled() {
		return enabled;
	}

	/**
	 * ����Tag�ĸü���ı����Ƿ���
	 * 
	 * @param enabled Tag�ĸü���ı����Ƿ���
	 */
	public void setEnabled(boolean[] enabled) {
		this.enabled = enabled;
	}

}
