// Shape.h: interface for the CShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPE_H__0DDFC950_19D8_41D5_B543_F4AE9A832BB7__INCLUDED_)
#define AFX_SHAPE_H__0DDFC950_19D8_41D5_B543_F4AE9A832BB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CShape  
{
protected:
	COLORREF borderColor;//边框颜色
	COLORREF fillColor;//填充颜色
	CPoint startPoint;//绘制起点
	CPoint endPoint;//绘制终点
	enum shapeType{UNSURE,LINE,RECTANGLE,ELLIPSE};//形状类型
	shapeType type;
public:
	CShape();
	CShape(COLORREF p_borderColor,COLORREF p_fillColor,CPoint p_startPoint,CPoint p_endPoint);
	virtual void draw(CDC* pDC)=0;//绘图函数，在子类中具体实现
	//set
	COLORREF setBorderColor(COLORREF color){return borderColor=color;}//设置边框颜色
	COLORREF setFillColor(COLORREF color){return fillColor=color;}//设置填充颜色
	CPoint setStartPoint(CPoint point){return startPoint=point;}//设置起点
	CPoint setEndPoint(CPoint point){return endPoint=point;}//设置终点	
	shapeType setShapeType(shapeType p_type){return type=p_type;}
	//get
	COLORREF getBorderColor(){return borderColor;}
	COLORREF getFillColor(){return fillColor;}
	CPoint getStartPoint(){return startPoint;}
	CPoint getEndPoint(){return endPoint;}
	shapeType getShapeType(){return type;}

	virtual ~CShape();

};

#endif // !defined(AFX_SHAPE_H__0DDFC950_19D8_41D5_B543_F4AE9A832BB7__INCLUDED_)
