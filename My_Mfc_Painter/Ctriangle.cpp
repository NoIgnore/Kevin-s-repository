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

Ctriangle::Ctriangle()
{
}

Ctriangle::~Ctriangle()
{
}
