////����ָ������벻����������
//class complex
//{
//private:
//	double re, im;
//
//	//friend complex& __doapl(complex*, const complex&); //��Ԫ�������Է���˽�г�Ա//��Ԫ����Ҫ������private��
//public:
//	complex(double r = 0, double i = 0) :re(r), im(i)
//	{} //����д���Ĺ��캯��Ч�ʻ����
//
//	double real() const { return re; } 
//	double imag() const { return im; }
//
//	//complex& �����ô��ݲ���,����ֵ
//	//��Ա�����Ĳ���������
//	inline complex&
//		operator += (const complex & r)
//	{
//		return __doapl(this, r);
//	}
//
//	inline complex&
//		__doapl(complex* ths, const complex& r)
//	{
//		ths->re += r.re;
//		ths->im += r.im;
//		return *ths;
//	}
//
//};
//
//complex c1(2, 1); //����ķ���
//complex c2; //����Ĭ�ϵĳ�ʼֵ��0��0��
//complex* p = new complex(4); //ͨ��ָ�봴����̬����
//
////�ǳ�Ա�����Ĳ��������� ʹ������cout<<c1;
////
//ostream&
//operator << (ostream& os, const complex& x)
//{
//	return os << '(' << x.real() << ',' << x.imag() << ')';
//}