#include <iostream>
#include <cstdlib>
using namespace std;

class MATH1   //類別MATH1:可封裝"副程式"與"變數"
{
public:	//public為公開之成員,可讓外部程式呼叫

	//MATH1(int a) { c = a; } //建構式(initialization)
	//~MATH1();				//解構式(清除...)

	int Add(int a, int b)	//成員函式
	{
		return(a + b);
	}
	int Sub(int a, int b);	//成員函式(未定義)
	int c;					//成員變數3

};
int MATH1::Sub(int a, int b) //也可在class外面定義副程式
{
	return(a - b);
}
/*
MATH1::~MATH1() {
	printf("end the class MATH1\n");
}
*/

//類別MATH2 宣告與定義(第二代)
class MATH2 : public MATH1 //繼承上一代(MATH1)的成員內容
{
public:
	int Mul(int a, int b) { return (a*b); }
	float Div(int a, int b) { return((float)a / (float)b); }
};

//類別MATH3 宣告與定義(第三代)
class MATH3 : public MATH2 //繼承上一代(MATH2)的成員內容
{
public:
	int And(int a, int b) { return (a&b); }
	int Xor(int a, int b) { return (a^b); }
};

int main()
{
	int a, b, c;  //local variables

	//MATH1類別的使用
	MATH1 *lpMath1;
	lpMath1 = new MATH1(); //觸動建構式,回傳新建的class的記憶體位址給lpMath1 
	a = 10; b = 20; c = 30;
	printf("%d + %d = %d\n", a, b, lpMath1->Add(a, b));
	printf("%d - %d = %d\n", a, b, lpMath1->Sub(a, b));
	printf("c = %d\n", lpMath1->c);  //記憶: 指標加箭頭,變數加點
	lpMath1->c = c;
	printf("c = %d\n", lpMath1->c);
	delete lpMath1; //觸動解構式

	//MATH2類別的使用
	MATH2 *lpMath2 = new MATH2();
	printf("%d * %d = %d\n", a, b, lpMath2->Mul(a, b));
	printf("%d / %d = %f\n", a, b, lpMath2->Div(a, b));
	printf("%d + %d = %d\n", a, b, lpMath2->Add(a, b));

	//MATH3類別的使用
	MATH3 *lpMath3 = new MATH3();

	printf("%d / %d = %f\n", a, b, lpMath3->Div(a, b)); //父親的
	printf("%d + %d = %d\n", a, b, lpMath3->Add(a, b)); //祖父的
	printf("%d & %d = %d\n", a, b, lpMath3->And(a, b));	//自己的
	printf("%d ^ %d = %d\n", a, b, lpMath3->Xor(a, b));
}