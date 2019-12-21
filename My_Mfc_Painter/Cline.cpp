#include "pch.h"
#include "Cline.h"

void Cline::OnDraw(CDC* pDC)
{
	pDC->MoveTo(m_start);
	pDC->LineTo(m_end);
	if (m_type == selecting) 
	{	
		pDC->FillSolidRect(m_start.x - 3, m_start.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_end.x - 3, m_end.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
	}
}
void Cline::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_end = point;
	m_type = normal;
}
void Cline::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_start = point;
	m_shape = 1;
}
void Cline::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	
	if (nFlags & MK_LBUTTON) 
	{
		pDC->SetROP2(R2_NOT);
		if (m_end.x != MAXLONG)
		{
			pDC->MoveTo(m_start);
			pDC->LineTo(m_end);
		}
		m_end = point;
		pDC->MoveTo(m_start);
		pDC->LineTo(m_end);
	}
}
void Cline::SelectLayer(UINT nFlags, CPoint point)
{
	CRect rect(m_start, m_end);
	rect.NormalizeRect();
	m_type = rect.PtInRect(point) ? selecting : normal;//Ê¹m_type±ä³Éselecting
	my_point_selected = point;
}
void Cline::Offset(CPoint ptoffset)
{
	m_start.Offset(ptoffset);
	m_end.Offset(ptoffset);
}

void Cline::OnFileSave()
{
	buffer.Format(_T("%d %d %d %d %d"),
			m_shape,
			m_start.x,
			m_start.y,
			m_end.x,
			m_end.y
	);
	buffer += "\n";
}

void Cline::OnFileOpen(CString pathName)
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
		 >> m_end.x
		 >> m_end.y;
	fin2.close();
}


Cline::Cline():m_end(MAXLONG, MAXLONG),m_start(0,0)
{
}
Cline::~Cline() {

}