#include "pch.h"
#include "Ctriangle.h"

void Ctriangle::OnDraw(CDC* pDC)
{
	if (layer_click == 0 || read_file_o)
	{
		pDC->MoveTo(m_start);
		pDC->LineTo(m_middle);
		pDC->MoveTo(m_middle);
		pDC->LineTo(m_end);
		pDC->MoveTo(m_end);
		pDC->LineTo(m_start);
	}
	if (m_type == selecting)
	{
		pDC->FillSolidRect(m_start.x - 3, m_start.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_middle.x - 3, m_middle.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_end.x - 3, m_end.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
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
		m_start = point;
		layer_click = 2;
	}
	else if (layer_click == 2) {
		m_middle = point;
		layer_click = 3;
	}
	else if (layer_click == 3) {
		m_end = point;
		layer_click = 0;
	}
}

void Ctriangle::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	m_shape = 4;
}

void Ctriangle::SelectLayer(UINT nFlags, CPoint point)
{
	CRect rect1(m_start, m_middle);
	rect1.NormalizeRect();
	CRect rect2(m_middle, m_end);
	rect2.NormalizeRect();
	CRect rect3(m_end, m_start);
	rect3.NormalizeRect();
	m_type = (rect1.PtInRect(point) || rect2.PtInRect(point) || rect3.PtInRect(point)) ? selecting : normal;//Ê¹m_type±ä³Éselecting
	my_point_selected = point;
}

void Ctriangle::Offset(CPoint ptoffset)
{
	m_start.Offset(ptoffset);
	m_middle.Offset(ptoffset);
	m_end.Offset(ptoffset);
}

void Ctriangle::OnFileSave()
{
	buffer.Format(_T("%d %d %d %d %d %d %d"),
		m_shape,
		m_start.x,
		m_start.y,
		m_middle.x,
		m_middle.y,
		m_end.x,
		m_end.y
	);
	buffer += "\n";
}

void Ctriangle::OnFileOpen(CString pathName)
{
	ifstream fin2;
	fin2.open(pathName);
	if (layer_n >= 2)
	{
		for (int i = 1; i < layer_n; i++)
		{
			getline(fin2, layer_string);
		}
	}
	fin2 >> m_shape
		 >> m_start.x
		 >> m_start.y
		 >> m_middle.x
		 >> m_middle.y
		 >> m_end.x
		 >> m_end.y;
	fin2.close();
	read_file_o = 1;
}

Ctriangle::Ctriangle()
{
}

Ctriangle::~Ctriangle()
{
}
