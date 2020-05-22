#include "ConstructorMode.h"
#include <iostream>
using namespace std;

void main()
{
	//客户直接造房子
	//优点 理解起来最方便 
	//缺点 没有将 一个“类别” 封装起来 缺乏面向对象的思想 简单粗暴 面向过程
	//House* pHose = new House;
	//pHose->setDoor("wbm门");
	//pHose->setFloor("wbmFloor");
	//pHose->setWall("wbmWall");
	//delete pHose;


	////工程队直接造房子
	////优点 对具体的建造细节 进行了封装 
	////缺点 灵活性较差 一旦需求有变动 工程队将不能满足
	//Builder *builder = new FlatBuild;
	//builder->makeFloor();
	//builder->makeWall();
	//builder->makeDoor();


	//设计师--》指挥不同的工程队--》建造不同需求的房子

	//指挥者（设计师）指挥 工程队 和 建房子
	Director* director = new Director;

	//建公寓 想要公寓就让 公寓工程队去建造
	Builder* builder = new FlatBuild;
	director->Construct(builder); //设计师 指挥 工程队干活
	House* house = builder->GetHouse();
	cout << house->getFloor() << endl;
	delete house;
	delete builder;

	//建别墅  //想要别墅就让别墅工程队去建造
	builder = new VillaBuild;//这个时候已经创造了房子这个对象
	//只不过对象所具有的方法 属性没有得到相应的初始化 
	//就理解为 既然要找别墅工程队 来，就已经确定了是建造别墅了 工程队 是带着别墅的思想和 对象来的
	director->Construct(builder); //设计师 指挥 工程队干活 这个地方就已经将房子内部建造装饰完毕了
	house = builder->GetHouse();//这个地方只不过是拿到这个房子的钥匙而已 房子在前面早就完成了
	cout << house->getFloor() << endl;
	delete house;
	delete builder;

	delete director;

	system("pause");
	return;
}
