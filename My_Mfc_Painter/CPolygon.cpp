#include "pch.h"
#include "CPolygon.h"

void CPolygon::OnDraw(CDC* pDC)
{
	if (layer_click == 0 || read_file_o)
	{
		pDC->MoveTo(m_start);
		pDC->LineTo(m_middle1);
		pDC->MoveTo(m_middle1);
		pDC->LineTo(m_middle2);
		pDC->MoveTo(m_middle2);
		pDC->LineTo(m_end);
		pDC->MoveTo(m_end);
		pDC->LineTo(m_start);
	}
	if (m_type == selecting)
	{
		pDC->FillSolidRect(m_start.x - 3, m_start.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_middle1.x - 3, m_middle1.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_middle2.x - 3, m_middle2.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_end.x - 3, m_end.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));

	}
	read_file_o = 0;
}

void CPolygon::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_type = normal;
}

void CPolygon::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (layer_click == 1)
	{
		m_start = point;
		layer_click = 2;
	}
	else if (layer_click == 2) {
		m_middle1 = point;
		layer_click = 3;
	}
	else if (layer_click == 3) {
		m_middle2 = point;
		layer_click = 4;
	}
	else if (layer_click == 4) {
		m_end = point;
		layer_click = 0;
	}
}

void CPolygon::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	m_shape = 5;
}

void CPolygon::SelectLayer(UINT nFlags, CPoint point)
{
	CRect rect1(m_start, m_middle1);
	rect1.NormalizeRect();
	CRect rect2(m_middle1, m_middle2);
	rect2.NormalizeRect();
	CRect rect3(m_middle2, m_end);
	rect3.NormalizeRect();
	CRect rect4(m_end, m_start);
	rect4.NormalizeRect();
	m_type = (rect1.PtInRect(point) || rect2.PtInRect(point) || rect3.PtInRect(point) || rect4.PtInRect(point)) ? selecting : normal;//Ê¹m_type±ä³Éselecting
	my_point_selected = point;
}

void CPolygon::Offset(CPoint ptoffset)
{
	m_start.Offset(ptoffset);
	m_middle1.Offset(ptoffset);
	m_middle2.Offset(ptoffset);
	m_end.Offset(ptoffset);
}

void CPolygon::OnFileSave()
{
	buffer.Format(_T("%d %d %d %d %d %d %d %d %d"),
		m_shape,
		m_start.x,
		m_start.y,
		m_middle1.x,
		m_middle1.y,
		m_middle2.x,
		m_middle2.y,
		m_end.x,
		m_end.y
	);
	buffer += "\n";
}

void CPolygon::OnFileOpen(CString pathName)
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
		>> m_middle1.x
		>> m_middle1.y
		>> m_middle2.x
		>> m_middle2.y
		>> m_end.x
		>> m_end.y;
	fin2.close();
	read_file_o = 1;
}

CPolygon::CPolygon()
{
	layer_click = 1;
}

CPolygon::~CPolygon()
{
}
