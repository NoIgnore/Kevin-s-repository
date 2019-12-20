#include "pch.h"
#include "Cline.h"

void Cline::OnDraw(CDC* pDC)
{
	if (read_file_o == 1) 
	{
		m_start = from_layer_startpoint;
		m_end = from_layer_endpoint;
		read_file_o = 0;
	}
	pDC->MoveTo(m_start);
	pDC->LineTo(m_end);
	if (m_type == selecting) 
	{	
		pDC->FillSolidRect(m_start.x - 3, m_start.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_end.x - 3, m_end.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
	}
	read_file_o = 0;//view.cpp的142行详情
}
void Cline::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_end = point;
	from_layer_endpoint = point;
	m_type = normal;
}
void Cline::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_start = point;
	from_layer_startpoint = point;
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
	m_type = rect.PtInRect(point) ? selecting : normal;//使m_type变成selecting
	my_point_selected = point;
}
void Cline::Offset(CPoint ptoffset)
{
	m_start.Offset(ptoffset);
	m_end.Offset(ptoffset);
	from_layer_startpoint = m_start;
	from_layer_endpoint = m_end;
}

void Cline::OnFileSave()
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

void Cline::OnFileOpen(CString pathName)
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


Cline::Cline():m_end(MAXLONG, MAXLONG),m_start(0,0)
{
}
Cline::~Cline() {

}