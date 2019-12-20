#include "pch.h"
#include "Ctriangle.h"

void Ctriangle::OnDraw(CDC* pDC)
{
	if (layer_click == 0 || read_file_o)
	{
		pDC->MoveTo(from_layer_startpoint);
		pDC->LineTo(from_layer_middlepoint);
		pDC->MoveTo(from_layer_middlepoint);
		pDC->LineTo(from_layer_endpoint);
		pDC->MoveTo(from_layer_endpoint);
		pDC->LineTo(from_layer_startpoint);
	}
	if (m_type == selecting)
	{
		pDC->FillSolidRect(from_layer_startpoint.x - 3, from_layer_startpoint.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(from_layer_middlepoint.x - 3, from_layer_middlepoint.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(from_layer_endpoint.x - 3, from_layer_endpoint.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
	}
	//Mypointlist* test_point = from_layer_head_point->next;
	/*if (test == 1)
	{
		Mypointlist* test_point = from_layer_head_point->next;
		while (test_point->next != nullptr)
		{
			pDC->MoveTo(test_point->my__point);
			pDC->LineTo(test_point->next->my__point);
			test_point = test_point->next;
		}
		pDC->MoveTo(from_layer_tail_point->my__point);
		pDC->LineTo(from_layer_head_point->my__point);
	}*/
	read_file_o = 0;
}

void Ctriangle::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_type = normal;
}

void Ctriangle::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (layer_click == 1)
	{
		from_layer_startpoint = point;
		layer_click = 2;
	}
	else if (layer_click == 2) {
		from_layer_middlepoint = point;
		layer_click = 3;
	}
	else if (layer_click == 3) {
		from_layer_endpoint = point;
		layer_click = 0;
	}
}

void Ctriangle::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	m_shape = 4;
}

void Ctriangle::SelectLayer(UINT nFlags, CPoint point)
{
	CRect rect1(from_layer_startpoint, from_layer_middlepoint);
	rect1.NormalizeRect();
	CRect rect2(from_layer_middlepoint, from_layer_endpoint);
	rect2.NormalizeRect();
	CRect rect3(from_layer_endpoint, from_layer_startpoint);
	rect3.NormalizeRect();
	m_type = (rect1.PtInRect(point) || rect2.PtInRect(point) || rect3.PtInRect(point)) ? selecting : normal;//Ê¹m_type±ä³Éselecting
	my_point_selected = point;
}

void Ctriangle::Offset(CPoint ptoffset)
{
	from_layer_startpoint.Offset(ptoffset);
	from_layer_middlepoint.Offset(ptoffset);
	from_layer_endpoint.Offset(ptoffset);
}

void Ctriangle::OnFileSave()
{
	buffer.Format(_T("%d %d %d %d %d %d %d"),
		m_shape,
		from_layer_startpoint.x,
		from_layer_startpoint.y,
		from_layer_middlepoint.x,
		from_layer_middlepoint.y,
		from_layer_endpoint.x,
		from_layer_endpoint.y
	);
	buffer += "\n";
}

void Ctriangle::OnFileOpen(CString pathName)
{
	if (layer_n >= 2)
	{
		ifstream fin2;
		fin2.open(pathName);
		for (int i = 1; i < layer_n; i++)
		{
			getline(fin2, layer_string);
		}
		fin2 >> m_shape
			>> from_layer_startpoint.x
			>> from_layer_startpoint.y
			>> from_layer_middlepoint.x
			>> from_layer_middlepoint.y
			>> from_layer_endpoint.x
			>> from_layer_endpoint.y;
		fin2.close();
	}
	else {
		ifstream fin2;
		fin2.open(pathName);
		fin2 >> m_shape
			>> from_layer_startpoint.x
			>> from_layer_startpoint.y
			>> from_layer_middlepoint.x
			>> from_layer_middlepoint.y
			>> from_layer_endpoint.x
			>> from_layer_endpoint.y;
		fin2.close();
	}
	read_file_o = 1;
}

//void Ctriangle::OnFileOpen()
//{
//	ifstream hhj;
//	while (!hhj.eof())
//	{
//		hhj >> from_layer_startpoint.x
//			>> from_layer_startpoint.y
//			>> from_layer_middlepoint.x
//			>> from_layer_middlepoint.y
//			>> from_layer_endpoint.x
//			>> from_layer_endpoint.y;
//	}
//	read_file_o = 1;
//}

Ctriangle::Ctriangle()
{
}

Ctriangle::~Ctriangle()
{
}
