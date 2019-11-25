#include "Hsah.h"
int main()
{
	Hsah hs;
	// 添加记录
	hs.append("小东", "中关村22号", "15675650786");
	hs.append("小智", "下家村58号", "15685638912");
	hs.append("小明", "详细28号", "14226048511");
	hs.append("小南", "月月光45号", "13226856411");
	hs.append("小北", "明朗小8号", "13205501111");

	cout << endl;
	//按号码查找
	hs.findnum("15675650786");
	hs.findnum("15685638912");

	hs.findnum("17584511");
	cout << endl;

	//按姓名查找
	hs.findname("小明");
	hs.findname("小南");

	hs.findname("小");

	cout << endl;

	//显示列表
	hs.showphone();
	cout << endl;
	hs.showname();
	return 0;
}
/*
小东　15675650786 中关村22号
小智　15685638912 下家村58号
没有此人记录！

小明　14226048511 详细28号
小南　13226856411 月月光45号
没有此人记录！

姓名：小北
电话号码：13205501111
住宅地址：明朗小8号
姓名：小智
电话号码：15685638912
住宅地址：下家村58号
姓名：小明
电话号码：14226048511
住宅地址：详细28号
姓名：小东
电话号码：15675650786
住宅地址：中关村22号
姓名：小南
电话号码：13226856411
住宅地址：月月光45号

姓名：小北
电话号码：13205501111
住宅地址：明朗小8号
姓名：小东
电话号码：15675650786
住宅地址：中关村22号
姓名：小智
电话号码：15685638912
住宅地址：下家村58号
姓名：小南
电话号码：13226856411
住宅地址：月月光45号
姓名：小明
电话号码：14226048511
住宅地址：详细28号
请按任意键继续:*/