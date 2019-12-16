﻿
// MFC222Doc.cpp: CMFC222Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC222.h"
#endif

#include "MFC222Doc.h"



#include "CLayer.h"//......................
#include "Cline.h"
#include <fstream>
#include"CEllipse.h"
#include"CRectangle.h"
#include"CPencil.h"
#include"Ctriangle.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC222Doc

IMPLEMENT_DYNCREATE(CMFC222Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFC222Doc, CDocument)
	ON_COMMAND(ID_FILE_SAVE, &CMFC222Doc::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CMFC222Doc::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFC222Doc::OnFileSaveAs)
	ON_COMMAND(ID_DRAW_ARROW, &CMFC222Doc::OnDrawArrow)
END_MESSAGE_MAP()


// CMFC222Doc 构造/析构

CMFC222Doc::CMFC222Doc()
{
	m_nindex2 = ID_DRAW_ARROW;
}

CMFC222Doc::~CMFC222Doc()
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}
}

void CMFC222Doc::draw(CDC* pDC)
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		shapes[i]->OnDraw(pDC);
	}
}

BOOL CMFC222Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFC222Doc 序列化

void CMFC222Doc::Serialize(CArchive& ar)
{
	/*numberdoc = m_docls.GetSize();*/
	if (ar.IsStoring())
	{
		
	}
	else
	{
		
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFC222Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFC222Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFC222Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFC222Doc 诊断

#ifdef _DEBUG
void CMFC222Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC222Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC222Doc 命令


void CMFC222Doc::OnFileSave()
{
	CString HAHAHA;
	HAHAHA = ".txt";
	CFileDialog saveDlg(false, TEXT("painter"), TEXT("未命名"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, HAHAHA);
	saveDlg.DoModal();
	CString pathName = saveDlg.GetPathName();

	if (pathName == "") return;
	CStdioFile fout;
	CString buffer;
	if (!fout.Open(pathName, CFile::modeCreate | CFile::modeWrite))
		return;
	for (size_t i = 0; i < size(); i++)
	{
		buffer.Format(_T("%d %d %d %d %d %d %d"),
			shapes[i]->m_shape,
			shapes[i]->from_layer_startpoint.x,
			shapes[i]->from_layer_startpoint.y,
			shapes[i]->from_layer_middlepoint.x,
			shapes[i]->from_layer_middlepoint.y,
			shapes[i]->from_layer_endpoint.x,
			shapes[i]->from_layer_endpoint.y
		);
		if (i != size() - 1)
			buffer += "\n";
		fout.WriteString(buffer);
	}
	fout.Close();
}


void CMFC222Doc::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog openDlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
	openDlg.DoModal();
	CString pathName = openDlg.GetPathName();
	if (pathName == "") return;
	
	using namespace std;
	ifstream fin;

	CPoint startPoint;
	CPoint middlePoint;
	CPoint endPoint;
	
	int type;//形状

	CLayer* newShape = NULL;

	fin.open(pathName);
	while (!fin.eof())
	{
		fin >> type
			>> startPoint.x
			>> startPoint.y
			>> middlePoint.x
			>> middlePoint.y
			>> endPoint.x
			>> endPoint.y;
		switch (type)
		{
		case 1://直线
			newShape = new Cline;
			newShape->m_shape = type;
			newShape->read_file_o = 1;
			newShape->from_layer_startpoint = startPoint;
			newShape->from_layer_endpoint = endPoint;

			break;
		case 2://矩形
			newShape = new CRectangle;
			newShape->m_shape = type;
			newShape->read_file_o = 1;
			newShape->from_layer_startpoint = startPoint;
			newShape->from_layer_endpoint = endPoint;

			break;
		case 3:
			newShape = new CEllipse;
			newShape->m_shape = type;
			newShape->read_file_o = 1;
			newShape->from_layer_startpoint = startPoint;
			newShape->from_layer_endpoint = endPoint;

			break;
		case 4://triangle
			newShape = new Ctriangle;
			newShape->m_shape = type;
			newShape->read_file_o = 1;
			newShape->layer_click = 1;
			newShape->from_layer_startpoint = startPoint;
			newShape->from_layer_middlepoint = middlePoint;
			newShape->from_layer_endpoint = endPoint;

			break;
		}
		push_back(newShape);


	}
	fin.close();
	numberdoc = 1;
}


void CMFC222Doc::OnFileSaveAs()
{
	CString HAHAHA;
	HAHAHA = ".txt";
	CFileDialog saveDlg(false, TEXT("txt"), TEXT("未命名"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, HAHAHA);
	saveDlg.DoModal();
	CString pathName = saveDlg.GetPathName();

	if (pathName == "") return;
	CStdioFile fout;
	CString buffer;
	if (!fout.Open(pathName, CFile::modeCreate | CFile::modeWrite))
		return;
	for (size_t i = 0; i < size(); i++)
	{
		buffer.Format(_T("%d %d %d %d %d"),
			shapes[i]->m_shape,
			shapes[i]->from_layer_startpoint.x,
			shapes[i]->from_layer_startpoint.y,
			shapes[i]->from_layer_endpoint.x,
			shapes[i]->from_layer_endpoint.y
		);
		if (i != size() - 1)
			buffer += "\n";
		fout.WriteString(buffer);
	}
	fout.Close();
}


void CMFC222Doc::OnDrawArrow()
{
	// TODO: 在此添加命令处理程序代码
}



