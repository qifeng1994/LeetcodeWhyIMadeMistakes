//P11
//composition��ʾhas-a��ϵ
//���ģʽ adapter ������ģʽ

//composition by reference��ʾ������ͨ��ָ��������ָ��ָ�����ʵ�֡�

//inheritance��ʾis-a-kind-of��ϵ

//P12 �麯��

//���ģʽ��template method ��������ø���ķ���
//class CDocument
//{
//public:
//	OnFileOpen();
//	virtual Serialize() {} //�յ��麯��
//};
//
//CDocument::OnFileOpen()
//{
//	//...
//	Serialize();
//	//...
//}
//
//class CMyDoc :public CDocument
//{
//public:
//	virtual Serialize(){}
//};
//
//main()
//{
//	CMyDoc myDoc;
//	myDoc.OnFileOpen();
//}

//���ģʽ observer or Publish/subscribe �۲���ģʽ��delegation+inheritance

//P13
//���ģʽ composite
//class Component
//{
//private:
//	int value;
//public:
//	Component(int val) { value = val; }
//	virtual void add(Component*){} //�յ��麯��
//};
//
//class Primitive :public Component
//{
//public:
//	Primitive(int val):Component(val){}
//};
//
//class Composite :public Component
//{
//private:
//	vector<Component*> c; //composite����Է�component����
//public:
//	Composite(int val) :Component(val) {}
//	void add(Component* elem) { c.push_back(elem); } //ʵ����ί��
//};

//���ģʽ prototype û����
